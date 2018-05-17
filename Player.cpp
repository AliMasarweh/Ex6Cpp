#include "Player.h"

Player::Player() {
	const Status tmp{ '.' };
	this->myChar = tmp;
}

Player::Player(char XorO) {
	const Status tmp{ XorO };
	this->myChar = tmp;
}

Player::Player(const Status& stat) {
	this->myChar = stat;
}

const char Player::getChar() const {
	return myChar;
}

void Player::setStatus(char XorO) {
	this->myChar.setStatus(XorO);
}
