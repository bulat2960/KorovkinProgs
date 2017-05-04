#include "LongIntDigit.h"

#include <cmath>
#include <iostream>
using namespace std;

LongIntDigit::LongIntDigit()
{
    sign = true;
}

LongIntDigit::LongIntDigit(const Vector<char>& _vec)
{
    if (_vec[0] != '-')
    {
        for (int i = 0; i < _vec.size(); i++)
        {
            vec.push_back(static_cast<int>(_vec[i] - char(48)));
        }
        sign = true;
    }
    else
    {
        for (int i = 1; i < _vec.size(); i++)
        {
            vec.push_back(static_cast<int>(_vec[i] - char(48)));
        }
        sign = false;
    }
}

LongIntDigit::LongIntDigit(const LongIntDigit& dig)
{
    vec = dig.vec;
    sign = dig.sign;
}

void LongIntDigit::digitNormalization()
{
    for (int i = vec.size() - 1; i > 0; i--)
    {
        if (vec[i] >= 10)
        {
            int transit = vec[i] / 10;
            int remainder = vec[i] - transit * 10;
            vec[i] = remainder;
            vec[i - 1] += transit;
        }
        if (vec[i] < 0)
        {
            vec[i] += 10;
            vec[i - 1]--;
        }
    }

    while (vec[0] >= 10)
    {
        int transit = vec[0] / 10;
        int remainder = vec[0] - transit * 10;
        vec[0] = remainder;
        vec.push_front(transit);
    }
}

LongIntDigit& LongIntDigit::operator+(const LongIntDigit& digit)
{
    LongIntDigit copyDigit = digit;

    int diff = max(vec.size() - digit.vec.size(), digit.vec.size() - vec.size());

    //CASE 1: ++ & SIZE1 >= SIZE2
    if (sign == true && digit.sign == true && vec.size() >= digit.vec.size())
    {
        for (int i = vec.size(); i >= diff; i--)
        {
            vec[i] += digit.vec[i - diff];
        }
    }

    //CASE 2: -- & SIZE1 >= SIZE2
    if (sign == false && digit.sign == false && vec.size() >= digit.vec.size())
    {
        for (int i = vec.size(); i >= diff; i--)
        {
            vec[i] += digit.vec[i - diff];
        }
    }
    cout << "VEC: ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
    }
    cout << endl;
    digitNormalization();
    cout << "VEC: ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
    }
    cout << endl;
    return *this;
}

LongIntDigit& LongIntDigit::operator-(const LongIntDigit& digit)
{
    LongIntDigit copyDigit = digit;
    copyDigit.sign == true ? copyDigit.sign = false : copyDigit.sign = true;
    *this = *this + copyDigit;
    return *this;
}

LongIntDigit& LongIntDigit::operator*(const LongIntDigit& digit)
{
    LongIntDigit result;
    result.vec.resize(vec.size() + digit.vec.size() - 1);

    const Vector<int> tempVec = vec;
    for (int i = digit.vec.size() - 1; i >= 0; i--)
    {
        LongIntDigit tempDigit;
        tempDigit.vec = tempVec;
        tempDigit.sign = sign;

        for (int j = 0; j < tempDigit.vec.size(); j++)
        {
            tempDigit.vec[j] *= digit.vec[i];
        }

        for (int i = 0; i < digit.vec.size() - 1 - i; i++)
        {
            tempDigit.vec.push_back(0);
        }
        result = result + tempDigit;
    }

    vec = result.vec;
    return *this;
}

Vector<int> LongIntDigit::getDigit() const
{
    return vec;
}

bool LongIntDigit::getSign() const
{
    return sign;
}
