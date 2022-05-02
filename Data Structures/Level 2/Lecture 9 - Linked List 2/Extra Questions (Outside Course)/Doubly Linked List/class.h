#include <iostream>
#ifndef CLASS_H
#define CLASS_H

using namespace std;

class Node
{
public:
    int data;
    Node *previous, *next;
    Node(int data)
    {
        this->data = data;
        this->previous = NULL;
        this->next = NULL;
    }
};

#endif