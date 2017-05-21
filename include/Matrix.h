#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <stdexcept>
#include <iomanip>
#include "Vector.h"

using namespace std;

template<typename T>
class Matrix
{
    private:
        Vector<T>* _matrix;
        int _size1;
        int _size2;
    public:
        Matrix(int size1, int size2)
        {
            _size1 = size1;
            _size2 = size2;
            _matrix = new Vector<T>[_size1];

            for (int i = 0; i < _size1; i++)
            {
                Vector<T> vec(_size2);
                _matrix[i] = vec;
            }
        }

        int size1() const
        {
            return _size1;
        }

        int size2() const
        {
            return _size2;
        }

        Vector<T>& operator[](int index) const
        {
            if (index < 0 || index > _size1 - 1)
            {
                throw std::out_of_range("Index is outside the array");
            }
            return _matrix[index];
        }

        ~Matrix()
        {
            delete[] _matrix;
        }

        friend ostream& operator<<(ostream& ost, const Matrix& matrix)
        {
            for (int i = 0; i < matrix.size1(); i++)
            {
                for (int j = 0; j < matrix.size2(); j++)
                {
                    if (matrix[i][j] < 0.001 && matrix[i][j] > -0.001)
                    {
                        matrix[i][j] = 0;
                    }
                    ost << setw(4) << setprecision(2) << matrix[i][j] << ' ';
                }
                ost << endl;
            }
            return ost;
        }
};

#endif // MATRIX_H_INCLUDED
