#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>

class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;
    TreeNode(T data)
    {
        this->data = data;
    }
    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data : " << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

int getHeightNode(TreeNode<int> *root, int key)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == key)
    {
        return 1;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        int smallanswer = getHeightNode(root->children.at(i), key);
        if (smallanswer != -1)
        {
            return smallanswer + 1;
        }
    }
    return -1;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    cout << getHeightNode(root, 10) << endl;
    cout << getHeightNode(root, 20) << endl;
    cout << getHeightNode(root, 30) << endl;
    cout << getHeightNode(root, 40) << endl;
    cout << getHeightNode(root, 50) << endl;
    cout << getHeightNode(root, 60) << endl;
    cout << getHeightNode(root, 70) << endl;
    return 0;
}

// 10 3 20 30 40 2 50 60 0 0 0 0