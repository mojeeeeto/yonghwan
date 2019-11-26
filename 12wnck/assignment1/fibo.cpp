#include <iostream>

int fibo(int f)
{
	if(f < 2)
	{
		return f;
	}
	else
	{
		return fibo(f-1) + fibo(f-2);
	}
}
int main()
{
	int i;
	std::cin >> i;
	int val = fibo(i);
	std::cout << val << std::endl;
	return 0;
}

