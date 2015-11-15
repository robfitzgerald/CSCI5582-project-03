#include <iostream>
#include "moves.h"
#include "helper.h"

int main (int argc, char** argv)
{
	std::vector<std::string> obstacles;
	std::string moveString;
	parseCommandLine(argc,argv,moveString,obstacles);
	chessRules c;

	return 0;
}