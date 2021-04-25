#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <queue>

#include "Node.h"

using namespace std;

void showVecNode(vector<Node*> v)
{
	vector<Node*> vec = v;

	for (int i = 0; i < vec.size(); i++)
	{
		cout << '\t' << vec[i]->getLetter() << ":" << vec[i]->getFreq();
	}
	cout << endl;
}

void showVecPair(vector<pair<char, int>> v)
{
	vector<pair<char, int>> vec = v;

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i].first << " //  " << vec[i].second;
		cout << endl;
	}
	cout << endl;
}


//test de tri

vector<pair<char, int>> sortVec(vector<pair<char, int>> v) {
	vector<pair<char, int>> vec = v;
	for (int i = v.size()-1; i > 1; i--) {
		for (int j = 0; j < i - 1; j++) {
			if (v[j + 1].second < v[j].second)
			{
				(v[j + 1], v[j]) = (v[j], v[j + 1]);
			}
		}
	}

	return vec;
}

int main()
{
	//DECLARE
	fstream fs;
	map<char, int> charMap;
	char c;
	vector<pair<char, int>> vecNode;
	pair <char, int> product1;
	
	//OPENING TXT
	fs.open("Lyrics.txt");
	
	//PLAYING LOOP
	while (fs.get(c))
	{
		
		//PRINTING TXT
		//cout << c;

		//MAP IMPLEMENTATION
		map<char, int>::iterator it = charMap.find(c);
		//IL EXISTE
		if (it == charMap.end())
		{
			charMap.insert({ c,1 });
		}

		//IL EXISTE PAS ENCORE
		else
		{
			it->second += 1;
		}
	}

	//PRINTING THE MAP ZEBI
	for (const auto & l : charMap) {
		cout << "Char: " << l.first << " = " << l.second << " fois" << endl;
		pair<char, int> pair(l.first, l.second);

		vecNode.push_back(pair);

		//Node* node = new Node(l.first, l.second);

	}

	showVecPair(vecNode);
	showVecPair(sortVec(vecNode));



	return 0;
}