#pragma once
#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <string>
typedef unsigned int uint;
#include "Board.h"

using namespace std;

using Coordinate = Coordination;

class Player {
protected:
	string _name;
	Status myChar;
public:
	Player();
	Player(char XorO);
	Player(const Status& XorO);
	const char getChar() const;
	void setStatus(char XorO);
	void setName(string name);
	virtual const string name() const = 0;
	virtual const Coordination play(const Board& board) = 0;
};


#endif
