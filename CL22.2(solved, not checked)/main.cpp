#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>
#include "Matrix.h"

using namespace std;

template<typename T>
void generateMatrix(Matrix<T>& matrix)
{
    for(int i = 0; i < matrix.size1(); i++)
    {
        for(int j = 0; j < matrix.size2(); j++)
        {
            cin >> matrix[i][j];
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
bool isStrMin(const Matrix<T>& matrix, int strNumber, int colNumber)
{
    double Min = matrix[strNumber][colNumber];
    int counter = 0;
    for (int i = 0; i < matrix.size2(); i++)
    {
        if (Min <= matrix[strNumber][i])
        {
            counter++;
        }
    }
    if (counter == matrix.size2())
    {
        return true;
    }
    return false;
}

template<typename T>
bool isColMax(const Matrix<T>& matrix, int strNumber, int colNumber)
{
    double Max = matrix[strNumber][colNumber];
    int counter = 0;
    for (int i = 0; i < matrix.size1(); i++)
    {
        if (Max >= matrix[i][colNumber])
        {
            counter++;
        }
    }
    if (counter == matrix.size1())
    {
        return true;
    }
    return false;
}


int main()
{
    int m, n;
    cin >> n >> m;
    Matrix<double> matrix(n, m);
    generateMatrix(matrix);
    showMatrix(matrix);

    ofstream out("output.txt");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << isStrMin(matrix, i, j) << ' ' << isColMax(matrix, i, j) << endl;
            if (isStrMin(matrix, i, j) && isColMax(matrix, i, j))
            {
                out << "(" << i + 1 << ", " << j + 1 << ")" << endl;
            }
        }
    }
    system("pause");
    return 0;
}
