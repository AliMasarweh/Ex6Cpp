class Coordination {
private:
	int x, y;

public:
	Coordination(int x, int y);
	Coordination& operator= (const Coordination& c);
	int getX() const;
	int getY() const;
	~Coordination();
};