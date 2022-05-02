#include "class.h"
#ifndef LENGTH_H
#define LENGTH_H
int length(Node *head)
{
    int count=0;
    Node*temp=head;
    do{
        temp=temp->next;
        count++;
    }while(temp!=head);
    return count;
}
#endif