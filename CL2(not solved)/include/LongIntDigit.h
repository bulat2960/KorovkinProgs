#ifndef LONGINTDIGIT_H
#define LONGINTDIGIT_H

#include "vector.h"

class LongIntDigit
{
    private:
        Vector<int> vec;
        bool sign;
    public:
        LongIntDigit(Vector<char>);
        LongIntDigit(const LongIntDigit&);
        void digitNormalization();
        Vector<int> getDigit() const;
        LongIntDigit& operator+=(const LongIntDigit&);
};

#endif // LONGINTDIGIT_H
