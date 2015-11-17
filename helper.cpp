#include "helper.h"
#include <iostream>

void parseCommandLine(int argc, char** argv, std::string& move, int& length, std::vector<std::string>& obstacles)
{
	// ./trajectories <move> <length>
	if (argc > 3)
	{
		// has obstacles
		for (int i = 3; i < argc; ++i)
		{
			obstacles.push_back(std::string(argv[i]));
		}
	}
	if (argc > 2)
	{
		// has a move and length
		move = std::string(argv[1]);
		length = atoi(argv[2]);
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

int coordToIndex(int x, int y, int bound) {
	if (0 <= x && x <= bound && 0 <= y && y <= bound) 
	{
		return x + (y * bound);
	} else {
		return -1;
	}
}

bool invalidInput(std::vector<int> input, int numberOfPieceTypes)
{
	return !(
		// left as expected values within parens for readability,
		// negated outside of parens.
		input.size() == 5 &&
		0 <= input[0] &&
		input[0] < numberOfPieceTypes &&
		0 <= input[1] &&
		input[1] < 8 &&
		0 <= input[2] &&
		input[2] < 8 &&
		0 <= input[3] &&
		input[3] < 8 &&
		0 <= input[4] &&
		input[4] < 8
		);
}

void printUsageToConsole()
{
	std::cout << std::endl;
	std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=- Chess Trajectories =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
	std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
	std::cout << "- usage:                                                                     =\n";
	std::cout << "= ./trajectories <chess-move> <length> [<obstacle> ..]                       -\n";
	std::cout << "- <chess-move> : <piece><position>-<position>  (example: Ka4-h4)             =\n";
	std::cout << "= <piece> : K   | Q    | r   | b     | k     | p   | S                       -\n";
	std::cout << "-           King  Queen  rook  bishop  knight  pawn  Skippy-the-wonder-piece =\n";
	std::cout << "= <position> : ([a-g][1-8])                                                  -\n";
	std::cout << "- <length> : [1-7]                                                           =\n";
	std::cout << "= <obstacle> : <position>                                                    -\n";
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
	std::cout << "\n";
}
