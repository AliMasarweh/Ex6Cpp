#pragma once
#ifndef BOARD_HPP_
#define BOARD_HPP_


#include "Status.h"
#include "Coordination.h"
#include "IllegalCoordinateException.cpp"


class Board {
private:
	Status** board;
	int sizeOfBoard;

public:
	Board();
	Board(int size);
	Board(const Board& newBorad);
	~Board();
	Board& operator=(const Board& newBorad);
	Board& operator= (const char newChar);
	Status& operator[] (const Coordination &newChar) const;
	friend ostream& operator<< (ostream& os, const Board& newBorad);
	unsigned int size() const;
	int BoardSize() const;
};

#endif