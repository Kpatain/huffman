#include "Node.h"
#include "NodeFeuille.h"
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

Node::Node(vector<pair<char, int>> v, int index)
{
	int sum = 0;
	for (int i = index; i < v.size(); i++)
	{
		sum = sum + v[i].second;
	}

	index = index + 1;

	//FEUILLE
	NodeFeuille* feuille = new NodeFeuille(v, index);

	//BRANCHE
	settotal(sum);
	Node* node = new Node(v, index);
}

Node::Node(vector<pair<char, int>> v, int index)
{
	setLetter(v[index].first);
	setfreq(v[index].second);
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
