#pragma once

class NodeFeuille {
private:
    char letter;
    int freq = 0;

public:

    NodeFeuille();
    NodeFeuille(vector<pair<char, int>> v, int index);
    ~NodeFeuille();

    //SETTERS
    void setLetter(char l);
    void setfreq(int f);

    //GETTERS
    char getLetter()const;
    int getFreq()const;
};

