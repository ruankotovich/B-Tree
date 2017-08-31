#include "btree.hpp"

Node::Node(int order) {
    count = 0;
    isLeaf = true;
    
    int i;

    for (i = 0; i < order; i++) {
        std::cout << i << std::endl;
        blockPointers[i] = -1; // -1 não faz sentido como posição do arquivo, então é como um "Nullptr"
    }

    std::cout << std::endl << i;
}

union BTreeHeader {
    BTree btreeHeader;
    char fake[4096];
};

void BTree::buildIndex(FILE* f){
    BTreeHeader *header = (BTreeHeader*) &this->header;
    fwrite(header, sizeof(BTreeHeader), 1, f);
}

void insertInArrayOrdered(int key, int count, unsigned int *v) {
    int i;
    for (i = count; i >= 1; i--) {
        if (key > v[i - 1]) {
            v[i] = key;
            break;
        }
        else {
            v[i] = v[i - 1];
        }
    }
    if (i == 0) {
        v[0] = key;
    }
}

void insertWithoutSplit(int key, Node &node) {
    unsigned int *v = &node.keys[0];

    insertInArrayOrdered(key, node.count, v);
}

void BTree::insert(int key, FILE *indexFile) { // [TROCAR]
    if (this->root.count == MAX_KEYS) {

    }
    else { 
        insertWithoutSplit(key, this->root);
    }
}