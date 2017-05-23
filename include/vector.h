#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <stdexcept>

using namespace std;

template <typename T>
class Vector
{
    private:
        T* _stor;
        int _storSize;
    public:
        Vector()
        {
            _storSize = 0;
            _stor = nullptr;
        }

        Vector(int storSize)
        {
            _storSize = storSize;
            _stor = new T[_storSize];
        }

        Vector(const Vector<T>& vec)
        {
            *this = vec;
        }

        void operator=(const Vector<T>& vec)
        {
            _storSize = vec._storSize;
            _stor = new T[_storSize];
            for (int i = 0; i < vec._storSize; i++)
            {
                _stor[i] = vec._stor[i];
            }
        }

        Vector<T> operator+(const Vector<T>& vec)
        {
            Vector<T> result = *this;
            for (int i = 0; i < vec.size(); i++)
            {
                result.push_back(vec[i]);
            }
            return result;
        }

        ~Vector()
        {
            delete[] _stor;
        }

        void push_back(T data)
        {
            T* tempStor = new T[_storSize];

            for (int i = 0; i < _storSize; i++)
            {
                tempStor[i] = _stor[i];
            }

            delete[] _stor;

            _storSize++;
            _stor = new T[_storSize];

            for (int i = 0; i < _storSize; i++)
            {
                _stor[i] = ((i != _storSize - 1) ? tempStor[i] : data);
            }
        }

        void push_front(T data)
        {
            T* tempStor = new T[_storSize];

            for (int i = 0; i < _storSize; i++)
            {
                tempStor[i] = _stor[i];
            }

            delete[] _stor;

            _storSize++;
            _stor = new T[_storSize];

            for (int i = 0; i < _storSize; i++)
            {
                _stor[i] = ((i == 0) ? data : tempStor[i - 1]);
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

        T& operator[](int index) const
        {
            if (index < 0 || index > _storSize - 1)
            {
                throw out_of_range("Index is outside the array");
            }
            return _stor[index];
        }

        friend istream& operator>>(istream& ist, Vector& vec)
        {
            if (vec.size() == 0)
            {
                throw invalid_argument("Vector size == 0");
            }

            int i = 0;
            T element;

            while (ist >> element)
            {
                vec[i] = element;
                i++;
                if (i == vec.size())
                {
                    break;
                }
            }
            return ist;
        }

        friend ostream& operator<<(ostream& ost, const Vector& vec)
        {
            for (int i = 0; i < vec.size(); i++)
            {
                ost << vec[i] << ' ';
            }
            return ost;
        }

};

#endif // VECTOR_H_INCLUDED

