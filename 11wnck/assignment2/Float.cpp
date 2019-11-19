//
// Created by 김혁진 on 2019/11/11.
//

#include "Float.h"
#include "Integer.h"
#include "Complex.h"

double Float::parse_string(std::string str) {
    double result = atof(str.c_str());
    return result;
}

Float::Float() {
	this->value = 0;
}

Float::Float(double _value) {
	this->value = _value;
}

Float::Float(const std::string& str) {
	this->value = parse_string(str);
}

Number *Float::add(Number * num) {
	if (num->types() == INTEGER)
	{
		Integer* other = dynamic_cast<Integer*>(num);
		this->set_val(this->val() + other->val());
		delete(other);
		return this;
	}
	else if (num->types() == FLOAT)
	{
		Float* other = dynamic_cast<Float*>(num);
		other->set_val(this->val() + other->val());
		delete(this);
		return other;
	}
	else if (num->types() == COMPLEX)
	{
		Complex* other = dynamic_cast<Complex*>(num);
		other->set_val(other->val().first + this->val(), other->val().second);
		delete(this);
		return other;
	}
    return nullptr;
}

Number *Float::sub(Number * num) {
	if (num->types() == INTEGER)
	{
		Integer* other = dynamic_cast<Integer*>(num);
		this->set_val(this->val() - other->val());
		delete(other);
		return this;
	}
	else if (num->types() == FLOAT)
	{
		Float* other = dynamic_cast<Float*>(num);
		other->set_val(this->val() - other->val());
		delete(this);
		return other;
	}
	else if (num->types() == COMPLEX)
	{
		Complex* other = dynamic_cast<Complex*>(num);
		other->set_val(this->val() - other->val().first, other->val().second);
		delete(this);
		return other;
	}
	return nullptr;
}

Number *Float::mul(Number *num) {
	if (num->types() == INTEGER)
	{
		Integer* other = dynamic_cast<Integer*>(num);
		this->set_val(this->val() * other->val());
		delete(other);
		return this;
	}
	else if (num->types() == FLOAT)
	{
		Float* other = dynamic_cast<Float*>(num);
		other->set_val(this->val() * other->val());
		delete(this);
		return other;
	}
	else if (num->types() == COMPLEX)
	{
		Complex* other = dynamic_cast<Complex*>(num);
		other->set_val(this->val() * other->val().first, this->val()*other->val().second);
		delete(this);
		return other;
	}
	return nullptr;
}

Number *Float::div(Number *num) {
	if (num->types() == INTEGER)
	{
		Integer* other = dynamic_cast<Integer*>(num);
		this->set_val(this->val() / other->val());
		delete(other);
		return this;
	}
	else if (num->types() == FLOAT)
	{
		Float* other = dynamic_cast<Float*>(num);
		other->set_val(this->val() / other->val());
		delete(this);
		return other;
	}
	else if (num->types() == COMPLEX)
	{
		return nullptr;
	}
	return nullptr;

}

void Float::set_val(double val) {
	this->value = val;
}

double Float::val() const {
    return this->value;
}

Number::type Float::types() const {
	return FLOAT;
}

std::string Float::to_string() const {
    return std::to_string(value);
}
