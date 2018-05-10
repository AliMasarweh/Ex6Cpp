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
	Board(const Board& newBorad);
	~Board();
	char Board::getSize() const;
	Board& operator=(const Board& newBorad);
	Board& operator= (const char newChar);
	Status& operator[] (const Coordination& newChar) const;
	friend ostream& operator<< (ostream& os, const Board& newBorad);
};

#endif
