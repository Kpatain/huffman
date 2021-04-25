#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <queue>

#include "Node.h"
#include "NodeFeuille.h"

using namespace std;

/*
	Après moulte tentatives je ne comprend pas la stratégie de code à adopter (entre la question 4 et 5)
	j'essaye alors ici de créer l'arbre par récurrence (je créé la racine et l'arbre en découle)
	mais ne connaissant pas assez cet aspect du cpp je ne suis même passur que l'on puisse appeler un creator d'un node dans lui même !
	M'en voila bien penaud.
	Il manque encore les références entre node de toute sorte pour structuré un peu tout ça, mais bon je ne peux pas le tester 
	(brancheGauche* et brancheDroite* quelque chose comme ça). 
	Et la fin de ma crétion aussi n'est pas bonne (ne se fini pas par deux feuilles) 
	mais bon encore un fois je ne peux pas le tester de toute façcon je ne comprend vraiment pas pourquoi.

	" C2661	'Node::Node' : aucune fonction surchargée ne nécessite 2 arguments "

	alors que si techniquement       Node(vector<pair<char, int>> v, int index);        a 2 arguments ¯\_(--)_/¯

*/

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