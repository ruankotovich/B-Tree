#pragma once
#include <cstdlib>
#include <iostream>
#include <cmath>
#define MAX_KEYS 680 // m = 340

struct Node {
    unsigned short count;
    unsigned char isLeaf;
    unsigned int keys[MAX_KEYS];  // 2m   -> trocar por char[300] para o Título [TROCAR]
    
    unsigned short blockPointers[MAX_KEYS + 1]; // 2m + 1
    
    Node(int order);
};

class BTree {
private:
    /* Degree, grau. Em outras palavras, o lower-bound, a quantidade mínima de elementos 
    em cada nó (exceto na raíz). */
    
    struct BTree_Header{
        short rootIndex;
    } header;

    Node root;
public:
    void insert(int key, FILE *indexFile);
    // bool getArticle()
    void buildIndex(FILE*);
};