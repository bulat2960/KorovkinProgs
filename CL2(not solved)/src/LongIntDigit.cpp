#include "LongIntDigit.h"

#include <cmath>

LongIntDigit::LongIntDigit(Vector<char> _vec)
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
    }

    int temp = vec[0];
    int counter = 0;
    while (temp != 0)
    {
        temp /= 10;
        counter++;
    }

    Vector<int> tempVec;

    for (int i = 0; i < counter; i++)
    {
        int element = vec[0] / pow(10, counter - 1 - i);
        tempVec.push_back(element);
        vec[0] -= element * 10;
    }

    for (int i = 1; i < vec.size(); i++)
    {
        tempVec.push_back(vec[i]);
    }

    vec = tempVec;
}

#include <iostream>
using namespace std;

LongIntDigit& LongIntDigit::operator+=(const LongIntDigit& digit)
{
    if (vec.size() > digit.vec.size())
    {
        /*cout << "CLASS DIGIT, SIZE = " << vec.size() << endl;
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << ' ';
        }
        cout << endl;

        cout << "RECEIVED DIGIT, SIZE = " << digit.vec.size() << endl;
        for (int i = 0; i < digit.vec.size(); i++)
        {
            cout << digit.vec[i] << ' ';
        }
        cout << endl;*/

        for (int i = 0; i < digit.vec.size(); i++)
        {
            vec[i + vec.size() - digit.vec.size()] += digit.vec[i];
        }
        digitNormalization();
    }
    return *this;
}

Vector<int> LongIntDigit::getDigit() const
{
    return vec;
}
