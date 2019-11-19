//
// Created by 김혁진 on 2019/11/11.
//

#include "Integer.h"
#include "Float.h"
#include "Complex.h"

int Integer::parse_string(const std::string& str) {
    /**
     * 문자열을 int로 변환하는 함수
     */
    int result = atoi(str.c_str());
    return result;
}

Integer::Integer() {
    /**
     * value를 0으로 저장
     */
	this->value = 0;
}

Integer::Integer(int _value) {
    /**
     * 입력받은 int 값(_value)을 value에 저장
     */
	this->value = _value;
}

Integer::Integer(const std::string& str) {
    /**
     * Integer의 parse_string 함수를 통해 입력받은 문자열 값을 int 값으로 value에 저장
     */
	int _str = parse_string(str);
	this->value = _str;
}

Number *Integer::add(Number * num) {
    if (num->types() == INTEGER) {
		Integer* other = dynamic_cast<Integer*>(num);
		other->set_val(other->val() + this->val());
		delete(this);
		return other;

    } else if (num->types() == FLOAT) {
		Float* other = dynamic_cast<Float*>(num);
		other->set_val(other->val() + this->val());
		delete(this);
		return other;
    } else if (num->types() == COMPLEX) {
		Complex* other = dynamic_cast<Complex*>(num);
		other->set_val(other->val().first + this->val(),other->val().second);
		delete(this);
		return other;
    } else {
		return nullptr;
    }
}

Number *Integer::sub(Number * num) {
    /**
     * this->value - num->value // num의 value는 private 이므로 호출 불가능 (단순 개념 설명임)
     * this의 값과 parameter로 들어온 num의 value를 빼는 함수
     */
	if (num->types() == INTEGER) {
		Integer* other = dynamic_cast<Integer*>(num);
		other->set_val(this->val() - other->val());
		delete(this);
		return other;

	}
	else if (num->types() == FLOAT) {
		Float* other = dynamic_cast<Float*>(num);
		other->set_val(this->val() - other->val());
		delete(this);
		return other;
	}
	else if (num->types() == COMPLEX) {
		Complex* other = dynamic_cast<Complex*>(num);
		other->set_val(other->val().first - this->val(), other->val().second);
		delete(this);
		return other;
	}
	else {
		return nullptr;
	}
    return nullptr;
}

Number *Integer::mul(Number * num) {
    /**
     * this->value * num->value // num의 value는 private 이므로 호출 불가능 (단순 개념 설명임)
     * this의 값과 parameter로 들어온 num의 value를 곱하는 함수
     *
     * Complex 값은 실수부와 허수부 모두에 this->value값을 곱해줘야 함
     */
	if (num->types() == INTEGER) {
		Integer* other = dynamic_cast<Integer*>(num);
		other->set_val(other->val() * this->val());
		delete(this);
		return other;

	}
	else if (num->types() == FLOAT) {
		Float* other = dynamic_cast<Float*>(num);
		other->set_val(other->val() * this->val());
		delete(this);
		return other;
	}
	else if (num->types() == COMPLEX) {
		Complex* other = dynamic_cast<Complex*>(num);
		other->set_val(other->val().first * this->val(), other->val().second* this->val());
		delete(this);
		return other;
	}
	else {
		return nullptr;
	}
    return nullptr;
}

Number *Integer::div(Number * num) {
    /**
     * this->value / num->value // num의 value는 private 이므로 호출 불가능 (단순 개념 설명임)
     * this의 값과 parameter로 들어온 num의 value를 더하는 함수
     *
     * Type이 COMPLEX 경우 nullptr 를 반환한다.
     * 이 때는 this와 num 모두 delete하지 않는다.
     */
	if (num->types() == INTEGER)
	{
		Integer* other = dynamic_cast<Integer*>(num);
		other->set_val(this->val() / other->val());
		delete(this);
		return other;
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

void Integer::set_val(int val) {
    /**
     * 입력받은 val을 value값으로 저장하는 함수 (value의 setter)
     */
	this->value = val;
}

int Integer::val() const {
    /**
     * value 값을 return하는 함수 (value의 getter)
     */

	return this->value;
}

Number::type Integer::types() const {
    /**
     * Number의 enum 값인 INTEGER 값을 반환
     */
	return INTEGER;
}

std::string Integer::to_string() const {
    /**
     * int 값의 string
     */
    return std::to_string(value);
}
