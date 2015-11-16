#include "graph.h"

node::node(){}

node::node(std::string s)
{
	thisMove = s;
}

node* node::getNode() 
{
	return this&;
}

node* node::getChildNode(unsigned i)
{
	node* output = null_ptr;
	if (i < children.size())
	{
		output = children[i];
	}
	return output;
}

unsigned node::childCount()
{
	return (unsigned) children.size();
}

void node::addChildNode(std::string s)
{
	node* child = new node(s);
	children.push_back(child);
}

std::string node::getMove()
{
	return thisMove;
}

