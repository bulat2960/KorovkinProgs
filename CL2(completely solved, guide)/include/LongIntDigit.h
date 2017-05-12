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
        LongIntDigit(const Vector<int>&, bool);
        void operator=(const LongIntDigit&);
        Vector<int> getDigit() const;
        bool getSign() const;
        LongIntDigit operator+(const LongIntDigit&);
        LongIntDigit operator-(const LongIntDigit&);
        LongIntDigit operator*(const LongIntDigit&);
        LongIntDigit operator/(const LongIntDigit&);
        LongIntDigit operator%(const LongIntDigit&);
        LongIntDigit operator^(int);
};

#endif // LONGINTDIGIT_H
