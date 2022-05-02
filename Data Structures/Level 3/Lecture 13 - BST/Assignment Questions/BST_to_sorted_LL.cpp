#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int> *takeInput()
{
    int rootData;

    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

class answer
{
public:
    Node<int> *head;
    Node<int> *tail;

    answer()
    {
        head = tail = NULL;
    }
};

answer constructLinkedListHelper(BinaryTreeNode<int> *root)
{
    answer a;
    if (root == NULL)
    {
        return a;
    }

    answer l = constructLinkedListHelper(root->left);
    answer r = constructLinkedListHelper(root->right);

    Node<int> *newNode = new Node<int>(root->data);
    
    if (l.head == NULL)
    {
        l.head = l.tail = newNode;
    }
    else
    {
        l.tail->next = newNode;
        l.tail = newNode;
    }

    l.tail->next = r.head;

    a.head = l.head;

    if (r.tail)
    {
        a.tail = r.tail;
    }
    else
    {
        a.tail = newNode;
    }

    return a;
}

Node<int> *constructLinkedList(BinaryTreeNode<int> *root)
{
    return constructLinkedListHelper(root).head;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    Node<int> *head = constructLinkedList(root);

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}