#include <iostream>
#include <vector>
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
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

vector<int> *longestPath(BinaryTreeNode<int> *root)
{
    if (!root)
    {
        return NULL;
    }
    if (!root->left && !root->right)
    {
        vector<int> *answer = new vector<int>;
        answer->push_back(root->data);
        return answer;
    }
    vector<int> *left_answer = longestPath(root->left);
    vector<int> *right_answer = longestPath(root->right);

    if (!left_answer)
    {
        right_answer->push_back(root->data);
        return right_answer;
    }
    else if (!right_answer)
    {
        left_answer->push_back(root->data);
        return left_answer;
    }
    else
    {
        if (left_answer->size() > right_answer->size())
        {
            left_answer->push_back(root->data);
            return left_answer;
        }
        else
        {
            right_answer->push_back(root->data);
            return right_answer;
        }
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    vector<int> *output = longestPath(root);
    vector<int>::iterator i = output->begin();
    while (i != output->end())
    {
        cout << *i << endl;
        i++;
    }
}