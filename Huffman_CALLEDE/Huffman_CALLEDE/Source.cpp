#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <queue>

#include "Node.h"

using namespace std;

// on print un vecteur de node
void showvecNode(vector<Node*> v)
{
	vector<Node*> vec = v;

	for (int i = 0; i < vec.size(); i++)
	{
		cout << '\t' << vec[i]->getLetter() << ":" << vec[i]->getFrequency();
	}
	cout << endl;
}


int main()
{
	//DECLARE
	fstream fs;
	map<char, int> charMap;
	char c;
	vector<Node*> vecNode;
	
	//OPENING TXT
	fs.open("Lyrics.txt");
	
	//PLAYING LOOP
	while (fs.get(c))
	{
		
		//PRINTING TXT
		//cout << c;

		//MAP IMPLEMENTATION
		map<char, int>::iterator it = charMap.find(c);
		//il est la
		if (it == charMap.end())
		{
			charMap.insert({ c,1 });
		}

		//il est pas la
		else
		{
			it->second += 1;
		}
	}

	//On fait le vec de Node (tas de feuilles)
	for (const auto & l : charMap) {
		cout << "Char: " << l.first << " = " << l.second << " fois" << endl;
		Node* node = new Node(l.first, l.second);
		vecNode.push_back(node);
	}



	//On print vecNode
	showvecNode(vecNode);



	return 0;
}