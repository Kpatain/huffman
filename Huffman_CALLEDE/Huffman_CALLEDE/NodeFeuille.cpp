#include "NodeFeuille.h"
#include <iostream>
#include <vector>

using namespace std;



NodeFeuille::NodeFeuille()
{

}


NodeFeuille::NodeFeuille(vector<pair<char, int>> v, int index)
{
	setLetter(v[index].first);
	setfreq(v[index].second);
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


//SETTERS
void NodeFeuille::setLetter(char l)
{
	letter = l;
}
void NodeFeuille::setfreq(int f)
{
	freq = f;
}

