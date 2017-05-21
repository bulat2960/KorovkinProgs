#include <iostream>
#include <iomanip>
#include "Matrix.h"

using namespace std;

int main()
{
    int m;
    int n;
    cin >> m >> n;
    if (m <= 1 || n <= 1)
    {
        cout << "MATRIX DIMENSIONS MUST BE CORRECT" << endl;
        return 0;
    }

    Matrix<int> matrix(m, n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = -1;
        }
    }

    int i = 0;
    int j = 0;
    int counter = 1;

    while (counter <= n * m)
    {
        while (matrix[i][j] == -1 && j < n)
        {
            matrix[i][j] = counter++;
            if (j != n - 1)
            {
                if (matrix[i][j + 1] != -1)
                {
                    break;
                }
                j++;
            }
        }
        i++;

        while (matrix[i][j] == -1 && i < m)
        {
            matrix[i][j] = counter++;
            if (i != m - 1)
            {
                if (matrix[i + 1][j] != -1)
                {
                    break;
                }
                i++;
            }
        }
        j--;

        while (matrix[i][j] == -1 && j >= 0)
        {
            matrix[i][j] = counter++;
            if (j != 0)
            {
                if (matrix[i][j - 1] != -1)
                {
                    break;
                }
                j--;
            }
        }
        i--;

        while (matrix[i][j] == -1 && i >= 0)
        {
            matrix[i][j] = counter++;

            if (i != 0)
            {
                if (matrix[i - 1][j] != -1)
                {
                    break;
                }
                i--;
            }
        }
        j++;
    }

    cout << matrix;
    return 0;
}
