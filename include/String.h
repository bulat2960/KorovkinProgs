#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

using namespace std;

class String
{
    private:
        char* _str;
        int _strSize;
    public:
        String()
        {
            _str = nullptr;
            _strSize = 0;
        }

        String(const char* str)
        {
            _strSize = getSize(str);
            _str = new char[_strSize];
            for (int i = 0; i < _strSize; i++)
            {
                _str[i] = str[i];
            }
        }

        int getSize(const char* str)
        {
            int i = 0;
            while (str[i] != '\0')
            {
                i++;
            }
            return i;
        }

        void operator=(const char* str)
        {
            delete[] _str;
            _strSize = getSize(str);
            _str = new char[_strSize];
            for (int i = 0; i < _strSize; i++)
            {
                _str[i] = str[i];
            }
        }

        bool operator==(const String& str)
        {
            if (_strSize != str._strSize)
            {
                return false;
            }
            else
            {
                for (int i = 0; i < _strSize; i++)
                {
                    if (_str[i] != str._str[i])
                    {
                        return false;
                    }
                }
            }
            return true;
        }

        int size() const
        {
            return _strSize;
        }

        ~String()
        {
            delete[] _str;
        }

        const char& operator[](int index) const
        {
            return _str[index];
        }

        friend istream& operator>>(istream& ist, String& str)
        {
            char* arr = new char[256];

            int i = 0;
            while (true)
            {
                char element = ist.get();
                if (element != ' ' && element != '\n' && !ist.eof())
                {
                    arr[i] = element;
                    i++;
                }
                else
                {
                    break;
                }
            }

            str._str = arr;
            str._strSize = str.getSize(arr);
            return ist;
        }

        friend ostream& operator<<(ostream& ost, const String& str)
        {
            for (int i = 0; i < str.size(); i++)
            {
                ost << str._str[i];
            }
            return ost;
        }
};

#endif // STRING_H_INCLUDED
