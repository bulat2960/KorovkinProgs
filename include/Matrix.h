#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

template<typename T>
class Array
{
    private:
        T* arr;
		int _arrSize;
    public:
        Array()
        {
            arr = nullptr;
            _arrSize = 0;
        }

        Array(const Array<T>& _arr)
        {
            _arrSize = _arr._arrSize;
            arr = new T[_arrSize];
            for (int i = 0; i < _arrSize; i++)
            {
                arr[i] = _arr[i];
            }
        }

        Array(int arrSize)
        {
            arr = new T[arrSize];
			_arrSize = arrSize;
        }

        int arrSize() const
        {
            return _arrSize;
        }

        T& operator[](int index) const
        {
            return arr[index];
        }

        ~Array()
        {
            delete[] arr;
        }
};

template<typename T>
class Matrix
{
    private:
        Array<T>* matrix;
        int _size1;
        int _size2;
    public:
        Matrix(int size1, int size2)
        {
            matrix = new Array<T>[size1];
            for (int i = 0; i < size1; i++)
            {
                matrix[i] = *(new Array<T>(size2));
            }
            _size1 = size1;
            _size2 = size2;
        }

        int size1() const
        {
            return _size1;
        }

        int size2() const
        {
            return _size2;
        }

        Array<T>& operator[](int index) const
        {
            return matrix[index];
        }

        ~Matrix()
        {
            delete matrix;
        }
};

#endif // MATRIX_H_INCLUDED
