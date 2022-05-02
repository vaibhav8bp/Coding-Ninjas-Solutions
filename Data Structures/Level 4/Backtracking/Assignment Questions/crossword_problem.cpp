#include <iostream>
#include <vector>
using namespace std;

bool canPlaceHorizontally(string *crossword, string currentWord, int i, int j)
{
    // For perfect fit
    if (j - 1 >= 0 && crossword[i][j - 1] != '+')
    {
        return false;
    }
    else if (j + currentWord.length() < 10 && crossword[i][j + currentWord.length()] != '+')
    {
        return false;
    }
    for (int jj = 0; jj < currentWord.length(); jj++)
    {
        if (j + jj >= 10)
        {
            return false;
        }
        if (crossword[i][j + jj] == '-' || crossword[i][j + jj] == currentWord[jj])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void placeWordHorizontally(string *crossword, string currentWord, int i, int j, bool *wePlace)
{
    for (int jj = 0; jj < currentWord.length(); jj++)
    {
        if (crossword[i][j + jj] == currentWord[jj])
        {
            wePlace[jj] = false;
        }
        crossword[i][j + jj] = currentWord[jj];
    }
}

void unplaceWordHorizontally(string *crossword, int currentLength, bool *wePlace, int i, int j)
{
    for (int jj = 0; jj < currentLength; jj++)
    {
        if (wePlace[jj])
        {
            crossword[i][j + jj] = '-';
        }
    }
}

bool canPlaceVertically(string *crossword, string currentWord, int i, int j)
{
    // For perfect fit
    if (i - 1 >= 0 && crossword[i - 1][j] != '+')
    {
        return false;
    }
    else if (i + currentWord.length() < 10 && crossword[i + currentWord.length()][j] != '+')
    {
        return false;
    }
    for (int ii = 0; ii < currentWord.length(); ii++)
    {
        if (i + ii >= 10)
        {
            return false;
        }
        if (crossword[i + ii][j] == '-' || crossword[i + ii][j] == currentWord[ii])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void placeWordVertically(string *crossword, string currentWord, int i, int j, bool *wePlace)
{
    for (int ii = 0; ii < currentWord.length(); ii++)
    {
        if (crossword[i + ii][j] == currentWord[ii])
        {
            wePlace[ii] = false;
        }
        crossword[i + ii][j] = currentWord[ii];
    }
}

void unplaceWordVertically(string *crossword, int currentLength, bool *wePlace, int i, int j)
{
    for (int ii = 0; ii < currentLength; ii++)
    {
        if (wePlace[ii])
        {
            crossword[i + ii][j] = '-';
        }
    }
}

bool solve(string *crossword, vector<string> words, int current_word_index)
{
    if (current_word_index == words.size())
    {
        return true;
    }
    string currentWord = words[current_word_index];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (crossword[i][j] == '-' || crossword[i][j] == currentWord[0])
            {
                if (canPlaceHorizontally(crossword, currentWord, i, j))
                {
                    bool *wePlace = new bool[currentWord.length()];
                    for (int i = 0; i < currentWord.length(); i++)
                    {
                        wePlace[i] = true;
                    }
                    placeWordHorizontally(crossword, currentWord, i, j, wePlace);
                    if (solve(crossword, words, current_word_index + 1))
                    {
                        return true;
                    }
                    unplaceWordHorizontally(crossword, currentWord.length(), wePlace, i, j);
                    delete[] wePlace;
                }
                if (canPlaceVertically(crossword, currentWord, i, j))
                {
                    bool *wePlace = new bool[currentWord.length()];
                    for (int i = 0; i < currentWord.length(); i++)
                    {
                        wePlace[i] = true;
                    }
                    placeWordVertically(crossword, currentWord, i, j, wePlace);
                    if (solve(crossword, words, current_word_index + 1))
                    {
                        return true;
                    }
                    unplaceWordVertically(crossword, currentWord.length(), wePlace, i, j);
                    delete[] wePlace;
                }
            }
        }
    }
    return false;
}

int main()
{
    string *crossword = new string[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> crossword[i];
    }

    string s, temp;
    cin >> s;

    vector<string> words;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ';')
        {
            words.push_back(temp);
            temp = "";
        }
        else
        {
            temp += s[i];
        }
    }

    words.push_back(temp);

    if (solve(crossword, words, 0))
    {
        for (int i = 0; i < 10; i++)
        {
            cout << crossword[i] << endl;
        }
    }
    delete[] crossword;
    return 0;
}