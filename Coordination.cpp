#include "Coordination.h"

Coordination::Coordination(int x, int y) {
	this->x_Coordination = x;
	this->y = y;
}

Coordination& Coordination::operator= (const Coordination& otherCoordination) {
	this->x_Coordination = otherCoordination.getXCoordination();
	this->y_Coordination = otherCoordination.getYCoordination();
	return *this;
}

Coordination::~Coordination() { }

int Coordination::getXCoordination() const {
	return this->x_Coordination;
}

int Coordination::getYCoordination() const {
	return this->y_Coordination;
}
