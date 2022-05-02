#include <iostream>
#include "class.h"
#include "print.cpp"
#include "insertion.cpp"
#include "deletion.cpp"
#include "reverse.cpp"

using namespace std;

Node *takeInput()
{
    Node *tail, *head = NULL;
    int choice, data;
    cin >> choice;
    while (choice != -1)
    {
        cin >> data;
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            tail->next = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
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