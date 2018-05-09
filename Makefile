CXX=clang++-5.0
CXXFLAGS=-std=c++17

make: main.cpp Board.o Coordination.o Status.o Symbol.o
	$(CXX) $(CXXFLAGS) main.cpp *.o -o a.out 
	valgrind --tool=memcheck ./a.out

Board.o: Board.cpp Coordination.cpp IllegalCharException.cpp  IllegalCoordinateException.cpp Board.h Coordination.h Symbol.h Status.h Status.cpp
	$(CXX) $(CXXFLAGS) -c Board.cpp -o Board.o
	$(CXX) $(CXXFLAGS) -c Coordination.cpp -o Coordination.o
	$(CXX) $(CXXFLAGS) -c Status.cpp -o Status.o
 $(CXX) $(CXXFLAGS) -c IllegalCharException.cpp 
 $(CXX) $(CXXFLAGS) -c IllegalCoordinateException.cpp 
 $(CXX) $(CXXFLAGS) -o Symbol.cpp


clean:
	rm *.o a.out
 
 
