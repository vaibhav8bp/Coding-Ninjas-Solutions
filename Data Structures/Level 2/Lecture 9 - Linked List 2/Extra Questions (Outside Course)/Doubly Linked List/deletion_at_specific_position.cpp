#include "class.h"

Node *deletion_at_specific_position(Node *head, int position)
{
    if (head == NULL || (head->next == NULL && position == 0))
    {
        return NULL;
    }
    
    int count = 0;
    Node *temp = head;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    Node *temp1 = temp->next;
    if (temp1->next == NULL)
    {
        temp->next = NULL;
        free(temp1);
    }
    else
    {
        if (temp->previous == NULL)
        {
            head = head->next;
            head->previous = NULL;
        }
        else
        {
            temp->next = temp1->next;
            temp1->next->previous = temp;
            free(temp1);
        }
    }
    return head;
}