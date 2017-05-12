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
            matrix[i][j] = rand() % 10;
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

int main(int argc, char** argv)
{
    srand(time(0));

    ofstream out(argv[1]);

    int m, n;
    cin >> n >> m;
    if (n <= 1 || m <= 1)
    {
        cout << "MATRIX DIMENSIONS MUST BE CORRECT" << endl;
        return 0;
    }

    Matrix<double> matrix(n, m);

    bool flag = false;
    while (flag == false)
    {
        generateMatrix(matrix);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (isStrMin(matrix, i, j) && isColMax(matrix, i, j))
                {
                    cout << "COORDS: " << i + 1 << ' ' << j + 1 << endl;
                    flag = true;
                }
            }
        }

        if (flag == true)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    out << matrix[i][j] << ' ';
                }
                out << endl;
            }
        }
    }
    return 0;
}
