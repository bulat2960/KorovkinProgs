#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
    // ���� ��������� ������ - ������� ������� �������, ������������� � �����
    // �� ����������� ����������� ������� - � ������� include, ������ ���� �� ���
    Matrix<double> matrix(5, 5);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = i + j;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
