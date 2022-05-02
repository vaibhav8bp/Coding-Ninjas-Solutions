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

void print_nodes_at_k_depth(TreeNode<int> *root, int depth)
{
    if (root == NULL)
    {
        return;
    }
    if (depth == 0)
    {
        cout << root->data << " ";
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        print_nodes_at_k_depth(root->children.at(i), depth - 1);
    }
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    for (int i = 0; i <= 3; i++)
    {
        cout << "Nodes at depth : " << i << " are : ";
        print_nodes_at_k_depth(root, i);
        cout << endl;
    }
    return 0;
}

// 1 3 2 3 4 0 2 5 6 0 0 0