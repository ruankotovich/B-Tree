# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`define `[`RELATIVE_LEFT`](#arrayoperations_8hpp_1af5eb35cf6918de189bf2bec7dcc3ea7a)            | An position relative to the left.
`define `[`RELATIVE_MIDDLE`](#arrayoperations_8hpp_1aebd1980c52109a8b2d940c766df2ce68)            | An position relative to the middle.
`define `[`RELATIVE_RIGHT`](#arrayoperations_8hpp_1ad1096431f7752dc4df2ee307b92ccfaf)            | An position relative to the right.
`define `[`FIELD_TITLE_MAX_SIZE`](#article_8hpp_1a7f0fb854ad1e5c749aa14072096f422b)            | Max size of the article title.
`define `[`FIELD_AUTHORS_MAX_SIZE`](#article_8hpp_1a4efec02e356c0aea3b68d038fcae54d4)            | Max size of the article authors' names.
`define `[`FIELD_DATE_MAX_SIZE`](#article_8hpp_1afbed943af9c72a768f5df31dcc5adff0)            | Max size of the article date.
`define `[`FIELD_SNIPPET_MAX_SIZE`](#article_8hpp_1a4bda691dffbd5477de0ed57a762038fd)            | Max size of the article snippet.
`define `[`BLOCK_SIZE`](#block_8hpp_1ad51ded0bbd705f02f73fc60c0b721ced)            | Preset block size.
`define `[`RECORD_HEADER_SIZE`](#block_8hpp_1a4c5a6c66027c91ec2d616914b4ea5641)            | Preset record header size.
`define `[`RECORD_TAIL_SIZE`](#block_8hpp_1a2706eb743623c5740e72b42cba2e76a5)            | Preset record header size.
`define `[`RECORD_AREA_SIZE`](#block_8hpp_1a05dbf893ffc04a18c4434173238393ab)            | Preset record area size, containing the data.
`define `[`DATA_LOCATION`](#block_8hpp_1a12fdc42053ff045f379c23c3fc72cba2)            | 
`define `[`TAIL_LOCATION`](#block_8hpp_1ac14e50c8e3667d2e4d64aa5398544478)            | Preset tail location.
`define `[`VERIFICATION_MASK`](#block_8hpp_1aea1b41efd249efe8af8a1ea4a2f9b80c)            | The mask used for validation.
`define `[`R_NOTHING`](#iohandler_8cpp_1ae39a3fd7e93fd4f14bca6137f5bfff35)            | The two characters are nothing in special.
`define `[`R_SOR`](#iohandler_8cpp_1a9caa5949b270f7611fad0e56d8ee804f)            | The two characters means START OF RECORD.
`define `[`R_EOC`](#iohandler_8cpp_1ae7aa42681447f2e2141614715ab21b5d)            | The two characters means END OF RECORD.
`define `[`R_SON`](#iohandler_8cpp_1aaf615c5e27cd1ce437b93be9babf322d)            | The two characters means START OF NULL.
`define `[`IOHANDLER_READY`](#iohandler_8hpp_1aeff02e9ef62c3d8e61d2b482ba778da0)            | READY state of the buffer reading.
`define `[`IOHANDLER_SLEEPING`](#iohandler_8hpp_1a69953bf0f9d56283428b4dc01a30ed54)            | SLEEPING state of the buffer reading.
`define `[`IOHANDLER_END`](#iohandler_8hpp_1a3f07bcdebff5e53f22463cefa26431b9)            | END state of the buffer reading.
`define `[`IOHANDLER_READ_BUFFER_SIZE`](#iohandler_8hpp_1afa706a09fe5c06b69ca8716a05ed480c)            | [IOHandler](#classIOHandler) reading buffer size (block size)
`define `[`PRIMARY_MAX_KEYS`](#primarybtree_8hpp_1aaf583a52d4e5e5609cb5ccbd55a1e9e0)            | Max keys count.
`define `[`PRIMARY_RIGHT_MIDDLE_KEY`](#primarybtree_8hpp_1aeca77294b113c075568f43f60babab1a)            | The position of the middle key.
`define `[`PRIMARY_LEFT_MIDDLE_KEY`](#primarybtree_8hpp_1a233158aca68f85eeebafab607b1d06ab)            | The block pointers count.
`define `[`PRIMARY_HALF_MAX_KEYS`](#primarybtree_8hpp_1a2bd892fc9d430d278b24cd6d09f2a0ab)            | The half count of the maxium keys count.
`define `[`SECONDARY_MAX_KEYS`](#secondarybtree_8hpp_1a074218b45ee1200b4d38f0ac4aa3b6db)            | Max keys count.
`define `[`SECONDARY_RIGHT_MIDDLE_KEY`](#secondarybtree_8hpp_1a34437bbc3827f8631474bc10ca48befe)            | The position of the middle key.
`define `[`SECONDARY_LEFT_MIDDLE_KEY`](#secondarybtree_8hpp_1a0631f54edc0615b8c1572e1fc85e65f8)            | The block pointers count.
`define `[`SECONDARY_HALF_MAX_KEYS`](#secondarybtree_8hpp_1a32c0742bdfc7df9b32e5a17ba96579e4)            | The half count of the maxium keys count.
`define `[`SECONDARY_KEY_LENGTH`](#secondarybtree_8hpp_1a928e198dfa983cdb30ab5275c9e52fa9)            | The size of the key.
`define `[`BYTE`](#typessize_8hpp_1aec93e83855ac17c3c25c55c37ca186dd)            | Binding for unsigned char.
`define `[`BYTE_BITS`](#typessize_8hpp_1a40094f03df908fa568fd08bc4b87820a)            | Byte size in bits.
`define `[`SHORT_SIZE`](#typessize_8hpp_1adeb5281b5f526ce88376cb4b4b36572e)            | Short size in bytes.
`define `[`INT_SIZE`](#typessize_8hpp_1a3ac36dd0f02f263e5966ac1d1ecbd1bd)            | Int size in bytes.
`define `[`LONG_SIZE`](#typessize_8hpp_1aff6ef0fbcfed01f51caa8ed5592731b8)            | Long size in bytes.
`define `[`BYTE_SIZE`](#typessize_8hpp_1a86fd4404b140711fdb77326609c0f393)            | Byte size in bytes (?)
`public template<typename T,typename K>`  <br/>`inline static int `[`upperBound`](#arrayoperations_8hpp_1ad54d60786745ca4f61fb0c0762cbeae9)`(T * array,int length,K value)`            | Perform a binary search on the array  : receive na array, a length and a value  : a pair, the first paramether regards if the search has found the value, false if it hasn't been found; the second paramether regards the index in the array Perform a upper_bound search on the array  : receive na array, a length and a value  : a integer showing where the value must be placed
`public template<typename T,typename K>`  <br/>`inline static int `[`lowerBound`](#arrayoperations_8hpp_1a4ba2c3c9d0fc30601350d4088b332833)`(T * array,int length,K value)`            | Perform a lower_bound search on the array  : receive na array, a length and a value  : a integer showing where the value must be placed
`public template<typename T,typename K>`  <br/>`inline static std::pair< bool, int > `[`binarySearch`](#arrayoperations_8hpp_1a9ba3114e7ba13b7d131394afce080c39)`(T * array,int length,K value)`            | Retrieves and return the index where the value must be placed
`public template<typename T,typename K>`  <br/>`inline static std::pair< bool, int > `[`secondaryBinarySearch`](#arrayoperations_8hpp_1a6a6e7d58ec67b844a8b5151c0f836262)`(T * array,int length,K value)`            | Retrieves and return the index where the value must be placed
`public template<typename T>`  <br/>`inline static std::pair< bool, unsigned short > `[`orderedInsert`](#arrayoperations_8hpp_1a520e0a69400a815341a0ff7ba2231930)`(T * array,unsigned short & length,T & value)`            | Perform a ordered insert  : receive an array, a length and a value  : void
`public void `[`printAll`](#debug_8cpp_1a2df98dd613396749426b2570a1ab1ec8)`(`[`Block_t`](#structBlock__t)` & block,FILE * indexFile,`[`BlockDerreference`](#unionBlockDerreference)` * derreference)`            | 
`public int `[`main`](#debug_8cpp_1ae66f6b31b5ad750f1fe042a706a4e3d4)`()`            | 
`public int `[`main`](#findrec_8cpp_1a0ddf1224851353fc92bfbff6f499fa97)`(int argc,char * argv)`            | 
`public bool `[`getArticleFromHash`](#hashfinder_8cpp_1a363b91b45181a1757f9b04b2f5e71f8c)`(int id,`[`Article_t`](#structArticle__t)` * article,FILE * toRead)`            | Retrieves and return an article from the file using the id
`public bool `[`getArticleFromHash`](#hashfinder_8hpp_1a363b91b45181a1757f9b04b2f5e71f8c)`(int id,`[`Article_t`](#structArticle__t)` * article,FILE * toRead)`            | Retrieves and return the article from the hash file
`public inline static char `[`after_pairClass`](#iohandler_8cpp_1ab00c0b4a11c5b93553dd251826fe5d28)`(char previous,char current)`            | Second degree verifyer, classify a pair of characters.
`public inline static char `[`pairClass`](#iohandler_8cpp_1a57ad4115185f725aa84cfa399de7875d)`(char previous,char current)`            | First degree verifyer, classify a pair of characters.
`public inline static void `[`readColumn`](#iohandler_8cpp_1a426a6bcaba1b0a41bcc1a658db45e374)`(FILE * file,char * buffer,char previous)`            | Read a column receiving the file, the buffer and the previous char
`public inline static void `[`readNIgnoreColumn`](#iohandler_8cpp_1a13a75b63bc655194bfc89812d3a32ee1)`(FILE * file,char previous)`            | Read a column receiving the file and the previous char, ignoring the buffer
`public inline void `[`writeBackNode`](#primarybtree_8cpp_1ac5f1ce9c3df8bca7c76a6a67ac294ebc)`(`[`PrimaryBTreeNode`](#structPrimaryBTreeNode)` * node,int offset,FILE * indexFile)`            | Write a node back into the file
`public inline char `[`relativeKeyPosition`](#primarybtree_8cpp_1a24ea8b6d11d9590463ce9027133f541d)`(int key,int leftMiddle,int rightMiddle)`            | Returns the relative key position based on the extremes
`public inline int `[`writeNewNode`](#primarybtree_8cpp_1a069a7c3af1dd5be5b6f82b9480ade8c5)`(`[`PrimaryBTreeNode`](#structPrimaryBTreeNode)` * node,FILE * indexFile)`            | Write a new node
`public inline void `[`writeBackNode`](#secondarybtree_8cpp_1a7c07fbcfb989230f5dd8216f5ea02e93)`(`[`SecondaryBTreeNode`](#structSecondaryBTreeNode)` * node,int offset,FILE * indexFile)`            | Write a node back into the file
`public inline char `[`relativeKeyPosition`](#secondarybtree_8cpp_1a2e6c691d155e9caa855195d3b69e77fb)`(`[`SecondaryBTreeDataMap`](#structSecondaryBTreeDataMap)` & key,`[`SecondaryBTreeDataMap`](#structSecondaryBTreeDataMap)` & leftMiddle,`[`SecondaryBTreeDataMap`](#structSecondaryBTreeDataMap)` & rightMiddle)`            | Returns the relative key position based on the extremes
`public inline int `[`writeNewNode`](#secondarybtree_8cpp_1aa0a19488ae38c6d8e39579558a89fd85)`(`[`SecondaryBTreeNode`](#structSecondaryBTreeNode)` * node,FILE * indexFile)`            | Write a new node
`public int `[`main`](#seek1_8cpp_1a3c04138a5bfe5d72780bb7e82a18e627)`(int argc,char ** argv)`            | 
`public int `[`main`](#seek2_8cpp_1a3c04138a5bfe5d72780bb7e82a18e627)`(int argc,char ** argv)`            | 
`public int `[`main`](#upload_8cpp_1a0ddf1224851353fc92bfbff6f499fa97)`(int argc,char * argv)`            | 
`class `[`HashFileFactory`](#classHashFileFactory) | A class to recover raw information in the hashed file
`class `[`IOHandler`](#classIOHandler) | A class to read and handle the CSV file, buffering and handleing the fields
`class `[`PrimaryBTree`](#classPrimaryBTree) | A class abstracting the btree
`class `[`SecondaryBTree`](#classSecondaryBTree) | A class abstracting the btree
`struct `[`AbstractBlock_t`](#structAbstractBlock__t) | 
`struct `[`Article_t`](#structArticle__t) | A struct to embbed and abstract an article and its fields
`struct `[`Block_t`](#structBlock__t) | A struct to embbed and abstract an block, its head, data and tail
`struct `[`Header_Interpretation_t::Header`](#structHeader__Interpretation__t_1_1Header) | Abstract header representation
`struct `[`PrimaryBTreeNode`](#structPrimaryBTreeNode) | A struct used for abstract the concept of node
`struct `[`PrimaryBTreeRecursionResponse`](#structPrimaryBTreeRecursionResponse) | A struct used for save the response of the recursive insertion method
`struct `[`SecondaryBTreeDataMap`](#structSecondaryBTreeDataMap) | A struct used for abstract the keymap and the data block
`struct `[`SecondaryBTreeNode`](#structSecondaryBTreeNode) | A struct used for abstract the concept of node
`struct `[`SecondaryBTreeRecursionResponse`](#structSecondaryBTreeRecursionResponse) | A struct used for save the response of the recursive insertion method
`struct `[`Tail_Interpretation_t::Tail`](#structTail__Interpretation__t_1_1Tail) | Abstract tail representation
`union `[`Article_Interpretation_t`](#unionArticle__Interpretation__t) | An union to abstract the reinterpretation of the article onto the block
`union `[`BlockDerreference`](#unionBlockDerreference) | 
`union `[`Header_Interpretation_t`](#unionHeader__Interpretation__t) | An union to abstract the reinterpretation of the header onto the block
`union `[`PrimaryBTreeHeaderReinterpret`](#unionPrimaryBTreeHeaderReinterpret) | An union used to represent an interpretation of the header regardins blocks
`union `[`PrimaryBTreeNodeReinterpret`](#unionPrimaryBTreeNodeReinterpret) | An union used to represent an interpretation of the node regardins blocks
`union `[`SecondaryBTreeHeaderReinterpret`](#unionSecondaryBTreeHeaderReinterpret) | An union used to represent an interpretation of the header regardins blocks
`union `[`SecondaryBTreeNodeReinterpret`](#unionSecondaryBTreeNodeReinterpret) | An union used to represent an interpretation of the node regardins blocks
`union `[`Tail_Interpretation_t`](#unionTail__Interpretation__t) | An union to abstract the reinterpretation of the tail onto the block

## Members

#### `define `[`RELATIVE_LEFT`](#arrayoperations_8hpp_1af5eb35cf6918de189bf2bec7dcc3ea7a) 

An position relative to the left.

#### `define `[`RELATIVE_MIDDLE`](#arrayoperations_8hpp_1aebd1980c52109a8b2d940c766df2ce68) 

An position relative to the middle.

#### `define `[`RELATIVE_RIGHT`](#arrayoperations_8hpp_1ad1096431f7752dc4df2ee307b92ccfaf) 

An position relative to the right.

#### `define `[`FIELD_TITLE_MAX_SIZE`](#article_8hpp_1a7f0fb854ad1e5c749aa14072096f422b) 

Max size of the article title.

#### `define `[`FIELD_AUTHORS_MAX_SIZE`](#article_8hpp_1a4efec02e356c0aea3b68d038fcae54d4) 

Max size of the article authors' names.

#### `define `[`FIELD_DATE_MAX_SIZE`](#article_8hpp_1afbed943af9c72a768f5df31dcc5adff0) 

Max size of the article date.

#### `define `[`FIELD_SNIPPET_MAX_SIZE`](#article_8hpp_1a4bda691dffbd5477de0ed57a762038fd) 

Max size of the article snippet.

#### `define `[`BLOCK_SIZE`](#block_8hpp_1ad51ded0bbd705f02f73fc60c0b721ced) 

Preset block size.

#### `define `[`RECORD_HEADER_SIZE`](#block_8hpp_1a4c5a6c66027c91ec2d616914b4ea5641) 

Preset record header size.

#### `define `[`RECORD_TAIL_SIZE`](#block_8hpp_1a2706eb743623c5740e72b42cba2e76a5) 

Preset record header size.

#### `define `[`RECORD_AREA_SIZE`](#block_8hpp_1a05dbf893ffc04a18c4434173238393ab) 

Preset record area size, containing the data.

#### `define `[`DATA_LOCATION`](#block_8hpp_1a12fdc42053ff045f379c23c3fc72cba2) 

#### `define `[`TAIL_LOCATION`](#block_8hpp_1ac14e50c8e3667d2e4d64aa5398544478) 

Preset tail location.

#### `define `[`VERIFICATION_MASK`](#block_8hpp_1aea1b41efd249efe8af8a1ea4a2f9b80c) 

The mask used for validation.

#### `define `[`R_NOTHING`](#iohandler_8cpp_1ae39a3fd7e93fd4f14bca6137f5bfff35) 

The two characters are nothing in special.

#### `define `[`R_SOR`](#iohandler_8cpp_1a9caa5949b270f7611fad0e56d8ee804f) 

The two characters means START OF RECORD.

#### `define `[`R_EOC`](#iohandler_8cpp_1ae7aa42681447f2e2141614715ab21b5d) 

The two characters means END OF RECORD.

#### `define `[`R_SON`](#iohandler_8cpp_1aaf615c5e27cd1ce437b93be9babf322d) 

The two characters means START OF NULL.

#### `define `[`IOHANDLER_READY`](#iohandler_8hpp_1aeff02e9ef62c3d8e61d2b482ba778da0) 

READY state of the buffer reading.

#### `define `[`IOHANDLER_SLEEPING`](#iohandler_8hpp_1a69953bf0f9d56283428b4dc01a30ed54) 

SLEEPING state of the buffer reading.

#### `define `[`IOHANDLER_END`](#iohandler_8hpp_1a3f07bcdebff5e53f22463cefa26431b9) 

END state of the buffer reading.

#### `define `[`IOHANDLER_READ_BUFFER_SIZE`](#iohandler_8hpp_1afa706a09fe5c06b69ca8716a05ed480c) 

[IOHandler](#classIOHandler) reading buffer size (block size)

#### `define `[`PRIMARY_MAX_KEYS`](#primarybtree_8hpp_1aaf583a52d4e5e5609cb5ccbd55a1e9e0) 

Max keys count.

#### `define `[`PRIMARY_RIGHT_MIDDLE_KEY`](#primarybtree_8hpp_1aeca77294b113c075568f43f60babab1a) 

The position of the middle key.

#### `define `[`PRIMARY_LEFT_MIDDLE_KEY`](#primarybtree_8hpp_1a233158aca68f85eeebafab607b1d06ab) 

The block pointers count.

#### `define `[`PRIMARY_HALF_MAX_KEYS`](#primarybtree_8hpp_1a2bd892fc9d430d278b24cd6d09f2a0ab) 

The half count of the maxium keys count.

#### `define `[`SECONDARY_MAX_KEYS`](#secondarybtree_8hpp_1a074218b45ee1200b4d38f0ac4aa3b6db) 

Max keys count.

#### `define `[`SECONDARY_RIGHT_MIDDLE_KEY`](#secondarybtree_8hpp_1a34437bbc3827f8631474bc10ca48befe) 

The position of the middle key.

#### `define `[`SECONDARY_LEFT_MIDDLE_KEY`](#secondarybtree_8hpp_1a0631f54edc0615b8c1572e1fc85e65f8) 

The block pointers count.

#### `define `[`SECONDARY_HALF_MAX_KEYS`](#secondarybtree_8hpp_1a32c0742bdfc7df9b32e5a17ba96579e4) 

The half count of the maxium keys count.

#### `define `[`SECONDARY_KEY_LENGTH`](#secondarybtree_8hpp_1a928e198dfa983cdb30ab5275c9e52fa9) 

The size of the key.

#### `define `[`BYTE`](#typessize_8hpp_1aec93e83855ac17c3c25c55c37ca186dd) 

Binding for unsigned char.

#### `define `[`BYTE_BITS`](#typessize_8hpp_1a40094f03df908fa568fd08bc4b87820a) 

Byte size in bits.

#### `define `[`SHORT_SIZE`](#typessize_8hpp_1adeb5281b5f526ce88376cb4b4b36572e) 

Short size in bytes.

#### `define `[`INT_SIZE`](#typessize_8hpp_1a3ac36dd0f02f263e5966ac1d1ecbd1bd) 

Int size in bytes.

#### `define `[`LONG_SIZE`](#typessize_8hpp_1aff6ef0fbcfed01f51caa8ed5592731b8) 

Long size in bytes.

#### `define `[`BYTE_SIZE`](#typessize_8hpp_1a86fd4404b140711fdb77326609c0f393) 

Byte size in bytes (?)

#### `public template<typename T,typename K>`  <br/>`inline static int `[`upperBound`](#arrayoperations_8hpp_1ad54d60786745ca4f61fb0c0762cbeae9)`(T * array,int length,K value)` 

Perform a binary search on the array  : receive na array, a length and a value  : a pair, the first paramether regards if the search has found the value, false if it hasn't been found; the second paramether regards the index in the array Perform a upper_bound search on the array  : receive na array, a length and a value  : a integer showing where the value must be placed

#### `public template<typename T,typename K>`  <br/>`inline static int `[`lowerBound`](#arrayoperations_8hpp_1a4ba2c3c9d0fc30601350d4088b332833)`(T * array,int length,K value)` 

Perform a lower_bound search on the array  : receive na array, a length and a value  : a integer showing where the value must be placed

#### `public template<typename T,typename K>`  <br/>`inline static std::pair< bool, int > `[`binarySearch`](#arrayoperations_8hpp_1a9ba3114e7ba13b7d131394afce080c39)`(T * array,int length,K value)` 

Retrieves and return the index where the value must be placed

#### `public template<typename T,typename K>`  <br/>`inline static std::pair< bool, int > `[`secondaryBinarySearch`](#arrayoperations_8hpp_1a6a6e7d58ec67b844a8b5151c0f836262)`(T * array,int length,K value)` 

Retrieves and return the index where the value must be placed

#### `public template<typename T>`  <br/>`inline static std::pair< bool, unsigned short > `[`orderedInsert`](#arrayoperations_8hpp_1a520e0a69400a815341a0ff7ba2231930)`(T * array,unsigned short & length,T & value)` 

Perform a ordered insert  : receive an array, a length and a value  : void

#### `public void `[`printAll`](#debug_8cpp_1a2df98dd613396749426b2570a1ab1ec8)`(`[`Block_t`](#structBlock__t)` & block,FILE * indexFile,`[`BlockDerreference`](#unionBlockDerreference)` * derreference)` 

#### `public int `[`main`](#debug_8cpp_1ae66f6b31b5ad750f1fe042a706a4e3d4)`()` 

#### `public int `[`main`](#findrec_8cpp_1a0ddf1224851353fc92bfbff6f499fa97)`(int argc,char * argv)` 

#### `public bool `[`getArticleFromHash`](#hashfinder_8cpp_1a363b91b45181a1757f9b04b2f5e71f8c)`(int id,`[`Article_t`](#structArticle__t)` * article,FILE * toRead)` 

Retrieves and return an article from the file using the id

#### `public bool `[`getArticleFromHash`](#hashfinder_8hpp_1a363b91b45181a1757f9b04b2f5e71f8c)`(int id,`[`Article_t`](#structArticle__t)` * article,FILE * toRead)` 

Retrieves and return the article from the hash file

Retrieves and return an article from the file using the id

#### `public inline static char `[`after_pairClass`](#iohandler_8cpp_1ab00c0b4a11c5b93553dd251826fe5d28)`(char previous,char current)` 

Second degree verifyer, classify a pair of characters.

Classes : R_NOTHING as 0 \ R_SOR as 1 \ R_EOC as 2 \ R_SON as 3 \

#### `public inline static char `[`pairClass`](#iohandler_8cpp_1a57ad4115185f725aa84cfa399de7875d)`(char previous,char current)` 

First degree verifyer, classify a pair of characters.

Classes : R_NOTHING as 0 \ R_SOR as 1 \ R_EOC as 2 \ R_SON as 3 \

#### `public inline static void `[`readColumn`](#iohandler_8cpp_1a426a6bcaba1b0a41bcc1a658db45e374)`(FILE * file,char * buffer,char previous)` 

Read a column receiving the file, the buffer and the previous char

#### `public inline static void `[`readNIgnoreColumn`](#iohandler_8cpp_1a13a75b63bc655194bfc89812d3a32ee1)`(FILE * file,char previous)` 

Read a column receiving the file and the previous char, ignoring the buffer

#### `public inline void `[`writeBackNode`](#primarybtree_8cpp_1ac5f1ce9c3df8bca7c76a6a67ac294ebc)`(`[`PrimaryBTreeNode`](#structPrimaryBTreeNode)` * node,int offset,FILE * indexFile)` 

Write a node back into the file

#### `public inline char `[`relativeKeyPosition`](#primarybtree_8cpp_1a24ea8b6d11d9590463ce9027133f541d)`(int key,int leftMiddle,int rightMiddle)` 

Returns the relative key position based on the extremes

#### `public inline int `[`writeNewNode`](#primarybtree_8cpp_1a069a7c3af1dd5be5b6f82b9480ade8c5)`(`[`PrimaryBTreeNode`](#structPrimaryBTreeNode)` * node,FILE * indexFile)` 

Write a new node

#### `public inline void `[`writeBackNode`](#secondarybtree_8cpp_1a7c07fbcfb989230f5dd8216f5ea02e93)`(`[`SecondaryBTreeNode`](#structSecondaryBTreeNode)` * node,int offset,FILE * indexFile)` 

Write a node back into the file

#### `public inline char `[`relativeKeyPosition`](#secondarybtree_8cpp_1a2e6c691d155e9caa855195d3b69e77fb)`(`[`SecondaryBTreeDataMap`](#structSecondaryBTreeDataMap)` & key,`[`SecondaryBTreeDataMap`](#structSecondaryBTreeDataMap)` & leftMiddle,`[`SecondaryBTreeDataMap`](#structSecondaryBTreeDataMap)` & rightMiddle)` 

Returns the relative key position based on the extremes

#### `public inline int `[`writeNewNode`](#secondarybtree_8cpp_1aa0a19488ae38c6d8e39579558a89fd85)`(`[`SecondaryBTreeNode`](#structSecondaryBTreeNode)` * node,FILE * indexFile)` 

Write a new node

#### `public int `[`main`](#seek1_8cpp_1a3c04138a5bfe5d72780bb7e82a18e627)`(int argc,char ** argv)` 

#### `public int `[`main`](#seek2_8cpp_1a3c04138a5bfe5d72780bb7e82a18e627)`(int argc,char ** argv)` 

#### `public int `[`main`](#upload_8cpp_1a0ddf1224851353fc92bfbff6f499fa97)`(int argc,char * argv)` 

# class `HashFileFactory` 

A class to recover raw information in the hashed file

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public void `[`createBinaryFilePerfectHash`](#classHashFileFactory_1af64194105d574ff29ae3c42a692a6577)`(FILE * toRead,FILE * toWrite)` | Create the hashed file using the file on the first paramether to read the CSV format file and the file on the second paramether to write the binary file as a bonus, create the primary index as well xD

## Members

#### `public void `[`createBinaryFilePerfectHash`](#classHashFileFactory_1af64194105d574ff29ae3c42a692a6577)`(FILE * toRead,FILE * toWrite)` 

Create the hashed file using the file on the first paramether to read the CSV format file and the file on the second paramether to write the binary file as a bonus, create the primary index as well xD

# class `IOHandler` 

A class to read and handle the CSV file, buffering and handleing the fields

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`IOHandler`](#classIOHandler_1a6f8dc5e7c219e3c8c41e9590d88d8980)`(FILE *)` | Default [IOHandler](#classIOHandler) constructor, receiving a file to read
`public bool `[`hasNext`](#classIOHandler_1af8bee2b8cc00394e3d0879eca488b66f)`()` | Verify if there is next record in the buffer
`public void `[`parseNext`](#classIOHandler_1a2dd83f5ba06daa0566808153c3fc87b8)`()` | Prepare the next parsing element
`public void `[`operator>>`](#classIOHandler_1a550ed8aba7144814c4438691a6f3c051)`(`[`Article_t`](#structArticle__t)` &)` | Copy the content of the buffer into an article
`public int `[`getBiggestId`](#classIOHandler_1a5383c31a191a91c4697024a73904b459)`()` | Parse the next record contained in the buffer

## Members

#### `public  `[`IOHandler`](#classIOHandler_1a6f8dc5e7c219e3c8c41e9590d88d8980)`(FILE *)` 

Default [IOHandler](#classIOHandler) constructor, receiving a file to read

#### `public bool `[`hasNext`](#classIOHandler_1af8bee2b8cc00394e3d0879eca488b66f)`()` 

Verify if there is next record in the buffer

#### `public void `[`parseNext`](#classIOHandler_1a2dd83f5ba06daa0566808153c3fc87b8)`()` 

Prepare the next parsing element

#### `public void `[`operator>>`](#classIOHandler_1a550ed8aba7144814c4438691a6f3c051)`(`[`Article_t`](#structArticle__t)` &)` 

Copy the content of the buffer into an article

#### `public int `[`getBiggestId`](#classIOHandler_1a5383c31a191a91c4697024a73904b459)`()` 

Parse the next record contained in the buffer

# class `PrimaryBTree` 

A class abstracting the btree

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public unsigned short `[`rootOffset`](#classPrimaryBTree_1a34bf3c19a0553c194431994a0fe9d3c9) | 
`public void `[`insert`](#classPrimaryBTree_1aa730e6f8d8e62375ea120a71604f8a90)`(int key,FILE * indexFile)` | Insert a key in the tree
`public std::pair< bool, int > `[`getArticle`](#classPrimaryBTree_1afc29d73665c9df8b3bb1d5bea2d7292c)`(int key,`[`Article_t`](#structArticle__t)` *,FILE *)` | Get an article from the tree
`public void `[`buildIndex`](#classPrimaryBTree_1aaf3279355fa7a3818bb453d7bd0e3fc6)`(FILE *)` | Build the [PrimaryBTree](#classPrimaryBTree) index, writing a new root and its offset
`public void `[`readRoot`](#classPrimaryBTree_1ae1388a6ddbe57a1437c31a5429445b12)`(FILE * indexFile)` | Read the root whence the offset is set
`public  `[`PrimaryBTree`](#classPrimaryBTree_1a6479ac0c1a7dafea15b47540f8823581)`()` | [PrimaryBTree](#classPrimaryBTree) constructor

## Members

#### `public unsigned short `[`rootOffset`](#classPrimaryBTree_1a34bf3c19a0553c194431994a0fe9d3c9) 

#### `public void `[`insert`](#classPrimaryBTree_1aa730e6f8d8e62375ea120a71604f8a90)`(int key,FILE * indexFile)` 

Insert a key in the tree

#### `public std::pair< bool, int > `[`getArticle`](#classPrimaryBTree_1afc29d73665c9df8b3bb1d5bea2d7292c)`(int key,`[`Article_t`](#structArticle__t)` *,FILE *)` 

Get an article from the tree

#### `public void `[`buildIndex`](#classPrimaryBTree_1aaf3279355fa7a3818bb453d7bd0e3fc6)`(FILE *)` 

Build the [PrimaryBTree](#classPrimaryBTree) index, writing a new root and its offset

#### `public void `[`readRoot`](#classPrimaryBTree_1ae1388a6ddbe57a1437c31a5429445b12)`(FILE * indexFile)` 

Read the root whence the offset is set

#### `public  `[`PrimaryBTree`](#classPrimaryBTree_1a6479ac0c1a7dafea15b47540f8823581)`()` 

[PrimaryBTree](#classPrimaryBTree) constructor

# class `SecondaryBTree` 

A class abstracting the btree

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public int `[`rootOffset`](#classSecondaryBTree_1ac18f4a43f67189cefc3181549cb02920) | 
`public void `[`insert`](#classSecondaryBTree_1a8c28fdfad8ed08d089ea5a844680727b)`(`[`SecondaryBTreeDataMap`](#structSecondaryBTreeDataMap)` &,FILE * indexFile)` | Insert a key in the tree
`public std::pair< bool, int > `[`getArticle`](#classSecondaryBTree_1a306602256c122f9dd0349a7c4d6cf06a)`(`[`SecondaryBTreeDataMap`](#structSecondaryBTreeDataMap)` & key,`[`Article_t`](#structArticle__t)` *,FILE *)` | Get an article from the tree
`public void `[`buildIndex`](#classSecondaryBTree_1a171cb2a90b7f5b125be7d46e634dc4f6)`(FILE *)` | Build the [PrimaryBTree](#classPrimaryBTree) index, writing a new root and its offset
`public void `[`readRoot`](#classSecondaryBTree_1af6c413fc1b6f4b164b567ec8ed99a7e7)`(FILE * indexFile)` | Read the root whence the offset is set
`public  `[`SecondaryBTree`](#classSecondaryBTree_1a0d51148b5ca1adc98902b30e3b4a14b6)`()` | [PrimaryBTree](#classPrimaryBTree) constructor

## Members

#### `public int `[`rootOffset`](#classSecondaryBTree_1ac18f4a43f67189cefc3181549cb02920) 

#### `public void `[`insert`](#classSecondaryBTree_1a8c28fdfad8ed08d089ea5a844680727b)`(`[`SecondaryBTreeDataMap`](#structSecondaryBTreeDataMap)` &,FILE * indexFile)` 

Insert a key in the tree

#### `public std::pair< bool, int > `[`getArticle`](#classSecondaryBTree_1a306602256c122f9dd0349a7c4d6cf06a)`(`[`SecondaryBTreeDataMap`](#structSecondaryBTreeDataMap)` & key,`[`Article_t`](#structArticle__t)` *,FILE *)` 

Get an article from the tree

#### `public void `[`buildIndex`](#classSecondaryBTree_1a171cb2a90b7f5b125be7d46e634dc4f6)`(FILE *)` 

Build the [PrimaryBTree](#classPrimaryBTree) index, writing a new root and its offset

#### `public void `[`readRoot`](#classSecondaryBTree_1af6c413fc1b6f4b164b567ec8ed99a7e7)`(FILE * indexFile)` 

Read the root whence the offset is set

#### `public  `[`SecondaryBTree`](#classSecondaryBTree_1a0d51148b5ca1adc98902b30e3b4a14b6)`()` 

[PrimaryBTree](#classPrimaryBTree) constructor

# struct `AbstractBlock_t` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public char `[`data`](#structAbstractBlock__t_1a285108e3023c319f9d847e0ef6f9db6e) | 

## Members

#### `public char `[`data`](#structAbstractBlock__t_1a285108e3023c319f9d847e0ef6f9db6e) 

# struct `Article_t` 

A struct to embbed and abstract an article and its fields

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public int `[`id`](#structArticle__t_1a2f8468641cd607ecabac8bd5dd430f54) | 
`public char `[`title`](#structArticle__t_1afe043f73dc3a50d652f47ccc50b52ef3) | 
`public int `[`year`](#structArticle__t_1ab825fc134cf15bac264b00d692abd8de) | 
`public char `[`authors`](#structArticle__t_1af714c3f0c1139088b2067765b62d4e9e) | 
`public int `[`citations`](#structArticle__t_1ae2ad9f28254e7d0da90822e5c8421a2d) | 
`public char `[`date`](#structArticle__t_1a3b7b5bd84038566c9f0c9a5360e473c9) | 
`public char `[`snippet`](#structArticle__t_1af092556db9ccf21e5c0fd0dc45f40618) | 
`public std::string `[`toString`](#structArticle__t_1a6b981a29c37b826f950e0441c24fd7c2)`()` | Transform the content of this block into a string
`public  `[`Article_t`](#structArticle__t_1aaaecc4f794a5d41e7743df5920aef7cd)`(int,char,int,char,int,char,char)` | Constructor including the fields
`public  `[`Article_t`](#structArticle__t_1a432051cea45657cb986990c1fa2c25ad)`()` | Default constructor of an Article

## Members

#### `public int `[`id`](#structArticle__t_1a2f8468641cd607ecabac8bd5dd430f54) 

#### `public char `[`title`](#structArticle__t_1afe043f73dc3a50d652f47ccc50b52ef3) 

#### `public int `[`year`](#structArticle__t_1ab825fc134cf15bac264b00d692abd8de) 

#### `public char `[`authors`](#structArticle__t_1af714c3f0c1139088b2067765b62d4e9e) 

#### `public int `[`citations`](#structArticle__t_1ae2ad9f28254e7d0da90822e5c8421a2d) 

#### `public char `[`date`](#structArticle__t_1a3b7b5bd84038566c9f0c9a5360e473c9) 

#### `public char `[`snippet`](#structArticle__t_1af092556db9ccf21e5c0fd0dc45f40618) 

#### `public std::string `[`toString`](#structArticle__t_1a6b981a29c37b826f950e0441c24fd7c2)`()` 

Transform the content of this block into a string

#### `public  `[`Article_t`](#structArticle__t_1aaaecc4f794a5d41e7743df5920aef7cd)`(int,char,int,char,int,char,char)` 

Constructor including the fields

#### `public  `[`Article_t`](#structArticle__t_1a432051cea45657cb986990c1fa2c25ad)`()` 

Default constructor of an Article

# struct `Block_t` 

A struct to embbed and abstract an block, its head, data and tail

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public BYTE `[`content`](#structBlock__t_1a70cccc783eadc4f21eab996ba37cb1db) | 
`public bool `[`tryPutArticle`](#structBlock__t_1a3e9a5b8a917e6f27fda056c3dc625825)`(`[`Article_t`](#structArticle__t)` &)` | Try to put the article into the block, return true if it has been successfull
`public bool `[`hasSpace`](#structBlock__t_1a84f41f534c751f3a75aa137f1b0b3e51)`()` | Verify if there is space in the block
`public bool `[`isValid`](#structBlock__t_1a8d06ee95a0233c82be6cafbb85611075)`()` | Verify if the block is valid
`public void `[`validate`](#structBlock__t_1a513ec4b125a0b0cfebe745c3aa761656)`()` | Validate the block before the insertion so the block can be identifyed
`public `[`Article_t`](#structArticle__t)` * `[`getArticle`](#structBlock__t_1a0960b26d4ac2f6773a400efd1a8b13b9)`(unsigned int)` | Get an article in the relative position in the block
`public  `[`Block_t`](#structBlock__t_1aae9cfad211d45f096f386cf9d64c01ac)`()` | Default block constructor

## Members

#### `public BYTE `[`content`](#structBlock__t_1a70cccc783eadc4f21eab996ba37cb1db) 

#### `public bool `[`tryPutArticle`](#structBlock__t_1a3e9a5b8a917e6f27fda056c3dc625825)`(`[`Article_t`](#structArticle__t)` &)` 

Try to put the article into the block, return true if it has been successfull

#### `public bool `[`hasSpace`](#structBlock__t_1a84f41f534c751f3a75aa137f1b0b3e51)`()` 

Verify if there is space in the block

#### `public bool `[`isValid`](#structBlock__t_1a8d06ee95a0233c82be6cafbb85611075)`()` 

Verify if the block is valid

#### `public void `[`validate`](#structBlock__t_1a513ec4b125a0b0cfebe745c3aa761656)`()` 

Validate the block before the insertion so the block can be identifyed

#### `public `[`Article_t`](#structArticle__t)` * `[`getArticle`](#structBlock__t_1a0960b26d4ac2f6773a400efd1a8b13b9)`(unsigned int)` 

Get an article in the relative position in the block

#### `public  `[`Block_t`](#structBlock__t_1aae9cfad211d45f096f386cf9d64c01ac)`()` 

Default block constructor

# struct `Header_Interpretation_t::Header` 

Abstract header representation

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public unsigned long `[`verificationMask`](#structHeader__Interpretation__t_1_1Header_1aa4b1112900317acab6f94f7a09504567) | 
`public unsigned char `[`count`](#structHeader__Interpretation__t_1_1Header_1aa58d12f236042a6a7cd0a7f841f200ed) | 

## Members

#### `public unsigned long `[`verificationMask`](#structHeader__Interpretation__t_1_1Header_1aa4b1112900317acab6f94f7a09504567) 

#### `public unsigned char `[`count`](#structHeader__Interpretation__t_1_1Header_1aa58d12f236042a6a7cd0a7f841f200ed) 

# struct `PrimaryBTreeNode` 

A struct used for abstract the concept of node

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public unsigned short `[`count`](#structPrimaryBTreeNode_1a087a983f4477c6f319862d70521562be) | 
`public unsigned short `[`countPointers`](#structPrimaryBTreeNode_1a7f182de99b8a0356398dccdbaf44c880) | 
`public int `[`keys`](#structPrimaryBTreeNode_1ac4735393937b18b8d32669b9d6ffd57f) | 
`public unsigned short `[`blockPointers`](#structPrimaryBTreeNode_1ae6a628bd0f4918e01ac239333fb25063) | 
`public  `[`PrimaryBTreeNode`](#structPrimaryBTreeNode_1a43725d39bd87ac19736faf7d9b90edea)`(int order)` | [PrimaryBTreeNode](#structPrimaryBTreeNode) constructor
`public bool `[`isLeaf`](#structPrimaryBTreeNode_1ac38de1baf8b9e7096ab158268f8a3871)`()` | Verify if a node is a leaf
`public bool `[`hasRoom`](#structPrimaryBTreeNode_1a02d9f99ba8973164083e33ff6539b81f)`()` | Verify if a node has room to insert new nodes
`public unsigned short `[`insert`](#structPrimaryBTreeNode_1a72e8e6d644b4da168e6c84cf7b4e077d)`(int key)` | Insert a key in a node and returns the index where the insertion was made.

## Members

#### `public unsigned short `[`count`](#structPrimaryBTreeNode_1a087a983f4477c6f319862d70521562be) 

#### `public unsigned short `[`countPointers`](#structPrimaryBTreeNode_1a7f182de99b8a0356398dccdbaf44c880) 

#### `public int `[`keys`](#structPrimaryBTreeNode_1ac4735393937b18b8d32669b9d6ffd57f) 

#### `public unsigned short `[`blockPointers`](#structPrimaryBTreeNode_1ae6a628bd0f4918e01ac239333fb25063) 

#### `public  `[`PrimaryBTreeNode`](#structPrimaryBTreeNode_1a43725d39bd87ac19736faf7d9b90edea)`(int order)` 

[PrimaryBTreeNode](#structPrimaryBTreeNode) constructor

#### `public bool `[`isLeaf`](#structPrimaryBTreeNode_1ac38de1baf8b9e7096ab158268f8a3871)`()` 

Verify if a node is a leaf

#### `public bool `[`hasRoom`](#structPrimaryBTreeNode_1a02d9f99ba8973164083e33ff6539b81f)`()` 

Verify if a node has room to insert new nodes

#### `public unsigned short `[`insert`](#structPrimaryBTreeNode_1a72e8e6d644b4da168e6c84cf7b4e077d)`(int key)` 

Insert a key in a node and returns the index where the insertion was made.

# struct `PrimaryBTreeRecursionResponse` 

A struct used for save the response of the recursive insertion method

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public bool `[`hasBeenSplit`](#structPrimaryBTreeRecursionResponse_1a5731cc6a32df7fce26fd76eac62c6536) | 
`public int `[`promotedKey`](#structPrimaryBTreeRecursionResponse_1af790f3004b06d5b5b9cedc853148a562) | 
`public unsigned short `[`newBlockOffset`](#structPrimaryBTreeRecursionResponse_1af9ba0f46f858415cb1b45a73131cf1fd) | 
`public  `[`PrimaryBTreeRecursionResponse`](#structPrimaryBTreeRecursionResponse_1a701b593720c517ca87b52bfb4af7a5d3)`(bool,int,unsigned short)` | Build a recursion response from the core

## Members

#### `public bool `[`hasBeenSplit`](#structPrimaryBTreeRecursionResponse_1a5731cc6a32df7fce26fd76eac62c6536) 

#### `public int `[`promotedKey`](#structPrimaryBTreeRecursionResponse_1af790f3004b06d5b5b9cedc853148a562) 

#### `public unsigned short `[`newBlockOffset`](#structPrimaryBTreeRecursionResponse_1af9ba0f46f858415cb1b45a73131cf1fd) 

#### `public  `[`PrimaryBTreeRecursionResponse`](#structPrimaryBTreeRecursionResponse_1a701b593720c517ca87b52bfb4af7a5d3)`(bool,int,unsigned short)` 

Build a recursion response from the core

# struct `SecondaryBTreeDataMap` 

A struct used for abstract the keymap and the data block

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public char `[`key`](#structSecondaryBTreeDataMap_1a89c77fa03f1ed5b606cd44df3b25e3ab) | 
`public int `[`dataPointer`](#structSecondaryBTreeDataMap_1aec8420054a3e3207d6ccf2d8a4fc8c6b) | 
`public bool `[`operator<`](#structSecondaryBTreeDataMap_1a0c1b3f020c446050b679c0396a66b5ab)`(const `[`SecondaryBTreeDataMap`](#structSecondaryBTreeDataMap)` & other) const` | 
`public bool `[`operator>`](#structSecondaryBTreeDataMap_1a07af9b1d93234ae27ba047c72660a6e5)`(const `[`SecondaryBTreeDataMap`](#structSecondaryBTreeDataMap)` & other) const` | 
`public bool `[`operator==`](#structSecondaryBTreeDataMap_1ad524eb3163f03242bd7bcffc05d7db65)`(const `[`SecondaryBTreeDataMap`](#structSecondaryBTreeDataMap)` & other) const` | 
`public void `[`operator=`](#structSecondaryBTreeDataMap_1a0404fb45bd355174d6e5a2ec71ec2059)`(const `[`SecondaryBTreeDataMap`](#structSecondaryBTreeDataMap)` & other)` | 

## Members

#### `public char `[`key`](#structSecondaryBTreeDataMap_1a89c77fa03f1ed5b606cd44df3b25e3ab) 

#### `public int `[`dataPointer`](#structSecondaryBTreeDataMap_1aec8420054a3e3207d6ccf2d8a4fc8c6b) 

#### `public bool `[`operator<`](#structSecondaryBTreeDataMap_1a0c1b3f020c446050b679c0396a66b5ab)`(const `[`SecondaryBTreeDataMap`](#structSecondaryBTreeDataMap)` & other) const` 

#### `public bool `[`operator>`](#structSecondaryBTreeDataMap_1a07af9b1d93234ae27ba047c72660a6e5)`(const `[`SecondaryBTreeDataMap`](#structSecondaryBTreeDataMap)` & other) const` 

#### `public bool `[`operator==`](#structSecondaryBTreeDataMap_1ad524eb3163f03242bd7bcffc05d7db65)`(const `[`SecondaryBTreeDataMap`](#structSecondaryBTreeDataMap)` & other) const` 

#### `public void `[`operator=`](#structSecondaryBTreeDataMap_1a0404fb45bd355174d6e5a2ec71ec2059)`(const `[`SecondaryBTreeDataMap`](#structSecondaryBTreeDataMap)` & other)` 

# struct `SecondaryBTreeNode` 

A struct used for abstract the concept of node

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public unsigned short `[`count`](#structSecondaryBTreeNode_1a033a775826693aa3d0f853642891b721) | 
`public unsigned short `[`countPointers`](#structSecondaryBTreeNode_1abbd35b09fdb6d0fcf37f341e20dfa093) | 
`public `[`SecondaryBTreeDataMap`](#structSecondaryBTreeDataMap)` `[`keys`](#structSecondaryBTreeNode_1a52a2768a8c63ffa7a5ee0df8957b9fc8) | 
`public int `[`blockPointers`](#structSecondaryBTreeNode_1a40354a16c99ece2dbd98edc045a84af3) | 
`public  `[`SecondaryBTreeNode`](#structSecondaryBTreeNode_1a2fc4b3aea2cfb27efdf39c78ceabdb9b)`(int order)` | [PrimaryBTreeNode](#structPrimaryBTreeNode) constructor
`public bool `[`isLeaf`](#structSecondaryBTreeNode_1ae4ea7731fd1b795fa9cea2ce6f5654d7)`()` | Verify if a node is a leaf
`public bool `[`hasRoom`](#structSecondaryBTreeNode_1a5cba6636f4afab01902224a108e37e07)`()` | Verify if a node has room to insert new nodes
`public int `[`insert`](#structSecondaryBTreeNode_1aa0ed0aa03df074c6351103f78420ca6e)`(`[`SecondaryBTreeDataMap`](#structSecondaryBTreeDataMap)` &)` | Insert a key in a node and returns the index where the insertion was made.

## Members

#### `public unsigned short `[`count`](#structSecondaryBTreeNode_1a033a775826693aa3d0f853642891b721) 

#### `public unsigned short `[`countPointers`](#structSecondaryBTreeNode_1abbd35b09fdb6d0fcf37f341e20dfa093) 

#### `public `[`SecondaryBTreeDataMap`](#structSecondaryBTreeDataMap)` `[`keys`](#structSecondaryBTreeNode_1a52a2768a8c63ffa7a5ee0df8957b9fc8) 

#### `public int `[`blockPointers`](#structSecondaryBTreeNode_1a40354a16c99ece2dbd98edc045a84af3) 

#### `public  `[`SecondaryBTreeNode`](#structSecondaryBTreeNode_1a2fc4b3aea2cfb27efdf39c78ceabdb9b)`(int order)` 

[PrimaryBTreeNode](#structPrimaryBTreeNode) constructor

#### `public bool `[`isLeaf`](#structSecondaryBTreeNode_1ae4ea7731fd1b795fa9cea2ce6f5654d7)`()` 

Verify if a node is a leaf

#### `public bool `[`hasRoom`](#structSecondaryBTreeNode_1a5cba6636f4afab01902224a108e37e07)`()` 

Verify if a node has room to insert new nodes

#### `public int `[`insert`](#structSecondaryBTreeNode_1aa0ed0aa03df074c6351103f78420ca6e)`(`[`SecondaryBTreeDataMap`](#structSecondaryBTreeDataMap)` &)` 

Insert a key in a node and returns the index where the insertion was made.

# struct `SecondaryBTreeRecursionResponse` 

A struct used for save the response of the recursive insertion method

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public bool `[`hasBeenSplit`](#structSecondaryBTreeRecursionResponse_1aa2ae3c8c18f816bfcf426aa6e0aba673) | 
`public `[`SecondaryBTreeDataMap`](#structSecondaryBTreeDataMap)` `[`promotedKey`](#structSecondaryBTreeRecursionResponse_1a380665da9a03fc26c66c35a3d5110462) | 
`public int `[`newBlockOffset`](#structSecondaryBTreeRecursionResponse_1a3fb5b31c525097adecacb6668a88ea4b) | 
`public  `[`SecondaryBTreeRecursionResponse`](#structSecondaryBTreeRecursionResponse_1aa7a143131390c7aa46bd9bdce1c2fd7f)`(bool)` | Build a recursion response from the core
`public  `[`SecondaryBTreeRecursionResponse`](#structSecondaryBTreeRecursionResponse_1aeb64afe3ace0f073b1762381497603c8)`(bool,`[`SecondaryBTreeDataMap`](#structSecondaryBTreeDataMap)` &,int)` | Build a recursion response from the core

## Members

#### `public bool `[`hasBeenSplit`](#structSecondaryBTreeRecursionResponse_1aa2ae3c8c18f816bfcf426aa6e0aba673) 

#### `public `[`SecondaryBTreeDataMap`](#structSecondaryBTreeDataMap)` `[`promotedKey`](#structSecondaryBTreeRecursionResponse_1a380665da9a03fc26c66c35a3d5110462) 

#### `public int `[`newBlockOffset`](#structSecondaryBTreeRecursionResponse_1a3fb5b31c525097adecacb6668a88ea4b) 

#### `public  `[`SecondaryBTreeRecursionResponse`](#structSecondaryBTreeRecursionResponse_1aa7a143131390c7aa46bd9bdce1c2fd7f)`(bool)` 

Build a recursion response from the core

#### `public  `[`SecondaryBTreeRecursionResponse`](#structSecondaryBTreeRecursionResponse_1aeb64afe3ace0f073b1762381497603c8)`(bool,`[`SecondaryBTreeDataMap`](#structSecondaryBTreeDataMap)` &,int)` 

Build a recursion response from the core

# struct `Tail_Interpretation_t::Tail` 

Abstract tail representation

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public unsigned long `[`verificationMask`](#structTail__Interpretation__t_1_1Tail_1a28f27b558b37a0c703122cc8db993f4c) | 

## Members

#### `public unsigned long `[`verificationMask`](#structTail__Interpretation__t_1_1Tail_1a28f27b558b37a0c703122cc8db993f4c) 

Generated by [Moxygen](https://sourcey.com/moxygen)