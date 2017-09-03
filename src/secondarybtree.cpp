#include "secondarybtree.hpp"
SecondaryBTreeRecursionResponse::SecondaryBTreeRecursionResponse(bool _hasBeenSplit, SecondaryBTreeDataMap& _promotedKey, unsigned short _newBlockOffset)
: hasBeenSplit(_hasBeenSplit)
, newBlockOffset(_newBlockOffset)
{
  promotedKey = _promotedKey;
}

SecondaryBTreeRecursionResponse::SecondaryBTreeRecursionResponse(bool _hasBeenSplit)
: hasBeenSplit(_hasBeenSplit)
{
}

SecondaryBTreeNode::SecondaryBTreeNode(int order)
{
  count = 0;
  countPointers = 0;
}

void SecondaryBTreeDataMap::operator=(const SecondaryBTreeDataMap& other)
{
  // std::memcpy(this->key, other.key, SECONDARY_KEY_LENGTH);
  this->key = other.key;
  this->dataPointer = other.dataPointer;
}

bool SecondaryBTreeDataMap::operator==(const SecondaryBTreeDataMap& other) const
{
  return this->key ==  other.key;
}

bool SecondaryBTreeDataMap::operator<(const SecondaryBTreeDataMap& other) const
{
  return this->key< other.key;
}

bool SecondaryBTreeDataMap::operator>(const SecondaryBTreeDataMap& other) const
{
  return this->key > other.key;
}

bool SecondaryBTreeNode::isLeaf()
{
  return countPointers == 0;
}

bool SecondaryBTreeNode::hasRoom()
{
  return count < SECONDARY_MAX_KEYS;
}

