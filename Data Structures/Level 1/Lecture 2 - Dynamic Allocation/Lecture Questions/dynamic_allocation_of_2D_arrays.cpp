#include <iostream>
using namespace std;

int main()
{
    //Creating an array of size 10*20

    //Creating an array of pointers of size 10 i.e. the number of rows
    int **p = new int *[10];
    int i, j;
    for (i = 0; i < 10; i++)
    {
        //Creating an array of size 20(no. of columns) to link it to the indiviadual entries of pointer array.
        p[i] = new int[20];
        //Taking entries
        for (j = 0; j < 20; j++)
        {
            cin >> p[i][j];
        }
    }
    // Deleting array
    for (i = 0; i < 10; i++)
    {
        delete[] p[i];
    }
    delete[] p;
    return 0;
}