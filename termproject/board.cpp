#include <ctime>
#include "block_cross.h"
board::board()
{
	score = 0;
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			gameboard[i][j] = new block();
		}
	}
}
int board::can_explode()
{
	int arr_x[4] = {-1,1,0,0};//상하좌우
	int arr_y[4] = {0,0,-1,1};//상하좌우
	int target_color = 0;//지울 색
	int check = 0;

	for (int i = 11; i > 0; i--)
	{
		for (int j = 0; j < 5; j++)
		{
			std::vector<block*> can_explode = {};
			std::vector<block*> member = {};
			int visited[12][5] = { 0 };
			target_color = gameboard[i][j]->color;
			if (gameboard[i][j]->color != 0 && gameboard[i][j]->color != 4)
			{
				can_explode.push_back(gameboard[i][j]);
				member.push_back(gameboard[i][j]);
				visited[i][j] = 1;
				while (can_explode.size())
				{
					block* tmp = can_explode.back();
					can_explode.pop_back();
					for (int k = 0; k < 4; k++)
					{
						
						int nx = board::relocation_x( tmp->x + arr_x[k]);
						int ny = board::relocation_y( tmp->y + arr_y[k]);
						if (visited[nx][ny] == 0 &&gameboard[nx][ny]->color == target_color)
						{
							can_explode.push_back(gameboard[nx][ny]);
							member.push_back(gameboard[nx][ny]);
							visited[nx][ny] = 1;
						}
					}
				}
			}
			if (member.size() >= 4)
			{
				
				for (int l = 0; l < member.size(); l++)
				{
					for (int m = 0; m < 4; m++)
					{
						int nx = board::relocation_x(member[l]->x - arr_x[m]);
						int ny = board::relocation_y(member[l]->y - arr_y[m]);
						if (gameboard[nx][ny]->color == 4)
						{
							gameboard[nx][ny]->color = 0;
						}
					}
					gameboard[member[l]->x][member[l]->y]->color = 0;
				}
				board::score++;
				check = 1;
				return check;
				break;
			}

		}
	}
	return check;
}
void board::explode_down()
{
	for (int i = 11; i > 0; i--)
	{
		for (int j = 0; j < 5; j++)
		{
			if (gameboard[i][j]->color == 0)
			{
				for (int k = i; k > 0; k--)
				{
					if (gameboard[k][j]->color != 0)
					{
						gameboard[i][j]->color = gameboard[k][j]->color;
						gameboard[k][j]->color = 0;
						break;
					}
				}
			}
		}
	}
}
void board::erase(block* a)
{
	this->gameboard[a->x][a->y] = new block();
}

int board::random()
{
	srand((unsigned int)time(0));
	return rand();
}

int board::set_type_block()
{
	return board::random() % 3 + 1;
}

