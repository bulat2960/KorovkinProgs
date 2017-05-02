#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

template <typename T>
class Vector
{
    private:
        T* _stor;
        unsigned _storSize;
    public:
        Vector()
        {
            _storSize = 0;
            _stor = nullptr;
        }

        ~Vector()
        {
            delete[] _stor;
        }

        void push_back(T data)
        {
            _storSize++;
            T* result = new T[_storSize];

            for (unsigned i = 0; i < _storSize; i++)
            {
                result[i] = ((i != _storSize - 1) ? _stor[i] : data);
            }
            delete[] _stor;
            _stor = result;
        }

        int size() const
        {
            return _storSize;
        }

        bool empty() const
        {
            return _storSize == 0 ? true : false;
        }

        void clear()
        {
            _storSize = 0;
            _stor = new T[_storSize];
        }

        T back() const
        {
            return _stor[_storSize - 1];
        }

        T& operator [](int index) const
        {
            return _stor[index];
        }
};

#endif // VECTOR_H_INCLUDED
