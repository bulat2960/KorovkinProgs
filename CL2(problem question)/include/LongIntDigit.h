#ifndef LONGINTDIGIT_H
#define LONGINTDIGIT_H

#include "vector.h"
#include <cstdlib>

class LongIntDigit
{
    private:
        Vector<int> _vec;
    public:
        LongIntDigit(Vector<int>);
        LongIntDigit(const LongIntDigit&)
        LongIntDigit& operator+(const LongIntDigit&);
};

#endif // LONGINTDIGIT_H
