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

        Polynom(const Vector<T>& stor, int deg)
        {
            _deg = deg;
            _stor = stor;
        }

        void operator=(const Polynom& poly)
        {
            _deg = poly._deg;
            _stor = poly._stor;
        }

        Polynom operator+(const Polynom& poly)
        {
            Polynom temp = poly;
            while (temp._deg > _deg)
            {
                _deg++;
                _stor.push_front(0);
            }
            while (_deg > temp._deg)
            {
                temp._deg++;
                temp._stor.push_front(0);
            }

            Polynom result = *this;

            for (int i = 0; i <= _deg; i++)
            {
                result._stor[i] += temp._stor[i];
            }
            return result;
        }

        Polynom operator-(const Polynom& poly)
        {
            Polynom temp = poly;
            while (temp._deg > _deg)
            {
                _deg++;
                _stor.push_front(0);
            }
            while (_deg > temp._deg)
            {
                temp._deg++;
                temp._stor.push_front(0);
            }

            Polynom result = *this;

            for (int i = 0; i <= _deg; i++)
            {
                result._stor[i] -= temp._stor[i];
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
