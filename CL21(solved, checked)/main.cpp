#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Matrix.h"

using namespace std;

template<typename T>
void generateMatrix(Matrix<T>& matrix)
{
    for(int i = 0; i < matrix.size1(); i++)
    {
        for(int j = 0; j < matrix.size2(); j++)
        {
            matrix[i][j] = 1 + rand() % 10;
        }
    }
}

template<typename T>
void showMatrix(const Matrix<T>& matrix)
{
    cout << "Initial matrix" << endl;
    for (int i = 0; i < matrix.size1(); i++)
    {
        for (int j = 0; j < matrix.size2(); j++)
        {
            cout << setw(4) << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

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

    int n;
    cout << "Input dismensions ";
    cin >> n;
    Matrix<double> matrix(n, n);
    generateMatrix(matrix);

    showMatrix(matrix);

    cout << setprecision(10) << det(matrix);
    return 0;
}

