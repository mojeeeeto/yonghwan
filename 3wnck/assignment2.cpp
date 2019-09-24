#include <iostream>
//201502115 정용환
//c2440 오류 발생해서 const붙임
//a는 const 이므로 저장하고 있는 주소가 가리키고 있는값이 변경되지 않게 많든다.
//그러므로 a에 넣은 값이 변하는것은 불가능하므로 오류를 발생시킨다.
int main()
{
	const char * a = "ABC";
	char b[] = "ABC";

	b[0] = 'b';
	std::cout << a <<std::endl;
	std::cout << b <<std::endl;
}


