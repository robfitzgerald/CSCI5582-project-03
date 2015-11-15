#include "helper.h"

void parseCommandLine(int argc, char** argv, std::string& move, std::vector<std::string>& obstacles)
{
	if (argc > 2)
	{
		// has obstacles
		for (int i = 2; i < argc; ++i)
		{
			obstacles.push_back(new std::string(argv[i]));
		}
	}
	if (argc > 1)
	{
		// has a move
		move = new std::string(argv[1]);
	}
}

std::vector<int> chessNotationToInt(std::string moveString)
{
    std::vector<int> output;
    output.push_back(charToPiece(moveString.getChar(0)));
    output.push_back(moveString.getChar(1) - 97);
    output.push_back(moveString.getChar(2) - 49);
    output.push_back(moveString.getChar(3) - 97);
    output.push_back(moveString.getChar(4) - 49);
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