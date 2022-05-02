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

int depth(TreeNode<int> *root, int key)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == key)
    {
        return 0;
    }

    int answer = 0;

    for (int i = 0; i < root->children.size(); i++)
    {
        int smallanswer = depth(root->children.at(i), key);
        if (smallanswer != -1)
        {
            return 1 + smallanswer;
        }
    }
    return -1;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();

    cout << depth(root, 1) << endl;
    cout << depth(root, 2) << endl;
    cout << depth(root, 3) << endl;
    cout << depth(root, 4) << endl;
    cout << depth(root, 5) << endl;
    cout << depth(root, 6) << endl;
    cout << depth(root, 7) << endl;
    return 0;
}

// 1 3 2 3 4 0 2 5 6 0 0 0