void board::get_board()
{
	std::cout <<"  score : "<< this->score<< "\n" ;
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			std::cout <<"  "<< gameboard[i][j]->color<< "\t";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

int board::check_fail(int type)
{
	if (type == 1 &&
		(gameboard[0][2]->color != 0 ||
		gameboard[1][2]->color != 0 ||
		gameboard[1][1]->color != 0))
	{//fold
		return 0;
	}
	else if(type == 2 && 
		(gameboard[0][2]->color != 0 ||
		gameboard[1][2]->color != 0 ||
		gameboard[2][2]->color != 0 ||
		gameboard[1][1]->color != 0 ||
		gameboard[1][3]->color != 0))
	{//cross
		return 0;
	}
	else if(type == 3 && 
		(gameboard[0][2]->color != 0 ||
		gameboard[1][2]->color != 0 ||
		gameboard[2][2]->color != 0))
	{//tree
		return 0;
	}

	return 1;
}

void board::you_fail()
{
	std::cout << "score : " << this->score << "\n" << "G A M E  O V E R !! \n\n";
}

int board::relocation_x(int x)
{
	int re = x;
	if (0 > re)
	{
		re = 0;
	}
	else if (11 < re)
	{
		re = 11;
	}

	return re;
}
int board::relocation_y(int y)
{
	int re =y;
	if (0 > re)
	{
		re = 0;
	}
	else if (4 < re)
	{
		re = 4;
	}
	return re;
}
void board::rotate(int type)
{
	if (type == 1)
	{//fold
		block_fold* tmp = new block_fold;
		//최초
		block* a = tmp->get_a();
		block* b = tmp->get_b();
		block* c = tmp->get_c();
		this->gameboard[a->x][a->y] = a;
		this->gameboard[b->x][b->y] = b;
		this->gameboard[c->x][c->y] = c;
		this->get_board();
		int input;
		//이걸이제 움직여야지
		while (1)
		{
			this->erase(a);
			this->erase(b);
			this->erase(c);
			input = getchar();
			if (input ==97)
			{//좌
				if (tmp->get_mode() == 0)
				{
					if (gameboard[board::relocation_x(a->x)][board::relocation_y((a->y) - 1)]->color == 0 &&
						gameboard[board::relocation_x(b->x)][board::relocation_y((b->y) - 1)]->color == 0 &&
						!(b->y == 0))
					{
						a->y = board::relocation_y(a->y - 1);
						b->y = board::relocation_y(b->y - 1);
						c->y = board::relocation_y(c->y - 1);
					}
				}
				else if (tmp->get_mode() == 1)
				{
					if (gameboard[board::relocation_x(b->x)][board::relocation_y((b->y) - 1)]->color == 0 &&
						gameboard[board::relocation_x(c->x)][board::relocation_y((c->y) - 1)]->color == 0 &&
						!(b->y == 0 && c->y == 0))
					{
						a->y = board::relocation_y(a->y - 1);
						b->y = board::relocation_y(b->y - 1);
						c->y = board::relocation_y(c->y - 1);
					}

				}
				else if (tmp->get_mode() == 2)
				{
					if (gameboard[board::relocation_x(a->x)][board::relocation_y((a->y) - 1)]->color == 0 &&
						gameboard[board::relocation_x(c->x)][board::relocation_y((c->y) - 1)]->color == 0 &&
						!(a->y == 0))
					{
						a->y = board::relocation_y(a->y - 1);
						b->y = board::relocation_y(b->y - 1);
						c->y = board::relocation_y(c->y - 1);
					}

				}
				else if (tmp->get_mode() == 3)
				{
					if (gameboard[board::relocation_x(b->x)][board::relocation_y((b->y) - 1)]->color == 0 &&
						gameboard[board::relocation_x(c->x)][board::relocation_y((c->y) - 1)]->color == 0 &&
						!(a->y == 0))
					{
						a->y = board::relocation_y(a->y - 1);
						b->y = board::relocation_y(b->y - 1);
						c->y = board::relocation_y(c->y - 1);
					}

				}
				this->gameboard[a->x][a->y] = a;
				this->gameboard[b->x][b->y] = b;
				this->gameboard[c->x][c->y] = c;
				this->get_board();
			}
			else if (input == 100)
			{//우
				if (tmp->get_mode() == 0)
				{//ac
					if (gameboard[board::relocation_x(a->x)][board::relocation_y((a->y) + 1)]->color == 0 &&
						gameboard[board::relocation_x(c->x)][board::relocation_y((c->y) + 1)]->color == 0 &&
						!(a->y == 4 && c->y == 4))
					{
						a->y = board::relocation_y(a->y + 1);
						b->y = board::relocation_y(b->y + 1);
						c->y = board::relocation_y(c->y + 1);
					}
				}
				else if (tmp->get_mode() == 1)
				{//ab
					if (gameboard[board::relocation_x(a->x)][board::relocation_y((a->y) + 1)]->color == 0 &&
						gameboard[board::relocation_x(b->x)][board::relocation_y((b->y) + 1)]->color == 0 &&
						!(a->y == 4 && b->y == 3))
					{
						a->y = board::relocation_y(a->y + 1);
						b->y = board::relocation_y(b->y + 1);
						c->y = board::relocation_y(c->y + 1);
					}
				}
				else if (tmp->get_mode() == 2)
				{//ab
					if (gameboard[board::relocation_x(a->x)][board::relocation_y((a->y) + 1)]->color == 0 &&
						gameboard[board::relocation_x(b->x)][board::relocation_y((b->y) + 1)]->color == 0 &&
						!(a->y == 3 && b->y == 4))
					{
						a->y = board::relocation_y(a->y + 1);
						b->y = board::relocation_y(b->y + 1);
						c->y = board::relocation_y(c->y + 1);
					}
				}
				else if (tmp->get_mode() == 3)
				{
					if (gameboard[board::relocation_x(c->x)][board::relocation_y((c->y) + 1)]->color == 0 &&
						gameboard[board::relocation_x(b->x)][board::relocation_y((b->y) + 1)]->color == 0 &&
						!(c->y == 4 && b->y == 4))
					{
						a->y = board::relocation_y(a->y + 1);
						b->y = board::relocation_y(b->y + 1);
						c->y = board::relocation_y(c->y + 1);
					}
				}
				this->gameboard[a->x][a->y] = a;
				this->gameboard[b->x][b->y] = b;
				this->gameboard[c->x][c->y] = c;
				this->get_board();
			}
			else if (input == 115)
			{//하
				if (tmp->get_mode() == 0)
				{
					if (gameboard[board::relocation_x((b->x) + 1)][board::relocation_y((b->y))]->color == 0 &&
						gameboard[board::relocation_x((c->x) + 1)][board::relocation_y((c->y))]->color == 0 &&
						!(b->x == 11))
					{
						a->x = board::relocation_x(a->x + 1);
						b->x = board::relocation_x(b->x + 1);
						c->x = board::relocation_x(c->x + 1);
					}
					else
					{
						for (int i = 0; i < 12; i++)
						{
							if (gameboard[board::relocation_x((b->x) + 1)][b->y]->color == 0)
							{
								b->x = board::relocation_x(b->x + 1);
							}
						}
						for (int i = 0; i < 12; i++)
						{
							if (gameboard[board::relocation_x((c->x) + 1)][c->y]->color == 0 && (c->x < 11))
							{
								c->x = board::relocation_x(c->x + 1);
							}
						}
						a->x = (c->x) - 1;
						this->gameboard[a->x][a->y] = a;
						this->gameboard[b->x][b->y] = b;
						this->gameboard[c->x][c->y] = c;
						this->get_board();
						break;
					}
				}
				else if (tmp->get_mode() == 1)
				{
					if (gameboard[board::relocation_x((a->x) + 1)][board::relocation_y((a->y))]->color == 0 &&
						gameboard[board::relocation_x((c->x) + 1)][board::relocation_y((c->y))]->color == 0 &&
						!(a->x == 11))
					{
						a->x = board::relocation_x(a->x + 1);
						b->x = board::relocation_x(b->x + 1);
						c->x = board::relocation_x(c->x + 1);
					}
					else
					{
						for (int i = 0; i < 12; i++)
						{
							if (gameboard[board::relocation_x((a->x) + 1)][a->y]->color == 0 && (a->x < 11))
							{
								a->x = board::relocation_x(a->x + 1);
							}
						}
						for (int i = 0; i < 12; i++)
						{
							if (gameboard[board::relocation_x((c->x) + 1)][c->y]->color == 0 && (c->x < 11))
							{
								c->x = board::relocation_x(c->x + 1);
							}
						}
						b->x = (c->x) - 1;
						this->gameboard[a->x][a->y] = a;
						this->gameboard[b->x][b->y] = b;
						this->gameboard[c->x][c->y] = c;
						this->get_board();
						break;
					}
				}
				else if (tmp->get_mode() == 2)
				{
					if (gameboard[board::relocation_x((a->x) + 1)][board::relocation_y((a->y))]->color == 0 &&
						gameboard[board::relocation_x((b->x) + 1)][board::relocation_y((b->y))]->color == 0 &&
						!(a->x == 11))
					{
						a->x = board::relocation_x(a->x + 1);
						b->x = board::relocation_x(b->x + 1);
						c->x = board::relocation_x(c->x + 1);
					}
					else
					{
						for (int i = 0; i < 12; i++)
						{
							if (gameboard[board::relocation_x((a->x) + 1)][a->y]->color == 0 && (a->x < 11))
							{
								a->x = board::relocation_x(a->x + 1);
							}
						}
						for (int i = 0; i < 12; i++)
						{
							if (gameboard[board::relocation_x((b->x) + 1)][b->y]->color == 0 && (b->x < 11))
							{
								b->x = board::relocation_x(b->x + 1);
							}
						}
						c->x = (a->x) - 1;
						this->gameboard[a->x][a->y] = a;
						this->gameboard[b->x][b->y] = b;
						this->gameboard[c->x][c->y] = c;
						this->get_board();
						break;
					}
				}
				else if (tmp->get_mode() == 3)
				{
					if (gameboard[board::relocation_x((a->x) + 1)][board::relocation_y((a->y))]->color == 0 &&
						gameboard[board::relocation_x((b->x) + 1)][board::relocation_y((b->y))]->color == 0 &&
						!(b->x == 11))
					{
						a->x = board::relocation_x(a->x + 1);
						b->x = board::relocation_x(b->x + 1);
						c->x = board::relocation_x(c->x + 1);
					}
					else
					{
						for (int i = 0; i < 12; i++)
						{
							if (gameboard[board::relocation_x((a->x) + 1)][a->y]->color == 0 && (a->x < 11))
							{
								a->x = board::relocation_x(a->x + 1);
							}
						}
						for (int i = 0; i < 12; i++)
						{
							if (gameboard[board::relocation_x((b->x) + 1)][b->y]->color == 0 && (b->x < 11))
							{
								b->x = board::relocation_x(b->x + 1);
							}
						}
						c->x = (b->x) - 1;
						this->gameboard[a->x][a->y] = a;
						this->gameboard[b->x][b->y] = b;
						this->gameboard[c->x][c->y] = c;
						this->get_board();
						break;
					}
				}
				this->gameboard[a->x][a->y] = a;
				this->gameboard[b->x][b->y] = b;
				this->gameboard[c->x][c->y] = c;
				this->get_board();
			}
			else if (input == 120)
			{//끝까지
				if (tmp->get_mode() == 0)
				{
					for (int i = 0; i < 12; i++)
					{
						if (gameboard[board::relocation_x((b->x) + 1)][b->y]->color == 0 && (b->x < 11))
						{
							b->x = board::relocation_x(b->x + 1);
						}
					}
					for (int i = 0; i < 12; i++)
					{
						if (gameboard[board::relocation_x((c->x) + 1)][c->y]->color == 0 && (c->x < 11))
						{
							c->x = board::relocation_x(c->x + 1);
						}
					}
					a->x = (c->x) - 1;
				}
				else if (tmp->get_mode() == 1)
				{
					for (int i = 0; i < 12; i++)
					{
						if (gameboard[board::relocation_x((a->x) + 1)][a->y]->color == 0 && (a->x < 11))
						{
							a->x = board::relocation_x(a->x + 1);
						}
					}
					for (int i = 0; i < 12; i++)
					{
						if (gameboard[board::relocation_x((c->x) + 1)][c->y]->color == 0 && (c->x < 11))
						{
							c->x = board::relocation_x(c->x + 1);
						}
					}
					b->x = (c->x) - 1;
				}
				else if (tmp->get_mode() == 2)
				{
					for (int i = 0; i < 12; i++)
					{
						if (gameboard[board::relocation_x((a->x) + 1)][a->y]->color == 0 && (a->x < 11))
						{
							a->x = board::relocation_x(a->x + 1);
						}
					}
					for (int i = 0; i < 12; i++)
					{
						if (gameboard[board::relocation_x((b->x) + 1)][b->y]->color == 0 && (b->x < 11))
						{
							b->x = board::relocation_x(b->x + 1);
						}
					}
					c->x = (a->x) - 1;
				}
				else if (tmp->get_mode() == 3)
				{
					for (int i = 0; i < 12; i++)
					{
						if (gameboard[board::relocation_x((a->x) + 1)][a->y]->color == 0 && (a->x < 11))
						{
							a->x = board::relocation_x(a->x + 1);
						}
					}
					for (int i = 0; i < 12; i++)
					{
						if (gameboard[board::relocation_x((b->x) + 1)][b->y]->color == 0 && (b->x < 11))
						{
							b->x = board::relocation_x(b->x + 1);
						}
					}
					c->x = (b->x) - 1;
				}
				this->gameboard[a->x][a->y] = a;
				this->gameboard[b->x][b->y] = b;
				this->gameboard[c->x][c->y] = c;
				this->get_board();
				break;
			}
			else if (input == 101)
			{//회전
				if (tmp->get_mode() == 0 && gameboard[a->x][a->y - 1]->color == 0)
				{
					a->x = board::relocation_x(a->x + 1);
					b->x = board::relocation_x(b->x - 1);
					c->y = board::relocation_y(c->y - 1);
					tmp->inc_mode();
				}
				else if (tmp->get_mode() == 1 && gameboard[b->x][b->y + 1]->color == 0)
				{
					a->y = board::relocation_y(a->y - 1);
					b->y = board::relocation_y(b->y + 1);
					c->x = board::relocation_x(c->x - 1);
					tmp->inc_mode();
				}
				else if (tmp->get_mode() == 2 && gameboard[a->x][a->y + 1]->color == 0)
				{
					a->x = board::relocation_x(a->x - 1);
					b->x = board::relocation_x(b->x + 1);
					c->y = board::relocation_y(c->y + 1);
					tmp->inc_mode();
				}
				else if(tmp->get_mode() == 3 && gameboard[b->x][b->y - 1]->color == 0)
				{
					a->y = board::relocation_y(a->y + 1);
					b->y = board::relocation_y(b->y - 1);
					c->x = board::relocation_x(c->x + 1);
					tmp->inc_mode();
				}
				this->gameboard[a->x][a->y] = a;
				this->gameboard[b->x][b->y] = b;
				this->gameboard[c->x][c->y] = c;
				this->get_board();
			}
		}
	}
	if (type == 2)
	{//cross	
		block_cross* tmp = new block_cross;
		block* a = tmp->get_a();
		block* b = tmp->get_b();
		block* c = tmp->get_c();
		block* d = tmp->get_d();
		block* e = tmp->get_e();
		this->gameboard[a->x][a->y] = a;
		this->gameboard[b->x][b->y] = b;
		this->gameboard[c->x][c->y] = c;
		this->gameboard[d->x][d->y] = d;
		this->gameboard[e->x][e->y] = e;
		this->get_board();
		while (1)
		{
			this->erase(a);
			this->erase(b);
			this->erase(c);
			this->erase(d);
			this->erase(e);
			int input = getchar();
			if (input == 97)
			{//좌
				if (gameboard[board::relocation_x(a->x)][board::relocation_y((a->y) - 1)]->color == 0 &&
					gameboard[board::relocation_x(b->x)][board::relocation_y((b->y) - 1)]->color == 0 &&
					gameboard[board::relocation_x(e->x)][board::relocation_y((e->y) - 1)]->color == 0 &&
					!(b->y == 0))
				{
					a->y = board::relocation_y(a->y - 1);
					b->y = board::relocation_y(b->y - 1);
					c->y = board::relocation_y(c->y - 1);
					d->y = board::relocation_y(d->y - 1);
					e->y = board::relocation_y(e->y - 1);
				}
				this->gameboard[a->x][a->y] = a;
				this->gameboard[b->x][b->y] = b;
				this->gameboard[c->x][c->y] = c;
				this->gameboard[d->x][d->y] = d;
				this->gameboard[e->x][e->y] = e;
				this->get_board();
			}
			else if (input == 100)
			{//우
				if (gameboard[board::relocation_x(a->x)][board::relocation_y((a->y) + 1)]->color == 0 &&
					gameboard[board::relocation_x(d->x)][board::relocation_y((d->y) + 1)]->color == 0 &&
					gameboard[board::relocation_x(e->x)][board::relocation_y((e->y) + 1)]->color == 0 &&
					!(d->y == 4))
				{
					a->y = board::relocation_y(a->y + 1);
					b->y = board::relocation_y(b->y + 1);
					c->y = board::relocation_y(c->y + 1);
					d->y = board::relocation_y(d->y + 1);
					e->y = board::relocation_y(e->y + 1);
				}
				this->gameboard[a->x][a->y] = a;
				this->gameboard[b->x][b->y] = b;
				this->gameboard[c->x][c->y] = c;
				this->gameboard[d->x][d->y] = d;
				this->gameboard[e->x][e->y] = e;
				this->get_board();
			}
			else if (input == 115)
			{//하
				if (gameboard[board::relocation_x((b->x)+1)][board::relocation_y(b->y) ]->color == 0 &&
					gameboard[board::relocation_x((d->x)+1)][board::relocation_y(d->y) ]->color == 0 &&
					gameboard[board::relocation_x((e->x)+1)][board::relocation_y(e->y) ]->color == 0 &&
					!(e->x == 11))
				{
					a->x = board::relocation_x(a->x + 1);
					b->x = board::relocation_x(b->x + 1);
					c->x = board::relocation_x(c->x + 1);
					d->x = board::relocation_x(d->x + 1);
					e->x = board::relocation_x(e->x + 1);
				}
				else
				{//끝까지 내려갔을경우
					for (int i = 0; i < 12; i++)
					{
						if (gameboard[board::relocation_x((b->x) + 1)][b->y]->color == 0)
						{
							b->x = board::relocation_x(b->x + 1);
						}
					}
					for (int i = 0; i < 12; i++)
					{
						if (gameboard[board::relocation_x((e->x) + 1)][e->y]->color == 0 && (e->x < 11))
						{
							e->x = board::relocation_x(e->x + 1);
						}
					}
					for (int i = 0; i < 12; i++)
					{
						if (gameboard[board::relocation_x((d->x) + 1)][d->y]->color == 0 && (d->x < 11))
						{
							d->x = board::relocation_x(d->x + 1);
						}
					}
					c->x = (e->x) - 1;
					a->x = (e->x) - 2;
					this->gameboard[a->x][a->y] = a;
					this->gameboard[b->x][b->y] = b;
					this->gameboard[c->x][c->y] = c;
					this->gameboard[d->x][d->y] = d;
					this->gameboard[e->x][e->y] = e;
					this->get_board();
					break;
				}
				this->gameboard[a->x][a->y] = a;
				this->gameboard[b->x][b->y] = b;
				this->gameboard[c->x][c->y] = c;
				this->gameboard[d->x][d->y] = d;
				this->gameboard[e->x][e->y] = e;
				this->get_board();
			}
			else if (input == 120)
			{//끝까지
				for (int i = 0; i < 12; i++)
				{
					if (gameboard[board::relocation_x((b->x) + 1)][b->y]->color == 0)
					{
						b->x = board::relocation_x(b->x + 1);
					}
				}
				for (int i = 0; i < 12; i++)
				{
					if (gameboard[board::relocation_x((e->x) + 1)][e->y]->color == 0 && (e->x < 11))
					{
						e->x = board::relocation_x(e->x + 1);
					}
				}
				for (int i = 0; i < 12; i++)
				{
					if (gameboard[board::relocation_x((d->x) + 1)][d->y]->color == 0 && (d->x < 11))
					{
						d->x = board::relocation_x(d->x + 1);
					}
				}
				c->x = (e->x) - 1;
				a->x = (e->x) - 2;
				this->gameboard[a->x][a->y] = a;
				this->gameboard[b->x][b->y] = b;
				this->gameboard[c->x][c->y] = c;
				this->gameboard[d->x][d->y] = d;
				this->gameboard[e->x][e->y] = e;
				this->get_board();
				break;
			}
			else if (input == 101)
			{//회전

				int tmp_a = a->color;
				int tmp_b = b->color;
				int tmp_d = d->color;
				int tmp_e = e->color;
				a->color = tmp_b;
				b->color = tmp_e;
				d->color = tmp_a;
				e->color = tmp_d;
				this->gameboard[a->x][a->y] = a;
				this->gameboard[b->x][b->y] = b;
				this->gameboard[c->x][c->y] = c;
				this->gameboard[d->x][d->y] = d;
				this->gameboard[e->x][e->y] = e;
				this->get_board();
			}
		}
	}	
	if (type ==3)
	{//tree
		block_tree* tmp = new block_tree;
		//최초
		block* a = tmp->get_a();
		block* b = tmp->get_b();
		block* c = tmp->get_c();
		this->gameboard[a->x][a->y] = a;
		this->gameboard[b->x][b->y] = b;
		this->gameboard[c->x][c->y] = c;
		this->get_board();
		//이걸이제 움직여야지
		while (1)
		{
			int input = getchar();
			this->erase(a);
			this->erase(b);
			this->erase(c);
			if (input == 97)
			{//좌
				if (tmp->get_mode() == 0 || tmp->get_mode() == 2)
				{
					if (gameboard[board::relocation_x(a->x)][board::relocation_y((a->y) - 1)]->color == 0 &&
						gameboard[board::relocation_x(b->x)][board::relocation_y((b->y) - 1)]->color == 0 &&
						gameboard[board::relocation_x(c->x)][board::relocation_y((c->y) - 1)]->color == 0 && 
						!(a->y == 0&&b->y==0&&c->y==0))
					{
						a->y = board::relocation_y(a->y - 1);
						b->y = board::relocation_y(b->y - 1);
						c->y = board::relocation_y(c->y - 1);
					}
				}
				else if(tmp->get_mode() == 1 || tmp->get_mode() == 3)
				{
					if (tmp->get_mode()==1 && gameboard[board::relocation_x(c->x)][board::relocation_y((c->y) - 1)]->color == 0 && !(c->y==0))
					{
						a->y = board::relocation_y(a->y - 1);
						b->y = board::relocation_y(b->y - 1);
						c->y = board::relocation_y(c->y - 1);
					}
					else  if(tmp->get_mode() == 3 && gameboard[board::relocation_x(a->x)][board::relocation_y((a->y) - 1)]->color == 0 && !(a->y == 0))
					{
						a->y = board::relocation_y(a->y - 1);
						b->y = board::relocation_y(b->y - 1);
						c->y = board::relocation_y(c->y - 1);
					}
				}
				this->gameboard[a->x][a->y] = a;
				this->gameboard[b->x][b->y] = b;
				this->gameboard[c->x][c->y] = c;
				this->get_board();
			}
			else if (input == 100)
			{//우
				if (tmp->get_mode() == 0 || tmp->get_mode ()== 2)
				{
					if (gameboard[board::relocation_x(a->x)][board::relocation_y((a->y) + 1)]->color == 0 &&
						gameboard[board::relocation_x(b->x)][board::relocation_y((b->y) + 1)]->color == 0 &&
						gameboard[board::relocation_x(c->x)][board::relocation_y((c->y) + 1)]->color == 0 &&
						!(a->y == 4 && b->y == 4 && c->y == 4))
					{
						a->y = board::relocation_y(a->y + 1);
						b->y = board::relocation_y(b->y + 1);
						c->y = board::relocation_y(c->y + 1);
					}
				}
				else
				{
					if (tmp->get_mode() == 1 && gameboard[board::relocation_x(a->x)][board::relocation_y((a->y) + 1)]->color == 0 && !(a->y == 4))
					{
						a->y = board::relocation_y(a->y + 1);
						b->y = board::relocation_y(b->y + 1);
						c->y = board::relocation_y(c->y + 1);
					}
					else  if (tmp->get_mode() == 3 && gameboard[board::relocation_x(c->x)][board::relocation_y((c->y) + 1)]->color == 0 && !(c->y == 4))

					{
						a->y = board::relocation_y(a->y + 1);
						b->y = board::relocation_y(b->y + 1);
						c->y = board::relocation_y(c->y + 1);
					}
				}
				this->gameboard[a->x][a->y] = a;
				this->gameboard[b->x][b->y] = b;
				this->gameboard[c->x][c->y] = c;
				this->get_board();
			}
			else if (input == 115)
			{//하
				if (tmp->get_mode() == 0 || tmp->get_mode() == 2)
				{
					if (tmp->get_mode() ==0 &&gameboard[board::relocation_x((c->x) + 1)][board::relocation_y(c->y)]->color == 0 &&!(c->x == 11))
					{
						a->x = board::relocation_x(a->x + 1);
						b->x = board::relocation_x(b->x + 1);
						c->x = board::relocation_x(c->x + 1);
					}
					else if(tmp->get_mode() == 2 && gameboard[board::relocation_x((a->x) + 1)][board::relocation_y(a->y)]->color == 0 && !(a->x == 11))
					{
						a->x = board::relocation_x(a->x + 1);
						b->x = board::relocation_x(b->x + 1);
						c->x = board::relocation_x(c->x + 1);
					}
					else
					{
						this->gameboard[a->x][a->y] = a;
						this->gameboard[b->x][b->y] = b;
						this->gameboard[c->x][c->y] = c;
						this->get_board();
						break;
					}
				}
				else if(tmp->get_mode() == 1 || tmp->get_mode() == 3)
				{
					if (tmp->get_mode() == 1 && 
						gameboard[board::relocation_x((a->x) + 1)][board::relocation_y(a->y)]->color == 0 &&
						gameboard[board::relocation_x((b->x) + 1)][board::relocation_y(b->y)]->color == 0 &&
						gameboard[board::relocation_x((c->x) + 1)][board::relocation_y(c->y)]->color == 0 &&
						!(c->x == 11&&a->x == 11&& b->x==11))
					{
						a->x = board::relocation_x(a->x + 1);
						b->x = board::relocation_x(b->x + 1);
						c->x = board::relocation_x(c->x + 1);
					}
					else if (tmp->get_mode() == 3 &&
						gameboard[board::relocation_x((a->x) + 1)][board::relocation_y(a->y)]->color == 0 &&
						gameboard[board::relocation_x((b->x) + 1)][board::relocation_y(b->y)]->color == 0 &&
						gameboard[board::relocation_x((c->x) + 1)][board::relocation_y(c->y)]->color == 0 &&
						!(c->x == 11 && a->x == 11 && b->x == 11))
					{
						a->x = board::relocation_x(a->x + 1);
						b->x = board::relocation_x(b->x + 1);
						c->x = board::relocation_x(c->x + 1);
					}
					else
					{
						for (int i = 0; i < 12; i++)
						{
							if (gameboard[board::relocation_x((a->x) + 1)][a->y]->color == 0 && (a->x < 11))
							{
								a->x = board::relocation_x(a->x + 1);
							}
						}
						for (int i = 0; i < 12; i++)
						{
							if (gameboard[board::relocation_x((b->x) + 1)][b->y]->color == 0 && (b->x < 11))
							{
								b->x = board::relocation_x(b->x + 1);
							}
						}
						for (int i = 0; i < 12; i++)
						{
							if (gameboard[board::relocation_x((c->x) + 1)][c->y]->color == 0 && (c->x < 11))
							{
								c->x = board::relocation_x(c->x + 1);
							}
						}
						this->gameboard[a->x][a->y] = a;
						this->gameboard[b->x][b->y] = b;
						this->gameboard[c->x][c->y] = c;
						this->get_board();
						break;
					}
				}
				this->gameboard[a->x][a->y] = a;
				this->gameboard[b->x][b->y] = b;
				this->gameboard[c->x][c->y] = c;
				this->get_board();
			}
			else if (input == 120)
			{//끝까지
				if (tmp->get_mode() == 0 || tmp->get_mode() == 2)
				{
					if (tmp->get_mode() == 0)
					{
						for (int i = 0; i < 12; i++)
						{
							if (gameboard[board::relocation_x((c->x) + 1)][c->y]->color == 0 && (c->x < 11))
							{
								c->x = board::relocation_x(c->x + 1);
							}
						}
						b->x = c->x - 1;
						a->x = c->x - 2;
					}
					else
					{
						for (int i = 0; i < 12; i++)
						{
							if (gameboard[board::relocation_x((a->x) + 1)][a->y]->color == 0 && (a->x < 11))
							{
								a->x = board::relocation_x(a->x + 1);
							}
						}
						b->x = a->x - 1;
						c->x = a->x - 2;
					}
					
				}
				else
				{
					for (int i = 0; i < 12; i++)
					{
						if (gameboard[board::relocation_x((a->x) + 1)][a->y]->color == 0 && (a->x < 11))
						{
							a->x = board::relocation_x(a->x + 1);
						}
					}
					for (int i = 0; i < 12; i++)
					{
						if (gameboard[board::relocation_x((b->x) + 1)][b->y]->color == 0 && (b->x < 11))
						{
							b->x = board::relocation_x(b->x + 1);
						}
					}
					for (int i = 0; i < 12; i++)
					{
						if (gameboard[board::relocation_x((c->x) + 1)][c->y]->color == 0 && (c->x < 11))
						{
							c->x = board::relocation_x(c->x + 1);
						}
					}

				}
				this->gameboard[a->x][a->y] = a;
				this->gameboard[b->x][b->y] = b;
				this->gameboard[c->x][c->y] = c;
				this->get_board();
				break;
			}
			else if (input == 101)
			{//회전
				if (tmp->get_mode() == 0 && gameboard[b->x][b->y+1]->color ==0 && gameboard[b->x][b->y - 1]->color == 0)
				{
						if (b->y == 4)
						{
							a->x = b->x;
							a->y = b->y;
							b->y = b->y - 1;
							c->x = b->x;
							c->y = b->y - 1;
							tmp->inc_mode();
						}
						else if(b->y ==0)
						{
							c->x = b->x;
							c->y = b->y;
							b->y = b->y + 1;
							a->x = b->x;
							a->y = b->y + 1;
							tmp->inc_mode();
						}
						else
						{
							a->x = b->x;
							a->y = b->y + 1;
							c->x = b->x;
							c->y = b->y - 1;
							tmp->inc_mode();
						}
				}
				else if (tmp->get_mode() == 2 && gameboard[b->x][b->y + 1]->color == 0 && gameboard[b->x][b->y - 1]->color == 0)
				{
					if (b->y == 4)
					{
						c->x = b->x;
						c->y = b->y;
						b->y = b->y - 1;
						a->x = b->x;
						a->y = b->y - 1;
						tmp->inc_mode();
					}
					else if (b->y == 0)
					{
						a->x = b->x;
						a->y = b->y;
						b->y = b->y + 1;
						c->x = b->x;
						c->y = b->y + 1;
						tmp->inc_mode();
					}
					else
					{
						c->x = b->x;
						c->y = b->y + 1;
						a->x = b->x;
						a->y = b->y - 1;
						tmp->inc_mode();
					}
				}
				else if ((tmp->get_mode() == 1 || tmp->get_mode() == 3 )&& gameboard[b->x+1][b->y]->color==0 && gameboard[b->x - 1][b->y]->color == 0)
				{
					if (tmp->get_mode() == 1)
					{
						a->x = b->x+1;
						c->x = b->x - 1;
						a->y = b->y;
						c->y = b->y;
						tmp->inc_mode();
					}
					else
					{
						a->x = b->x - 1;
						c->x = b->x + 1;
						a->y = b->y;
						c->y = b->y;
						tmp->inc_mode();
					}
				}
				this->gameboard[a->x][a->y] = a;
				this->gameboard[b->x][b->y] = b;
				this->gameboard[c->x][c->y] = c;
				this->get_board();
			}
		}
	}
}