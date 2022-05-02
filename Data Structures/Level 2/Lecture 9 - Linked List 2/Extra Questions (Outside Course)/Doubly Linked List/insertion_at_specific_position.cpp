#include "class.h"

// This code will not work if position is greater than the length of the linked list.

Node *insert(Node *head, int position, int value)
{
    Node *newNode = new Node(value);

    if (head == NULL)
    {
        if (position == 0)
        {
            head = newNode;
        }
        return head;
    }

    int count = 0;
    Node *temp = head;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    newNode->next = temp->next;
    
    if (temp->next != NULL)
    {
        newNode->next->previous = newNode;
    }

    if (temp->previous != NULL)
    {
        temp->next = newNode;
        newNode->previous = temp;
    }
    else
    {
        head = newNode;
    }
    
    return head;
}