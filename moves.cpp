#include <iostream>
#include <vector>
#include "math.h"
#include "moves.h"
#include "helper.h"

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
	reachabilities[(int)Piece::PAWN] = new int [REACHABILITY_MATRIX_SIZE] {
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,
	};
	// not stored in reachabilities** - that would throw off the move type calculations
	PAWN_REVERSE = new int [REACHABILITY_MATRIX_SIZE] {
		0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	};
	// skips
	reachabilities[(int)Piece::SKIPPY] = new int [REACHABILITY_MATRIX_SIZE] {
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,6,0,5,0,4,0,3,0,4,0,5,0,6,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,5,0,4,0,3,0,2,0,3,0,4,0,5,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,4,0,3,0,2,0,1,0,2,0,3,0,4,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,3,0,2,0,1,0,0,0,1,0,2,0,3,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,4,0,3,0,2,0,1,0,2,0,3,0,4,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,5,0,4,0,3,0,2,0,3,0,4,0,5,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,6,0,5,0,4,0,3,0,4,0,5,0,6,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	};
}

void chessRules::trajectory(Piece p, int x1, int y1, int x2, int y2, int length, int* obstacles)
{	
	//int d = 0;
	int* sum = genEllipse(p,x1,y1,x2,y2,length,obstacles);
	std::cout << "\n=-=-=- all trajectories of length " << length << " -=-=-=\n\n";
	char sumT [] = "~";
	displayBoard(sumT,sum,BOARD_MATRIX_LENGTH);
	// was using 'd' as my distance, a calculated value. replaced with the paramater 'length'
	std::vector<int> path;
	for (int i = 0; i < BOARD_MATRIX_SIZE; ++i) 
	{
		path.push_back(0);
	}
	std::cout << "=-=-=- list of move strings -=-=-=\n\n";
	std::vector<std::vector<int> > result = _trajectory(p,x1,y1,x1,y1,1,length, sum, path, "");
	std::cout << "=-=-=- chess board representation -=-=-=\n\n";
	for (int i = 0; i < result.size(); ++i) 
	{
		char title [] = "~";
		int* printout = new int[BOARD_MATRIX_SIZE];
		for (int j = 0; j < BOARD_MATRIX_SIZE; ++j) 
		{
			printout[j] = result[i][j];
		}	
		displayBoard(title,printout,BOARD_MATRIX_LENGTH);
	}
	std::cout << "done, with " << result.size() << " results\n";

}

std::vector<std::vector<int> > chessRules::_trajectory(Piece p, int x1, int y1, int thisX, int thisY, int dStep, int d, int* sum, std::vector<int> path, std::string moveString)
{
	std::vector<std::vector<int> > paths;
	if (dStep > d) 
	{
		// leaf in tree. returns this path, which is a valid trajectory from start to end
		if (moveString.length() > 4)
		{
			moveString.erase((moveString.end()-4),moveString.end());  // remove the last arrow
			std::cout << moveString << std::endl;
		}
		paths.push_back(path);
		return paths;
	}

	// data for this node in this trajectory branch
	int* m1 = genMove(p,thisX,thisY,1);
	int* mn = genMove(p,x1,y1,dStep);
	int* next = new int [BOARD_MATRIX_SIZE];
	std::vector<Position> possibles;

	// build list of valid next moves, in other words, the next() operation
	for (int i = 0; i < BOARD_MATRIX_SIZE; ++i) 
	{
		int found = (((sum[i] > 0) && (m1[i] > 0) && (mn[i] > 0)) ? 1 : 0);
		next[i] = found;
		if (found > 0) 
		{
			Position foundP = indexToCoord(i, BOARD_MATRIX_LENGTH);
			possibles.push_back(foundP);
		}
	}
	// char sumT [] = "sum (ellipse)";
	// char m1T [] = "m1 (from current step)";
	// char mnT [] = "mn (from original spot)";
	// char moveT [] = "board";
	// displayBoard(sumT,sum,BOARD_MATRIX_LENGTH);
	// displayBoard(m1T,m1,BOARD_MATRIX_LENGTH);
	// displayBoard(mnT,mn,BOARD_MATRIX_LENGTH);
	// displayBoard(moveT,next,BOARD_MATRIX_LENGTH);

	// decision tree
	for (int i = 0; i < possibles.size(); ++i)
	{
		std::vector<int> nextPath = path;
		nextPath[coordToIndex(possibles[i].x,possibles[i].y,BOARD_MATRIX_LENGTH)] = 1;
		std::string nextMoveString = moveString;
		nextMoveString += intToChessNotation(p,thisX,thisY,possibles[i].x,possibles[i].y);
		nextMoveString += " -> ";
		std::vector<std::vector<int> > thesePaths = _trajectory(p,x1,y1,possibles[i].x,possibles[i].y,dStep+1,d,sum,nextPath,nextMoveString);
		for (int j = 0; j < thesePaths.size(); ++j)
		{
			paths.push_back(thesePaths[j]);
		}
	}

	// good housekeeping
	delete [] m1;
	delete [] mn;
	delete [] next;
	return paths;
}

