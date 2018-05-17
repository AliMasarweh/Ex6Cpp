#pragma once
#ifndef CHAMPION_HPP_
#define CHAMPION_HPP_

#include "Player.h"

class Champion : public Player {
public:
	const string name() const override { return "Ali"; }
	const Coordinate play(const Board& board) override;
};


#endif