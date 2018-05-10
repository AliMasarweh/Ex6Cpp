#pragma once
#ifndef COORDINATION_HPP_
#define COORDINATION_HPP_

class Coordination {
private:
	int x_Coordination, y_Coordination;

public:
	Coordination(int xCoordination, int yCoordination);
	~Coordination();
	Coordination& operator= (const Coordination& otherCoordination);
	int getXCoordination() const;
	int getYCoordination() const;
};
#endif
