.SUFFIXES: .cpp .o
OBJECTS = human.o shared_ref.o smart_obj.o student.o weak_pointer.o
CC = g++
TEST_FILE = test.o $(OBJECTS)
TEST = test

$(TEST) : $(TEST_FILE)
	$(CC) -o $(TEST) $(TEST_FILE)

test.o : test.cpp

smart_obj.o : smart_obj.cpp

shared_ref.o : shared_ref.cpp

student.o : student.cpp

weak_pointer.o : weak_pointer.cpp

human.o : human.cpp



clean :
	rm *.o test
