#include "Champion.h"


const Coordination Champion::play(const Board& board) {
	int boardSize = board.BoardSize() - 1;
	if (board[{0, boardSize}] == '.')
		return Coordination{ 0, board.BoardSize() - 1 };
	if (board[{ boardSize, 0 }] == '.')
		return Coordination{ boardSize,0 };
	for (int i = 1; i < boardSize; i++) {
		if (board[{ boardSize - i, i }] == '.')
			return Coordination{ board.BoardSize() - i - 1,i };
	}
	return { boardSize, boardSize };
}



/*Coordination c{ board.BoardSize()-1, board.BoardSize() - 1 };
if (board[{c.getXCoordination(), c.getYCoordination()}] == '.')
return c;
if (board[{c.getXCoordination(), c.getYCoordination()}] != '.' && board[{ 1, 0 }] == '.' && board[{ 0, 1 }] == '.') {
c.setYCoordination(board.BoardSize() - 2);
return c;
}
if (board[{ 1,0 }] != '.' && board[{ 0,1 }] == '.') {
Coordination temp{ board.BoardSize() - 1,0 };
if (board[{temp.getXCoordination(),temp.getYCoordination()}] != '.')
return temp;//Write on the (n,0) coordination, preventing the XYPlayer from winning and ensuring champion victory
}
if (board[{ 0,1 }] != '.' && board[{ 1,0 }] == '.') {
Coordination temp{ 0,board.BoardSize() - 1 };
if (board[{temp.getXCoordination(),temp.getYCoordination()}] != '.')
return temp;//Write on the (0,n) coordination, preventing the YXPlayer from winning and ensuring champion victory
}
if (board[{ 0,board.BoardSize() - 1 }] == '.') {
Coordination temp{ board.BoardSize() - 1,0 };
for (int i = 1; i < board.BoardSize() - 1; i++) {
temp.setYCoordination(i);
if (board[{temp.getXCoordination(),temp.getYCoordination()}] != '.')
return temp;//Write on the (n,i) coordination 1 < i < n-1, dominating the XYPlayer
}
}
if (board[{ board.BoardSize() - 1,0 }] == '.') {
Coordination temp{ 0,board.BoardSize() - 1 };
for (int i = 1; i < board.BoardSize() - 1; i++) {
temp.setXCoordination(i);
if (board[{temp.getXCoordination(),temp.getYCoordination()}] != '.')
return temp;//Write on the (i,n) coordination 1 < i < n-1, dominating the YXPlayer
}
}
//the other 2 will be eliminated by the game for illegitimate moves
return { 0,0 };//Won't happen becuase of isFull() funtion*/
