#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
    unsigned size1;
    unsigned size2;
    cin >> size1 >> size2;
    if (size1 <= 1 || size2 <= 1)
    {
        cout << "MATRIX DISMENSIONS MUST BE CORRECT" << endl;
        return 0;
    }

    Matrix<bool> matrix(size1, size2);
    for (unsigned i = 0; i < size1; i++)
    {
        for (unsigned j = 0; j < size2; j++)
        {
            (i + j) % 2 == 0 ? matrix[i][j] = true : matrix[i][j] = false;
        }
    }

    cout << matrix;

    return 0;
}
