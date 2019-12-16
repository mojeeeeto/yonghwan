#include "board.h"
int main()
{
	//init
	board* game = new board();
	int fail = 1;
	int block_type=0;
	int erase = 0;
	while (fail)
	{

		block_type = game->set_type_block(); //무슨 블럭이 나올지 결정
		fail = game->check_fail(block_type);//생성 가능 여부
		if (fail == 0)
		{//생성불가
			game->you_fail();//출력
			break;
		}
		game->rotate(block_type);
		while (1)
		{
			erase = game->can_explode();
			game->explode_down();
			if (erase == 0)
			{
				break;
			}
		}
	}
	
}