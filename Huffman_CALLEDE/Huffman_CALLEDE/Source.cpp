#include <iostream>
#include <fstream>
#include <map>
#include <vector>

#include "Node.h"

using namespace std;

void showVec(vector<Node*> v)
{
	vector<Node*> vec = v;

	for (int i = 0; i < vec.size(); i++)
	{
		cout << '\t' << vec[i]->getLetter() << ":" << vec[i]->getFreq();
	}
	cout << endl;
}

//test de tri

void sortMap(map<char, int> m) {
	map<char, int> map = m;
	for (int i = m.size()-1; i > 1; i--) {
		for (int j = 0; j < i - 1; j++) {
			if (l.second < map.begin()->second)
		}
	}
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
		std::cout << "Char: " << l.first << " = " << l.second << " fois" << endl;

		Node* node = new Node(l.first, l.second);


	}



	




	return 0;
}