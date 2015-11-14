#include <iostream>
#include "moves.h"

int main() {

	chessRules c;
	for (int i = 0; i < REACHABILITY_MATRIX_LENGTH; ++i)
	{
		int ind = c.coordToIndex(i,i,REACHABILITY_MATRIX_LENGTH);
		Position p = c.indexToCoord(ind);
		std::cout << "index for " << i << "," << i << ": " << ind << "\n";
		std::cout << "coordinates for " << ind << ": " << p.x << "," << p.y << "\n";
	}
	int* knight = c.getReachability(Piece::KNIGHT);
	char knightName [] = "Knight";
	displayBoard(knightName,knight,REACHABILITY_MATRIX_LENGTH);
	return 0;
}