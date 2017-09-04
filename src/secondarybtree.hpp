#pragma once
#include "arrayoperations.hpp"
#include "block.hpp"
#include "hashfinder.hpp"
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>

#define SECONDARY_MAX_KEYS 12 //!< Max keys count
#define SECONDARY_RIGHT_MIDDLE_KEY (SECONDARY_MAX_KEYS >> 1) //!< The position of the middle key
#define SECONDARY_LEFT_MIDDLE_KEY (SECONDARY_RIGHT_MIDDLE_KEY - 1) //!< The block pointers count
#define SECONDARY_HALF_MAX_KEYS SECONDARY_RIGHT_MIDDLE_KEY //!< The half count of the maxium keys count
#define SECONDARY_KEY_LENGTH 300 //!< The size of the key

/**
* A struct used for abstract the keymap and the data block
*/
struct SecondaryBTreeDataMap {
  char key[SECONDARY_KEY_LENGTH];
  int dataPointer;

  bool operator< (const SecondaryBTreeDataMap& other) const;
  bool operator> (const SecondaryBTreeDataMap& other) const;
  bool operator==(const SecondaryBTreeDataMap& other) const;
  void operator=(const SecondaryBTreeDataMap& other);
};

/**
* A struct used for save the response of the recursive insertion method
*/
struct SecondaryBTreeRecursionResponse {
  bool hasBeenSplit;
  SecondaryBTreeDataMap promotedKey;
  int newBlockOffset;
  SecondaryBTreeRecursionResponse(bool);
  SecondaryBTreeRecursionResponse(bool, SecondaryBTreeDataMap&, int);
};

/**
* A struct used for abstract the concept of node
*/
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

/**
* An union used to represent an interpretation of the node regardins blocks
*/
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

/**
* An union used to represent an interpretation of the header regardins blocks
*/
union SecondaryBTreeHeaderReinterpret{
  int offset;
  AbstractBlock_t block;
};

/**
* A class abstracting the btree
*/
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
