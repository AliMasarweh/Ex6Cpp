CXX=clang++5.0
CXXFLAGS=-std=c++17
all:  Board.o Coordination.o Status.o 

Board.o:  Board.cpp Board.h Coordination.h Status.h

$(CXX) $(CXXFLAGS) -c Board.cpp -o Board.o

Coordination.o: Coordination.cpp Coordination.h Board.h Status.h 

$(CXX) $(CXXFLAGS) -c Coordination.cpp -o Coordination.o

Status.o: Status.cpp Status.h Coordination.h Board.h  

$(CXX) $(CXXFLAGS) -c Status.cpp -o Status.o

clean:
  rm*.o a.out
