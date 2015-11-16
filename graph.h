#ifndef ai_project_03_graph_h
#define ai_project_03_graph_h

#include <vector>
#include <string>

class node
{
public:
	node();
	node(std::string);
	node* getNode();
	node* getChildNode(unsigned);
	unsigned childCount();
	void addChildNode(std::string);
	std::string getMove();
private:
	std::vector<node*> children;
	std::string thisMove;
};



#endif