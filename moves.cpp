#include <iostream>
#include "math.h"
#include "moves.h"

chessRules::chessRules() 
{
	reachabilities = new int* [(asInt(Piece::Count))];
	reachabilities[asInt(Piece::KING)] = new int [REACHABILITY_MATRIX_SIZE] { 
		7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
	    7,6,6,6,6,6,6,6,6,6,6,6,6,6,7,
 	    7,6,5,5,5,5,5,5,5,5,5,5,5,6,7,
		7,6,5,4,4,4,4,4,4,4,4,4,5,6,7,
		7,6,5,4,3,3,3,3,3,3,3,4,5,6,7,
		7,6,5,4,3,2,2,2,2,2,3,4,5,6,7,
		7,6,5,4,3,2,1,1,1,2,3,4,5,6,7,
		7,6,5,4,3,2,1,0,1,2,3,4,5,6,7,
		7,6,5,4,3,2,1,1,1,2,3,4,5,6,7,
		7,6,5,4,3,2,2,2,2,2,3,4,5,6,7,
		7,6,5,4,3,3,3,3,3,3,3,4,5,6,7,
		7,6,5,4,4,4,4,4,4,4,4,4,5,6,7,
		7,6,5,5,5,5,5,5,5,5,5,5,5,6,7,
		7,6,6,6,6,6,6,6,6,6,6,6,6,6,7,
		7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
					 };
	reachabilities[(int)Piece::QUEEN] = new int [REACHABILITY_MATRIX_SIZE] {
		1,2,2,2,2,2,2,1,2,2,2,2,2,2,1,
	    2,1,2,2,2,2,2,1,2,2,2,2,2,1,2,
 	    2,2,1,2,2,2,2,1,2,2,2,2,1,2,2,
		2,2,2,1,2,2,2,1,2,2,2,1,2,2,2,
		2,2,2,2,1,2,2,1,2,2,1,2,2,2,2,
		2,2,2,2,2,1,2,1,2,1,2,2,2,2,2,
		2,2,2,2,2,2,1,1,1,2,2,2,2,2,2,
		1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,
		2,2,2,2,2,2,1,1,1,2,2,2,2,2,2,
		2,2,2,2,2,1,2,1,2,1,2,2,2,2,2,
		2,2,2,2,1,2,2,1,2,2,1,2,2,2,2,
		2,2,2,1,2,2,2,1,2,2,2,1,2,2,2,
		2,2,1,2,2,2,2,1,2,2,2,2,1,2,2,
		2,1,2,2,2,2,2,1,2,2,2,2,2,1,2,
		1,2,2,2,2,2,2,1,2,2,2,2,2,2,1,
					 };
	reachabilities[(int)Piece::ROOK] = new int [REACHABILITY_MATRIX_SIZE] {
		2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,
		1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,
		2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,
	};
	reachabilities[(int)Piece::BISHOP] = new int [REACHABILITY_MATRIX_SIZE] {
		1,0,2,0,2,0,2,0,2,0,2,0,2,0,1,
	    0,1,0,2,0,2,0,2,0,2,0,2,0,1,0,
 	    2,0,1,0,2,0,2,0,2,0,2,0,1,0,2,
		0,2,0,1,0,2,0,2,0,2,0,1,0,2,0,
		2,0,2,0,1,0,2,0,2,0,1,0,2,0,2,
		0,2,0,2,0,1,0,2,0,1,0,2,0,2,0,
		2,0,2,0,2,0,1,0,1,0,2,0,2,0,2,
		0,2,0,2,0,2,0,0,0,2,0,2,0,2,0,
		2,0,2,0,2,0,1,0,1,0,2,0,2,0,2,
		0,2,0,2,0,1,0,2,0,1,0,2,0,2,0,
		2,0,2,0,1,0,2,0,2,0,1,0,2,0,2,
		0,2,0,1,0,2,0,2,0,2,0,1,0,2,0,
		2,0,1,0,2,0,2,0,2,0,2,0,1,0,2,
		0,1,0,2,0,2,0,2,0,2,0,2,0,1,0,
		1,0,2,0,2,0,2,0,2,0,2,0,2,0,1,
	};
	reachabilities[(int)Piece::KNIGHT] = new int [REACHABILITY_MATRIX_SIZE] {
		6,5,4,5,4,5,4,5,4,5,4,5,4,5,6,
		5,4,5,4,3,4,3,4,3,4,3,4,5,4,5,
		4,5,4,3,4,3,4,3,4,3,4,3,4,5,4,
		5,4,3,4,3,2,3,2,3,2,3,4,3,4,5,
		4,3,4,3,2,3,2,3,2,3,2,3,4,3,4,
		5,4,3,2,3,4,1,2,1,4,3,2,3,4,5,
		4,3,4,3,4,1,4,3,4,1,4,3,4,3,4,
		5,4,5,2,5,2,5,0,5,2,5,2,5,4,5,
		4,3,4,3,4,1,4,3,4,1,4,3,4,3,4,
		5,4,3,2,3,4,1,2,1,4,3,2,3,4,5,
		4,3,4,3,2,3,2,3,2,3,2,3,4,3,4,
		5,4,3,4,3,2,3,2,3,2,3,4,3,4,5,
		4,5,4,3,4,3,4,3,4,3,4,3,4,5,4,
		5,4,5,4,3,4,3,4,3,4,3,4,5,4,5,
		6,5,4,5,4,5,4,5,4,5,4,5,4,5,6,
	};
	// upside-down since array index 0 is the upper-left corner
	reachabilities[(int)Piece::PAWN] = new int [REACHABILITY_MATRIX_SIZE] {
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,
		0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,
		0,0,0,0,3,3,3,3,3,3,3,0,0,0,0,
		0,0,0,4,4,4,4,4,4,4,4,4,0,0,0,
		0,0,5,5,5,5,5,5,5,5,5,5,5,0,0,
		0,6,6,6,6,6,6,6,6,6,6,6,6,6,0,
		7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
	};
	// TODO: make this into fib-step reachability matrix
	reachabilities[(int)Piece::FIB] = new int [REACHABILITY_MATRIX_SIZE] {
		2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,
		1,1,1,1,1,2,1,0,1,2,1,1,1,1,1,
		2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,
	};
}

