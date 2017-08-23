### C Arguments
CC=g++
CFLAGS=-std=c++11 -Wall -g

### Program Arguments
NAME=cheeki

### Compiler Arguments
INCLUDE_PATH=src
SRC_PATH=src

all: merge clean

merge: main.o iohandler.o article.o block.o hashfilefactory.o
	$(CC) -o $(NAME) iohandler.o main.o article.o block.o hashfilefactory.o $(CFLAGS)

main.o: hashfilefactory.o $(SRC_PATH)/main.cpp
	$(CC) -c $(SRC_PATH)/main.cpp -I/$(INCLUDE_PATH) $(CFLAGS)

hashfilefactory.o: iohandler.o block.o $(SRC_PATH)/hashfilefactory.cpp $(INCLUDE_PATH)/hashfilefactory.hpp
	$(CC) -c $(SRC_PATH)/hashfilefactory.cpp -I/$(INCLUDE_PATH) $(CFLAGS)

iohandler.o: article.o $(SRC_PATH)/iohandler.cpp $(INCLUDE_PATH)/iohandler.hpp
	$(CC) -c $(SRC_PATH)/iohandler.cpp -I/$(INCLUDE_PATH) $(CFLAGS)

article.o: $(SRC_PATH)/article.cpp $(INCLUDE_PATH)/article.hpp $(INCLUDE_PATH)/json.hpp
	$(CC) -c $(SRC_PATH)/article.cpp -I/$(INCLUDE_PATH) $(CFLAGS)

block.o: article.o $(SRC_PATH)/block.cpp $(INCLUDE_PATH)/block.hpp
	$(CC) -c $(SRC_PATH)/block.cpp -I/$(INCLUDE_PATH) $(CFLAGS)

clean: 
	rm -rf **.o