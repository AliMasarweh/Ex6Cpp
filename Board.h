#pragma once
#ifndef BOARD_HPP_
#define BOARD_HPP_


#include "Status.h"
#include "IllegalCoordinateException.cpp"


class Board {
private:
	Status** board;
	int size;

public:
	Board(int size);
	Board(const Board& b);
	Board& operator=(const Board& b);
	Board& operator= (const char c);
	Status& operator[] (const Coordination& c) const;
	friend ostream& operator<< (ostream& os, const Board& b);
	~Board();
};

#endif