/**
* Insert a key in a node and returns the index where the insertion was made.
*/
unsigned short SecondaryBTreeNode::insert(SecondaryBTreeDataMap& key)
{ // [TROCAR]

  unsigned short i;

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

SecondaryBTree::SecondaryBTree()
: SUCCESSFUL_TREE_INSERTION(false)
{
  this->root = new SecondaryBTreeNodeReinterpret();
  rootOffset = 1;
}

void SecondaryBTree::buildIndex(FILE* indexFile)
{
  rewind(indexFile);
  fwrite(&rootOffset, sizeof(AbstractBlock_t), 1, indexFile);

  fseek(indexFile, sizeof(AbstractBlock_t), SEEK_SET);
  fwrite(root, sizeof(AbstractBlock_t), 1, indexFile);
}

void inline writeBackNode(SecondaryBTreeNode* node, int offset, FILE* indexFile)
{
  fseek(indexFile, sizeof(AbstractBlock_t) * offset, SEEK_SET);
  fwrite(node, sizeof(AbstractBlock_t), 1, indexFile);
}

void SecondaryBTree::readRoot(FILE* indexFile)
{
  rewind(indexFile);
  fread(&rootOffset, sizeof(unsigned short), 1, indexFile);

  SecondaryBTreeNodeReinterpret* reinterpretation = (SecondaryBTreeNodeReinterpret*)this->root;

  fseek(indexFile, sizeof(AbstractBlock_t) * rootOffset, SEEK_SET);
  fread(&reinterpretation->block, sizeof(AbstractBlock_t), 1, indexFile);
}

char inline relativeKeyPosition(SecondaryBTreeDataMap& key, SecondaryBTreeDataMap& leftMiddle, SecondaryBTreeDataMap& rightMiddle)
{
  if (key < leftMiddle) {
    return RELATIVE_LEFT;
  } else if (key > rightMiddle) {
    return RELATIVE_RIGHT;
  }

  return RELATIVE_MIDDLE;
}

int inline writeNewNode(SecondaryBTreeNode* node, FILE* indexFile)
{
  fseek(indexFile, 0, SEEK_END);

  fwrite(node, sizeof(AbstractBlock_t), 1, indexFile);
  return (ftell(indexFile) / sizeof(AbstractBlock_t)) - 1;
}

SecondaryBTreeRecursionResponse SecondaryBTree::insertRecursive(SecondaryBTreeDataMap& key, SecondaryBTreeNodeReinterpret* nodeReinterpretation, int offset, FILE* indexFile)
{
  for (unsigned short i = 0; i < nodeReinterpretation->node.count; ++i) {
    if (nodeReinterpretation->node.keys[i] == key) return SUCCESSFUL_TREE_INSERTION;
  }

  if (nodeReinterpretation->node.isLeaf()) {

    if (nodeReinterpretation->node.hasRoom()) {
      nodeReinterpretation->node.insert(key);
      writeBackNode(&nodeReinterpretation->node, offset, indexFile);
      return SUCCESSFUL_TREE_INSERTION;
    }

    SecondaryBTreeNode* splitLeaf = new SecondaryBTreeNode(SECONDARY_MAX_KEYS);
    SecondaryBTreeDataMap promoted;

    // elege o promoted e manipula os vetores resultantes da operação do splitLeaf.
    SecondaryBTreeDataMap leftMiddleKey = nodeReinterpretation->node.keys[SECONDARY_LEFT_MIDDLE_KEY];
    SecondaryBTreeDataMap rightMiddleKey = nodeReinterpretation->node.keys[SECONDARY_RIGHT_MIDDLE_KEY];

    splitLeaf->count = nodeReinterpretation->node.count = SECONDARY_HALF_MAX_KEYS;

    switch (relativeKeyPosition(key, leftMiddleKey, rightMiddleKey)) {
      case RELATIVE_LEFT: {
        promoted = leftMiddleKey;
        --nodeReinterpretation->node.count;

        nodeReinterpretation->node.insert(key);

        for (int i = SECONDARY_HALF_MAX_KEYS, j = 0; i < SECONDARY_MAX_KEYS; ++i, ++j) {
          splitLeaf->keys[j] = nodeReinterpretation->node.keys[i];
        }
      } // não esquecer de manipular os blockPointes para nós não-folha
      break;

      case RELATIVE_RIGHT: {
        promoted = rightMiddleKey;
        --splitLeaf->count;

        for (int i = SECONDARY_RIGHT_MIDDLE_KEY + 1, j = 0; i < SECONDARY_MAX_KEYS; ++i, ++j) {
          splitLeaf->keys[j] = nodeReinterpretation->node.keys[i];
        } // não esquecer de manipular os blockPointes para nós não-folha

        splitLeaf->insert(key);
      } break;

      case RELATIVE_MIDDLE: {
        promoted = key;

        for (int i = SECONDARY_HALF_MAX_KEYS, j = 0; i < SECONDARY_MAX_KEYS; ++i, ++j) {
          splitLeaf->keys[j] = nodeReinterpretation->node.keys[i];
        }
      } // não esquecer de manipular os blockPointes para nós não-folha

      break;
    }

    writeBackNode(&nodeReinterpretation->node, offset, indexFile);
    int offset = writeNewNode(splitLeaf, indexFile);

    delete splitLeaf; // deleta da memória principal pois já foi salvo no disco

    // return { true, { promoted, offset } };
    return SecondaryBTreeRecursionResponse(true, promoted, offset);
  }

  int result = upperBound(nodeReinterpretation->node.keys, nodeReinterpretation->node.count, key); // [TROCAR]
  //auto resultPair = u(nodeReinterpretation->node.keys, nodeReinterpretation->node.count, key);
  unsigned short childNodeOffset;

  if (result >= nodeReinterpretation->node.count) {
    childNodeOffset = (unsigned short)result;
    result = nodeReinterpretation->node.count - 1;
  }

  childNodeOffset = ((key < nodeReinterpretation->node.keys[result]) ? nodeReinterpretation->node.blockPointers[result] : nodeReinterpretation->node.blockPointers[result + 1]);

  SecondaryBTreeNodeReinterpret* retrieveNode = new SecondaryBTreeNodeReinterpret();
  fseek(indexFile, sizeof(AbstractBlock_t) * childNodeOffset, SEEK_SET);
  fread(&retrieveNode->block, sizeof(AbstractBlock_t), 1, indexFile);

  auto resultRecursion = insertRecursive(key, retrieveNode, childNodeOffset, indexFile);
  delete retrieveNode;

  // WARNING: FALTA RESOLVER A QUESTÃO DE DELEÇÃO DOS PONTEIROS PARA NODE NAS CHAMADAS RECURSIVAS

  if (resultRecursion.hasBeenSplit) { // caso em que veio um valor promovido e um blockPointer
    //caso 1 - tem espaço para inserir o promovido
    if (nodeReinterpretation->node.hasRoom()) {
      //o + 1 é para não realizar essa soma em toda iteração do for logo abaixo
      unsigned short rightIndexInserted = nodeReinterpretation->node.insert(resultRecursion.promotedKey) + 1;

      for (unsigned short i = nodeReinterpretation->node.countPointers; i > rightIndexInserted; --i) {
        nodeReinterpretation->node.blockPointers[i] = nodeReinterpretation->node.blockPointers[i - 1];
      }

      nodeReinterpretation->node.blockPointers[rightIndexInserted] = resultRecursion.newBlockOffset;
      ++nodeReinterpretation->node.countPointers;

      writeBackNode(&nodeReinterpretation->node, offset, indexFile);
    } else { // caso 2 - não tem espaço para inserir o promovido -> fazer o split com remanejamento de chaves
      SecondaryBTreeNodeReinterpret* split = new SecondaryBTreeNodeReinterpret();
      SecondaryBTreeDataMap promoted;

      // elege o promoted e manipula os vetores resultantes da operação do split.
      SecondaryBTreeDataMap leftMiddleKey = nodeReinterpretation->node.keys[SECONDARY_LEFT_MIDDLE_KEY];
      SecondaryBTreeDataMap rightMiddleKey = nodeReinterpretation->node.keys[SECONDARY_RIGHT_MIDDLE_KEY];

      split->node.count = nodeReinterpretation->node.count = SECONDARY_HALF_MAX_KEYS; // remoção lógica exatamente na metade

      //como está cheio, vai metade dos elementos para cada bloco, contnado com o split.
      // se vai metade, haverá metade + 1 ponteiros para bloco preenchidos.
      split->node.countPointers = nodeReinterpretation->node.countPointers = SECONDARY_HALF_MAX_KEYS + 1;

      switch (relativeKeyPosition(resultRecursion.promotedKey, leftMiddleKey, rightMiddleKey)) {
        case RELATIVE_LEFT: {
          promoted = leftMiddleKey;

          --nodeReinterpretation->node.count;

          // índice do ponteiro mais à direita do vetor blockPointers
          unsigned short greaterNodeBlockPointer = nodeReinterpretation->node.blockPointers[nodeReinterpretation->node.countPointers - 1]; // a subtração tem a ver com índice

          //índice em que foi inserido o promovido no nó já existente
          unsigned short rightIndexInserted = nodeReinterpretation->node.insert(resultRecursion.promotedKey) + 1;

          //remanejar os blockPoints
          for (unsigned short i = nodeReinterpretation->node.countPointers - 1; i > rightIndexInserted; --i) {
            nodeReinterpretation->node.blockPointers[i] = nodeReinterpretation->node.blockPointers[i - 1];
          }

          nodeReinterpretation->node.blockPointers[rightIndexInserted] = resultRecursion.newBlockOffset;

          for (int i = SECONDARY_HALF_MAX_KEYS, j = 0; i < SECONDARY_MAX_KEYS; ++i, ++j) {
            split->node.keys[j] = nodeReinterpretation->node.keys[i];
            split->node.blockPointers[j + 1] = nodeReinterpretation->node.blockPointers[i + 1];
          } // não esquecer de manipular os blockPointes para nós não-folha

          split->node.blockPointers[0] = greaterNodeBlockPointer;
        } break;

        case RELATIVE_RIGHT: {
          promoted = rightMiddleKey;
          --split->node.count;
          // não é preciso modificar o countPointers nem o count do node aqui porque eles já foram atribuidos ali em cima,
          // então a remoção lógica já foi feita

          for (int i = SECONDARY_RIGHT_MIDDLE_KEY + 1, j = 0; i < SECONDARY_MAX_KEYS; ++i, ++j) {
            split->node.keys[j] = nodeReinterpretation->node.keys[i];
            split->node.blockPointers[j] = nodeReinterpretation->node.blockPointers[i];
          } // não esquecer de manipular os blockPointes para nós não-folha/

          split->node.blockPointers[SECONDARY_HALF_MAX_KEYS - 1] = nodeReinterpretation->node.blockPointers[SECONDARY_MAX_KEYS];
          unsigned short rightIndexInserted = split->node.insert(resultRecursion.promotedKey) + 1;

          //remanejar os blockPoints
          for (unsigned short i = split->node.countPointers - 1; i > rightIndexInserted; --i) {
            split->node.blockPointers[i] = split->node.blockPointers[i - 1];
          }

          split->node.blockPointers[rightIndexInserted] = resultRecursion.newBlockOffset;
        } break;

        case RELATIVE_MIDDLE: {
          promoted = resultRecursion.promotedKey;

          for (int i = SECONDARY_HALF_MAX_KEYS, j = 0; i < SECONDARY_MAX_KEYS; ++i, ++j) {
            split->node.keys[j] = nodeReinterpretation->node.keys[i];
            split->node.blockPointers[j + 1] = nodeReinterpretation->node.blockPointers[i + 1];
          } // não esquecer de manipular os blockPointes para nós não-folha
          split->node.blockPointers[0] = resultRecursion.newBlockOffset;
        } break;
      }

      writeBackNode(&nodeReinterpretation->node, offset, indexFile);
      int offset = writeNewNode(&split->node, indexFile);
      delete split; // deleta da memória principal pois já foi salvo no disco
      return SecondaryBTreeRecursionResponse(true, promoted, offset);
    }
  }

  return SUCCESSFUL_TREE_INSERTION;
  // return SecondaryBTreeRecursionResponse(false, 0, 0);
  // return { false, { 0, 0 } };
}

void SecondaryBTree::insert(SecondaryBTreeDataMap& key, FILE* indexFile)
{ // [TROCAR]
  auto result = insertRecursive(key, root, rootOffset, indexFile);

  if (result.hasBeenSplit) { // se tiver um promovido vindo de um split abaixo
    SecondaryBTreeNodeReinterpret* newRoot = new SecondaryBTreeNodeReinterpret();
    newRoot->node.insert(result.promotedKey); // insere a key promovida do nível abaixo
    newRoot->node.blockPointers[0] = rootOffset; //apontador esquerdo -> antiga raíz

    // considerando que o block splittado já foi salvo no arquivo na função insertRecursive
    newRoot->node.blockPointers[1] = result.newBlockOffset;
    newRoot->node.countPointers = 2;

    // salvar o newRoot no arquivo da SecondaryBTree
    rootOffset = writeNewNode(&newRoot->node, indexFile);

    // atualizar o header
    fseek(indexFile, 0, SEEK_SET);

    fwrite(&rootOffset, sizeof(AbstractBlock_t), 1, indexFile);

    delete (root);
    root = newRoot;

    fseek(indexFile, 0, SEEK_END);
  }
}

std::pair<bool, int> SecondaryBTree::getArticle(SecondaryBTreeDataMap& key, Article_t* article, FILE* indexFile)
{

  SecondaryBTreeNodeReinterpret* reinterpretation = (SecondaryBTreeNodeReinterpret*)this->root;

  if (reinterpretation->node.count <= 0) {
    //std::cout << "Not Found" << '\n';
    return { false, 0 };
  }

  auto currentPointer = binarySearch(reinterpretation->node.keys, reinterpretation->node.count, key);
  // std::cout << "Searching for key " << key << " at the root(" << this->rootOffset << ")\n";

  int countTraversed = 1;

  while (!currentPointer.first) {
    if (reinterpretation->node.isLeaf()) {
      //std::cout << "Not Found" << '\n';
      return { false, 0 };
    }
    //std::cout << "It was supposed to be in this position in the block : " << currentPointer.second << '\n';
    unsigned short toSeek = currentPointer.second >= reinterpretation->node.count ? reinterpretation->node.blockPointers[reinterpretation->node.count] : (key < reinterpretation->node.keys[currentPointer.second] ? reinterpretation->node.blockPointers[currentPointer.second] : reinterpretation->node.blockPointers[currentPointer.second + 1]);
    // std::cout << "Seeking between " << reinterpretation->node.blockPointers[currentPointer.second] << " and " << reinterpretation->node.blockPointers[currentPointer.second + 1] << '\n';
    //std::cout << "New block to search : " << toSeek << "\n\n";

    fseek(indexFile, sizeof(AbstractBlock_t) * toSeek, SEEK_SET);
    fread(&reinterpretation->block, sizeof(AbstractBlock_t), 1, indexFile);

    currentPointer = binarySearch(reinterpretation->node.keys, reinterpretation->node.count, key);
    ++countTraversed;
  }

  //std::cout << "Found at the position " << currentPointer.second << '\n';

  FILE* blockFile = fopen("./data.block", "rb+");
  if (blockFile != NULL) {
    rewind(blockFile);
    getArticleFromHash(reinterpretation->node.keys[currentPointer.second].dataPointer, article, blockFile);
  }

  return { true, countTraversed };
}
