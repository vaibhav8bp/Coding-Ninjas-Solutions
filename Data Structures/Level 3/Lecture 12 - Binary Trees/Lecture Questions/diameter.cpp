#include <iostream>
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

// Better Solution
// Time Complexity is O(N) where N is the number of nodes.

// Inbuilt pair with 2 attributes first and second.
pair<int, int> height_and_diameter(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> leftanswer = height_and_diameter(root->left);
    pair<int, int> rightanswer = height_and_diameter(root->right);

    int left_height = leftanswer.first;
    int left_diameter = leftanswer.second;
    int right_height = rightanswer.first;
    int right_diamter = rightanswer.second;

    int height = 1 + max(left_height, right_height);
    int diameter = max(left_height + right_height, max(left_diameter, right_diamter));
    pair<int, int> answer;
    answer.first = height;
    answer.second = diameter;
    return answer;
}

// Time Complexity is O(N*H) where N is the number of nodes and H is the height of the given tree.
/*
int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int answer = 0;
    int l = height(root->left);
    int r = height(root->right);

    answer = (l > r) ? (l) : (r);
    return answer + 1;
}

int diameter(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);

    return max(option1, max(option2, option3));
}
*/

int main()
{
    BinaryTreeNode<int> *root;
    // return height_and_diameter(root).second;
    return 0;
}