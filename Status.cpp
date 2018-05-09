#include "Status.h"

Status::Status() : c('.') { }

Status::Status(const char c) {
	this->operator =(c);
}

Status::Status(const Status& dc) {
	this->c = dc.c;
}

Status& Status::operator= (const char c) {
	switch (c) {
	case Symbol::X:
		this->c = c;
		break;
	case Symbol::O:
		this->c = c;
		break;
	case Symbol::P:
		this->c = c;
		break;
	default:
		throw IllegalCharException(c);
		break;
	}
	return *this;
}


Status& Status::operator= (const Status& dc) {
	this->c = dc.c;
	return *this;
}

ostream& operator<< (ostream& os, const Status& dc) {
	return os << dc.c;
}

Status::operator char() const {
	return c;
}
