#include <iostream>
#include <fstream>
#include "Matrix.h"

using namespace std;

void Swap(int &element1, int &element2)
{
    int temp = element1;
    element1 = element2;
    element2 = temp;
}

template<typename T>
bool generateMatrix(Matrix<T>& matrix, ifstream& in)
{
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

    if (counter != matrix.size1() * matrix.size2())
    {
        cout << "NOT ENOUGH ELEMENTS" << endl;
        return false;
    }
    return true;
}

template<typename T>
int* getSum(const Matrix<T>& matrix)
{
    int* sumArr = new int[matrix.size1()];
    for (int i = 0; i < matrix.size1(); i++)
    {
        sumArr[i] = 0;
        for (int j = 0; j < matrix.size2(); j++)
        {
            sumArr[i] += matrix[i][j];
        }
    }
    return sumArr;
}

template<typename T>
void transformMatrix(const Matrix<T>& matrix, int* sumArr)
{
    for (int i = 0; i < matrix.size1() - 1; i++)
    {
        if (sumArr[i] > sumArr[i + 1])
        {
            Swap(sumArr[i], sumArr[i + 1]);
            for (int j = 0; j < matrix.size2(); j++)
            {
                Swap(matrix[i][j], matrix[i + 1][j]);
            }
        }
    }
}

template<typename T>
void writeMatrix(const Matrix<T>& matrix)
{
    string filename2;
    cin >> filename2;
    ofstream out(filename2);
    for (int i = 0; i < matrix.size1(); i++)
    {
        for (int j = 0; j < matrix.size2(); j++)
        {
            out << matrix[i][j] << ' ';
        }
        out << endl;
    }
    out.close();
}

int main()
{
    string filename1;
    cin >> filename1;
    ifstream in(filename1);
    if (!in.is_open())
    {
        cout << "CANNOT FIND FILE!!!" << endl;
        return 0;
    }

    int size1, size2;
    in >> size1 >> size2;
    if (size1 <= 1 || size2 <= 1)
    {
        cout << "MATRIX DIMENSIONS MUST BE CORRECT" << endl;
    }

    Matrix<int> matrix(size1, size2);

    if (generateMatrix(matrix, in) == false)
    {
        return 0;
    }

    int* sumArr = getSum(matrix);

    transformMatrix(matrix, sumArr);

    writeMatrix(matrix);

    return 0;
}
