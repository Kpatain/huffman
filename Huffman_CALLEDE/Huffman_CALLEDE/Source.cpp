#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <queue>

#include "Node.h"
#include "NodeFeuille.h"

using namespace std;

// on print un vecteur de nodeFeuille
void showvecNode(vector<NodeFeuille*> v)
{
	vector<NodeFeuille*> vec = v;

	for (int i = 0; i < vec.size(); i++)
	{
		cout << '\t' << vec[i]->getLetter() << ":" << vec[i]->getFreq();
	}
	cout << endl;
}

//on print le vecteur des occurences
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



//SORTING
bool sortbysec(const pair<int, int>& a,
	const pair<int, int>& b)
{
	return (a.second < b.second);
}

int main()
{
	//DECLARE
	fstream fs;
	map<char, int> charMap;
	char c;
	vector<pair<char, int>> vecList;
	vector<NodeFeuille*> vecNode;
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

	//On fait la map a partir du texte
	for (const auto & l : charMap) {
		cout << "Char: " << l.first << " = " << l.second << " fois" << endl;
		pair<char, int> pair(l.first, l.second);

		// et on l'a met dans un tableau enfaite parceque c'est plus facile a trier
		vecList.push_back(pair);
	}

	//On crée un tas de feuilles au moins et on les stacks dans vecNode
	for (int i = i; i < vecList.size(); i++)
	{
		//Tas de feuilles
		NodeFeuille* nodeFeuille = new NodeFeuille(vecList,i);
		vecNode.push_back(nodeFeuille);
	}

	//On print vecNode
	showvecNode(vecNode);

	//On re ordre un peu vecList
	showVecPair(vecList);
	sort(vecList.begin(), vecList.end(), sortbysec);
	reverse(vecList.begin(), vecList.end());
	showVecPair(vecList);

	//puis on créé l'arbre en récurrence
	Node* node = new Node(vecList, -1);


	return 0;
}