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
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
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

Node *skipMdeleteN(Node *head, int M, int N)
{
    if (head == NULL || N == 0)
    {
        return head;
    }
    if (M == 0)
    {
        return NULL;
    }
    Node *temp = head, *temp1;
    int count;
    while (temp != NULL)
    {
        count = 1;
        while (count < M && temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        if (temp == NULL)
        {
            return head;
        }
        temp1 = temp->next;
        count = 1;
        while (count <= N && temp1 != NULL)
        {
            Node *k = temp1;
            temp1 = temp1->next;
            free(k);
            count++;
        }
        temp->next = temp1;
        temp = temp1;
    }
    return head;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeinput();
        int m, n;
        cin >> m >> n;
        head = skipMdeleteN(head, m, n);
        print(head);
    }
    return 0;
}