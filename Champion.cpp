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


