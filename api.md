# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`define `[`FIELD_TITLE_MAX_SIZE`](#article_8hpp_1a7f0fb854ad1e5c749aa14072096f422b)            | Max size of the article title.
`define `[`FIELD_AUTHORS_MAX_SIZE`](#article_8hpp_1a4efec02e356c0aea3b68d038fcae54d4)            | Max size of the article authors' names.
`define `[`FIELD_DATE_MAX_SIZE`](#article_8hpp_1afbed943af9c72a768f5df31dcc5adff0)            | Max size of the article date.
`define `[`FIELD_SNIPPET_MAX_SIZE`](#article_8hpp_1a4bda691dffbd5477de0ed57a762038fd)            | Max size of the article snippet.
`define `[`BLOCK_SIZE`](#block_8hpp_1ad51ded0bbd705f02f73fc60c0b721ced)            | Preset block size.
`define `[`RECORD_HEADER_SIZE`](#block_8hpp_1a4c5a6c66027c91ec2d616914b4ea5641)            | Preset record header size.
`define `[`RECORD_AREA_SIZE`](#block_8hpp_1a05dbf893ffc04a18c4434173238393ab)            | Preset record area size, containing the data.
`define `[`R_NOTHING`](#iohandler_8cpp_1ae39a3fd7e93fd4f14bca6137f5bfff35)            | 
`define `[`R_SOR`](#iohandler_8cpp_1a9caa5949b270f7611fad0e56d8ee804f)            | 
`define `[`R_EOC`](#iohandler_8cpp_1ae7aa42681447f2e2141614715ab21b5d)            | 
`define `[`R_SON`](#iohandler_8cpp_1aaf615c5e27cd1ce437b93be9babf322d)            | 
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
`public template<typename T,typename L>`  <br/>`inline static std::pair< bool, int > `[`binarySearch`](#arrayoperations_8hpp_1ad92627121af51bfcf8524c366af38d7d)`(T * array,L length,T value)`            | Perform a binary search on the array  : receive a array, a length and a value  : a pair, the first paramether regards if the search has found the value, false if it hasn't been found; the second paramether regards the index in the array
`public template<typename T,typename L>`  <br/>`inline static void `[`orderedInsert`](#arrayoperations_8hpp_1a62993b5993a378d41d4fc87f1630cf6a)`(T * array,L length,T value)`            | 
`public int `[`main`](#findrec_8cpp_1a0ddf1224851353fc92bfbff6f499fa97)`(int argc,char * argv)`            | 
`public inline static char `[`after_pairClass`](#iohandler_8cpp_1ab00c0b4a11c5b93553dd251826fe5d28)`(char previous,char current)`            | Second degree verifyer, classify a pair of characters.
`public inline static char `[`pairClass`](#iohandler_8cpp_1a57ad4115185f725aa84cfa399de7875d)`(char previous,char current)`            | First degree verifyer, classify a pair of characters.
`public inline static void `[`readColumn`](#iohandler_8cpp_1a426a6bcaba1b0a41bcc1a658db45e374)`(FILE * file,char * buffer,char previous)`            | Read a column receibing the file, the buffer and the previous char
`public int `[`main`](#upload_8cpp_1a0ddf1224851353fc92bfbff6f499fa97)`(int argc,char * argv)`            | 
`class `[`HashFileFactory`](#classHashFileFactory) | 
`class `[`IOHandler`](#classIOHandler) | 
`struct `[`Article_t`](#structArticle__t) | 
`struct `[`Block_t`](#structBlock__t) | 
`struct `[`Header_Interpretation_t::Header`](#structHeader__Interpretation__t_1_1Header) | 
`union `[`Article_Interpretation_t`](#unionArticle__Interpretation__t) | 
`union `[`Header_Interpretation_t`](#unionHeader__Interpretation__t) | 

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

#### `define `[`RECORD_AREA_SIZE`](#block_8hpp_1a05dbf893ffc04a18c4434173238393ab) 

Preset record area size, containing the data.

#### `define `[`R_NOTHING`](#iohandler_8cpp_1ae39a3fd7e93fd4f14bca6137f5bfff35) 

#### `define `[`R_SOR`](#iohandler_8cpp_1a9caa5949b270f7611fad0e56d8ee804f) 

#### `define `[`R_EOC`](#iohandler_8cpp_1ae7aa42681447f2e2141614715ab21b5d) 

#### `define `[`R_SON`](#iohandler_8cpp_1aaf615c5e27cd1ce437b93be9babf322d) 

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

Perform a binary search on the array  : receive a array, a length and a value  : a pair, the first paramether regards if the search has found the value, false if it hasn't been found; the second paramether regards the index in the array

#### `public template<typename T,typename L>`  <br/>`inline static void `[`orderedInsert`](#arrayoperations_8hpp_1a62993b5993a378d41d4fc87f1630cf6a)`(T * array,L length,T value)` 

#### `public int `[`main`](#findrec_8cpp_1a0ddf1224851353fc92bfbff6f499fa97)`(int argc,char * argv)` 

#### `public inline static char `[`after_pairClass`](#iohandler_8cpp_1ab00c0b4a11c5b93553dd251826fe5d28)`(char previous,char current)` 

Second degree verifyer, classify a pair of characters.

Classes : R_NOTHING as 0 \ R_SOR as 1 \ R_EOC as 2 \ R_SON as 3 \

#### `public inline static char `[`pairClass`](#iohandler_8cpp_1a57ad4115185f725aa84cfa399de7875d)`(char previous,char current)` 

First degree verifyer, classify a pair of characters.

Classes : R_NOTHING as 0 \ R_SOR as 1 \ R_EOC as 2 \ R_SON as 3 \

#### `public inline static void `[`readColumn`](#iohandler_8cpp_1a426a6bcaba1b0a41bcc1a658db45e374)`(FILE * file,char * buffer,char previous)` 

Read a column receibing the file, the buffer and the previous char

#### `public int `[`main`](#upload_8cpp_1a0ddf1224851353fc92bfbff6f499fa97)`(int argc,char * argv)` 

# class `HashFileFactory` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`HashFileFactory`](#classHashFileFactory_1a3da9e9bc23b17c0d6c23ce4c5296bc31)`()` | 
`public void `[`createBinaryFilePerfectHash`](#classHashFileFactory_1af64194105d574ff29ae3c42a692a6577)`(FILE * toRead,FILE * toWrite)` | 
`public bool `[`getArticleFromHash`](#classHashFileFactory_1aade3ddf0f478dd0b5ef1b5192b857056)`(int id,`[`Article_t`](#structArticle__t)` * article,FILE * toRead)` | 

## Members

#### `public  `[`HashFileFactory`](#classHashFileFactory_1a3da9e9bc23b17c0d6c23ce4c5296bc31)`()` 

#### `public void `[`createBinaryFilePerfectHash`](#classHashFileFactory_1af64194105d574ff29ae3c42a692a6577)`(FILE * toRead,FILE * toWrite)` 

#### `public bool `[`getArticleFromHash`](#classHashFileFactory_1aade3ddf0f478dd0b5ef1b5192b857056)`(int id,`[`Article_t`](#structArticle__t)` * article,FILE * toRead)` 

# class `IOHandler` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`IOHandler`](#classIOHandler_1a6f8dc5e7c219e3c8c41e9590d88d8980)`(FILE *)` | Default [IOHandler](#classIOHandler) constructor, receiving a file to read
`public bool `[`hasNext`](#classIOHandler_1af8bee2b8cc00394e3d0879eca488b66f)`()` | Verify if there is next record in the buffer
`public void `[`parseNext`](#classIOHandler_1a2dd83f5ba06daa0566808153c3fc87b8)`()` | Parse the next record contained in the buffer
`public void `[`operator>>`](#classIOHandler_1a550ed8aba7144814c4438691a6f3c051)`(`[`Article_t`](#structArticle__t)` &)` | Copy the content of the buffer into an article

## Members

#### `public  `[`IOHandler`](#classIOHandler_1a6f8dc5e7c219e3c8c41e9590d88d8980)`(FILE *)` 

Default [IOHandler](#classIOHandler) constructor, receiving a file to read

#### `public bool `[`hasNext`](#classIOHandler_1af8bee2b8cc00394e3d0879eca488b66f)`()` 

Verify if there is next record in the buffer

#### `public void `[`parseNext`](#classIOHandler_1a2dd83f5ba06daa0566808153c3fc87b8)`()` 

Parse the next record contained in the buffer

#### `public void `[`operator>>`](#classIOHandler_1a550ed8aba7144814c4438691a6f3c051)`(`[`Article_t`](#structArticle__t)` &)` 

Copy the content of the buffer into an article

# struct `Article_t` 

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

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public BYTE `[`content`](#structBlock__t_1a70cccc783eadc4f21eab996ba37cb1db) | 
`public bool `[`tryPutArticle`](#structBlock__t_1a3e9a5b8a917e6f27fda056c3dc625825)`(`[`Article_t`](#structArticle__t)` &)` | Try to put the article into the block, return true if it has been successfull
`public bool `[`hasSpace`](#structBlock__t_1a84f41f534c751f3a75aa137f1b0b3e51)`()` | Verify if there is space in the block
`public `[`Article_t`](#structArticle__t)` * `[`getArticle`](#structBlock__t_1a0960b26d4ac2f6773a400efd1a8b13b9)`(unsigned int)` | Get an article in the relative position in the block
`public  `[`Block_t`](#structBlock__t_1aae9cfad211d45f096f386cf9d64c01ac)`()` | Default block constructor

## Members

#### `public BYTE `[`content`](#structBlock__t_1a70cccc783eadc4f21eab996ba37cb1db) 

#### `public bool `[`tryPutArticle`](#structBlock__t_1a3e9a5b8a917e6f27fda056c3dc625825)`(`[`Article_t`](#structArticle__t)` &)` 

Try to put the article into the block, return true if it has been successfull

#### `public bool `[`hasSpace`](#structBlock__t_1a84f41f534c751f3a75aa137f1b0b3e51)`()` 

Verify if there is space in the block

#### `public `[`Article_t`](#structArticle__t)` * `[`getArticle`](#structBlock__t_1a0960b26d4ac2f6773a400efd1a8b13b9)`(unsigned int)` 

Get an article in the relative position in the block

#### `public  `[`Block_t`](#structBlock__t_1aae9cfad211d45f096f386cf9d64c01ac)`()` 

Default block constructor

# struct `Header_Interpretation_t::Header` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public unsigned char `[`valid`](#structHeader__Interpretation__t_1_1Header_1a5c7e34803430fcb0bb46882019d32a61) | 
`public unsigned char `[`count`](#structHeader__Interpretation__t_1_1Header_1aa58d12f236042a6a7cd0a7f841f200ed) | 

## Members

#### `public unsigned char `[`valid`](#structHeader__Interpretation__t_1_1Header_1a5c7e34803430fcb0bb46882019d32a61) 

#### `public unsigned char `[`count`](#structHeader__Interpretation__t_1_1Header_1aa58d12f236042a6a7cd0a7f841f200ed) 

Generated by [Moxygen](https://sourcey.com/moxygen)