int* chessRules::genMove(Piece p, int x, int y, int d)
{
	int* move = new int [BOARD_MATRIX_SIZE];
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
int* chessRules::genEllipse(Piece p, int xStart, int yStart, int xEnd, int yEnd, int d, int* ob) 
{
	int* ellipse = new int [BOARD_MATRIX_SIZE];
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
			startTrajectories[thisBoardIndex] = reachabilities[(int)p][thisReachIndex] + ob[thisBoardIndex];
		}
	}

	// endTrajectories
	// if the Piece is a Piece::PAWN then we need to substitute in the int* PAWN_REVERSE
	// a hack solution for this project. ideally, get the math right to read it backwards!
	// but for now this will suffice.
	int* endReachabilityMatrix;
	if (p == Piece::PAWN)
	{
		endReachabilityMatrix = PAWN_REVERSE;
	} 
	else 
	{
		endReachabilityMatrix = reachabilities[(int)p];
	}

	for (int yIter = 0; yIter < BOARD_MATRIX_LENGTH; ++yIter) 
	{
		for (int xIter = 0; xIter < BOARD_MATRIX_LENGTH; ++xIter) 
		{
			int thisX = xIter + xEndOffset;
			int thisY = yIter + yEndOffset;  // TODO: isn't flipping for pawn
			int thisBoardIndex = coordToIndex(xIter,yIter,BOARD_MATRIX_LENGTH);
			int thisReachIndex = coordToIndex(thisX,thisY,REACHABILITY_MATRIX_LENGTH);
			endTrajectories[thisBoardIndex] = endReachabilityMatrix[thisReachIndex] + ob[thisBoardIndex];
		}
	}

	// WRONGGGGGG!!!!!!!!  now passing length value into function, from user input	
	// distance
	// int distanceToEnd = startTrajectories[coordToIndex(xEnd,yEnd,BOARD_MATRIX_LENGTH)];
	// int distanceToStart = endTrajectories[coordToIndex(xStart,yStart,BOARD_MATRIX_LENGTH)];
	// d = ((distanceToEnd > distanceToStart) ? distanceToEnd : distanceToStart);
	
	// ellipse
	for (int index = 0; index < BOARD_MATRIX_SIZE; ++index)
	{
		if ((startTrajectories[index] + endTrajectories[index]) == d) 
		{
			ellipse[index] = d;
		}
	}
	// char sT [] = "startTrajectories";
	// char eT [] = "endTrajectories";
	// displayBoard(sT,startTrajectories,BOARD_MATRIX_LENGTH);
	// displayBoard(eT,endTrajectories,BOARD_MATRIX_LENGTH);
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

Position chessRules::indexToCoord(int index, int bound) 
{
	return Position((index % bound), (index / bound), bound);
}

int chessRules::reverseIndex(int index)
{
	return REACHABILITY_MATRIX_SIZE - index;
}

int asInt(Piece p) {
	return static_cast<std::size_t> (p);
}

void displayBoard(char* piece, int* board, int length)
{
	// header
	std::cout << "-------";
	int pieceIter = 0;
	while (piece[pieceIter]) {
		std::cout << piece[pieceIter];
		++pieceIter;
	}
	std::cout << "-------\n";

	// print right-side up, by y descending, x ascending
	for (int y = length-1; y >= 0; --y) {  
		for (int x = 0; x < length; ++x) {
			std::cout << board[(y*length)+x] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

Piece charToPiece(char c)
{
	switch(c)
	{
		case 'S':
			return Piece::SKIPPY;
			break;
		case 'K':
			return Piece::KING;
			break;
		case 'Q':
			return Piece::QUEEN;
			break;
		case 'r':
			return Piece::ROOK;
			break;
		case 'b':
			return Piece::BISHOP;
			break;
		case 'k':
			return Piece::KNIGHT;
			break;
		case 'p':
			return Piece::PAWN;
			break;
		default:
			return Piece::EMPTY;
	}	
}

Piece intToPiece(int i)
{
	switch(i)
	{
		case 7:
			return Piece::SKIPPY;
			break;
		case 6:
			return Piece::KING;
			break;
		case 5:
			return Piece::QUEEN;
			break;
		case 4:
			return Piece::ROOK;
			break;
		case 3:
			return Piece::BISHOP;
			break;
		case 2:
			return Piece::KNIGHT;
			break;
		case 1:
			return Piece::PAWN;
			break;
		default:
			return Piece::EMPTY;
	}	
}

char pieceToChar(Piece p)
{
	switch (p)
	{
		case Piece::SKIPPY:
			return 'S';
			break;
		case Piece::KING:
			return 'K';
			break;
		case Piece::QUEEN:
			return 'Q';
			break;
		case Piece::ROOK:
			return 'r';
			break;
		case Piece::BISHOP:
			return 'b';
			break;
		case Piece::KNIGHT:
			return 'k';
			break;
		case Piece::PAWN:
			return 'p';
			break;
		default:
			return 'p';
	}
}

