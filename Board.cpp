#include "Board.h"


Board::Board(int size)  {
	this->board = new Status*[size];
	int i;
	for (i = 0; i < size; i++)
		this->board[i] = new Status[size];
}

Board::Board(const Board& b) {
	this->size = b.size;
	this->board = new Status*[this->size];
	int i, j;
	for (i = 0; i < this->size; i++) {
		this->board[i] = new Status[this->size];
		for (j = 0; j < this->size; j++)
			this->board[i][j] = b.board[i][j];
	}
}

Board& Board::operator=(const Board& b) {
	this->~Board();
	size = b.size;
	board = new Status*[size];
	int i, j;
	for (i = 0; i < size; i++) {
		board[i] = new Status[size];
		for (j = 0; j < size; j++)
			board[i][j] = b.board[i][j];
	}
	return *this;
}

Board& Board::operator= (const char c) {
	Status dc(c);
	int i, j;
	for (i = 0; i < this->size; i++)
		for (j = 0; j < this->size; j++)
			this->board[i][j] = dc;
	return *this;
}

Status& Board::operator[] (const Coordination& c) const {
	if (c.getX() < size && c.getX() >= 0 && c.getY() < size && c.getY() >= 0)
		return board[c.getX()][c.getY()];
	throw IllegalCoordinateException(c);
}

ostream& operator<< (ostream& os, const Board& b) {
	int i, j;
	for (i = 0; i < b.size; i++) {
		for (j = 0; j < b.size; j++)
			os << b.board[i][j];
		os << endl;
	}
	return os;
}

Board::~Board() {
	int i;
	for (i = 0; i< this->size; i++)
		delete[] board[i]; //This part was allocated with new[], so we use delete[]
	delete[] board;
}
