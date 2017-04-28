#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Matrix.h"

using namespace std;

template<typename T>
void generateMatrix(Matrix<T>& matrix)
{
    for (int i = 0; i < matrix.size1(); i++)
    {
        for (int j = 0; j < matrix.size2(); j++)
        {
            matrix[i][j] = rand() % 2;
        }
    }
}

template<typename T>
void showMatrix(const Matrix<T>& matrix)
{
    for (int i = 0; i < matrix.size1(); i++)
    {
        for (int j = 0; j < matrix.size2(); j++)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

template<typename T>
bool checkCol(const Matrix<T>& matrix, int k)
{
    for (int i = 0; i <= matrix.size1() - k; i++)
    {
        for (int j = 0; j < matrix.size2(); j++)
        {
            int winCounter = 0;
            for (int counter = i; counter < i + k; counter++)
            {
                matrix[counter][j] == 1 ? winCounter++ : winCounter = 0;
            }
            if (winCounter == k)
            {
                cout << "X win(col): str " << i + 1 << ", col " << j + 1 << endl;
                return true;
            }
        }
    }
    return false;
}

template<typename T>
bool checkRow(const Matrix<T>& matrix, int k)
{
    for (int i = 0; i < matrix.size1(); i++)
    {
        for (int j = 0; j <= matrix.size2() - k; j++)
        {
            int winCounter = 0;
            for (int counter = j; counter < j + k; counter++)
            {
                matrix[i][counter] == 1 ? winCounter++ : winCounter = 0;
            }
            if (winCounter == k)
            {
                cout << "X win(row): str " << i + 1 << ", col " << j + 1 << endl;
                return true;
            }
        }
    }
    return false;
}

template<typename T>
bool checkPrimDiag(const Matrix<T>& matrix, int k)
{
    for (int i = 0; i <= matrix.size1() - k; i++)
    {
        for (int j = 0; j <= matrix.size2() - k; j++)
        {
            int winCounter = 0;
            for (int counter = 0; counter < k; counter++)
            {
                matrix[i + counter][j + counter] == 1 ? winCounter++ : winCounter = 0;
            }
            if (winCounter == k)
            {
                cout << "X win(primary diag): str " << i + 1 << ", col " << j + 1 << endl;
                return true;
            }
        }
    }
    return false;
}

template<typename T>
bool checkSecondDiag(const Matrix<T>& matrix, int k)
{
    for (int i = 0; i <= matrix.size1() - k; i++)
    {
        for (int j = k; j < matrix.size2(); j++)
        {
            int winCounter = 0;
            for (int counter = 0; counter < k; counter++)
            {
                matrix[i + counter][j - counter] == 1 ? winCounter++ : winCounter = 0;
            }
            if (winCounter == k)
            {
                cout << "X win(secondary diag): str " << i + 1 << ", col " << j + 1 << endl;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    srand(time(0));

    int m, n, k;
    cin >> m >> n >> k;
    if (m <= 1 || n <= 1 || k <= 1)
    {
        cout << "WRONG INPUT DATA" << endl;
        return 0;
    }

    Matrix<int> matrix(m, n);

    generateMatrix(matrix);

    showMatrix(matrix);

    if (checkCol(matrix, k) == true)
    {
        return 0;
    }
    if (checkRow(matrix, k) == true)
    {
        return 0;
    }
    if (checkPrimDiag(matrix, k) == true)
    {
        return 0;
    }
    if (checkSecondDiag(matrix, k) == true)
    {
        return 0;
    }

    return 0;
}
