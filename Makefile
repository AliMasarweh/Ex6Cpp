CXX=clang++-5.0
CXXFLAGS=-std=c++17 

all:Board.o Coordination.o Status.o Champion.o DummyPlayers.o Player.o TicTacToe.o
	
Board.o: 
	$(CXX) $(CXXFLAGS) -c Board.cpp -o Board.o
Coordination.o:
	$(CXX) $(CXXFLAGS) -c Coordination.cpp -o Coordination.o
Status.o: 
	$(CXX) $(CXXFLAGS) -c Status.cpp -o Status.o
Champion.o: 
	$(CXX) $(CXXFLAGS) -c Champion.cpp -o Champion.o
DummyPlayers.o: 
	$(CXX) $(CXXFLAGS) -c DummyPlayers.cpp -o DummyPlayers.o
Player.o: 
	$(CXX) $(CXXFLAGS) -c Player.cpp -o Player.o
TicTacToe.o: 
	$(CXX) $(CXXFLAGS) -c TicTacToe.cpp -o TicTacToe.o

clean:
	rm *.o a.out
