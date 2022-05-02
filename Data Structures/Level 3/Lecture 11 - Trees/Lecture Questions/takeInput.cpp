#include <iostream>
#include <vector>
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

void print(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " : ";
    for (int i = 0; i < root->children.size(); i++)
    {
        if (i == root->children.size() - 1)
        {
            cout << root->children.at(i)->data;
        }
        else
        {
            cout << root->children.at(i)->data << ",";
        }
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        print(root->children.at(i));
    }
}

TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data : " << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    int n;
    cout << "Enter number of children for : " << rootData << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

int main()
{
    TreeNode<int> *root = takeInput();
    print(root);
    return 0;
}