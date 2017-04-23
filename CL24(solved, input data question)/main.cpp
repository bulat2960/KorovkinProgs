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

int main()
{
    unsigned size1;
    unsigned size2;

    string filename1;
    string filename2;

    cout << "ENTER FILENAMES" << endl;
    cin >> filename1 >> filename2;

    ifstream in(filename1);
    if (!in.is_open())
    {
        cout << "CANNOT FIND FILE!!!" << endl;
        return 0;
    }
    in >> size1;
    in >> size2;

    Matrix<int> matrix(size1, size2);
    for (unsigned i = 0; i < size1; i++)
    {
        for (unsigned j = 0; j < size2; j++)
        {
            int element;
            in >> element;
            matrix[i][j] = element;
        }
    }
    in.close();

    int* sumArr = new int[size1];
    for (unsigned i = 0; i < size1; i++)
    {
        sumArr[i] = 0;
        for (unsigned j = 0; j < size2; j++)
        {
            sumArr[i] += matrix[i][j];
        }
    }

    for (unsigned i = 0; i < size1 - 1; i++)
    {
        if (sumArr[i] > sumArr[i + 1])
        {
            Swap(sumArr[i], sumArr[i + 1]);
            for (unsigned j = 0; j < size2; j++)
            {
                Swap(matrix[i][j], matrix[i + 1][j]);
            }
        }
    }

    ofstream out(filename2);
    for (unsigned i = 0; i < size1; i++)
    {
        for (unsigned j = 0; j < size2; j++)
        {
            out << matrix[i][j] << ' ';
        }
        out << endl;
    }
    out.close();

    return 0;
}
