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

//on sort 
void bubbleSort(vector<Node*> v) {
	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = 0; j < v.size() - i - 1; j++) {
			if (v[j]->getFrequency() < v[j + 1]->getFrequency()) {
				Node buff(v[j]->getLetter(), v[j]->getFrequency());
				v[j]->setLetter(v[j + 1]->getLetter());
				v[j]->setFrenquency(v[j + 1]->getFrequency());				// j'ai piqué ces 4 lignes a mosieur Brieux
				v[j + 1]->setLetter((buff.getLetter()));					// mon precedant bubble (precedent push je crois) était
				v[j + 1]->setFrenquency(buff.getFrequency());				// pour des vecteur est j'ai pas réussi a l'adapté pour les nodes en 
			}																// si peu de temps (lundi -> mercredi) j'ai voulu surtout tenté plus loin (questions 6 et +)
		}																	// bon au final ca marché pas j'ai enlevé mais je ne voulais pas passé trop de temps la dessus
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
	for (const auto& l : charMap) {
		cout << "Char: " << l.first << " = " << l.second << " fois" << endl;
		Node* node = new Node(l.first, l.second);
		vecNode.push_back(node);
	}



	//On tri et print vecNode
	bubbleSort(vecNode);
	showvecNode(vecNode);



	return 0;
}