#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "Matrix.h"

using namespace std;

const int n = 5;

template<typename T>
void fillMatrix(Matrix<T>& matrix)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = 1 + rand() % 9;
        }
    }
}

template<typename T>
int determinantMatrix(Matrix<T>& matrix)
{
    double coef;

    cout << "Initial matrix" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(5) << setprecision(2) << matrix[i][j] << ' ';
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            coef = matrix[j][i] / matrix[i][i];
            for (int k = 0; k < n; k++)
            {
                matrix[j][k] -= matrix[i][k] * coef;
            }
        }
    }

    int det = 1;
    for (int i = 0; i < n; i++)
    {
        det *= matrix[i][i];
    }
    return det;
}

int main()
{
    srand(time(0));

    Matrix<double> matrix(n, n);
    fillMatrix(matrix);

    cout << determinantMatrix(matrix);

    return 0;
}
