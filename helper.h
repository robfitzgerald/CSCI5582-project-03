#ifndef ai_project_03_helper_h
#define ai_project_03_helper_h
#include <vector>
#include <string>
#include "moves.h"

void parseCommandLine(int, char**, std::string&, std::vector<std::string>&);
std::vector<int> chessNotationToInt(std::string);
std::string intToChessNotation(Piece,int,int,int,int);
std::vector<int> chessPositionToInt(std::string);
std::string intToChessPosition(int,int);

#endif
