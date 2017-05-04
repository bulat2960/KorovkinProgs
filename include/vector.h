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

        Vector(const Vector<T>& vec)
        {
            if (vec._storSize > 0)
            {
                delete[] _stor;
            }
            _storSize = vec._storSize;
            _stor = new T[vec._storSize];
            for (unsigned i = 0; i < vec._storSize; i++)
            {
                _stor[i] = vec._stor[i];
            }
        }

        ~Vector()
        {
            delete[] _stor;
        }

        void push_back(T data)
        {
            T* result = new T[_storSize];

            for (unsigned i = 0; i < _storSize; i++)
            {
                result[i] = _stor[i];
            }

            delete[] _stor;

            _storSize++;
            _stor = new T[_storSize];

            for (unsigned i = 0; i < _storSize; i++)
            {
                _stor[i] = ((i != _storSize - 1) ? result[i] : data);
            }
        }

        void push_front(T data)
        {
            T* result = new T[_storSize];

            for (unsigned i = 0; i < _storSize; i++)
            {
                result[i] = _stor[i];
            }

            delete[] _stor;

            _storSize++;
            _stor = new T[_storSize];

            for (unsigned i = 0; i < _storSize; i++)
            {
                _stor[i] = ((i == 0) ? data : result[i - 1]);
            }
        }

        int size() const
        {
            return _storSize;
        }

        void resize(int newSize)
        {
            _storSize = newSize;
            delete[] _stor;
            _stor = new T[_storSize];
            for (unsigned i = 0; i < _storSize; i++)
            {
                _stor[i] = 0;
            }
        }

        bool empty() const
        {
            return (_storSize == 0 ? true : false);
        }

        void clear()
        {
            _storSize = 0;
            delete[] _stor;
        }
		
		T front() const
		{
			return _stor[0];
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
