#pragma once

class Node{
private:
    char letter;
    int freq = 0;
    int total = 0;

public:

    Node();
    Node(char l, int f);
    Node(bool b, vector<pair<char, int>> v, int index);
    ~Node();

    //SETTERS
    void setLetter(char l);
    void setfreq(int f);
    void settotal(int t);

    //GETTERS
    char getLetter()const;
    int getFreq()const;
    int getTotal()const;
};

