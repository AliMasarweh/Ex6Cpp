CCX=g++ -std=c++11


a.out: Board.o Coordination.o Status.o IllegalCharException.o IllegalCoordinateException.o
		$(CCX) main.cpp *.o
		
Board.o: Board.cpp Board.h
		$(CCX) -c Board.cpp
		
Coordination.o: Coordination.cpp Coordination.h
		$(CCX) -c Coordination.cpp
		
Status.o: Status.cpp Status.h
		$(CCX) -c Status.cpp

# Symbol.o: Symbol.h
# 		$(CCX) -c Symbol.h

IllegalCharException.o: IllegalCharException.cpp
		$(CCX) -c IllegalCharException.cpp

IllegalCoordinateException.o: IllegalCoordinateException.cpp
		$(CCX) -c IllegalCoordinateException.cpp
		
Clean:
		rm *.o a.out
