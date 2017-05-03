#ifndef POLYNOM_H
#define POLYNOM_H

template<typename T>
class Polynom
{
    private:
        T* arr;
        int deg;
    public:
        Polynom()
        {
            arr = nullptr;
            deg = 0;
        }

        Polynom(T* _arr, int _deg)
        {
            deg = _deg;
            arr = new T[_deg];

            for (int i = 0; i <= deg; i++)
            {
                arr[i] = _arr[i];
            }
        }

        ~Polynom()
        {
            delete[] arr;
        }

        Polynom& operator+(const Polynom& poly)
        {
            if (deg >= poly.deg)
            {
                int diff = deg - poly.deg;
                for (int i = 0; i <= deg; i++)
                {
                    arr[diff + i] += poly.arr[i];
                }
                return *this;
            }
            else
            {
                int* temp = new T[deg + 1];
                for (int i = 0; i <= deg; i++)
                {
                    temp[i] = arr[i];
                }

                delete[] arr;

                arr = new T[poly.deg + 1];
                deg = poly.deg;
                for (int i = 0; i <= deg; i++)
                {
                    arr[i] = poly.arr[i];
                }

                int diff = poly.deg - deg;
                for (int i = 0; i <= deg; i++)
                {
                    arr[diff + i] += temp[i];
                }
                return *this;
            }
        }
};

#endif // POLYNOM_H
