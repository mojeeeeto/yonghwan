//
// Created by 김혁진 on 14/10/2019.
//

#include "shared_mut.h"

namespace ptr {
shared_mut::shared_mut() {
    _mgr = new mgr();
}

shared_mut::shared_mut(Object* _obj) {
    _mgr = new mgr(_obj);
}

void shared_mut::increase() {
	_mgr->count++;
}



shared_mut::~shared_mut() {
    release();
}

Object* shared_mut::get() const {

	return this->_mgr->ptr;
}

Object* shared_mut::operator->()
{
	return _mgr->ptr;
}

void shared_mut::release() {
	
	this->_mgr->count--;
	if (_mgr->count == 0)
	{
		delete(this->_mgr);
	}
	
}

int shared_mut::count() {
	return _mgr->count;
}



shared_mut shared_mut::operator+(const shared_mut &shared) {
	int b = shared._mgr->ptr->get();
	int a = this->_mgr->ptr->get();
	return shared_mut(new Object(a+b));
}	
shared_mut shared_mut::operator-(const shared_mut &shared) {
	
	int a = this->_mgr->ptr->get();
	int b = shared._mgr->ptr->get();
	shared_mut ii(new Object(a - b));
	return ii;
}

shared_mut shared_mut::operator*(const shared_mut &shared)
{
	int a = this->_mgr->ptr->get();
	int b = shared._mgr->ptr->get();
	shared_mut ii(new Object(a * b));
	return ii;
}

shared_mut shared_mut::operator/(const shared_mut &shared)
{
	int a = this->_mgr->ptr->get();
	int b = shared._mgr->ptr->get();
	shared_mut ii(new Object(a * b));
	return ii;
}

shared_mut shared_mut::operator+(unique_immut &unique)
{
	int a = this->_mgr->ptr->get();
	Object* bb = unique.get();
	int b = bb->get();
	unique.~unique_immut();
	return shared_mut(new Object(a + b));
}
shared_mut shared_mut::operator-(unique_immut &unique)
{
	int a = this->_mgr->ptr->get();
	Object* bb = unique.get();
	int b = bb->get();
	unique.~unique_immut();
	return shared_mut(new Object(a - b));
}
shared_mut shared_mut::operator*(unique_immut &unique)
{
	int a = this->_mgr->ptr->get();
	Object* bb = unique.get();
	int b = bb->get();
	unique.~unique_immut();
	return shared_mut(new Object(a * b));
}
shared_mut shared_mut::operator/(unique_immut &unique)
{
	int a = this->_mgr->ptr->get();
	Object* bb = unique.get();
	int b = bb->get();
	unique.~unique_immut();
	return shared_mut(new Object(a / b));
}

shared_mut& shared_mut::operator= (const shared_mut &r)
{
	this->_mgr = r._mgr;
	this->increase();
	return *this;
}

shared_mut& shared_mut::operator=(unique_immut &r)
{
	this->_mgr->ptr = r.get();
	this->increase();
	r.~unique_immut();
	return *this;
}



} // end of namespace ptr
