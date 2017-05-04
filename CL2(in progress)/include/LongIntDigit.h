#ifndef LONGINTDIGIT_H
#define LONGINTDIGIT_H

#include "Vector.h"

class LongIntDigit
{
    private:
        Vector<int> vec;
        bool sign;
    public:
        LongIntDigit();
        LongIntDigit(const Vector<char>&);
        LongIntDigit(const LongIntDigit&);
        Vector<int> getDigit() const;
        bool getSign() const;
        void digitNormalization();
        LongIntDigit& operator+(const LongIntDigit&);
        LongIntDigit& operator-(const LongIntDigit&);
        LongIntDigit& operator*(const LongIntDigit&);
};

#endif // LONGINTDIGIT_H
