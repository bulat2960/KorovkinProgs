#include <iostream>
#include "Vector.h"
#include "Polynom.h"

using namespace std;

int main()
{
    Vector<double> vec1(3);
    Vector<double> vec2(2);

    cout << "Enter digit1: ";
    cin >> vec1;

    cout << "Enter digit2: ";
    cin >> vec2;

    Polynom<double> poly1(vec1);
    Polynom<double> poly2(vec2);
    Polynom<double> poly3 = poly1 + poly2;
    Polynom<double> poly4 = poly1 - poly2;
    Polynom<double> poly5 = poly1 * poly2;
    Polynom<double> poly6 = poly1 / poly2;
    Polynom<double> poly7 = poly1 % poly2;
    double sum = poly1.pointValue(2);
    cout << "POLY1 = " << poly1 << endl;
    cout << "POLY2 = " << poly2 << endl;
    cout << "PLUS = " << poly3 << endl;
    cout << "MINUS = " << poly4 << endl;
    cout << "MULT = " << poly5 << endl;
    cout << "DIV = " << poly6 << endl;
    cout << "REM = " << poly7 << endl;
    cout << "POINT VALUE = " << sum << endl;

    return 0;
}
