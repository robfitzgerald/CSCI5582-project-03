#include <iostream>
#include "moves.h"

int main() {

	chessRules c;
	for (int i = 0; i < REACHABILITY_MATRIX_LENGTH; ++i)
	{
		std::cout << "index for " << i << "," << i << ": ";
		std::cout << c.coordToIndex(i,i,REACHABILITY_MATRIX_LENGTH) << "\n";
	}

	return 0;
}