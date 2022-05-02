#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *reverse_LL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *smallAnswer = reverse_LL(head->next);
    Node *tail = head->next;
    tail->next = head;
    head->next = NULL;
    return smallAnswer;
}

Node *NextLargeNumber(Node *head)
{
    head = reverse_LL(head);
    Node *current = head, *previous = NULL;
    int carry = 1;
    while (current != NULL)
    {
        current->data = ((current->data) + carry) % 10;
        carry = ((current->data) + carry) / 10;
        previous = current;
        current = current->next;
    }
    if (carry != 0)
    {
        Node *newNode = new Node(carry);
        previous->next = newNode;
    }
    head = reverse_LL(head);
    return head;
}

// Node *helper(Node *head)
// {
//     if (head->next == NULL)
//     {
//         head->data++;
//         return head;
//     }
//     head->next = helper(head->next);
//     if (head->next->data > 9)
//     {
//         head->next->data = 0;
//         head->data += 1;
//     }
//     return head;
// }
// Node *NextLargeNumber(Node *head)
// {
//     head = helper(head);

//     if (head->data > 9)
//     {
//         Node *temp = new Node(1);
//         head->data = 0;
//         temp->next = head;
//         head = temp;
//     }
//     return head;
// }

int main()
{
    Node *head = takeinput();
    head = NextLargeNumber(head);
    print(head);
    return 0;
}