#include "Node.h"
#include <iostream>

using namespace std;



Node::Node()
{
	Node* n = new Node(l, 25, 1);
	n = new Node(l, 25, 0);

}

Node::Node(char l, int f)
{
	setLetter(l);
	setfreq(f);
}

Node::~Node()
{
	//cout << "Detruit" << endl;
}

//GETTERS
char Node::getLetter()const
{
	return letter;
}
int Node::getFreq() const
{
	return freq;
}


//SETTERS
void Node::setLetter(char l)
{
	letter = l;
}
void Node::setfreq(int f)
{
	freq = f;
}
