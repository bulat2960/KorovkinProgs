#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
    // ƒаже объ€сн€ть нечего - обычное задание матрицы, инициализаци€ и вывод
    // «а внутренниим устройством матрицы - в папочку include, читать гайд по ней
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
