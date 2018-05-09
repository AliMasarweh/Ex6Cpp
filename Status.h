#include <iostream>
#include "Symbol.h"
#include "IllegalCharException.cpp"

using namespace std;

class Status {
private:
	char c;

public:
	Status();
	Status(char c);
	Status(const Status& dc);
	Status& operator= (const char c);
	Status& operator= (const Status& dc);
	friend ostream& operator<< (ostream& os, const Status& dc);

	operator char() const;
};
