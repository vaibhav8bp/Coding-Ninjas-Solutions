#include <iostream>
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
        this->left = NULL;
        this->right = NULL;
    }
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        int leftChildData, rightChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            pendingNodes.push(leftChild);
            front->left = leftChild;
        }
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            pendingNodes.push(rightChild);
            front->right = rightChild;
        }
        pendingNodes.pop();
    }
    return root;
}

vector<int> *getRootToNodePath(BinaryTreeNode<int> *root, int key)
{
    if (!root)
    {
        return NULL;
    }

    if (root->data == key)
    {
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    vector<int> *left_answer = getRootToNodePath(root->left, key);
    if (left_answer)
    {
        left_answer->push_back(root->data);
        return left_answer;
    }
    else
    {
        vector<int> *right_answer = getRootToNodePath(root->right, key);
        if (right_answer)
        {
            right_answer->push_back(root->data);
            return right_answer;
        }
    }
    return NULL;
}

void print(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    if (root->left != NULL)
    {
        cout << " L : " << root->left->data << ",";
    }
    if (root->right != NULL)
    {
        cout << " R : " << root->right->data;
    }
    cout << endl;
    print(root->left);
    print(root->right);
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    vector<int> *answer = getRootToNodePath(root, 10);
    for (int i = 0; i < answer->size(); i++)
    {
        cout << answer->at(i) << " ";
    }
    cout << endl;
    return 0;
}

// 8 3 -1 10 -1 1 -1 6 4 -1 14 7 -1 -1 -1 13 -1 -1 -1

// 1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1