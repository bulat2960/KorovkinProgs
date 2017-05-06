#ifndef POLYNOM_H
#define POLYNOM_H

#include "Vector.h"

template<typename T>
class Polynom
{
    private:
        Vector<T> _stor;
        int _deg;
    public:
        Polynom()
        {
            _deg = 0;
        }

        Polynom(int deg)
        {
            _deg = deg;
            for (int i = 0; i <= _deg; i++)
            {
                _stor.push_back(0);
            }
        }

        Polynom(const Vector<T>& stor, int deg)
        {
            _deg = deg;
            _stor = stor;
        }

        void operator=(const Polynom& poly)
        {
            _deg = poly._deg;
            _stor.clear();
            for (int i = 0; i <= _deg; i++)
            {
                _stor.push_back(poly._stor[i]);
            }
        }

        Polynom operator+(const Polynom& poly)
        {
            while (poly._deg > _deg)
            {
                _deg++;
                _stor.push_front(0);
            }
            Polynom result = *this;

            for (int i = 0; i <= _deg; i++)
            {
                result._stor[i] += poly._stor[i];
            }
            std::cout << "WTF\n";
            return result;
        }

        Polynom operator-(const Polynom& poly)
        {
            while (poly._deg > _deg)
            {
                _deg++;
                _stor.push_front(0);
            }
            Polynom result = *this;

            for (int i = 0; i <= _deg; i++)
            {
                result._stor[i] -= poly._stor[i];
            }
            return result;
        }

        Polynom operator*(const Polynom& poly)
        {
        }

        int getDeg() const
        {
            return _deg;
        }

        Vector<T> getDigit() const
        {
            return _stor;
        }
};

#endif // POLYNOM_H
