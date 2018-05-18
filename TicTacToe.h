#pragma once
#ifndef TICTACTOE_HPP_
#define TICTACTOE_HPP_

#include "Board.h"
#include "Player.h"

class TicTacToe {
private:
	Board shingle;
	Player *p1, *p2, *victorious;
	
public:
	TicTacToe();
	TicTacToe(int n);
	const Board& play(Player& p1, Player& p2);
	const Board& board() const;
	const Player& winner() const;
	friend bool isTriumphal(TicTacToe& tictactoe, Coordination& coordinate,char stat);
	friend bool isFull(TicTacToe& tictactoe);
	friend bool isLegal(TicTacToe& tictactoe, Coordination& coordinate, Board& board);
};

#endif
