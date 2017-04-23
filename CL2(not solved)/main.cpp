#include <iostream>

using namespace std;

class LongIntDigit
{
    private:
        long int _digit;
    public:
        LongIntDigit(long int digit)
        {
            _digit = digit;
        }

        LongIntDigit& operator+=(const LongIntDigit number)
        {
            _digit = _digit + number._digit;
            return *this;
        }

        LongIntDigit& operator-=(const LongIntDigit number)
        {
            _digit = _digit - number._digit;
            return *this;
        }

        LongIntDigit& operator*=(const LongIntDigit number)
        {
            _digit = _digit * number._digit;
            return *this;
        }

        LongIntDigit& operator/=(const LongIntDigit number)
        {
            _digit = _digit / number._digit;
            return *this;
        }

        LongIntDigit& pow(unsigned k)
        {
            long int buf = _digit;
            for (unsigned i = 0; i < k - 1; i++) // -1 потому, что _digit уже содержит в себе один множитель
            {
                _digit *= buf;
            }
            return *this;
        }

        long int getData() const
        {
            return _digit;
        }
};


LongIntDigit operator+(const LongIntDigit& number1, const LongIntDigit& number2)
{
    LongIntDigit res = number1;
    res += number2;
    return res;
}

LongIntDigit operator-(const LongIntDigit& number1, const LongIntDigit& number2)
{
    LongIntDigit res = number1;
    res -= number2;
    return res;
}

LongIntDigit operator*(const LongIntDigit& number1, const LongIntDigit& number2)
{
    LongIntDigit res = number1;
    res *= number2;
    return res;
}

LongIntDigit operator/(const LongIntDigit& number1, const LongIntDigit& number2)
{
    LongIntDigit res = number1;
    res /= number2;
    return res;
}

ostream& operator<<(ostream& ost, const LongIntDigit& number)
{
    ost << number.getData();
    return ost;
}

bool testPlus()
{
    LongIntDigit number1(10);
    LongIntDigit number2(15);
    LongIntDigit number3 = number1 + number2;
    if (number3.getData() == 25)
    {
        return true;
    }
    return false;
}

bool testMinus()
{
    LongIntDigit number1(15);
    LongIntDigit number2(10);
    LongIntDigit number3 = number1 - number2;
    if (number3.getData() == 5)
    {
        return true;
    }
    return false;
}

bool testMult()
{
    LongIntDigit number1(10);
    LongIntDigit number2(25);
    LongIntDigit number3 = number1 * number2;
    if (number3.getData() == 250)
    {
        return true;
    }
    return false;
}

bool testDiv()
{
    LongIntDigit number1(10000);
    LongIntDigit number2(25);
    LongIntDigit number3 = number1 / number2;
    if (number3.getData() == 400)
    {
        return true;
    }
    return false;
}

bool testPow()
{
    LongIntDigit number(2);
    number.pow(10);
    if (number.getData() == 1024)
    {
        return true;
    }
    return false;
}

int main()
{
    cout << "TEST PLUS : " << testPlus() << endl;
    cout << "TEST MINUS : " << testMinus() << endl;
    cout << "TEST MULT : " << testMult() << endl;
    cout << "TEST DIV : " << testDiv() << endl;
    cout << "TEST POW : " << testPow() << endl;

    return 0;
}
