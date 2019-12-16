#include "block_fold.h"
#include <ctime>
#include <iostream>
block_fold::block_fold()
{
	srand((unsigned int)time(0));
	this->a = new block();
	a->color =  rand()% 4 + 1;

	a->x = 0;
	a->y = 2;
	this->b = new block();
	b->color = rand() % 4 + 1;

	b->x = 1;
	b->y = 1;
	this->c = new block();
	c->color = rand() % 4 + 1;

	c->x = 1;
	c->y = 2;
	mode = 0;
}

block* block_fold::get_a()
{
	return this->a;
}

block* block_fold::get_b()
{
	return this->b;
}

block* block_fold::get_c()
{
	return this->c;
}

int block_fold::get_mode()
{
	return mode;
}
void block_fold::inc_mode()
{
	int tmp = this->mode;
	tmp = (tmp + 1) % 4;
	this->mode = tmp;
}
