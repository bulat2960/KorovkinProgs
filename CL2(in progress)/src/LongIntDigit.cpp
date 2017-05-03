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
        int element = static_cast<int>(vec[0] / pow(10, counter - 1 - i));
        tempVec.push_back(element);
        vec[0] -= element * pow(10, counter - 1 - i);
    }

    for (int i = 1; i < vec.size(); i++)
    {
        tempVec.push_back(vec[i]);
    }

    vec = tempVec;
}

LongIntDigit& LongIntDigit::operator+(const LongIntDigit& digit)
{
    int diff = max(vec.size() - digit.vec.size(), digit.vec.size() - vec.size());
    if ((sign == true && digit.sign == true) || (sign == false && digit.sign == false))
    {
        if (vec.size() >= digit.vec.size())
        {
            for (int i = vec.size() - 1; i >= diff; i--)
            {
                vec[i] += digit.vec[i - diff];
            }
        }
        else
        {
            LongIntDigit copyDigit = digit;

            for (int i = copyDigit.vec.size() - 1; i >= diff; i--)
            {
                copyDigit.vec[i] += vec[i - diff];
            }
            vec = copyDigit.vec;
            sign = copyDigit.sign;
        }
    }
    else
    {
        if (vec.size() > digit.vec.size())
        {
            for (int i = vec.size() - 1; i >= diff; i--)
            {
                vec[i] -= digit.vec[i - diff];
            }
        }
        if (vec.size() == digit.vec.size())
        {
            bool flag = false;
            for (int i = 0; i < vec.size(); i++)
            {
                if (vec[i] == digit.vec[i])
                {
                    continue;
                }
                if (vec[i] > digit.vec[i])
                {
                    flag = true;
                    break;
                }
            }

            if (flag == true)
            {
                for (int i = vec.size() - 1; i >= diff; i--)
                {
                    vec[i] -= digit.vec[i - diff];
                }
            }
            else
            {
                LongIntDigit copyDigit = digit;
                for (int i = copyDigit.vec.size() - 1; i >= diff; i--)
                {
                    copyDigit.vec[i] -= vec[i - diff];
                }
                vec = copyDigit.vec;
                sign = copyDigit.sign;
            }
        }
        if (vec.size() < digit.vec.size())
        {
            LongIntDigit copyDigit = digit;
            for (int i = copyDigit.vec.size() - 1; i >= diff; i--)
            {
                copyDigit.vec[i] -= vec[i - diff];
            }
            vec = copyDigit.vec;
            sign = copyDigit.sign;

        }
    }
    digitNormalization();
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

    for (int i = digit.vec.size() - 1; i >= 0; i--)
    {
        LongIntDigit tempDigit = *this;

        for (int j = 0; j < tempDigit.vec.size(); j++)
        {
            tempDigit.vec[j] *= digit.vec[i];
        }

        for (int j = 0; j < digit.vec.size() - 1 - i; j++)
        {
            tempDigit.vec.push_back(0);
        }

        cout << "TEMP: ";
        for (int i = 0; i < tempDigit.vec.size(); i++)
        {
            cout << tempDigit.vec[i];
        }
        cout << endl;

        result = result + tempDigit;
        cout << "RESULT: ";
        for (int i = 0; i < result.vec.size(); i++)
        {
            cout << result.vec[i];
        }
        cout << endl;
    }
    vec = result.vec;
    digitNormalization();
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
