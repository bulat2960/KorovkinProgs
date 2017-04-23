#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Matrix.h"

using namespace std;

int main()
{
    srand(time(0));

    bool winFlag = false;

    unsigned m;
    unsigned n;
    unsigned k;
    cin >> m >> n >> k;

    Matrix<int> matrix(m, n);
    for (unsigned i = 0; i < m; i++)
    {
        for (unsigned j = 0; j < n; j++)
        {
            matrix[i][j] = rand() % 2;
        }
    }

    for (unsigned i = 0; i < m; i++)
    {
        for (unsigned j = 0; j < n; j++)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }

    for (unsigned i = 0; i <= m - k; i++)
    {
        for (unsigned j = 0; j < n; j++)
        {
            unsigned winCounter = 0;
            for (unsigned counter = i; counter < i + k; counter++)
            {
                matrix[counter][j] == 1 ? winCounter++ : winCounter = 0;
            }
            if (winCounter == k && winFlag == false)
            {
                cout << "X win(col): str " << i + 1 << ", col " << j + 1 << endl;
                winFlag = true;
                break;
            }
        }
    }

    for (unsigned i = 0; i < m; i++)
    {
        for (unsigned j = 0; j <= n - k; j++)
        {
            unsigned winCounter = 0;
            for (unsigned counter = j; counter < j + k; counter++)
            {
                matrix[i][counter] == 1 ? winCounter++ : winCounter = 0;
            }
            if (winCounter == k && winFlag == false)
            {
                cout << "X win(row): str " << i + 1 << ", col " << j + 1 << endl;
                winFlag = true;
            }
        }
    }

    for (unsigned i = 0; i <= m - k; i++)
    {
        for (unsigned j = 0; j <= n - k; j++)
        {
            unsigned winCounter = 0;
            for (unsigned counter = 0; counter < k; counter++)
            {
                matrix[i + counter][j + counter] == 1 ? winCounter++ : winCounter = 0;
            }
            if (winCounter == k && winFlag == false)
            {
                cout << "X win(primary diag): str " << i + 1 << ", col " << j + 1 << endl;
                winFlag = true;
            }
        }
    }

    for (unsigned i = 0; i <= m - k; i++)
    {
        for (unsigned j = k; j < n; j++)
        {
            unsigned winCounter = 0;
            for (unsigned counter = 0; counter < k; counter++)
            {
                matrix[i + counter][j - counter] == 1 ? winCounter++ : winCounter = 0;
            }
            if (winCounter == k && winFlag == false)
            {
                cout << "X win(secondary diag): str " << i + 1 << ", col " << j + 1 << endl;
                winFlag = true;
            }
        }
    }


    return 0;
}
