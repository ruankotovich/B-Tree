### C Arguments
CC=g++
CFLAGS=-std=c++11 -g -Wall

### Compiler Arguments
INCLUDE_PATH=src
SRC_PATH=src

all: upload findrec seek1 seek2 debug clean

seek1: seek1.o
	$(CC) -o seek1 iohandler.o seek1.o primarybtree.o article.o block.o hashfinder.o $(CFLAGS)

seek2: seek2.o
	$(CC) -o seek2 iohandler.o seek2.o secondarybtree.o article.o block.o hashfinder.o $(CFLAGS)

debug: debug.o
	$(CC) -o debug iohandler.o debug.o secondarybtree.o article.o block.o hashfinder.o $(CFLAGS)

main: main.o
	$(CC) -o main iohandler.o main.o primarybtree.o article.o block.o hashfilefactory.o hashfinder.o $(CFLAGS)

main.o: primarybtree.o $(SRC_PATH)/main.cpp
	$(CC) -c $(SRC_PATH)/main.cpp -I/$(INCLUDE_PATH) $(CFLAGS)

debug.o: secondarybtree.o $(SRC_PATH)/debug.cpp
	$(CC) -c $(SRC_PATH)/debug.cpp -I/$(INCLUDE_PATH) $(CFLAGS)

seek1.o: primarybtree.o $(SRC_PATH)/seek1.cpp
	$(CC) -c $(SRC_PATH)/seek1.cpp -I/$(INCLUDE_PATH) $(CFLAGS)

seek2.o: secondarybtree.o $(SRC_PATH)/seek2.cpp
	$(CC) -c $(SRC_PATH)/seek2.cpp -I/$(INCLUDE_PATH) $(CFLAGS)

upload: upload.o
	$(CC) -o upload iohandler.o upload.o secondarybtree.o primarybtree.o article.o block.o hashfilefactory.o hashfinder.o $(CFLAGS)

findrec: findrec.o
	$(CC) -o findrec iohandler.o findrec.o article.o block.o hashfinder.o $(CFLAGS)

findrec.o: hashfinder.o $(SRC_PATH)/findrec.cpp
	$(CC) -c $(SRC_PATH)/findrec.cpp -I/$(INCLUDE_PATH) $(CFLAGS)

upload.o: primarybtree.o hashfilefactory.o $(SRC_PATH)/upload.cpp
	$(CC) -c $(SRC_PATH)/upload.cpp -I/$(INCLUDE_PATH) $(CFLAGS)

hashfilefactory.o: iohandler.o block.o primarybtree.o secondarybtree.o $(SRC_PATH)/hashfilefactory.cpp $(INCLUDE_PATH)/hashfilefactory.hpp
	$(CC) -c $(SRC_PATH)/hashfilefactory.cpp -I/$(INCLUDE_PATH) $(CFLAGS)

hashfinder.o: block.o article.o $(SRC_PATH)/hashfinder.cpp $(INCLUDE_PATH)/hashfinder.hpp
	$(CC) -c $(SRC_PATH)/hashfinder.cpp -I/$(INCLUDE_PATH) $(CFLAGS)

primarybtree.o: hashfinder.o $(SRC_PATH)/primarybtree.cpp $(INCLUDE_PATH)/primarybtree.hpp
	$(CC) -c $(SRC_PATH)/primarybtree.cpp -I/$(INCLUDE_PATH) $(CFLAGS)

secondarybtree.o: hashfinder.o $(SRC_PATH)/secondarybtree.cpp $(INCLUDE_PATH)/secondarybtree.hpp
	$(CC) -c $(SRC_PATH)/secondarybtree.cpp -I/$(INCLUDE_PATH) $(CFLAGS)

iohandler.o: article.o $(SRC_PATH)/iohandler.cpp $(INCLUDE_PATH)/iohandler.hpp
	$(CC) -c $(SRC_PATH)/iohandler.cpp -I/$(INCLUDE_PATH) $(CFLAGS)

article.o: $(SRC_PATH)/article.cpp $(INCLUDE_PATH)/article.hpp
	$(CC) -c $(SRC_PATH)/article.cpp -I/$(INCLUDE_PATH) $(CFLAGS)

block.o: article.o $(SRC_PATH)/block.cpp $(INCLUDE_PATH)/block.hpp
	$(CC) -c $(SRC_PATH)/block.cpp -I/$(INCLUDE_PATH) $(CFLAGS)

clean:
	rm -rf **.o
