#include "Coordination.h"

Coordination::Coordination(int x, int y) {
	this->x = x;
	this->y = y;
}

Coordination& Coordination::operator= (const Coordination& otherCoordination) {
	this->x = otherCoordination.getX();
	this->y = otherCoordination.getY();
	return *this;
}

Coordination::~Coordination() { }

int Coordination::getX() const {
	return this->x;
}

int Coordination::getY() const {
	return this->y;
}
