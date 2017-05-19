#ifndef VECTORDICTIONARY_H_INCLUDED
#define VECTORDICTIONARY_H_INCLUDED

using namespace std;

template <typename T>
class VectorDictionary
{
    private:
        T* _words;
        T* _translates;
        int _storSize;
    public:
        VectorDictionary()
        {
            _storSize = 0;
            _words = nullptr;
            _translates = nullptr;
        }

        VectorDictionary(int storSize)
        {
            _storSize = storSize;
            _words = new T[_storSize];
            _translates = new T[_storSize];
        }

        VectorDictionary(const VectorDictionary<T>& vec)
        {
            *this = vec;
        }

        void operator=(const VectorDictionary<T>& vec)
        {
            _storSize = vec._storSize;
            _words = new T[_storSize];
            _translates = new T[_storSize];

            for (int i = 0; i < vec._storSize; i++)
            {
                _words[i] = vec._words[i];
                _translates[i] = vec._translates[i];
            }
        }

        ~VectorDictionary()
        {
            delete[] _words;
            delete[] _translates;
        }

        void push_back(T data1, T data2)
        {
            T* tempWords = new T[_storSize];
            T* tempTranslates = new T[_storSize];

            for (int i = 0; i < _storSize; i++)
            {
                tempWords[i] = _words[i];
                tempTranslates[i] = _translates[i];
            }

            delete[] _words;
            delete[] _translates;

            _storSize++;
            _words = new T[_storSize];
            _translates = new T[_storSize];

            for (int i = 0; i < _storSize; i++)
            {
                _words[i] = ((i != _storSize - 1) ? tempWords[i] : data1);
                _translates[i] = ((i != _storSize - 1) ? tempTranslates[i] : data2);
            }

            delete[] tempWords;
            delete[] tempTranslates;
        }

        int size() const
        {
            return _storSize;
        }

        bool empty() const
        {
            return (_storSize == 0 ? true : false);
        }

        void clear()
        {
            _storSize = 0;
            delete[] _words;
            delete[] _translates;
        }

        T searchKey(T& word)
        {
            for (int i = 0; i < _storSize; i++)
            {
                if (word == _words[i])
                {
                    return _translates[i];
                }
            }
            throw "WORD NOT FOUND";
        }

        friend ostream& operator<<(ostream& ost, const VectorDictionary<T>& vec)
        {
            for (int i = 0; i < vec._storSize; i++)
            {
                ost << vec._words[i] << ' ' << vec._translates[i] << '\n';
            }
            return ost;
        }
};

#endif // VECTORDICTIONARY_H_INCLUDED
