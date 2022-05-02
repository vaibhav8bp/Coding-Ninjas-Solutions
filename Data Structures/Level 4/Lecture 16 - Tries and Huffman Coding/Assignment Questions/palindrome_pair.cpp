#include <iostream>
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
    void add(TrieNode *root, string word)
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
        add(child, word.substr(1));
    }

    void add(string word)
    {
        add(root, word);
    }

    /*..................... Palindrome Pair................... */

    bool search(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            return true;
        }
        int index = word[word.length() - 1] - 'a';
        TrieNode *child = root->children[index];
        if (child != NULL)
        {
            if (child->isTerminal)
            {
                int i = 0, j = word.length() - 2;
                while (i < j)
                {
                    if (word[i] != word[j])
                    {
                        return false;
                    }
                    i++;
                    j--;
                }
                return true;
            }
        }
        else
        {
            return false;
        }
        return search(child, word.substr(0, word.length() - 1));
    }

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

    bool isPalindromePair(vector<string> words)
    {
        for (int i = 0; i < words.size(); i++)
        {
            add(words.at(i));
        }
        bool answer = false;
        for (int i = 0; i < words.size(); i++)
        {
            answer = search(root, words.at(i));
            if (answer)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Trie t;
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> words[i];
    }

    cout << (t.isPalindromePair(words) ? "true" : "false");
}