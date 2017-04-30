#include "LongIntDigit.h"

LongIntDigit::LongIntDigit(Vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        _vec.push_back(vec[i]);
    }
}

LongIntDigit::LongIntDigit(const LongIntDigit& dig)
{
    _vec = dig._vec;
}

LongIntDigit& operator+(const LongIntDigit& digit);
{
    if (_vec.size() > digit._vec.size())
    {
        LongIntDigit res(*this);
        return res;
    }
    else
    {
        LongIntDigit res(digit);
        return res;
    }
}
