#include <iostream>
#include <cstdlib>
#include "LongIntDigit.h"
#include "Vector.h"

using namespace std;

void generateDigit(Vector<char>& vec)
{
    while (true)
    {
        char element = cin.get();
        if (element != '\n')
        {
            vec.push_back(element);
        }
        else
        {
            break;
        }
    }
}

ostream& operator<<(ostream& ost, const LongIntDigit& digit) //????????????????????Неверно
{
    if (digit.getSign() == false)
    {
        ost << '-';
    }
    int k = 0;
    while (digit.getDigit()[k] == 0)
    {
        k++;
    }
    for (int i = k; i < digit.getDigit().size(); i++)
    {
        ost << digit.getDigit()[i];
    }
    return ost;
}

int main()
{
    Vector<char> dig1;
    Vector<char> dig2;

    cout << "Enter digit1: ";
    generateDigit(dig1);
    cout << "Enter digit2: ";
    generateDigit(dig2);

    LongIntDigit digit1(dig1);
    LongIntDigit digit2(dig2);

    cout << "digit1 = " << digit1 << endl;
    cout << "digit2 = " << digit2 << endl;

    LongIntDigit digitSumma = digit1 + digit2;
    cout << "digitSumma = " << digitSumma << endl;
    LongIntDigit digitMinus = digit1 - digit2;
    cout << "digitMinus = " << digitMinus << endl;
    LongIntDigit digitMult = digit1 * digit2;
    cout << "digitMult = " << digitMult << endl;
    LongIntDigit digitDiv = digit1 / digit2;
    cout << "digitDiv = " << digitDiv << endl;

    return 0;
}

