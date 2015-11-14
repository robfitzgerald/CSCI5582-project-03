#include <iostream>
#include "moves.h"

int main() {

	chessRules c;
	// basic functionality tests
/*	for (int i = 0; i < REACHABILITY_MATRIX_LENGTH; ++i)
	{
		int ind = c.coordToIndex(i,i,REACHABILITY_MATRIX_LENGTH);
		Position p = c.indexToCoord(ind);
		std::cout << "index for " << i << "," << i << ": " << ind << "\n";
		std::cout << "coordinates for " << ind << ": " << p.x << "," << p.y << "\n";
	}
	int* knight = c.getReachability(Piece::KNIGHT);
	char knightName [] = "Knight";
	displayBoard(knightName,knight,REACHABILITY_MATRIX_LENGTH);
*/	
	// logic tests
	int* kb2 = c.calculateEllipse(Piece::KING,2,1,0,0);
	char boardName [] = "trajectories kb2 (2,1)";
	displayBoard(boardName,kb2,BOARD_MATRIX_LENGTH);
	return 0;
}