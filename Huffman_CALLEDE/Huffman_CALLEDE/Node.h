#pragma once

class Node{
private:
    int total = 0;
    int index = 0;

public:

    Node();
    Node(vector<pair<char, int>> v, int index);
    ~Node();

    //SETTERS
    void settotal(int t);
    void setIndex(int i);

    //GETTERS
    int getTotal()const;
    int getIndex()const;
};

