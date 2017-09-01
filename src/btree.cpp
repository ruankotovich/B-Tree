#include "btree.hpp"

Node::Node(int order)
{
    count = 0;
    countPointers = 0;

    int i;

    for (i = 0; i < order; i++) {
        //std::cout << i << std::endl;
        blockPointers[i] = -1; // -1 não faz sentido como posição do arquivo, então é como um "Nullptr"
    }
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
int Node::insert(int key)
{ // [TROCAR]

    int i;

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
{
    rootOffset = 1;
}

void BTree::buildIndex(FILE* indexFile)
{
    fwrite(&rootOffset, sizeof(BTreeHeader), 1, indexFile);

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

int inline writeNewNode(Node *node,FILE *indexFile) {
    fseek(indexFile, 0, SEEK_END);
    
    fwrite(node, sizeof(NodeReinterpret), 1, indexFile);
    return (ftell(indexFile) / sizeof(Block_t)) - 1;
}

std::pair<bool, std::pair<int, int>> BTree::insertRecursive(int key, Node* node, int offset, FILE* indexFile)
{
    if (node->isLeaf()) {
        if (node->hasRoom()) {
            node->insert(key);
            writeBackNode(node, offset, indexFile);

            return { false, { 0, 0 } };
        }

        Node *split = new Node(MAX_KEYS);
        int promoted;

        // elege o promoted e manipula os vetores resultantes da operação do split.
        int leftMiddleKey = node->keys[LEFT_MIDDLE_KEY];
        int rightMiddleKey = node->keys[RIGHT_MIDDLE_KEY];
        
        switch (relativeKeyPosition(key, leftMiddleKey, rightMiddleKey)) {
            case RELATIVE_LEFT:
                promoted = leftMiddleKey;
                split->count = node->count = HALF_MAX_KEYS;
                --node->count;
                
                node->insert(key);

                for (int i = HALF_MAX_KEYS, j = 0; i < MAX_KEYS; ++i, ++j) {
                    split->keys[j] = node->keys[i];
                } // não esquecer de manipular os blockPointes para nós não-folha
            break;

            case RELATIVE_RIGHT:
                promoted = rightMiddleKey;

                split->count = node->count = HALF_MAX_KEYS;
                --split->count;

                for (int i = RIGHT_MIDDLE_KEY + 1, j = 0; i < MAX_KEYS; ++i, ++j) {
                    split->keys[j] = node->keys[i];
                } // não esquecer de manipular os blockPointes para nós não-folha
            break;

            case RELATIVE_MIDDLE:
                promoted = key;
                split->count = node->count = HALF_MAX_KEYS;

                for (int i = HALF_MAX_KEYS, j = 0; i < MAX_KEYS; ++i, ++j) {
                    split->keys[j] = node->keys[i];
                } // não esquecer de manipular os blockPointes para nós não-folha

            break;
        }

        int offset = writeNewNode(split, indexFile);

        return {true, {promoted, offset}};
    }
}

void BTree::insert(int key, FILE* indexFile)
{ // [TROCAR]
    auto result = insertRecursive(key, root, rootOffset, indexFile);

    if (result.first) { // se tiver um promovido vindo de um split abaixo
        Node* newRoot = new Node(MAX_KEYS);
        newRoot->insert(result.second.first); // insere a key promovida do nível abaixo
        newRoot->blockPointers[0] = rootOffset; //apontador esquerdo -> antiga raíz

        // considerando que o block splittado já foi salvo no arquivo na função insertRecursive
        newRoot->blockPointers[1] = result.second.second;
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