#include "class.h"

Node *insertion(Node *head, int position, int value)
{
    if (head == NULL)
    {
        return head;
    }
    Node *temp = head;
    Node *newNode = new Node(value);
    if (position == 0)
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
        return head;
    }
    else
    {
        int count = 0;
        while (count < position - 1)
        {
            temp = temp->next;
            count++;
        }
        if (temp->next == head)
        {
            temp->next = newNode;
            newNode->next = head;
        }
        else
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
        return head;
    }
}