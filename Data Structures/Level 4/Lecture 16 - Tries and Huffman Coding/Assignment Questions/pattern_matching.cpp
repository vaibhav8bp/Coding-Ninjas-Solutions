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
            return;
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
        insertWord(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertWord(root, word);
    }

    bool searchWordHelper(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return true;
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

    bool patternMatching(vector<string> vect, string pattern)
    {
        for (int i = 0; i < vect.size(); i++)
        {
            for (int j = 0; j < vect.at(i).length(); j++)
            {
                insertWord(vect.at(i).substr(j));
            }
        }

        return searchWordHelper(this->root, pattern);
    }
};

int main()
{
    Trie t;
    int n;
    cin >> n;
    string pattern;
    vector<string> vect;

    for (int i = 0; i < n; ++i)
    {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    cin >> pattern;

    cout << (t.patternMatching(vect, pattern) ? "true" : "false");
}