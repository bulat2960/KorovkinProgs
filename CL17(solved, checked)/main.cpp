#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
    unsigned size1;
    unsigned size2;
    cin >> size1 >> size2;

    Matrix<bool> mtrx(size1, size2);
    for (unsigned i = 0; i < size1; i++)
    {
        for (unsigned j = 0; j < size2; j++)
        {
            (i + j) % 2 == 0 ? mtrx[i][j] = true : mtrx[i][j] = false;
        }
    }

    for (unsigned i = 0; i < size1; i++)
    {
        for (unsigned j = 0; j < size2; j++)
        {
            cout << mtrx[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
