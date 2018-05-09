CXX=clang++-5.0
CXXFLAGS=-std=c++17
all:Board.o Coordination.o Status.O

Board.o: Board.cpp Board.h Coordination.h Status.h
$(CXX) $(CXXFLAGS) -c Board.cpp -O Board.O

Coordination.o: Coordination.cpp Coordination.h Board.h Status.h

$(CXX) $(CXXFLAGS) -c Coordination.cpp -O Coordination.O

Status.o: Status.cpp Status.h Board.h Coordination.h

$(CXX) $(CXXFLAGS) -c Status.cpp -O Status.O

clean:
 rm*.o a.out
