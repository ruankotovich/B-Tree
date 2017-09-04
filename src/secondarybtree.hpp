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
#define SECONDARY_KEY_LENGTH 300


struct SecondaryBTreeDataMap {
  char key[SECONDARY_KEY_LENGTH];
  int dataPointer;

  bool operator< (const SecondaryBTreeDataMap& other) const;
  bool operator> (const SecondaryBTreeDataMap& other) const;
  bool operator==(const SecondaryBTreeDataMap& other) const;
  void operator=(const SecondaryBTreeDataMap& other);
};

struct SecondaryBTreeRecursionResponse {
  bool hasBeenSplit;
  SecondaryBTreeDataMap promotedKey;
  int newBlockOffset;
  SecondaryBTreeRecursionResponse(bool);
  SecondaryBTreeRecursionResponse(bool, SecondaryBTreeDataMap&, int);
};

struct SecondaryBTreeNode {
  unsigned short count;
  unsigned short countPointers;
  SecondaryBTreeDataMap keys[SECONDARY_MAX_KEYS]; // 2m   -> trocar por char[SECONDARY_KEY_LENGTH] para o Título [TROCAR]
  int blockPointers[SECONDARY_MAX_KEYS + 1]; // 2m + 1

  SecondaryBTreeNode(int order);
  bool isLeaf();
  bool hasRoom();
  int insert(SecondaryBTreeDataMap&); //[TROCAR]
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
  int offset;
  AbstractBlock_t block;
};

class SecondaryBTree {
private:
  SecondaryBTreeRecursionResponse SUCCESSFUL_TREE_INSERTION;
  SecondaryBTreeNodeReinterpret* root;
  SecondaryBTreeRecursionResponse insertRecursive(SecondaryBTreeDataMap&, SecondaryBTreeNodeReinterpret* node, int offset, FILE* indexFile);

public:
  void insert(SecondaryBTreeDataMap&, FILE* indexFile);
  std::pair<bool, int> getArticle(SecondaryBTreeDataMap& key, Article_t*, FILE*);
  void buildIndex(FILE*);
  void readRoot(FILE *indexFile);
  int rootOffset;
  SecondaryBTree();
};
