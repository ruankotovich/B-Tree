#pragma once
#include "arrayoperations.hpp"
#include "block.hpp"
#include <cmath>
#include <cstdlib>
#include <iostream>
#define RELATIVE_LEFT -1
#define RELATIVE_MIDDLE 0
#define RELATIVE_RIGHT 1

#define MAX_KEYS 680 // m = 340
#define RIGHT_MIDDLE_KEY (MAX_KEYS >> 1)
#define LEFT_MIDDLE_KEY (RIGHT_MIDDLE_KEY - 1)
#define HALF_MAX_KEYS RIGHT_MIDDLE_KEY

struct TreeRecursionResponse {
    bool hasBeenSplit;
    int promotedKey;
    unsigned short newBlockOffset;
    TreeRecursionResponse(bool, int, unsigned short);
};



struct Node {
    unsigned short count;
    unsigned short countPointers;

    unsigned int keys[MAX_KEYS]; // 2m   -> trocar por char[300] para o Título [TROCAR]

    unsigned short blockPointers[MAX_KEYS + 1]; // 2m + 1

    Node(int order);
    bool isLeaf();
    bool hasRoom();
    unsigned short insert(int key); //[TROCAR]
};

union NodeReinterpret {
    Node node;
    char fake[BLOCK_SIZE];
};

class BTree {
private:
    TreeRecursionResponse SUCCESSFUL_TREE_INSERTION;
    
    /* Degree, grau. Em outras palavras, o lower-bound, a quantidade mínima de elementos 
    em cada nó (exceto na raíz). */

    Node* root;
    TreeRecursionResponse insertRecursive(int key, Node* node, int offset, FILE* indexFile);

public:
    void insert(int key, FILE* indexFile);
    // bool getArticle()
    void buildIndex(FILE*);
    short rootOffset;
    BTree();
};

union BTreeHeader {
    short rootOffset;
    char fake[BLOCK_SIZE];
};