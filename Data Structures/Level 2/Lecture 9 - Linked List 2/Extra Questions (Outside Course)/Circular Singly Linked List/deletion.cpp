#include "class.h"

Node *deletion(Node *head, int position)
{
    if (head == NULL || (head->next == head && position == 0))
    {
        delete (head);
        return NULL;
    }
    int count = 0;
    Node *temp = head;
    if (position == 0)
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = head->next;
        head = head->next;
        return head;
    }
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    Node *temp1 = temp->next;
    temp->next = temp1->next;
    free(temp1);
    return head;
}