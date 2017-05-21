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
            _stor = Vector<T>(deg + 1);
            for (int i = 0; i <= _deg; i++)
            {
                _stor[i] = 0;
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
            _stor = poly._stor;
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
