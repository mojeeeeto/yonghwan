.SUFFIXES: .cpp .o

OBJECTS = Complex.o Float.o Integer.o

TEST_FILE = test.o $(OBJECTS)

CC = g++

TEST = test

$(TEST) : $(TEST_FILE)
	$(CC) -o $(TEST) $(TEST_FILE)

Complex.o : Complex.cpp

Float.o : Float.cpp

Integer.o : Integer.cpp


clean :
	rm *.o test
