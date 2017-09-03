#pragma once
#include "arrayoperations.hpp"
#include "block.hpp"
#include "hashfinder.hpp"
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>

#define SECONDARY_MAX_KEYS 12 // m = 6
#define SECONDARY_RIGHT_MIDDLE_KEY (SECONDARY_MAX_KEYS >> 1)
#define SECONDARY_LEFT_MIDDLE_KEY (SECONDARY_RIGHT_MIDDLE_KEY - 1)
#define SECONDARY_HALF_MAX_KEYS SECONDARY_RIGHT_MIDDLE_KEY

struct SecondaryBTreeRecursionResponse {
  bool hasBeenSplit;
  int promotedKey;
  unsigned short newBlockOffset;
  SecondaryBTreeRecursionResponse(bool, int, unsigned short);
};

struct SecondaryBTreeDataMap {
    char key[300];
    int dataPointer;
    
    bool operator< (const SecondaryBTreeDataMap& other);
};

struct SecondaryBTreeNode {
  unsigned short count;
  unsigned short countPointers;
  unsigned int keys[SECONDARY_MAX_KEYS]; // 2m   -> trocar por char[300] para o Título [TROCAR]
  unsigned short blockPointers[SECONDARY_MAX_KEYS + 1]; // 2m + 1

  SecondaryBTreeNode(int order);
  bool isLeaf();
  bool hasRoom();
  unsigned short insert(int key); //[TROCAR]
};

union SecondaryBTreeNodeReinterpret {
  SecondaryBTreeNode node;
  AbstractBlock_t block;
  SecondaryBTreeNodeReinterpret()
  : node(SECONDARY_MAX_KEYS)
  {
  }

  SecondaryBTreeNodeReinterpret(SecondaryBTreeNodeReinterpret* abs) : node(SECONDARY_MAX_KEYS)
  {
    std::memcpy(&this->block, &abs->block, sizeof(AbstractBlock_t));
  }
};

union SecondaryBTreeHeaderReinterpret{
  unsigned short offset;
  AbstractBlock_t block;
};

class SecondaryBTree {
private:
  SecondaryBTreeRecursionResponse SUCCESSFUL_TREE_INSERTION;
  SecondaryBTreeNodeReinterpret* root;
  SecondaryBTreeRecursionResponse insertRecursive(int key, SecondaryBTreeNodeReinterpret* node, int offset, FILE* indexFile);
  
public:
  void insert(int key, FILE* indexFile);
  std::pair<bool, int> getArticle(int key, Article_t*, FILE*);
  void buildIndex(FILE*);
  void readRoot(FILE *indexFile);
  unsigned short rootOffset;
  SecondaryBTree();
};
