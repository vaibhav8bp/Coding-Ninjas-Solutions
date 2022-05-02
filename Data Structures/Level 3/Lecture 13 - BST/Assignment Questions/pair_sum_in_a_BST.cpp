#include <iostream>
#include <stack>
#include <queue>
using namespace std;

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

    ~BinaryTreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
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

void printLevelATNewLine(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL)
        {
            if (q.empty())
            {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL)
        {
            q.push(first->left);
        }
        if (first->right != NULL)
        {
            q.push(first->right);
        }
    }
}

int totalNodes(BinaryTreeNode<int> *root)
{
    if (!root)
    {
        return 0;
    }
    return 1 + totalNodes(root->left) + totalNodes(root->right);
}

void printNodesSumToS(BinaryTreeNode<int> *root, int s)
{
    if (!root)
    {
        return;
    }
    stack<BinaryTreeNode<int> *> inOrder, revInOrder;
    BinaryTreeNode<int> *currentNode = root;

    while (currentNode)
    {
        inOrder.push(currentNode);
        currentNode = currentNode->left;
    }

    currentNode = root;

    while (currentNode)
    {
        revInOrder.push(currentNode);
        currentNode = currentNode->right;
    }

    int total = totalNodes(root);
    int count = 0;

    while (count < total - 1)
    {
        BinaryTreeNode<int> *inOrderTop = inOrder.top();
        BinaryTreeNode<int> *revInOrderTop = revInOrder.top();
        if (inOrderTop->data + revInOrderTop->data == s)
        {
            cout << inOrderTop->data << " " << revInOrderTop->data << endl;
            BinaryTreeNode<int> *top = inOrderTop;
            inOrder.pop();
            count++;
            if (top->right)
            {
                top = top->right;
                while (top)
                {
                    inOrder.push(top);
                    top = top->left;
                }
            }
            top = revInOrderTop;
            revInOrder.pop();
            count++;
            if (top->left)
            {
                top = top->left;
                while (top)
                {
                    revInOrder.push(top);
                    top = top->right;
                }
            }
        }
        else if (inOrderTop->data + revInOrderTop->data > s)
        {
            BinaryTreeNode<int> *top = revInOrderTop;
            revInOrder.pop();
            count++;
            if (top->left)
            {
                top = top->left;
                while (top)
                {
                    revInOrder.push(top);
                    top = top->right;
                }
            }
        }
        else
        {
            BinaryTreeNode<int> *top = inOrderTop;
            inOrder.pop();
            count++;
            if (top->right)
            {
                top = top->right;
                while (top)
                {
                    inOrder.push(top);
                    top = top->left;
                }
            }
        }
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int s;
    cin >> s;
    printNodesSumToS(root, s);
    delete root;
}