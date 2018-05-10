CXX=clang++-5.0
CXXFLAGS=-std=c++17 

all:Board.o Coordination.o Status.o
	
Board.o: 
	$(CXX) $(CXXFLAGS) -c Board.cpp -o Board.o
Coordination.o:
	$(CXX) $(CXXFLAGS) -c Coordination.cpp -o Coordination.o
Status.o: 
	$(CXX) $(CXXFLAGS) -c Status.cpp -o Status.o

clean:
	rm *.o a.out
