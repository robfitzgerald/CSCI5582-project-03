#include <iostream>

void displayMoves(char* piece, int* board)
{
	std::cout << "\n  --------";
	int pieceIter = 0;
	while (piece[pieceIter]) {
		std::cout << piece[pieceIter];
		++pieceIter;
	}
	std::cout << "--------\n";
	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 15; ++j) {
			std::cout << board[(i*15)+j] << " ";
		}
		std::cout << "\n\n";
	}
}

int main()
{
	const int king [225] = { 
		7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
	    7,6,6,6,6,6,6,6,6,6,6,6,6,6,7,
 	    7,6,5,5,5,5,5,5,5,5,5,5,5,6,7,
		7,6,5,4,4,4,4,4,4,4,4,4,5,6,7,
		7,6,5,4,3,3,3,3,3,3,3,4,5,6,7,
		7,6,5,4,3,2,2,2,2,2,3,4,5,6,7,
		7,6,5,4,3,2,1,1,1,2,3,4,5,6,7,
		7,6,5,4,3,2,1,0,1,2,3,4,5,6,7,
		7,6,5,4,3,2,1,1,1,2,3,4,5,6,7,
		7,6,5,4,3,2,2,2,2,2,3,4,5,6,7,
		7,6,5,4,3,3,3,3,3,3,3,4,5,6,7,
		7,6,5,4,4,4,4,4,4,4,4,4,5,6,7,
		7,6,5,5,5,5,5,5,5,5,5,5,5,6,7,
		7,6,6,6,6,6,6,6,6,6,6,6,6,6,7,
		7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
					 };
	const int queen [225] = {
		1,2,2,2,2,2,2,1,2,2,2,2,2,2,1,
	    2,1,2,2,2,2,2,1,2,2,2,2,2,1,2,
 	    2,2,1,2,2,2,2,1,2,2,2,2,1,2,2,
		2,2,2,1,2,2,2,1,2,2,2,1,2,2,2,
		2,2,2,2,1,2,2,1,2,2,1,2,2,2,2,
		2,2,2,2,2,1,2,1,2,1,2,2,2,2,2,
		2,2,2,2,2,2,1,1,1,2,2,2,2,2,2,
		1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,
		2,2,2,2,2,2,1,1,1,2,2,2,2,2,2,
		2,2,2,2,2,1,2,1,2,1,2,2,2,2,2,
		2,2,2,2,1,2,2,1,2,2,1,2,2,2,2,
		2,2,2,1,2,2,2,1,2,2,2,1,2,2,2,
		2,2,1,2,2,2,2,1,2,2,2,2,1,2,2,
		2,1,2,2,2,2,2,1,2,2,2,2,2,1,2,
		1,2,2,2,2,2,2,1,2,2,2,2,2,2,1,
					 };
	}
 	displayMoves("king", king);
 	displayMoves("queen", queen);
	return 0;
}

