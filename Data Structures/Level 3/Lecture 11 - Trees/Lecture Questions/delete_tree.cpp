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

void delete_tree(TreeNode<int> *root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        delete_tree(root->children.at(i));
    }
    delete root;
}

int main()
{
    return 0;
}