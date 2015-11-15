#include "helper.h"
#include <iostream>

void parseCommandLine(int argc, char** argv, std::string& move, std::vector<std::string>& obstacles)
{
	if (argc > 2)
	{
		// has obstacles
		for (int i = 2; i < argc; ++i)
		{
			obstacles.push_back(std::string(argv[i]));
		}
	}
	if (argc > 1)
	{
		// has a move
		move = std::string(argv[1]);
	}
}

std::vector<int> chessNotationToInt(std::string moveString)
{
    std::vector<int> output;
    if (moveString.length() == 6)
    {
    	output.push_back((int)charToPiece(moveString.at(0)));
	    output.push_back(moveString.at(1) - 97);
	    output.push_back(moveString.at(2) - 49);
	    // position 3 is a hyphen.
	    output.push_back(moveString.at(4) - 97);
	    output.push_back(moveString.at(5) - 49);
    }

    return output;
}

std::string intToChessNotation(Piece p, int x1, int y1, int x2, int y2) {
    std::string output;
    output.push_back(pieceToChar(p));
    output.push_back(97 + x1);
    output.push_back(49 + y1);
    output.push_back('-');
    output.push_back(97 + x2);
    output.push_back(49 + y2);
    return output;
}

std::vector<int> chessPositionToInt(std::string pos)
{
	std::vector<int> output;
    output.push_back(pos.at(0) - 97);
    output.push_back(pos.at(1) - 49);
    return output;
}

std::string intToChessPosition(int x, int y)
{
	std::string output;
    output.push_back(97 + x);
    output.push_back(49 + y);
    return output;	
}
