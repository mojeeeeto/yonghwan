#include "block_cross.h"
#include <ctime>
#include <iostream>

block_cross::block_cross()
{
	srand((unsigned int)time(0));
	this->a = new block();
	a->color = rand() % 4 + 1;

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
	this->d = new block();
	d->color = rand() % 4 + 1;

	d->x = 1;
	d->y = 3;
	this->e = new block();
	e->color = rand() % 4 + 1;

	e->x = 2;
	e->y = 2;

}

block* block_cross::get_a()
{
	return this->a;
}

block* block_cross::get_b()
{
	return this->b;
}

block* block_cross::get_c()
{
	return this->c;
}

block* block_cross::get_d()
{
	return this->d;
}

block* block_cross::get_e()
{
	return this->e;
}
