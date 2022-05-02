#include "class.h"
#include "print.cpp"
#include "insertion.cpp"
#include "deletion.cpp"
#include "reverse.cpp"
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
            head = tail = newNode;
            head->next = head->previous = head;
        }
        else
        {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
            tail->next = head;
            head->previous = tail;
        }
        cin >> choice;
    }
    return head;
}

int main()
{
    Node *head = takeInput();
    print(head);
    head = insertion(head,9,100);
    print(head);
    return 0;
}

// 1 10 2 20 3 30 4 40 5 50 6 60 7 70 8 80 9 90 -1