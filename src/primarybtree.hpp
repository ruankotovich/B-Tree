#pragma once
#include "arrayoperations.hpp"
#include "block.hpp"
#include "hashfinder.hpp"
#include <cmath>
#include <cstdlib>
#include <iostream>

#define PRIMARY_MAX_KEYS 680 //!< Max keys count
#define PRIMARY_RIGHT_MIDDLE_KEY (PRIMARY_MAX_KEYS >> 1) //!< The position of the middle key
#define PRIMARY_LEFT_MIDDLE_KEY (PRIMARY_RIGHT_MIDDLE_KEY - 1) //!< The block pointers count
#define PRIMARY_HALF_MAX_KEYS PRIMARY_RIGHT_MIDDLE_KEY //!< The half count of the maxium keys count

/**
* A struct used for save the response of the recursive insertion method
*/
struct PrimaryBTreeRecursionResponse {
  bool hasBeenSplit;
  int promotedKey;
  unsigned short newBlockOffset;
  PrimaryBTreeRecursionResponse(bool, int, unsigned short);
};

/**
* A struct used for abstract the concept of node
*/
struct PrimaryBTreeNode {
  unsigned short count;
  unsigned short countPointers;
  int keys[PRIMARY_MAX_KEYS]; // 2m   -> trocar por char[300] para o Título [TROCAR]
  unsigned short blockPointers[PRIMARY_MAX_KEYS + 1]; // 2m + 1

  PrimaryBTreeNode(int order);
  bool isLeaf();
  bool hasRoom();
  unsigned short insert(int key); //[TROCAR]
};

/**
* An union used to represent an interpretation of the node regardins blocks
*/
union PrimaryBTreeNodeReinterpret {
  PrimaryBTreeNode node;
  AbstractBlock_t block;
  PrimaryBTreeNodeReinterpret()
  : node(PRIMARY_MAX_KEYS)
  {
  }

  PrimaryBTreeNodeReinterpret(PrimaryBTreeNodeReinterpret* abs) : node(PRIMARY_MAX_KEYS)
  {
    std::memcpy(&this->block, &abs->block, sizeof(AbstractBlock_t));
  }
};

/**
* An union used to represent an interpretation of the header regardins blocks
*/
union PrimaryBTreeHeaderReinterpret{
  unsigned short offset;
  AbstractBlock_t block;
};

/**
* A class abstracting the btree
*/
class PrimaryBTree {
private:
  PrimaryBTreeRecursionResponse SUCCESSFUL_TREE_INSERTION;
  PrimaryBTreeNodeReinterpret* root;
  PrimaryBTreeRecursionResponse insertRecursive(int key, PrimaryBTreeNodeReinterpret* node, int offset, FILE* indexFile);
  
public:
  void insert(int key, FILE* indexFile);
  std::pair<bool, int> getArticle(int key, Article_t*, FILE*);
  void buildIndex(FILE*);
  void readRoot(FILE *indexFile);
  unsigned short rootOffset;
  PrimaryBTree();
};
