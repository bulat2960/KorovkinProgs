#include <iostream>
#include "Vector.h"
#include "Polynom.h"

using namespace std;

template<typename T>
ostream& operator<<(ostream& ost, const Polynom<T>& poly)
{
    for (int i = 0; i <= poly.getDeg(); i++)
    {
        if (poly.getDigit()[i] != 0)
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
    }
    return ost;
}

int main()
{
    Vector<int> vec1;
    Vector<int> vec2;
    int element;
    for (int i = 0; i < 3; i++)
    {
        cin >> element;
        vec1.push_back(element);
    }
    for (int i = 0; i < 2; i++)
    {
        cin >> element;
        vec2.push_back(element);
    }

    Polynom<int> poly1(vec1, 2);
    Polynom<int> poly2(vec2, 1);
    Polynom<int> poly3 = poly1 + poly2;
    cout << "poly1 = " << poly1 << endl;
    cout << "poly2 = " << poly2 << endl;
    cout << "poly3 = " << poly3 << endl;
    return 0;
}
