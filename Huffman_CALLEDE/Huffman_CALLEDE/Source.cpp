#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	fstream fs;
	fs.open("Lyrics.txt");
	char c;
	while (fs.get(c))
	{
		cout << c;
	}

	return 0;
}