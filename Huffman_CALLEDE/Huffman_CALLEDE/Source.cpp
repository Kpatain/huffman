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
	Apr�s moulte tentatives je ne comprend pas la strat�gie de code � adopter (entre la question 4 et 5)
	j'essaye alors ici de cr�er l'arbre par r�currence (je cr�� la racine et l'arbre en d�coule)
	mais ne connaissant pas assez cet aspect du cpp je ne suis m�me passur que l'on puisse appeler un creator d'un node dans lui m�me !
	M'en voila bien penaud.
	Il manque encore les r�f�rences entre node de toute sorte pour structur� un peu tout �a, mais bon je ne peux pas le tester 
	(brancheGauche* et brancheDroite* quelque chose comme �a). 
	Et la fin de ma cr�tion aussi n'est pas bonne (ne se fini pas par deux feuilles) 
	mais bon encore un fois je ne peux pas le tester de toute fa�con je ne comprend vraiment pas pourquoi.

	" C2661	'Node::Node'�: aucune fonction surcharg�e ne n�cessite 2 arguments "

	alors que si techniquement       Node(vector<pair<char, int>> v, int index);        a 2 arguments �\_(--)_/�

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

	//On cr�e un tas de feuilles au moins et on les stacks dans vecNode
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

	//puis on cr�� l'arbre en r�currence
	Node* node = new Node(vecList, -1);


	return 0;
}