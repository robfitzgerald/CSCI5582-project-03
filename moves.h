#ifndef moves_h
#define moves_h

void displayMoves(char*, int*);

const int REACHABILITY_MATRIX_SIZE = 225;
const int REACHABILITY_MATRIX_LENGTH = 15;
const int BOARD_MATRIX_SIZE = 64;
const int BOARD_MATRIX_LENGTH = 8;
enum class Piece { EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING, FIB, Count};
struct Position
{
	Position(char row, int col, const int len) {
		x = (int) row - len;
		y = col;
	}
	int x;
	int y;
};

class chessRules
{
public:
	chessRules();
	int* getReachability(Piece p) {
		return reachabilities[asInt(p)];
	}
	int** calculateEllipse(Piece p, int x1, int y1, int x2, int y2);
	int coordToIndex(int x, int y, int bound);
	Position indexToCoord(int index);
	int reverseIndex(int index);
	int asInt(Piece p);
private:
	int** reachabilities;
};
#endif