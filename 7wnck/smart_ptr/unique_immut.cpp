//
// Created by 김혁진 on 14/10/2019.
//

#include "unique_immut.h"

namespace ptr {
unique_immut::unique_immut() {
    _mgr = new mgr();
}

unique_immut::unique_immut(Object *obj) {
    _mgr = new mgr(obj);
}

unique_immut::unique_immut(const unique_immut &immut) {
    if (immut._mgr) {
        int val = immut._mgr->ptr->get();
        _mgr = new mgr(val);
    }
}

unique_immut::~unique_immut() {
    release();
}

void unique_immut::release()
{
	if (this->_mgr->ptr != nullptr)
	{
		this->_mgr->~mgr();
	}
}
Object* unique_immut::get() const
{
	return _mgr->ptr;
}

unique_immut unique_immut::operator+(unique_immut &unique)
{
	int a = this->_mgr->ptr->get();
	this->_mgr->ptr->~Object();
	this->_mgr->ptr = nullptr;
	int b = unique._mgr->ptr->get();
	unique._mgr->ptr->~Object();
	unique._mgr->ptr = nullptr;

	return unique_immut(new Object(a + b));
}
unique_immut unique_immut::operator-(unique_immut &unique)
{
	int a = this->_mgr->ptr->get();
	this->_mgr->ptr->~Object();
	this->_mgr->ptr = nullptr;
	int b = unique._mgr->ptr->get();
	unique._mgr->ptr->~Object();
	unique._mgr->ptr = nullptr;
	return unique_immut(new Object(a - b));
}
unique_immut unique_immut::operator*(unique_immut &unique)
{
	int a = this->_mgr->ptr->get();
	this->_mgr->ptr->~Object();
	this->_mgr->ptr = nullptr;
	int b = unique._mgr->ptr->get();
	unique._mgr->ptr->~Object();
	unique._mgr->ptr = nullptr;
	return unique_immut(new Object(a * b));

}
unique_immut unique_immut::operator/(unique_immut &unique)
{
	int a = this->_mgr->ptr->get();
	this->_mgr->ptr->~Object();
	this->_mgr->ptr = nullptr;
	int b = unique._mgr->ptr->get();
	unique._mgr->ptr->~Object();
	unique._mgr->ptr = nullptr;
	return unique_immut(new Object(a / b));
}
Object* unique_immut::operator->()
{
	return _mgr->ptr;
}

unique_immut& unique_immut::operator=(unique_immut& r)
{
	if (this->_mgr->ptr->get() == r._mgr->ptr->get())
	{
		return *this;
	}
	else
	{
		this->_mgr->~mgr();
		this->_mgr = r._mgr;
		return *this;
	}
}
} // end of namespace ptr
