#include "class.h"

Node *reverseDoublyLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *temp = NULL, *current = head, *previous = NULL;
    while (current != NULL)
    {
        temp = current->next;
        current->next = previous;
        current->previous = temp;
        previous = current;
        current = temp;
    }
    return previous;
}