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

BTree::BTree() {
    rootOffset = 1;
}

void BTree::buildIndex(FILE* indexFile)
{
    fwrite(&rootOffset, sizeof(BTreeHeader), 1, indexFile);

    root = new Node(MAX_KEYS);
    fwrite(root, sizeof(Block_t), 1, indexFile);
}

std::pair<bool, std::pair<int, int>> BTree::insertRecursive(int key, Node* node, FILE* indexFile)
{
    
    
}

void BTree::insert(int key, FILE* indexFile)
{ // [TROCAR]
    auto result = insertRecursive(key, root, indexFile);

    if (result.first) { // se tiver um promovido vindo de um split abaixo
        Node *newRoot = new Node(MAX_KEYS);
        newRoot->insert(result.second.first); // insere a key promovida do nível abaixo
        newRoot->blockPointers[0] = rootOffset; //apontador esquerdo -> antiga raíz

         // considerando que o block splittado já foi salvo no arquivo na função insertRecursive
        newRoot->blockPointers[1] = result.second.second;
        newRoot->countPointers = 2;

        // salvar o newRoot no arquivo da BTree
        fwrite(newRoot, sizeof(NodeReinterpret), 1, indexFile);
        rootOffset = (ftell(indexFile) / sizeof(Block_t)) - 1;

        // atualizar o header
        fseek(indexFile, 0, SEEK_SET);

        fwrite(&rootOffset, sizeof(Block_t), 1, indexFile);

        delete(root);
        root = newRoot;

        fseek(indexFile, 0, SEEK_END);
    }
}