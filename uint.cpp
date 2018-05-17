#include "uint.h"

uint::uint(int value) {
	if (value < 0)
		value *= -1;
	this->_value = value;
}

const uint& uint::operator++() {
	++(this->_value);
	return *this;
}

uint::operator int() const {
	int value =(int) this->_value;
	if (value < 0)
		value *= -1;
	return value;
}