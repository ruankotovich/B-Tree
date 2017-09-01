#pragma once
#include <cstdlib>
#include <iostream>
#include <cmath>
#include "block.hpp"

#define MAX_KEYS 680 // m = 340

struct Node {
    unsigned short count;
    unsigned short countPointers;
    
    unsigned int keys[MAX_KEYS];  // 2m   -> trocar por char[300] para o Título [TROCAR]
    
    unsigned short blockPointers[MAX_KEYS + 1]; // 2m + 1
    
    Node(int order);
    bool isLeaf();
    bool hasRoom();
    int insert(int key); //[TROCAR]
};

union NodeReinterpret {
    Node node;
    char fake[BLOCK_SIZE];
};

class BTree {
private:
    /* Degree, grau. Em outras palavras, o lower-bound, a quantidade mínima de elementos 
    em cada nó (exceto na raíz). */

    Node *root;
    std::pair<bool, std::pair<int, int>> insertRecursive(int key, Node *node, FILE *indexFile);
public:
    void insert(int key, FILE *indexFile);
    // bool getArticle()
    void buildIndex(FILE*);
    short rootOffset;
    BTree();
};

union BTreeHeader {
    short rootOffset;
    char fake[BLOCK_SIZE];
};