void chessRules::trajectory(Piece p, int x1, int y1, int x2, int y2, int* obstacles)
{

}

int* chessRules::genMove(Piece p, int x, int y, int d)
{
	int* move = new int [BOARD_MATRIX_SIZE];
/*	for (int index = 0; index < BOARD_MATRIX_SIZE; ++index)
	{
		move[index] = 0;
	}*/
	int xOffset = ceil(REACHABILITY_MATRIX_LENGTH/2);
	int yOffset = xOffset;
	xOffset -= x;
	yOffset -= y;
	for (int yIter = 0; yIter < BOARD_MATRIX_LENGTH; ++yIter) 
	{
		for (int xIter = 0; xIter < BOARD_MATRIX_LENGTH; ++xIter) 
		{
			int thisX = xIter + xOffset;
			int thisY = yIter + yOffset;
			int thisBoardIndex = coordToIndex(xIter,yIter,BOARD_MATRIX_LENGTH);
			int thisReachIndex = coordToIndex(thisX,thisY,REACHABILITY_MATRIX_LENGTH);
			int thisValue = reachabilities[(int)p][thisReachIndex];
			thisValue = ((thisValue==d) ? thisValue : 0);
			move[thisBoardIndex] = thisValue;
		}
	}
	return move;
}

///////////////////////////////////////////////////////////////////////////
// assumes we are determining the trajcetory ellipse, which is for an 8x8
// board stored in an integer array of size 64.
// returns a copy of the ellipse board
int* chessRules::genEllipse(Piece p, int xStart, int yStart, int xEnd, int yEnd) 
{
	int* ellipse = new int [BOARD_MATRIX_SIZE];
	for (int index = 0; index < BOARD_MATRIX_SIZE; ++index)
	{
		ellipse[index] = 0;
	}
	//int xDist = std::abs(xEnd-xStart);
	//int yDist = std::abs(yEnd-yStart);
	//int distance = ((xDist > yDist) ? xDist : yDist);  NOT TRUE for all
	int* startTrajectories = new int [BOARD_MATRIX_SIZE]; 
	int* endTrajectories = new int [BOARD_MATRIX_SIZE];
	// begin ƒ superimpose() - **nice to have** abstraction of the below process
	int xStartOffset = ceil(REACHABILITY_MATRIX_LENGTH/2);
	int yStartOffset = xStartOffset;
	int xEndOffset = xStartOffset;
	int yEndOffset = xStartOffset;
	xStartOffset -= xStart;
	yStartOffset -= yStart;
	xEndOffset -= xEnd;
	yEndOffset -= yEnd;
	// startTrajectories
	for (int yIter = 0; yIter < BOARD_MATRIX_LENGTH; ++yIter) 
	{
		for (int xIter = 0; xIter < BOARD_MATRIX_LENGTH; ++xIter) 
		{
			int thisX = xIter + xStartOffset;
			int thisY = yIter + yStartOffset;
			int thisBoardIndex = coordToIndex(xIter,yIter,BOARD_MATRIX_LENGTH);
			int thisReachIndex = coordToIndex(thisX,thisY,REACHABILITY_MATRIX_LENGTH);
			startTrajectories[thisBoardIndex] = reachabilities[(int)p][thisReachIndex];
		}
	}

	// endTrajectories
	for (int yIter = 0; yIter < BOARD_MATRIX_LENGTH; ++yIter) 
	{
		for (int xIter = 0; xIter < BOARD_MATRIX_LENGTH; ++xIter) 
		{
			int thisX = xIter + xEndOffset;
			int flipY = yIter + yEndOffset;  // TODO: isn't flipping for pawn
			int thisBoardIndex = coordToIndex(xIter,yIter,BOARD_MATRIX_LENGTH);
			int thisReachIndex = coordToIndex(thisX,flipY,REACHABILITY_MATRIX_LENGTH);
			endTrajectories[thisBoardIndex] = reachabilities[(int)p][thisReachIndex];
		}
	}

	// distance
	int distanceToEnd = startTrajectories[coordToIndex(xEnd,yEnd,BOARD_MATRIX_LENGTH)];
	int distanceToStart = endTrajectories[coordToIndex(xStart,yStart,BOARD_MATRIX_LENGTH)];
	int distance = ((distanceToEnd > distanceToStart) ? distanceToEnd : distanceToStart);
	std::cout << "distance: " << distance << "\n";
	
	// ellipse
	for (int index = 0; index < BOARD_MATRIX_SIZE; ++index)
	{
		if ((startTrajectories[index] + endTrajectories[index]) == distance) 
		{
			ellipse[index] = distance;
		}
	}

	return ellipse;
}

int chessRules::coordToIndex(int x, int y, int bound) {
	if (0 <= x && x <= bound && 0 <= y && y <= bound) 
	{
		return x + (y * bound);
	} else {
		return -1;
	}
}

Position chessRules::indexToCoord(int index) 
{
	return Position((index % REACHABILITY_MATRIX_LENGTH), (index / REACHABILITY_MATRIX_LENGTH), REACHABILITY_MATRIX_LENGTH);
}

int chessRules::reverseIndex(int index)
{
	return REACHABILITY_MATRIX_SIZE - index;
}

int chessRules::asInt(Piece p) {
	return static_cast<std::size_t> (p);
}

void displayBoard(char* piece, int* board, int length)
{
	// header
	std::cout << "   --------";
	int pieceIter = 0;
	while (piece[pieceIter]) {
		std::cout << piece[pieceIter];
		++pieceIter;
	}
	std::cout << "--------\n";

	// print right-side up, by y descending, x ascending
	for (int y = length-1; y >= 0; --y) {  
		for (int x = 0; x < length; ++x) {
			std::cout << board[(y*length)+x] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}


