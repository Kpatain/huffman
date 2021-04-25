#include "NodeFeuille.h"
#include <iostream>
#include <vector>

using namespace std;



NodeFeuille::NodeFeuille()
{

}


NodeFeuille::NodeFeuille(vector<pair<char, int>> v, int i)
{
	vector<pair<char, int>> vec = v;
	//On lui dit qui il est pas son char et la freq du char
	setLetter(vec[i].first);
	setfreq(vec[i].second);

	//et son etage dans l'arbre
	setIndex(i);
}

NodeFeuille::~NodeFeuille()
{
	//cout << "adios NodeFeuille" << endl;
}


//GETTERS
char NodeFeuille::getLetter()const
{
	return letter;
}
int NodeFeuille::getFreq() const
{
	return freq;
}
int NodeFeuille::getIndex() const
{
	return index;
}



//SETTERS
void NodeFeuille::setLetter(char l)
{
	letter = l;
}
void NodeFeuille::setfreq(int f)
{
	freq = f;
}
void NodeFeuille::setIndex(int i)
{
	index = i;
}

