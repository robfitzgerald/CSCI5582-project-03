#include <iostream>
#include "moves.h"
#include "helper.h"

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
	// int d = 0;
	// int* someMove = c.genEllipse(Piece::QUEEN,0,3,7,3,d);
	// char someMoveTitle [] = "board";
	// displayBoard(someMoveTitle,someMove,BOARD_MATRIX_LENGTH);
	// displayBoard(someMoveTitle,c.genMove(Piece::KING,3,3,1),BOARD_MATRIX_LENGTH);
	// displayBoard(someMoveTitle,c.genMove(Piece::KING,3,3,2),BOARD_MATRIX_LENGTH);
	// displayBoard(someMoveTitle,c.genMove(Piece::KING,3,3,3),BOARD_MATRIX_LENGTH);
	// displayBoard(someMoveTitle,c.genMove(Piece::KING,3,3,4),BOARD_MATRIX_LENGTH);
	// displayBoard(someMoveTitle,c.genMove(Piece::KING,3,3,5),BOARD_MATRIX_LENGTH);
	
	//c.trajectory(Piece::KING,0,3,7,3);

	c.trajectory(Piece::QUEEN,4,1,7,4);
	return 0;
}