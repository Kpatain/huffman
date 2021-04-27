#include "Node.h"


Node::Node() {
	c = ' ';
	f = 0;
	Node* gauche;
	Node* droite;
}


Node::Node(char c, int f) {
	c = c;
	f = f;
	Node* gauche;
	Node* droite;
}

Node::Node(int fr, Node* g, Node* d) {
	c = ' ';
	f = fr;
	gauche = g;
	droite = d;
}



Node::~Node()
{
	//cout << "nodeBranche mort" << endl;
}


char Node::getLetter() {
	return c;
}

int Node::getFrequency() {
	return f;
}

Node* Node::getChild(char child) {
	if (child == 'g') 
	{
		return gauche;
	}

	else if(child == 'd')
	{
		return droite;
	}

	else
	{
		std::cout << "wrong child, retry:\n";
		std::cin >> child;

		getChild(child);
	}
}


void Node::setChar(char ch) {
	c = ch;
}



void Node::setFrenquency(int fr) {
	f = fr;
}


void Node::setChild(char child, Node& ref) {
	if (child == 'g')
	{
		gauche = &ref;
	}

	else if (child == 'd')
	{
		droite = &ref;
	}

	else
	{
		std::cout << "wrong child, retry:\n";
		std::cin >> child;

		setChild(child, ref);
	}
}
