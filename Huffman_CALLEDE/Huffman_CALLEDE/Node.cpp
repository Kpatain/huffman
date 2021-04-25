#include "Node.h"
#include "NodeFeuille.h"
#include <iostream>
#include <vector>

using namespace std;



Node::Node()
{

}


Node::Node(vector<pair<char, int>> v, int i)
{
	vector<pair<char, int>> vec = v;

	//son étages (0 = root)
	setIndex(i);


	int sum = 0;
	for (int i = i; i < vec.size(); i++)
	{
		sum = sum + vec[i].second;
	}

	//La somme restante
	settotal(sum);

	i = i + 1;

	// si on dépasse pas le nombre de type de char
	if (i < vec.size()) {
		//FEUILLE CREA
		NodeFeuille* feuille = new NodeFeuille(vec, i);

		//BRANCHE CREA
		Node* node = new Node(vec, i); // BAM CA MARCHE PAS super allé 
	}
	
}


Node::~Node()
{
	//cout << "nodeBranche mort" << endl;
}


//GETTERS
int Node::getTotal() const
{
	return total;
}
int Node::getIndex() const
{
	return index;
}


//SETTERS
void Node::settotal(int t)
{
	total = t;
}

void Node::setIndex(int i)
{
	index = i;
}
