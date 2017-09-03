#pragma once
#include "arrayoperations.hpp"
#include "block.hpp"
#include "hashfinder.hpp"
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

union BTreeNodeReinterpret {
  Node node;
  AbstractBlock_t block;
  BTreeNodeReinterpret()
  : node(MAX_KEYS)
  {
  }
  BTreeNodeReinterpret(BTreeNodeReinterpret* abs)
  {
    std::memcpy(&this->block, &abs->block, sizeof(AbstractBlock_t));
  }
};

union BTreeHeaderReinterpret{
  unsigned short offset;
  AbstractBlock_t block;
};

class BTree {
private:
  TreeRecursionResponse SUCCESSFUL_TREE_INSERTION;
  BTreeNodeReinterpret* root;
  TreeRecursionResponse insertRecursive(int key, BTreeNodeReinterpret* node, int offset, FILE* indexFile);
  
public:
  void insert(int key, FILE* indexFile);
  std::pair<bool, int> getArticle(int key, Article_t*, FILE*);
  void buildIndex(FILE*);
  void readRoot(FILE *indexFile);
  unsigned short rootOffset;
  BTree();
};
