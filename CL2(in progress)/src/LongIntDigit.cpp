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
    int start = 0;
    if (_vec[0] != '-')
    {
        sign = true;
    }
    else
    {
        start = 1;
        sign = false;
    }

    for (int i = start; i < _vec.size(); i++)
    {
        vec.push_back(static_cast<int>(_vec[i] - char(48)));
    }
}
LongIntDigit::LongIntDigit(const Vector<int>& _vec, bool _sign)
{
    vec = _vec;
    sign = _sign;
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

LongIntDigit LongIntDigit::operator+(const LongIntDigit& digit)
{
    LongIntDigit Result;
    int VecSize0 = vec.size();
    int VecSize1 = digit.vec.size();
    int MaxVecSize = max(VecSize0, VecSize1);
    Vector<int> vecRes(MaxVecSize);
    int DigitAdd = 0;
    bool ResSign;
    for (int i = 0; i < MaxVecSize; i++)
    {
        int Digit0, Digit1, Digit2;
        Digit0 = (i < VecSize0) ? vec[VecSize0 - i - 1] : 0;
        Digit1 = (i < VecSize1) ? digit.vec[VecSize1 - i - 1] : 0;
        Digit2 = (sign == true ? 1 : -1) * Digit0 + (digit.sign == true ? 1 : -1) * Digit1 + DigitAdd;
        if (abs(Digit2) >= 10)
        {
            DigitAdd = Digit2 > 0 ? 1 : -1;   //Добавляем(отнимаем) 1 к следующему разряду
            Digit2 -= DigitAdd * 10;      //Само число тоже изменяем
        }
        else
        {
            DigitAdd = 0;
        }
        ResSign = (Digit2 >= 0 && DigitAdd >= 0);
        if ((sign!=digit.sign ) && (Digit2 < 0))
        {
            DigitAdd = -1;
            Digit2 += 10;
        }
        vecRes[MaxVecSize - i - 1] = abs(Digit2);
    }
    if ( ( sign!=digit.sign ) && DigitAdd == -1 )
    {
        Vector<int> vecMil(MaxVecSize);
        vecMil.push_front(1);
        Result = LongIntDigit( vecMil, true ) + LongIntDigit( vecRes, false );
        Result.sign = false;
    }
    else {
        if ( abs( DigitAdd ) == 1 )
            vecRes.push_front(1);
        Result = LongIntDigit( vecRes, ResSign );
    }
    return Result;
}

LongIntDigit LongIntDigit::operator-(const LongIntDigit& digit)
{
    LongIntDigit result;
    LongIntDigit copyDigit = digit;
    copyDigit.sign == true ? copyDigit.sign = false : copyDigit.sign = true;
    result = *this + copyDigit;
    return result;
}

LongIntDigit LongIntDigit::operator*(const LongIntDigit& digit)
{
    LongIntDigit Result;
    int VecSize0 = vec.size()
    int VecSize1 = digit.vec.size();
    for (int i = 0; i < VecSize1; i++)
    {
        Vector<int> vecRes(VecSize0+1);
        int Digit0, Digit1, Digit2;
        int DigitAdd = 0;

        Digit1 = digit.vec[VecSize1-i-1];
        for (int j = 0; j < VecSize0; j++)
        {
            Digit0 = vec[VecSize0-j-1];
            Digit2 = Digit0 * Digit1 + DigitAdd;
            DigitAdd = Digit2 / 10;
            Digit2 -= DigitAdd * 10;
            vecRes[VecSize0-j] = Digit2; //Здесь VecSize0-j т.к. vecRes на один разряд длинее
        }
        vecRes[0] = DigitAdd;
        for (int k = 0; k < i; k++)
        {
            vecRes.push_back(0);
        }
        Result = Result + LongIntDigit( vecRes, sign==digit.sign );
    }
    return Result;
}

LongIntDigit LongIntDigit::operator/(const LongIntDigit& digit)
{
    LongIntDigit Result;
    int
        VecSize0 = vec.size()
    ,   VecSize1 = digit.vec.size()
    ,   Digit2;
    Vector<int> vecRes(0), Divider = digit.vec;

    LongIntDigit
        lidDelta,
        lidDividend = LongIntDigit( vec, true );
    for (int i = 0; i < VecSize0 - VecSize1 + 1; i++)
    {
        Vector<int>
            Divider = digit.vec;
        for (int k = 0; k < VecSize0 - VecSize1 - i; k++)
            Divider.push_back( 0 );
        LongIntDigit
            lidDivider = LongIntDigit( Divider, true );

        Digit2 = 0;
        lidDelta = lidDividend;
        while( lidDelta.sign == true )
        {
            lidDelta = lidDelta - lidDivider;
            if( lidDelta.sign == true )
            {
                Digit2++;
                lidDividend = lidDelta;
            }
        }
        vecRes.push_back( Digit2 );
    }
    Result = LongIntDigit( vecRes, sign==digit.sign );
    return Result;
}


Vector<int> LongIntDigit::getDigit() const
{
    return vec;
}

bool LongIntDigit::getSign() const
{
    return sign;
}
