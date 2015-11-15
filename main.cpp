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

	return 0;
}