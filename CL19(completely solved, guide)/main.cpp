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
    for (int i = 0; i < matrix.size1(); i++)
    {
        for (int j = 0; j < matrix.size2(); j++)
        {
            matrix[i][j] = 1 + rand() % 9;
        }
    }
}

template<typename T>
void showMatrix(const Matrix<T>& matrix)
{
    cout << matrix << "--------------------------" << endl;
}

template<typename T>
void triangularMatrix(Matrix<T>& matrix)
{
    double coef;

    for (int i = 0; i < matrix.size1(); i++)
    {
        for (int j = i + 1; j < matrix.size2(); j++)
        {
            if (matrix[i][i] == 0)
            {
                throw invalid_argument("WRONG TRIANGULAR MATRIX!");
            }
            coef = matrix[j][i] / matrix[i][i];

            for (int k = 0; k < matrix.size2(); k++)
            {
                matrix[j][k] -= matrix[i][k] * coef;
            }
            //showMatrix(matrix);
        }
    }

    cout << "Final matrix" << endl;
    cout << matrix << endl;
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
    }

    Matrix<double> matrix(n, n);
    generateMatrix(matrix);
    showMatrix(matrix);

    try
    {
        triangularMatrix(matrix);

    }
    catch (const invalid_argument& e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
