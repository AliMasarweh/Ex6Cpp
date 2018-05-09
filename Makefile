CXX=clang++-5.0
CXXFLAGS=-std=c++17
all:Board.o Coordination.o Status.O

Board.o: Board.cpp Board.o Coordination.o Status.o
$(CXX) $(CXXFLAGS) -c Board.cpp -O Board.O

Coordination.o: Coordination.cpp Coordination.o Board.o Status.o

$(CXX) $(CXXFLAGS) -c Coordination.cpp -O Coordination.O

Status.o: Status.cpp Status.o Board.o Coordination.o

$(CXX) $(CXXFLAGS) -c Status.cpp -O Status.O

clean:
 rm*.o a.out
