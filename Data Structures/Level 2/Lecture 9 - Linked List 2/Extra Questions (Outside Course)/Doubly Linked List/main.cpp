#include "class.h"
#include "print.cpp"
#include "insertion_at_specific_position.cpp"
#include "deletion_at_specific_position.cpp"
#include "reverse_doubly_linked_list.cpp"

Node *takeInput()
{
    int choice, data;
    cin >> choice;
    Node *previous = NULL, *next = NULL, *head = NULL, *tail = NULL;
    while (choice != -1)
    {
        cin >> data;
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
        cin >> choice;
    }
    return head;
}

int main()
{
    Node *head = takeInput();
    print(head);
    head = deletion_at_specific_position(head,9);
    print(head);
    return 0;
}