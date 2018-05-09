#include <iostream>
#include "IllegalCharException.cpp"

using namespace std;

class Status {
private:
	char status;

public:
	Status();
	Status(char status);
	Status(const Status& status);
	~Status();
	char getStatus() const;
	void setStatus(char status);
	Status& operator= (const char status);
	Status& operator= (const Status& status);
	operator char() const;
	friend ostream& operator<< (ostream& os, const Status& status);
};
