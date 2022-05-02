#include <iostream>
#include <string>
#include <vector>
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

    void insertWord(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            if (!root->isTerminal)
            {
                root->isTerminal = true;
                return;
            }
            else
            {
                return;
            }
        }

        // Small calculation
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
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertWord(root, word);
    }

    pair<TrieNode *, bool> findNode(TrieNode *root, string pattern)
    {
        if (pattern.length() == 0)
        {
            pair<TrieNode *, bool> p;
            p.first = root;
            p.second = true;
            return p;
        }
        int index = pattern[0] - 'a';
        TrieNode *child = root->children[index];
        if (child == NULL)
        {
            pair<TrieNode *, bool> p;
            p.first = root;
            p.second = false;
            return p;
        }
        else
        {
            return findNode(child, pattern.substr(1));
        }
    }

    void printAllNodesFromRoot(TrieNode *root, string pattern)
    {
        if (!root)
        {
            return;
        }
        if (root->isTerminal)
        {
            cout << pattern << endl;
        }
        for (int i = 0; i < 26; i++)
        {
            TrieNode *child = root->children[i];
            if (child)
            {
                printAllNodesFromRoot(child, pattern + child->data);
            }
        }
    }

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

    void autoComplete(vector<string> input, string pattern)
    {
        for (int i = 0; i < input.size(); i++)
        {
            insertWord(input.at(i));
        }
        if (!findNode(root, pattern).second)
        {
            return;
        }
        TrieNode *patternStart = findNode(root, pattern).first;
        printAllNodesFromRoot(patternStart, pattern);
    }
};

int main()
{
    Trie t;
    int n;
    cin >> n;

    vector<string> vect;

    for (int i = 0; i < n; ++i)
    {
        string word;
        cin >> word;
        vect.push_back(word);
    }

    string pattern;
    cin >> pattern;

    t.autoComplete(vect, pattern);
}