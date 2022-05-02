#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;
    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;
    void insertWordHelper(TrieNode *root, string word)
    {
        // Base Case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        insertWordHelper(child, word.substr(1));
    }
    void deleteWordHelper(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = false;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
            deleteWordHelper(child, word.substr(1));
        }
        else
        {
            return;
        }
        if (child->isTerminal == false)
        {
            for (int i = 0; i < 26; i++)
            {
                if (child->children[i] != NULL)
                {
                    return;
                }
            }
            delete child;
            root->children[index] = NULL;
        }
    }
    bool searchWordHelper(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
            return searchWordHelper(child, word.substr(1));
        }
        else
        {
            return false;
        }
    }

public:
    Trie()
    {
        root = new TrieNode('\0');
    }
    void insertWord(string word)
    {
        insertWordHelper(this->root, word);
    }
    void deleteWord(string word)
    {
        deleteWordHelper(this->root, word);
    }
    bool searchWord(string word)
    {
        return searchWordHelper(this->root, word);
    }
};

int main()
{
    Trie t;
    t.insertWord("and");
    t.insertWord("are");
    t.insertWord("dot");

    cout << t.searchWord("and") << endl;
    t.deleteWord("and");

    cout << t.searchWord("and") << endl;
    return 0;
}