test : main.o student_id.o print.o
	g++ -o test main.o student_id.o print.o

main.o : main.cpp
	g++ -c -o main.o main.cpp

student_id.o : student_id.h student_id.cpp
	g++ -c student_id.h student_id.cpp

print.o : student_id.h print.h print.cpp
	g++ -c student_id.h print.h print.cpp

clean :
	rm -rf main.o print.o student_id.o test

