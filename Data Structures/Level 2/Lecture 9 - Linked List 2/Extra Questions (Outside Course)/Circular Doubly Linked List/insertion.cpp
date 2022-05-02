#include "class.h"

Node *insertion(Node *head, int position, int value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        if (position == 0)
        {
            head = newNode;
            head->next = head->previous = head;
        }
    }
    if (position == 0)
    {
        newNode->next = head;
        newNode->previous = head->previous;
        head->previous->next = newNode;
        newNode->next->previous = newNode;
        head = newNode;
    }
    else
    {
        int count = 0;
        Node *temp = head;
        while (count < position - 1)
        {
            temp = temp->next;
            count++;
        }
        newNode->next = temp->next;
        newNode->next->previous = newNode;
        newNode->previous = temp;
        temp->next = newNode;
    }
    return head;
}