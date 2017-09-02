#include "btree.hpp"
TreeRecursionResponse::TreeRecursionResponse(bool _hasBeenSplit, int _promotedKey, unsigned short _newBlockOffset)
    : hasBeenSplit(_hasBeenSplit)
    , promotedKey(_promotedKey)
    , newBlockOffset(_newBlockOffset)
{
}

Node::Node(int order)
{
    count = 0;
    countPointers = 0;
}

bool Node::isLeaf()
{
    return countPointers == 0;
}

bool Node::hasRoom()
{
    return count < MAX_KEYS;
}

/**
* Insert a key in a node and returns the index where the insertion was made.
*/
unsigned short Node::insert(int key)
{ // [TROCAR]

    unsigned short i;

    for (i = count; i >= 1; i--) {
        if (key > keys[i - 1]) {
            keys[i] = key;
            break;
        } else {
            keys[i] = keys[i - 1];
        }
    }
    if (i == 0) {
        keys[0] = key;
    }

    count++;

    return i;
}

BTree::BTree()
    : SUCCESSFUL_TREE_INSERTION(false, 0, 0)
{
    rootOffset = 1;
}

void BTree::buildIndex(FILE* indexFile)
{
    rewind(indexFile);
    fwrite(&rootOffset, sizeof(Block_t), 1, indexFile);
    root = new Node(MAX_KEYS);
    fwrite(root, sizeof(Block_t), 1, indexFile);
}

void inline writeBackNode(Node* node, int offset, FILE* indexFile)
{
    fseek(indexFile, sizeof(Block_t) * offset, SEEK_SET);
    fwrite(node, sizeof(Block_t), 1, indexFile);
}

char inline relativeKeyPosition(int key, int leftMiddle, int rightMiddle)
{
    if (key < leftMiddle) {
        return RELATIVE_LEFT;
    } else if (key > rightMiddle) {
        return RELATIVE_RIGHT;
    }

    return RELATIVE_MIDDLE;
}

int inline writeNewNode(Node* node, FILE* indexFile)
{
    fseek(indexFile, 0, SEEK_END);

    fwrite(node, sizeof(Block_t), 1, indexFile);
    return (ftell(indexFile) / sizeof(Block_t)) - 1;
}

