#include <iostream>
//201502115 정용환
//
int bss;
int data =0;
int code()
{
	return 0;
}

int main()
{
	const char* rodata = "a";
	int* heap = new int[2];
	int stack;
	
	std::cout << "code\t" <<(void*) code << std::endl;
	std::cout << "rodata\t" <<(void*) rodata << std::endl;
	std::cout << "data\t" << &data << std::endl;
	std::cout << "heap\t" << heap << std::endl;
	std::cout << "stack\t" << &stack <<std::endl;

}
