#include "class.h"

Node *reverse(Node *head)
{
    Node *prev = NULL, *current = head, *temp;
    do
    {
        temp = current->next;
        current->next = prev;
        current->previous = temp;
        prev = current;
        current = temp;
    } while (current != head);
    current->next = prev;
    prev->previous = current;
    return prev;
}