#pragma once

class Node{
private:
    char letter;
    int freq = 0;

public:

    Node();
    Node(char l, int f);
    ~Node();

    //SETTERS
    void setLetter(char l);
    void setfreq(int f);

    //GETTERS
    char getLetter()const;
    int getFreq()const;
};

