#include "class.h"
Node *reverse(Node *head)
{
    Node *previous = NULL;
    Node *current = head;
    Node *temp;
    do
    {
        temp = current->next;
        current->next = previous;
        previous = current;
        current = temp;
    } while (current != head);
    
    head->next = previous;
    return previous;
}