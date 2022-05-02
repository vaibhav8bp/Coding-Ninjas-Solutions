#include "class.h"
Node *deletion(Node *head, int position)
{
    if (head == NULL || (head->next == NULL && position == 0))
    {
        return NULL;
    }
    if (position == 0)
    {
        head->previous->next = head->next;
        head->next->previous = head->previous;
        head = head->next;
        return head;
    }
    Node *temp = head;
    int count = 0;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    temp->next = temp->next->next;
    temp->next->next->previous = temp;
    return head;
}