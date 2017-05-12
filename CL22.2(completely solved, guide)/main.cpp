#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>
#include "Matrix.h"

using namespace std;

template<typename T>
bool generateMatrix(Matrix<T>& matrix, ifstream& in)
{
    if (!in.is_open())
    {
        cout << "CAN'T OPEN FILE" << endl;
        return false;
    }

    int counter = 0;
    for(int i = 0; i < matrix.size1(); i++)
    {
        for(int j = 0; j < matrix.size2(); j++)
        {
            int element;
            if (in >> element)
            {
                counter++;
                matrix[i][j] = element;
            }
        }
    }

    if (counter < matrix.size1() * matrix.size2())
    {
        cout << "counter = " << counter << endl;
        cout << "NOT ENOUGH ELEMENTS" << endl;
        return false;
    }

    return true;
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
    ifstream in(argv[1]);

    int m, n;
    cin >> n >> m;
    if (n <= 1 || m <= 1)
    {
        cout << "MATRIX DIMENSIONS MUST BE CORRECT" << endl;
    }

    Matrix<double> matrix(n, m);

    if (generateMatrix(matrix, in) == false)
    {
        return 0;
    }

    showMatrix(matrix);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (isStrMin(matrix, i, j) && isColMax(matrix, i, j))
            {
                cout << "(" << i + 1 << ", " << j + 1 << ")" << endl;
            }
        }
    }
    return 0;
}
