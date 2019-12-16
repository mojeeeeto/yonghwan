#include "block_tree.h"
#include <ctime>
#include <iostream>
block_tree::block_tree()
{
	srand((unsigned int)time(0));
	this->a = new block();
	a->color = rand() % 4 + 1;

	a->x = 0;
	a->y = 2;
	this->b = new block();
	b->color = rand() % 4 + 1;

	b->x = 1;
	b->y = 2;
	this->c = new block();
	c->color = rand() % 4 + 1;

	c->x = 2;
	c->y = 2;
	mode = 0;
}

block* block_tree::get_a()
{
	return this->a;
}

block* block_tree::get_b()
{
	return this->b;
}

block* block_tree::get_c()
{
	return this->c;
}

int block_tree::get_mode()
{
	return this->mode;
}
void block_tree::inc_mode()
{
	int tmp = this->mode;
	tmp = (tmp + 1) % 4;
	this->mode = tmp;
}