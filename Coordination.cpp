#include "Coordination.h"

Coordination::Coordination(int x, int y) {
	this->x = x;
	this->y = y;
}

Coordination& Coordination::operator= (const Coordination& c) {
	this->x = c.getX();
	this->y = c.getY();
	return *this;
}

int Coordination::getX() const {
	return this->x;
}

int Coordination::getY() const {
	return this->y;
}

Coordination::~Coordination() { }