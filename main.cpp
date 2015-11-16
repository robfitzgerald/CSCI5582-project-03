#include <iostream>
#include "moves.h"
#include "helper.h"

int main (int argc, char** argv)
{
	chessRules c;
	std::vector<std::string> obstacles;
	std::string moveString;
	parseCommandLine(argc,argv,moveString,obstacles);

	std::vector<int> move = chessNotationToInt(moveString);


	int* obstacleBoard = new int [BOARD_MATRIX_SIZE];
	for (int i = 0; i < BOARD_MATRIX_SIZE; ++i) 
	{
		obstacleBoard[i] = 0;
	}
	for (int i = 0; i < obstacles.size(); ++i)
	{
		std::vector<int> pos = chessPositionToInt(obstacles[i]);
		obstacleBoard[coordToIndex(pos[0],pos[1],BOARD_MATRIX_LENGTH)] = 9;
	}
	c.trajectory(intToPiece(move[0]),move[1],move[2],move[3],move[4],obstacleBoard);

	return 0;
}