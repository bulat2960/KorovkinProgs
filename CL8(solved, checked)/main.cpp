#include <iostream>
#include <iomanip>
#include "Matrix.h"

using namespace std;

int main()
{
    Matrix<int> matrix(5, 5);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = i + j;
        }
    }

    for (unsigned i = 0; i < 5; i++)
    {
        for (unsigned j = 0; j < 5; j++)
        {
            cout << setw(2) << matrix[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
