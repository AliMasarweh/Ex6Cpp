
#include "TicTacToe.h"
#include "Status.h"


using namespace std;

TicTacToe::TicTacToe() {
	Board temp{ 4 };
	this->shingle = temp;
}

TicTacToe::TicTacToe(int n) {
	Board temp{ n };
	this->shingle = temp;
}

const Board& TicTacToe::board() const {
	return (this->shingle);
}

const Player& TicTacToe::winner() const {
	return *(this->victorious);
}

const Board& TicTacToe::play(Player& p1, Player& p2) {
	this->shingle = '.';
	p1.setStatus('X');
	p2.setStatus('O');
	Coordination *currentMove = new Coordination(0, 0);
	int turn = 2;
	do {
		try{
			turn = 3 - turn;
			if (turn == 1)
				*currentMove = p1.play(this->shingle);
			else
				*currentMove = p2.play(this->shingle);
			if (!isLegal(*this,*currentMove, this->shingle)) {
				throw (new IllegalCoordinateException(*currentMove))->theCoordination();
			}

			((this->shingle)[{currentMove->getXCoordination(), currentMove->getYCoordination()}])
				= turn == 1 ? 'X' : 'O';

			if (isTriumphal(*this, *currentMove, turn == 1 ? 'X' : 'O')) {
				(this->victorious) = &(turn == 1 ? p1 : p2);
				return this->shingle;
			}
		}
		catch (string e) {
			cout << e << endl;
			(this->victorious) = &(turn == 1 ? p2 : p1);
			return this->shingle;
		}
	} while (!isFull(*this));
	this->victorious = &p2;
	return this->shingle;
}


/* Returns true if the last move was a winning move, else false.
 * Using the data of the last move, The expected triumphal statuses are a vertical, a horizontal 
 * or a diagonal (if and only if the last move was in the diagonal of the board) status which 
 * contains this very move's Coordination.
*/
bool isTriumphal(TicTacToe& tictactoe,Coordination& Coordination,char stat) {
	char CoordinationStatus = (tictactoe.shingle)[{Coordination.getXCoordination(), Coordination.getYCoordination()}];
	bool triumph_Vertical = 1, triumph_horizontal = 1, triumph_diagonal = 1, triumph_diagonalInvert = 1;
	if (Coordination.getXCoordination() != Coordination.getYCoordination())
		triumph_diagonal = 0;
	if (((tictactoe.shingle).size() - Coordination.getXCoordination() - 1) != Coordination.getYCoordination())
		triumph_diagonalInvert = 0;
	for (int x = 0; x < tictactoe.shingle.size(); ++x) {
		char temp = (tictactoe.shingle)[{x, Coordination.getYCoordination()}];
		if (temp != CoordinationStatus) {
			triumph_Vertical = 0;
			break;
		}
	}
	for (int x = 0;x < tictactoe.shingle.size(); ++x) {
		char temp = (tictactoe.shingle)[{Coordination.getXCoordination(), x}];
		if (temp != CoordinationStatus) {
			triumph_horizontal = 0;
			break;
		}
	}
	if(triumph_diagonal)
		for (int x = 0;x < tictactoe.shingle.size(); ++x) {
			char temp = (tictactoe.shingle)[{x,x}];
			if (temp != CoordinationStatus) {
				triumph_diagonal = 0;
				break;
			}
		}
	if (triumph_diagonalInvert) {
		int sizeOfB = (tictactoe.shingle).size() - 1;
		for (int x = 0; x < tictactoe.shingle.size(); ++x) {
			int y = sizeOfB - x;
			char temp = (tictactoe.shingle)[{y,x}];
			if (temp != CoordinationStatus) {
				triumph_diagonalInvert = 0;
				break;
			}
		}
	}
	return (triumph_Vertical || triumph_horizontal || triumph_Vertical || triumph_diagonalInvert);
}


/* Returns true if the board is full, else flase.
*/
bool isFull(TicTacToe& tictactoe) {
	for (int x = 0; x < tictactoe.shingle.size(); ++x) {
		for (int y = 0; y < tictactoe.shingle.size(); ++y) {
			if ((tictactoe.shingle)[{ x, y }] == '.')
				return false;
		}
	}
	return true;
}


/* Returns true if this move is legal ,else false.
 * Illegal moves are the ones that exceed the limits of the board or overwrite an already written on coordination.
*/
bool isLegal(TicTacToe& tictactoe,Coordination& Coordination, Board& board) {
	const int x = Coordination.getXCoordination();
	const int y = Coordination.getYCoordination();
	int sizeOfBoard = board.size();
	if (x < 0 || x > sizeOfBoard || y < 0 || y > sizeOfBoard)
		return false;
	if ((tictactoe.shingle)[{x, y}] != '.') {
		return false;
	}
	return true;
}