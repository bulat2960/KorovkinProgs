#include "ComplexDigit.h"
#include <stdexcept>

ComplexDigit::ComplexDigit()
{
    a = 0;
    b = 0;
}

ComplexDigit::ComplexDigit(double _a, double _b)
{
    a = _a;
    b = _b;
}

ComplexDigit::ComplexDigit(const ComplexDigit& _digit)
{
    a = _digit.GetA();
    b = _digit.GetB();
}

void ComplexDigit::operator=(const ComplexDigit& _digit)
{
    a = _digit.GetA();
    b = _digit.GetB();
}

double ComplexDigit::GetA() const
{
    return a;
}

double ComplexDigit::GetB() const
{
    return b;
}

double& ComplexDigit::GetA()
{
    return a;
}

double& ComplexDigit::GetB()
{
    return b;
}

ComplexDigit ComplexDigit::operator+(const ComplexDigit& _digit)
{
    return ComplexDigit(a + _digit.a, b + _digit.b);
}

ComplexDigit ComplexDigit::operator-(const ComplexDigit& _digit)
{
    return ComplexDigit(a - _digit.a, b - _digit.b);
}

ComplexDigit ComplexDigit::operator*(const ComplexDigit& _digit)
{
    double c = _digit.a, d = _digit.b;
    return ComplexDigit((a * c - b * d), (b * c + a * d));
}

ComplexDigit ComplexDigit::operator/(const ComplexDigit& _digit)
{
    double c = _digit.a, d = _digit.b;
    double div = (c * c + d * d);
    if (div == 0)
    {
        throw std::invalid_argument("Divide by 0");
    }
    return ComplexDigit((a * c + b * d) / div, (b * c - a * d) / div);
}

ComplexDigit ComplexDigit::operator^(int _num)
{
    ComplexDigit result(1, 0);
    for (int i = 0; i < _num; i++)
    {
        result = result * (*this);
    }
    return result;
}

ComplexDigit ComplexDigit::operator-()
{
    return ComplexDigit(-a, -b);
}
