#include "block.h"
#include <vector>
#include <algorithm>
#include <iostream>

class board
{
protected:
	block* gameboard[12][5];
	int score;
	
public:
	board();
	void get_board();
	int check_fail(int type);
	int set_type_block();
	void you_fail();
	int random();
	int relocation_x(int x);
	int relocation_y(int y);
	void rotate(int type);
	void erase(block* a);
	int can_explode();//������ ���� 1 ������ ���� 0
	void explode_down();
};