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
        left = NULL;
        right = NULL;
    }
};

class BST
{
    BinaryTreeNode<int> *root;

    bool hasDataHelper(BinaryTreeNode<int> *root, int data)
    {
        if (root == NULL)
        {
            return false;
        }
        if (root->data == data)
        {
            return true;
        }
        else if (data < root->data)
        {
            return hasDataHelper(root->left, data);
        }
        else
        {
            return hasDataHelper(root->right, data);
        }
    }

    BinaryTreeNode<int> *insertDataHelper(BinaryTreeNode<int> *root, int data)
    {
        if (root == NULL)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if (data <= root->data)
        {
            root->left = insertDataHelper(root->left, data);
        }
        else
        {
            root->right = insertDataHelper(root->right, data);
        }
        return root;
    }

    BinaryTreeNode<int> *deleteDataHelper(BinaryTreeNode<int> *root, int data)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (data > root->data)
        {
            root->right = deleteDataHelper(root->right, data);
            return root;
        }
        else if (data < root->data)
        {
            root->left = deleteDataHelper(root->left, data);
            return root;
        }
        else
        {
            if (!root->left && !root->right)
            {
                delete root;
                return NULL;
            }
            else if (!root->left && root->right)
            {
                BinaryTreeNode<int> *temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }
            else if (!root->right && root->left)
            {
                BinaryTreeNode<int> *temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }
            else
            {
                BinaryTreeNode<int> *minNode = root->right;

                while (minNode->left)
                {
                    minNode = minNode->left;
                }
                int right_min = minNode->data;
                root->data = right_min;
                root->right = deleteDataHelper(root->right, right_min);
                return root;
            }
        }
    }

    void printTreeHelper(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << ":";
        if (root->left)
        {
            cout << "L:" << root->left->data << ",";
        }
        if (root->right)
        {
            cout << "R:" << root->right->data;
        }
        cout << endl;
        printTreeHelper(root->left);
        printTreeHelper(root->right);
    }

public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }

    void remove(int data)
    {
        this->root = deleteDataHelper(this->root, data);
    }

    void print()
    {
        printTreeHelper(this->root);
    }

    void insert(int data)
    {
        this->root = insertDataHelper(this->root, data);
    }

    bool search(int data)
    {
        return hasDataHelper(root, data);
    }
};

int main()
{
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> input;
            tree->insert(input);
            break;
        case 2:
            cin >> input;
            tree->remove(input);
            break;
        case 3:
            cin >> input;
            cout << ((tree->search(input)) ? "true\n" : "false\n");
            break;
        default:
            tree->print();
            break;
        }
    }
}