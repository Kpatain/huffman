#include "Node.h"
#include <iostream>
#include <vector>

using namespace std;



Node::Node()
{
	//Node* n = new Node(l, 25, 1);
	//n = new Node(l, 25, 0);

}

Node::Node(char l, int f)
{
	setLetter(l);
	setfreq(f);
}

Node::Node(bool b, vector<pair<char, int>> v, int index)
{
	int sum = 0;
	for (int i = index; i < v.size(); i++)
	{
		sum = sum + v[i].second;
	}

	if (b)
	{
		settotal(sum);
		index = index + 1;
		Node* node = new Node(1, v, index);

	}
	else
	{
		setLetter(v[index].first);
		setfreq(v[index].second);
		Node* node = new Node(0, v, index);
	}

}

Node::~Node()
{
	//cout << "Detruit" << endl;
}

//FONCTION DE CRETION DE NODE
//void Node::createNode(int index)

//GETTERS
char Node::getLetter()const
{
	return letter;
}
int Node::getFreq() const
{
	return freq;
}
int Node::getTotal() const
{
	return total;
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
void Node::settotal(int t)
{
	total = t;
}
