#include "Node.h"


Node::Node() {
	c = ' ';
	f = 0;
	Node* gauche;
	Node* droite;
}


Node::Node(char ch, int fr) {
	c = ch;
	f = fr;
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
	//std::cout << "node mort" << std::endl;
}

//GETTERS
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

	else if (child == 'd')
	{
		return droite;
	}
}

//SETTERS
void Node::setLetter(char ch) {
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
}
