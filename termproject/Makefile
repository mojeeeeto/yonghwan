.SUFFIXES: .cpp .o
OBJECTS = block_fold.o block_tree.o board.o block_cross.o
CC = g++
TEST_FILE = main.o $(OBJECTS)
TEST = test

$(TEST) : $(TEST_FILE)
	$(CC) -o $(TEST) $(TEST_FILE)

main.o : main.cpp

block_fold.o : block_fold.cpp

block_cross.o : block_cross.cpp

block_tree.o : block_tree.cpp

board.o : board.cpp

clean : 
	rm *.o test
