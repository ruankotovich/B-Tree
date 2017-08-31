# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
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
`define `[`BYTE`](#typessize_8hpp_1aec93e83855ac17c3c25c55c37ca186dd)            | Binding for unsigned char.
`define `[`BYTE_BITS`](#typessize_8hpp_1a40094f03df908fa568fd08bc4b87820a)            | Byte size in bits.
`define `[`SHORT_SIZE`](#typessize_8hpp_1adeb5281b5f526ce88376cb4b4b36572e)            | Short size in bytes.
`define `[`INT_SIZE`](#typessize_8hpp_1a3ac36dd0f02f263e5966ac1d1ecbd1bd)            | Int size in bytes.
`define `[`LONG_SIZE`](#typessize_8hpp_1aff6ef0fbcfed01f51caa8ed5592731b8)            | Long size in bytes.
`define `[`BYTE_SIZE`](#typessize_8hpp_1a86fd4404b140711fdb77326609c0f393)            | Byte size in bytes (?)
`public template<typename T,typename L>`  <br/>`inline static std::pair< bool, int > `[`binarySearch`](#arrayoperations_8hpp_1ad92627121af51bfcf8524c366af38d7d)`(T * array,L length,T value)`            | Perform a binary search on the array  : receive na array, a length and a value  : a pair, the first paramether regards if the search has found the value, false if it hasn't been found; the second paramether regards the index in the array
`public template<typename T,typename L>`  <br/>`inline static void `[`orderedInsert`](#arrayoperations_8hpp_1a62993b5993a378d41d4fc87f1630cf6a)`(T * array,L length,T value)`            | Perform a ordered insert  : receive an array, a length and a value  : void
`public int `[`main`](#findrec_8cpp_1a0ddf1224851353fc92bfbff6f499fa97)`(int argc,char * argv)`            | 
`public inline static char `[`after_pairClass`](#iohandler_8cpp_1ab00c0b4a11c5b93553dd251826fe5d28)`(char previous,char current)`            | Second degree verifyer, classify a pair of characters.
`public inline static char `[`pairClass`](#iohandler_8cpp_1a57ad4115185f725aa84cfa399de7875d)`(char previous,char current)`            | First degree verifyer, classify a pair of characters.
`public inline static void `[`readColumn`](#iohandler_8cpp_1a426a6bcaba1b0a41bcc1a658db45e374)`(FILE * file,char * buffer,char previous)`            | Read a column receiving the file, the buffer and the previous char
`public inline static void `[`readNIgnoreColumn`](#iohandler_8cpp_1a13a75b63bc655194bfc89812d3a32ee1)`(FILE * file,char previous)`            | Read a column receiving the file and the previous char, ignoring the buffer
`public int `[`main`](#upload_8cpp_1a0ddf1224851353fc92bfbff6f499fa97)`(int argc,char * argv)`            | 
`class `[`HashFileFactory`](#classHashFileFactory) | A class to recover raw information in the hashed file
`class `[`IOHandler`](#classIOHandler) | A class to read and handle the CSV file, buffering and handleing the fields
`struct `[`Article_t`](#structArticle__t) | A struct to embbed and abstract an article and its fields
`struct `[`Block_t`](#structBlock__t) | A struct to embbed and abstract an block, its head, data and tail
`struct `[`Header_Interpretation_t::Header`](#structHeader__Interpretation__t_1_1Header) | Abstract header representation
`struct `[`Tail_Interpretation_t::Tail`](#structTail__Interpretation__t_1_1Tail) | Abstract tail representation
`union `[`Article_Interpretation_t`](#unionArticle__Interpretation__t) | An union to abstract the reinterpretation of the article onto the block
`union `[`Header_Interpretation_t`](#unionHeader__Interpretation__t) | An union to abstract the reinterpretation of the header onto the block
`union `[`Tail_Interpretation_t`](#unionTail__Interpretation__t) | An union to abstract the reinterpretation of the tail onto the block

## Members

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

#### `public template<typename T,typename L>`  <br/>`inline static std::pair< bool, int > `[`binarySearch`](#arrayoperations_8hpp_1ad92627121af51bfcf8524c366af38d7d)`(T * array,L length,T value)` 

Perform a binary search on the array  : receive na array, a length and a value  : a pair, the first paramether regards if the search has found the value, false if it hasn't been found; the second paramether regards the index in the array

#### `public template<typename T,typename L>`  <br/>`inline static void `[`orderedInsert`](#arrayoperations_8hpp_1a62993b5993a378d41d4fc87f1630cf6a)`(T * array,L length,T value)` 

Perform a ordered insert  : receive an array, a length and a value  : void

#### `public int `[`main`](#findrec_8cpp_1a0ddf1224851353fc92bfbff6f499fa97)`(int argc,char * argv)` 

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

#### `public int `[`main`](#upload_8cpp_1a0ddf1224851353fc92bfbff6f499fa97)`(int argc,char * argv)` 

# class `HashFileFactory` 

A class to recover raw information in the hashed file

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`HashFileFactory`](#classHashFileFactory_1a3da9e9bc23b17c0d6c23ce4c5296bc31)`()` | 
`public void `[`createBinaryFilePerfectHash`](#classHashFileFactory_1af64194105d574ff29ae3c42a692a6577)`(FILE * toRead,FILE * toWrite)` | Create the hashed file using the file on the first paramether to read the CSV format file and the file on the second paramether to write the binary file
`public bool `[`getArticleFromHash`](#classHashFileFactory_1aade3ddf0f478dd0b5ef1b5192b857056)`(int id,`[`Article_t`](#structArticle__t)` * article,FILE * toRead)` | Attemp to read an article receiving the ID, a callback variable and a file whence fields will be read

## Members

#### `public  `[`HashFileFactory`](#classHashFileFactory_1a3da9e9bc23b17c0d6c23ce4c5296bc31)`()` 

#### `public void `[`createBinaryFilePerfectHash`](#classHashFileFactory_1af64194105d574ff29ae3c42a692a6577)`(FILE * toRead,FILE * toWrite)` 

Create the hashed file using the file on the first paramether to read the CSV format file and the file on the second paramether to write the binary file

#### `public bool `[`getArticleFromHash`](#classHashFileFactory_1aade3ddf0f478dd0b5ef1b5192b857056)`(int id,`[`Article_t`](#structArticle__t)` * article,FILE * toRead)` 

Attemp to read an article receiving the ID, a callback variable and a file whence fields will be read

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

# struct `Tail_Interpretation_t::Tail` 

Abstract tail representation

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public unsigned long `[`verificationMask`](#structTail__Interpretation__t_1_1Tail_1a28f27b558b37a0c703122cc8db993f4c) | 

## Members

#### `public unsigned long `[`verificationMask`](#structTail__Interpretation__t_1_1Tail_1a28f27b558b37a0c703122cc8db993f4c) 

Generated by [Moxygen](https://sourcey.com/moxygen)