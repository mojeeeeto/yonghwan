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

		block_type = game->set_type_block(); //���� ���� ������ ����
		fail = game->check_fail(block_type);//���� ���� ����
		if (fail == 0)
		{//�����Ұ�
			game->you_fail();//���
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