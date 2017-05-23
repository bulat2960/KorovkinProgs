#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
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
    cout << matrix << endl;
}

template<typename T>
double determinantMatrix(Matrix<T>& matrix)
{
    if (matrix.size1() == 2)
    {
        return (matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1]);
    }

    double coef;

    for (int i = 0; i < matrix.size1(); i++)
    {
        for (int j = i + 1; j < matrix.size2(); j++)
        {
            if (i == 2)
            {
                matrix[i][i] = 0;
            }
            cout << matrix << "-------------------------------" << endl;
            if (matrix[i][i] == 0)
            {
                throw invalid_argument("WRONG TRIANGULAR MATRIX!");
            }
            coef = matrix[j][i] / matrix[i][i];
            for (int k = 0; k < matrix.size2(); k++)
            {
                matrix[j][k] -= matrix[i][k] * coef;
                if (matrix[j][k] > -0.0001 && matrix[j][k] < 0.0001)
                {
                    matrix[j][k] = 0;
                }
            }
        }
    }

    double det = 1;
    for (int i = 0; i < matrix.size1(); i++)
    {
        det *= matrix[i][i];
    }
    return det;
}

int main()
{
    srand(time(0));

    int n;
    cout << "Input dimensions ";
    cin >> n;
    if (n <= 1)
    {
        cout << "MATRIX DIMENSIONS MUST BE CORRECT" << endl;
        return 0;
    }

    Matrix<double> matrix(n, n);
    generateMatrix(matrix);
    showMatrix(matrix);

    try
    {
        cout << setprecision(20) << determinantMatrix(matrix);

    }
    catch (const invalid_argument& error)
    {
        cout << error.what() << endl;
    }

    return 0;
}
