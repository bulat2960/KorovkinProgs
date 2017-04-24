#include <iostream>
#include <iomanip>
#include <vector>
#include "Matrix.h"

using namespace std;

int main()
{
    int n;
    int m;
    cin >> n >> m;
    if (n <= 1 || m <= 1)
    {
        cout << "MATRIX DISMENSIONS MUST BE CORRECT" << endl;
        return 0;
    }

    Matrix<int> matrix(n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = -1;
        }
    }

    int i = 0;
    int j = 0;
    int counter = 1;

    matrix[0][0] = 1;
    while (counter < n * m)
    {
        while (matrix[i][j + 1] == -1)
        {
            j++;
            matrix[i][j] = ++counter;
            if (j == m - 1)
            {
                break;
            }
            if (matrix[i][j + 1] != -1)
            {
                break;
            }
        }
        while (matrix[i + 1][j] == -1)
        {
            i++;
            matrix[i][j] = ++counter;
            if (i == n - 1)
            {
                break;
            }
            if (matrix[i + 1][j] != -1)
            {
                break;
            }
        }
        while (matrix[i][j - 1] == -1)
        {
            j--;
            matrix[i][j] = ++counter;
            if (j == 0)
            {
                break;
            }
            if (matrix[i][j - 1] != -1)
            {
                break;
            }
        }
        while (matrix[i - 1][j] == -1)
        {
            i--;
            matrix[i][j] = ++counter;
            if (i == 0)
            {
                break;
            }
            if (matrix[i - 1][j] != -1)
            {
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << setw(4) << matrix[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
