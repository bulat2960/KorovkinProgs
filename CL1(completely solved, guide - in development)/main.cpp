#include <iostream>
#include <cstdlib>
#include "ComplexDigit.h"
#include "CPolinom.h"

using namespace std;

ostream& operator<<(ostream& ost, const ComplexDigit& _digit)
{
    ost << "(" << _digit.GetA() << ", " << _digit.GetB() << "i)";
    return ost;
}

istream& operator>>(istream& ist, ComplexDigit& _digit)
{
    ist >> _digit.GetA() >> _digit.GetB();
    return ist;
}

ostream& operator<<(ostream& ost, const CPolinom& _cPol)
{
    int sizeI = _cPol.size();
    for(int i = sizeI - 1; i >= 1; i--)
    {
        ost << _cPol[i] << "*X^" << i << " + ";
    }
    ost << _cPol[0];
    return ost;
}

istream& operator>>(istream& ist, CPolinom& cPoly)
{
    int polySize = cPoly.size();
    for (int i = polySize - 1; i >= 0; i--)
    {
        ist >> cPoly[i];
    }
    return ist;
}

int main()
{
    /*ComplexDigit digit1;
    ComplexDigit digit2;

    cin >> digit1;
    cin >> digit2;

    cout << "digit1 = " << digit1 << endl;
    cout << "digit2 = " << digit2 << endl;
    cout << "Summma = " << digit1 + digit2 << endl;
    cout << "Minus = " << digit1 - digit2 << endl;
    cout << "Mult = " << digit1 * digit2 << endl;
    cout << "Div = " << digit1 / digit2 << endl;*/

    CPolinom Polinom1(3), Polinom2(2);
    cin >> Polinom1;
    cin >> Polinom2;
    cout << "Polinom1 = " << Polinom1 << endl;
    cout << "Polinom2 = " << Polinom2 << endl;
    cout << "Summa = " << Polinom1 + Polinom2 << endl;
    cout << "Minus = " << Polinom1 - Polinom2 << endl;
    cout << "Mult = " << Polinom1 * Polinom2 << endl;
    cout << "Div = " << Polinom1 / Polinom2 << endl;
    cout << "Mod = " << Polinom1 % Polinom2 << endl;
    cout << "PointValue = " << Polinom1.pointValue( ComplexDigit( 7, 7) ) << endl;
/*
    CPolinom Polinom1( 2 ), Polinom2( 5 );
    cin >> Polinom1;
    Polinom2 = Polinom1.UpPower( 3 );
    cout << Polinom2.size() << endl;
    cout << Polinom2 << endl;
*/
    return 0;
}
