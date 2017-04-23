#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Matrix.h"

using namespace std;

const int n = 5;

template<typename T>
double det(Matrix<T>& matrix)
{
    if(matrix.size1() == 2)
    {
        return (matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1]);
    }
    else
    {
        double res = 0;
        for (int i = 0 ; i < matrix.size1(); i++)
        {
            Matrix<double> minor(matrix.size1() - 1, matrix.size2() - 1);
            for (int j = 0; j < minor.size1(); j++)
            {
                for (int k = 0; k < minor.size2(); k++)
                {
                    k >= i ? minor[j][k] = matrix[j + 1][k + 1] : minor[j][k] = matrix[j + 1][k];
                }
            }

            i % 2 == 0 ? res += det(minor) * matrix[0][i] : res -= det(minor) * matrix[0][i];
        }
        return res;
    }
}

int main()
{
    srand(time(0));

    Matrix<double> matrix(n, n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            matrix[i][j] = 1 + rand() % 10;
        }
    }
    cout << det(matrix);
    return 0;
}
