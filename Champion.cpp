#include "Champion.h"


const Coordination Champion::play(const Board& board) {
	if (board[{0, board.size()-1}] == '.')
		return Coordination{ 0, board.size() - 1 };
	if (board[{ board.size() - 1, 0 }] == '.')
		return Coordination{ board.size() - 1,0 };
	for (int i = 1; i < board.size() - 1; i++) {
		if (board[{ board.size() - i - 1, i }] == '.')
			return Coordination{ board.size() - i - 1,i };
	}
	return { board.size() - 1, board.size() - 1 };
}



/*Coordination c{ board.size()-1, board.size() - 1 };
if (board[{c.getXCoordination(), c.getYCoordination()}] == '.')
return c;
if (board[{c.getXCoordination(), c.getYCoordination()}] != '.' && board[{ 1, 0 }] == '.' && board[{ 0, 1 }] == '.') {
c.setYCoordination(board.size() - 2);
return c;
}
if (board[{ 1,0 }] != '.' && board[{ 0,1 }] == '.') {
Coordination temp{ board.size() - 1,0 };
if (board[{temp.getXCoordination(),temp.getYCoordination()}] != '.')
return temp;//Write on the (n,0) coordination, preventing the XYPlayer from winning and ensuring champion victory
}
if (board[{ 0,1 }] != '.' && board[{ 1,0 }] == '.') {
Coordination temp{ 0,board.size() - 1 };
if (board[{temp.getXCoordination(),temp.getYCoordination()}] != '.')
return temp;//Write on the (0,n) coordination, preventing the YXPlayer from winning and ensuring champion victory
}
if (board[{ 0,board.size() - 1 }] == '.') {
Coordination temp{ board.size() - 1,0 };
for (int i = 1; i < board.size() - 1; i++) {
temp.setYCoordination(i);
if (board[{temp.getXCoordination(),temp.getYCoordination()}] != '.')
return temp;//Write on the (n,i) coordination 1 < i < n-1, dominating the XYPlayer
}
}
if (board[{ board.size() - 1,0 }] == '.') {
Coordination temp{ 0,board.size() - 1 };
for (int i = 1; i < board.size() - 1; i++) {
temp.setXCoordination(i);
if (board[{temp.getXCoordination(),temp.getYCoordination()}] != '.')
return temp;//Write on the (i,n) coordination 1 < i < n-1, dominating the YXPlayer
}
}
//the other 2 will be eliminated by the game for illegitimate moves
return { 0,0 };//Won't happen becuase of isFull() funtion*/