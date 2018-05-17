#pragma once
#ifndef UINT_HPP_
#define UINT_HPP_


class uint {
private:
	unsigned int _value;

public:
	uint(int value);
	const uint& operator++();
	operator int() const;
};



#endif