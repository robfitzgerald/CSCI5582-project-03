#include <iostream>
#include "moves.h"
#include "helper.h"

int main (int argc, char** argv)
{
	std::vector<std::string> obstacles;
	std::string moveString;
	parseCommandLine(argc,argv,moveString,obstacles);
	std::cout << moveString << "\n";
	for (int i = 0; i < obstacles.size(); ++i)
	{
		std::cout << obstacles[i] << ", ";
	}
	std::cout << "\n";
	std::cout << "move as integers:\n";
	std::vector<int> moveAsInts = chessNotationToInt(moveString);
	for (int i = 0; i < moveAsInts.size(); ++i)
	{
		std::cout << moveAsInts[i] << ",";
	}
	std::cout << std::endl;
	std::string backToString = intToChessNotation((Piece)moveAsInts[0],moveAsInts[1],moveAsInts[2],moveAsInts[3],moveAsInts[4]);
	std::cout << "back to string: " << backToString << "\n";
	return 0;
}