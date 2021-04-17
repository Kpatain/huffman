#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main()
{
	//DECLARE
	fstream fs;
	map<char, int> charMap;
	char c;
	
	//OPENING TXT
	fs.open("Lyrics.txt");
	
	//PLAYING LOOP
	while (fs.get(c))
	{
		
		//PRINTING TXT
		cout << c;

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
	for (const auto& p : charMap) {
		std::cout << "Char [" << p.first << "] = " << p.second << " iterations." << endl;
	}

	return 0;
}