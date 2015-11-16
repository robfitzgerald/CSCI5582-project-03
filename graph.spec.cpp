#include <iostream>
#include "graph.h"


int main()
{

	node* head = new node;
	head.addChildNode("move1");
	head.addChildNode("move2");
	std::cout << "number of children should be 2: " << node.childCount() << "\n";
	for (int i = 0; i < node.childCount(); ++i)
	{
		node* child = head.getChildNode(i);
		std::cout << "child " << i << " is " << child.getMove() << ".\n";
	}

	return 0;
}