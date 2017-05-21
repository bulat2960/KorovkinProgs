#include <iostream>
#include "Vector.h"
#include "Polynom.h"

using namespace std;

template<typename T>
ostream& operator<<(ostream& ost, const Polynom<T>& poly)
{
    for (int i = 0; i <= poly.getDeg(); i++)
    {
        if (poly.getDeg() - i != 0)
        {
            if (poly.getDigit()[i] != 1)
            {
                ost << "(" << poly.getDigit()[i] << "*x^" << poly.getDeg() - i << ") + ";
            }
            else
            {
                ost << "(x^" << poly.getDeg() - i << ") + ";
            }
        }
        else
        {
            ost << poly.getDigit()[i];
        }
    }
    return ost;
}

int main()
{
    Vector<double> vec1;
    Vector<double> vec2;
    int element;

    cout << "Enter digit1: ";
    for (int i = 0; i < 3; i++)
    {
        cin >> element;
        vec1.push_back(element);
    }

    cout << "Enter digit2: ";
    for (int i = 0; i < 3; i++)
    {
        cin >> element;
        vec2.push_back(element);
    }

    Polynom<double> poly1(vec1);
    Polynom<double> poly2(vec2);

    return 0;
}
