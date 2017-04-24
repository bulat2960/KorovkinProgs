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
    for (int i = 0; i < matrix.size1(); i++)
    {
        for (int j = 0; j < matrix.size2(); j++)
        {
            cout << setw(5) << setprecision(2) << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

template<typename T>
int determinantMatrix(Matrix<T>& matrix)
{
    double coef;

    for (int i = 0; i < n; i++)
    {int n;
    cin >> n;
        for (int j = i + 1; j < n; j++)
        {
            if (matrix[i][i] == 0)
            {
                throw invalid_argument("WRONG TRIANGULAR MATRIX!");
            }
            coef = matrix[j][i] / matrix[i][i];
            for (int k = 0; k < n; k++)
            {
                matrix[j][k] -= matrix[i][k] * coef;
                if (matrix[j][k] > -0.0001 && matrix[j][k] < 0.0001)
                {
                    matrix[j][k] = 0;
                }
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

    int n;
    cout << "Input dismensions ";
    cin >> n;
    Matrix<double> matrix(n, n);
    generateMatrix(matrix);
    showMatrix(matrix);

    try
    {
        cout << determinantMatrix(matrix);

    }
    catch (const invalid_argument& e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
