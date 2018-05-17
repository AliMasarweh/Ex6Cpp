#pragma once
#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <string>
#include "uint.h"
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
	virtual const string name() const = 0;
	virtual const Coordination play(const Board& board) = 0;
};


#endif