TreeRecursionResponse BTree::insertRecursive(int key, Node* node, int offset, FILE* indexFile)
{
    if (node->isLeaf()) {

        if (node->hasRoom()) {
            node->insert(key);
            writeBackNode(node, offset, indexFile);

            // return { false, { 0, 0 } };
            return SUCCESSFUL_TREE_INSERTION;
        }

        Node* splitLeaf = new Node(MAX_KEYS);
        int promoted;

        // elege o promoted e manipula os vetores resultantes da operação do splitLeaf.
        int leftMiddleKey = node->keys[LEFT_MIDDLE_KEY];
        int rightMiddleKey = node->keys[RIGHT_MIDDLE_KEY];

        splitLeaf->count = node->count = HALF_MAX_KEYS;

        switch (relativeKeyPosition(key, leftMiddleKey, rightMiddleKey)) {
        case RELATIVE_LEFT: {
            promoted = leftMiddleKey;
            --node->count;

            node->insert(key);

            for (int i = HALF_MAX_KEYS, j = 0; i < MAX_KEYS; ++i, ++j) {
                splitLeaf->keys[j] = node->keys[i];
            }
        } // não esquecer de manipular os blockPointes para nós não-folha
        break;

        case RELATIVE_RIGHT: {
            promoted = rightMiddleKey;
            --splitLeaf->count;

            for (int i = RIGHT_MIDDLE_KEY + 1, j = 0; i < MAX_KEYS; ++i, ++j) {
                splitLeaf->keys[j] = node->keys[i];
            } // não esquecer de manipular os blockPointes para nós não-folha

            splitLeaf->insert(key);
        } break;

        case RELATIVE_MIDDLE: {
            promoted = key;

            for (int i = HALF_MAX_KEYS, j = 0; i < MAX_KEYS; ++i, ++j) {
                splitLeaf->keys[j] = node->keys[i];
            }
        } // não esquecer de manipular os blockPointes para nós não-folha

        break;
        }

        writeBackNode(node, offset, indexFile);
        int offset = writeNewNode(splitLeaf, indexFile);

        delete splitLeaf; // deleta da memória principal pois já foi salvo no disco

        // return { true, { promoted, offset } };
        return TreeRecursionResponse(true, promoted, offset);
    }

    auto result = binarySearch(node->keys, node->count, key); // [TROCAR]

    unsigned short childNodeOffset = ((key < node->keys[result.second]) ? node->blockPointers[result.second] : node->blockPointers[result.second + 1]);

    Node* retrieveNode = new Node(MAX_KEYS);
    fseek(indexFile, sizeof(Block_t) * childNodeOffset, SEEK_SET);
    fread(retrieveNode, sizeof(Block_t), 1, indexFile);

    auto resultRecursion = insertRecursive(key, retrieveNode, childNodeOffset, indexFile);
    delete retrieveNode;

    // WARNING: FALTA RESOLVER A QUESTÃO DE DELEÇÃO DOS PONTEIROS PARA NODE NAS CHAMADAS RECURSIVAS

    if (resultRecursion.hasBeenSplit) { // caso em que veio um valor promovido e um blockPointer
        //caso 1 - tem espaço para inserir o promovido
        if (node->hasRoom()) {
            //o + 1 é para não realizar essa soma em toda iteração do for logo abaixo
            unsigned short rightIndexInserted = node->insert(resultRecursion.promotedKey) + 1;

            for (unsigned short i = node->countPointers; i > rightIndexInserted; --i) {
                node->blockPointers[i] = node->blockPointers[i - 1];
            }

            node->blockPointers[rightIndexInserted] = resultRecursion.newBlockOffset;
            ++node->countPointers;

            writeBackNode(node, offset, indexFile);
        } else { // caso 2 - não tem espaço para inserir o promovido -> fazer o split com remanejamento de chaves
            Node* split = new Node(MAX_KEYS);
            int promoted;

            // elege o promoted e manipula os vetores resultantes da operação do split.
            int leftMiddleKey = node->keys[LEFT_MIDDLE_KEY];
            int rightMiddleKey = node->keys[RIGHT_MIDDLE_KEY];

            split->count = node->count = HALF_MAX_KEYS; // remoção lógica exatamente na metade

            //como está cheio, vai metade dos elementos para cada bloco, contnado com o split.
            // se vai metade, haverá metade + 1 ponteiros para bloco preenchidos.
            split->countPointers = node->countPointers = HALF_MAX_KEYS + 1;

            switch (relativeKeyPosition(resultRecursion.promotedKey, leftMiddleKey, rightMiddleKey)) {
            case RELATIVE_LEFT: {
                promoted = leftMiddleKey;

                --node->count;

                // índice do ponteiro mais à direita do vetor blockPointers
                unsigned short greaterNodeBlockPointer = node->blockPointers[node->countPointers - 1]; // a subtração tem a ver com índice

                //índice em que foi inserido o promovido no nó já existente
                unsigned short rightIndexInserted = node->insert(resultRecursion.promotedKey) + 1;

                //remanejar os blockPoints
                for (unsigned short i = node->countPointers - 1; i > rightIndexInserted; --i) {
                    node->blockPointers[i] = node->blockPointers[i - 1];
                }

                node->blockPointers[rightIndexInserted] = resultRecursion.newBlockOffset;

                for (int i = HALF_MAX_KEYS, j = 0; i < MAX_KEYS; ++i, ++j) {
                    split->keys[j] = node->keys[i];
                    split->blockPointers[j + 1] = node->blockPointers[i + 1];
                } // não esquecer de manipular os blockPointes para nós não-folha

                split->blockPointers[0] = greaterNodeBlockPointer;
            } break;

            case RELATIVE_RIGHT: {
                promoted = rightMiddleKey;
                --split->count;
                // não é preciso modificar o countPointers nem o count do node aqui porque eles já foram atribuidos ali em cima,
                // então a remoção lógica já foi feita

                for (int i = RIGHT_MIDDLE_KEY + 1, j = 0; i < MAX_KEYS; ++i, ++j) {
                    split->keys[j] = node->keys[i];
                    split->blockPointers[j] = node->blockPointers[i];
                } // não esquecer de manipular os blockPointes para nós não-folha/

                split->blockPointers[HALF_MAX_KEYS - 1] = node->blockPointers[MAX_KEYS];
                unsigned short rightIndexInserted = split->insert(resultRecursion.promotedKey) + 1;

                //remanejar os blockPoints
                for (unsigned short i = split->countPointers - 1; i > rightIndexInserted; --i) {
                    split->blockPointers[i] = split->blockPointers[i - 1];
                }

                split->blockPointers[rightIndexInserted] = resultRecursion.newBlockOffset;
            } break;

            case RELATIVE_MIDDLE: {
                promoted = resultRecursion.promotedKey;

                for (int i = HALF_MAX_KEYS, j = 0; i < MAX_KEYS; ++i, ++j) {
                    split->keys[j] = node->keys[i];
                    split->blockPointers[j + 1] = node->blockPointers[i + 1];
                } // não esquecer de manipular os blockPointes para nós não-folha
                split->blockPointers[0] = resultRecursion.newBlockOffset;
            } break;
            }

            writeBackNode(node, offset, indexFile);
            int offset = writeNewNode(split, indexFile);
            delete split; // deleta da memória principal pois já foi salvo no disco
            return TreeRecursionResponse(true, promoted, offset);
            // return { true, { promoted, offset } };
        }
    }

    return SUCCESSFUL_TREE_INSERTION;
    // return TreeRecursionResponse(false, 0, 0);
    // return { false, { 0, 0 } };
}

