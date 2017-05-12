#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <stdexcept>
#include "Vector.h"

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
};

#endif // MATRIX_H_INCLUDED
