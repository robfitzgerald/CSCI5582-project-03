#ifndef ai_project_03_moves_h
#define ai_project_03_moves_h

#include <vector>
#include <string>

const int REACHABILITY_MATRIX_SIZE = 225;
const int REACHABILITY_MATRIX_LENGTH = 15;
const int BOARD_MATRIX_SIZE = 64;
const int BOARD_MATRIX_LENGTH = 8;
enum class Piece { EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING, SKIPPY, Count};

void displayBoard(char*, int*, int);
Piece charToPiece(char);
Piece intToPiece(int);
char pieceToChar(Piece);
int asInt(Piece p);

struct Position
{
	Position(int row, int col, const int len) 
	{
		x = row;
		y = col;
		length = len;
	}
	Position() 
	{
		x = 0;
		y = 0;
		length = 0;
	}
	int x;
	int y;
	int length;
};

class chessRules
{
public:
	chessRules();
	void trajectory(Piece p, int x1, int y1, int x2, int y2, int length, int* obstacles);
	std::vector<std::vector<int> > _trajectory(Piece p, int x1, int y1, int thisX, int thisY, int dstep, int d, int* sum, std::vector<int> path, std::string moveString);
	int* genEllipse(Piece p, int x1, int y1, int x2, int y2, int d, int* ob);
	int* genMove(Piece p, int x, int y, int d);
	int coordToIndex(int x, int y, int bound);
	Position indexToCoord(int index, int bound);
	int reverseIndex(int index);
	
private:
	int** reachabilities;
	int* PAWN_REVERSE;
};

#endif