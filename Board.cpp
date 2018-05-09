#include "Board.h"


Board::Board(int size) {
	this->size = size;
	this->board = new Status*[size];
	int i;
	for (i = 0; i < size; i++)
		this->board[i] = new Status[size];
}

Board::Board(const Board& newBoard) {
	this->size = newBoard.size;
	this->board = new Status*[this->size];
	int i, j;
	for (i = 0; i < this->size; i++) {
		this->board[i] = new Status[this->size];
		for (j = 0; j < this->size; j++)
			this[i,j] = (&newBoard)[i,j];
	}
}

Board::~Board() {
	int i;
	for (i = 0; i< this->size; i++)
		delete[] board[i];
	delete[] board;
}

Board& Board::operator=(const Board& newBoard) {
	this->~Board();
	size = newBoard.size;
	board = new Status*[size];
	int i, j;
	for (i = 0; i < size; i++) {
		board[i] = new Status[size];
		for (j = 0; j < size; j++)
			this[i,j] = (&newBoard)[i,j];
	}
	return *this;
}

Board& Board::operator= (const char newStatus) {
	Status status(newStatus);
	int i, j;
	for (i = 0; i < this->size; i++)
		for (j = 0; j < this->size; j++)
			this[i,j] = status;
	return *this;
}

Status& Board::operator[] (const Coordination& coordination) const {
	if (coordination.getX() < size && coordination.getX() >= 0 && coordination.getY() < size && coordination.getY() >= 0)
		return board[coordination.getX()][coordination.getY()];
	throw IllegalCoordinateException(coordination);//Invalied coordination
}

ostream& operator<< (ostream& os, const Board& inserteBoard) {
	int i, j;
	for (i = 0; i < inserteBoard.size; i++) {
		for (j = 0; j < inserteBoard.size; j++)
			os << inserteBoard.board[i,j];
		os << endl;
	}
	return os;
}
