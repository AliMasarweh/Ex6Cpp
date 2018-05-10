#include "Coordination.h"

Coordination::Coordination(int xCoordination, int yCoordination) {
	this->x_Coordination = xCoordination;
	this->y_Coordination = yCoordination;
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
