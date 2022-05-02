#include <iostream>
#include <queue>
#include <vector>
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

vector<int> *getPath(BinaryTreeNode<int> *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == data)
    {
        vector<int> *answer = new vector<int>();
        answer->push_back(root->data);
        return answer;
    }
    else if (data < root->data)
    {
        vector<int> *left_answer = getPath(root->left, data);
        if (left_answer)
        {
            left_answer->push_back(root->data);
            return left_answer;
        }
    }
    else
    {
        vector<int> *right_answer = getPath(root->right, data);
        if (right_answer)
        {
            right_answer->push_back(root->data);
            return right_answer;
        }
    }
    return NULL;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int k;
    cin >> k;
    vector<int> *output = getPath(root, k);

    if (output != NULL)
    {
        for (int i = 0; i < output->size(); i++)
        {
            cout << output->at(i) << " ";
        }
    }

    delete root;
}