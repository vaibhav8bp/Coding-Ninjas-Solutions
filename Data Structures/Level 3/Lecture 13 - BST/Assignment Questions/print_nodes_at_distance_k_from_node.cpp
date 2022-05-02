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
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printNodeAtDepthKDownward(BinaryTreeNode<int> *root, int k)
{
    if (!root)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }
    printNodeAtDepthKDownward(root->left, k - 1);
    printNodeAtDepthKDownward(root->right, k - 1);
}

int helper(BinaryTreeNode<int> *root, int node, int k)
{
    if (!root)
    {
        return -1;
    }
    if (root->data == node)
    {
        printNodeAtDepthKDownward(root, k);
        return 0;
    }

    int left_distance = helper(root->left, node, k);
    if (left_distance != -1)
    {
        if (left_distance + 1 == k)
        {
            cout << root->data << endl;
        }
        else
        {
            printNodeAtDepthKDownward(root->right, k - left_distance - 2);
        }
        return 1 + left_distance;
    }

    int right_distance = helper(root->right, node, k);
    if (right_distance != -1)
    {
        if (right_distance + 1 == k)
        {
            cout << root->data << endl;
        }
        else
        {
            printNodeAtDepthKDownward(root->left, k - right_distance - 2);
        }
        return 1 + right_distance;
    }

    return -1;
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k)
{
    if (!root)
    {
        return;
    }
    helper(root, node, k);
}

// void get(BinaryTreeNode<int> *root, int level)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     if (level == 0)
//     {
//         cout << root->data << endl;
//         return;
//     }

//     get(root->left, level - 1);
//     get(root->right, level - 1);
// }

// vector<pair<BinaryTreeNode<int> *, char>> path(BinaryTreeNode<int> *root, int node)
// {
//     if (root == NULL)
//     {
//         vector<pair<BinaryTreeNode<int> *, char>> ans;
//         return ans;
//     }
//     if (root->data == node)
//     {
//         vector<pair<BinaryTreeNode<int> *, char>> ans;
//         pair<BinaryTreeNode<int> *, char> i;
//         i.first = root;
//         i.second = 'c';
//         ans.push_back(i);
//         return ans;
//     }
//     vector<pair<BinaryTreeNode<int> *, char>> ans;
//     vector<pair<BinaryTreeNode<int> *, char>> ans1 = path(root->left, node);
//     vector<pair<BinaryTreeNode<int> *, char>> ans2 = path(root->right, node);
//     if (ans1.size())
//     {
//         pair<BinaryTreeNode<int> *, char> i;
//         i.first = root;
//         i.second = 'r';
//         ans1.push_back(i);
//         return ans1;
//     }
//     if (ans2.size())
//     {
//         pair<BinaryTreeNode<int> *, char> i;
//         i.first = root;
//         i.second = 'l';
//         ans2.push_back(i);
//         return ans2;
//     }
//     return ans;
// }

// void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k)
// {
//     vector<pair<BinaryTreeNode<int> *, char>> pathway = path(root, node);

//     // for (int i = 0; i < pathway.size(); i++)
//     // {
//     //     cout << pathway.at(i).first->data << " " << pathway.at(i).second << endl;
//     // }

//     for (int i = 0; i < pathway.size(); i++)
//     {
//         if (pathway[i].second == 'c')
//         {
//             get(pathway[i].first, k);
//         }
//         if (pathway[i].second == 'l')
//         {
//             if (k - i == 0)
//             {
//                 get(pathway[i].first, 0);
//             }
//             else
//             {
//                 get(pathway[i].first->left, k - i - 1);
//             }
//         }
//         if (pathway[i].second == 'r')
//         {
//             if (k - i == 0)
//             {
//                 get(pathway[i].first, 0);
//             }
//             else
//             {
//                 get(pathway[i].first->right, k - i - 1);
//             }
//         }
//     }
// }

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}

// 3 5 1 6 2 0 8 -1 -1 7 4 -1 -1 -1 -1 -1 -1 -1 -1 4 2