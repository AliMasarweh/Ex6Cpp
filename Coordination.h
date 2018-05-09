#pragma once
#ifndef COORDINATION_HPP_
#define COORDINATION_HPP_

class Coordination {
private:
	int x, y;

public:
	Coordination(int x, int y);
	~Coordination();
	Coordination& operator= (const Coordination& otherCoordination);
	int getX() const;
	int getY() const;
};
#endif