void BTree::insert(int key, FILE* indexFile)
{ // [TROCAR]
    auto result = insertRecursive(key, root, rootOffset, indexFile);

    if (result.hasBeenSplit) { // se tiver um promovido vindo de um split abaixo
        Node* newRoot = new Node(MAX_KEYS);
        newRoot->insert(result.promotedKey); // insere a key promovida do nível abaixo
        newRoot->blockPointers[0] = rootOffset; //apontador esquerdo -> antiga raíz

        // considerando que o block splittado já foi salvo no arquivo na função insertRecursive
        newRoot->blockPointers[1] = result.newBlockOffset;
        newRoot->countPointers = 2;

        // salvar o newRoot no arquivo da BTree
        rootOffset = writeNewNode(newRoot, indexFile);

        // atualizar o header
        fseek(indexFile, 0, SEEK_SET);

        fwrite(&rootOffset, sizeof(Block_t), 1, indexFile);

        delete (root);
        root = newRoot;

        fseek(indexFile, 0, SEEK_END);
    }
}

bool BTree::getArticle(int key, Article_t* article, FILE* indexFile)
{
    Block_t currentBlock;
    BTreeNodeReinterpret* reinterpretation = (BTreeNodeReinterpret*)&currentBlock;
    reinterpretation->node = *root;

    if (reinterpretation->node.count <= 0) {
        std::cout << "Not Found" << '\n';
        return false;
    }

    auto currentPointer = binarySearch(reinterpretation->node.keys, reinterpretation->node.count, key);
    std::cout << "Searching for key " << key << " at the root(" << this->rootOffset << ")\n";

    while (!currentPointer.first) {
        if (reinterpretation->node.isLeaf()) {
            std::cout << "Not Found" << '\n';
            return false;
        }

        std::cout << "It was supposed to be in this position in the block : " << currentPointer.second << '\n';
        unsigned short toSeek = (key < reinterpretation->node.keys[currentPointer.second] ? reinterpretation->node.blockPointers[currentPointer.second] : reinterpretation->node.blockPointers[currentPointer.second + 1]);
        std::cout << "Seeking between " << reinterpretation->node.blockPointers[currentPointer.second] << " and " << reinterpretation->node.blockPointers[currentPointer.second + 1] << '\n';
        std::cout << "New block to search : " << toSeek << "\n\n";

        fseek(indexFile, sizeof(Block_t) * toSeek, SEEK_SET);
        fread(&currentBlock, sizeof(Block_t), 1, indexFile);

        currentPointer = binarySearch(reinterpretation->node.keys, reinterpretation->node.count, key);
    }

    std::cout << "Found at the position " << currentPointer.second << '\n';
    HashFileFactory hashFileFactory;

    FILE* blockFile = fopen("./data.block", "rb+");

    if (blockFile != NULL) {
        rewind(blockFile);
        hashFileFactory.getArticleFromHash(reinterpretation->node.keys[currentPointer.second], article, blockFile);
    }

    return true;
}
