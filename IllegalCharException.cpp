
class IllegalCharException {
private:
	const char _char;

public:
	IllegalCharException(const char illigalChar) : _char(illigalChar) { }

	const char theChar() const {
		return this->_char;
	}
};
