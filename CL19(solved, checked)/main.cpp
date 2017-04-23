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
    cout << "Initial matrix" << endl;
    for (int i = 0; i < matrix.size1(); i++)
    {
        for (int j = 0; j < matrix.size2(); j++)
        {
            cout << setw(4) << setprecision(2) << matrix[i][j] << ' ';
        }
        cout << endl;
    }
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
            }cout << "Input dismensions ";
            coef = matrix[j][i] / matrix[i][i];

            // Delete the next 4 lines if you understand the principle of the Gauss method
            cout << "Transform element " << "[" << i + 1 << ", " << j + 1 << "]" << endl;
            cout << "From each element of line " << j + 1 << " subtract line " << i + 1;
            cout << " multiplied by " << setprecision(2) << matrix[j][i] << '/' << matrix[i][i] << endl;
            cout << "----------------------------------------------------------------" << endl;
            for (int k = 0; k < matrix.size2(); k++)
            {
                matrix[j][k] -= matrix[i][k] * coef;
            }
        }
    }

    cout << "Final matrix" << endl;
    for (int i = 0; i < matrix.size1(); i++)
    {
        for (int j = 0; j < matrix.size2(); j++)
        {
            if (matrix[i][j] < 0.00001 && matrix[i][j] > -0.00001)
            {
                matrix[i][j] = 0;
            }
            cout << setw(5) << setprecision(2) << matrix[i][j] << ' ';
        }
        cout << endl;
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
