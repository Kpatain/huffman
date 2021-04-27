#pragma once
#include <iostream>

class Node{
private:
    char c;
    int f;
    Node* gauche;
    Node* droite;

public:
    Node();
    Node(char c, int f);
    Node(int f, Node* g, Node* d);
    ~Node();

    //SETTERS
    void setFrenquency(int f);
    void setLetter(char c);
    void setChild(char ch, Node& ref);

    //GETTERS
    char getLetter();
    int getFrequency();
    Node* getChild(char ch);
};


