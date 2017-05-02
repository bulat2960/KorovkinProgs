#include <iostream>
#include <cstdlib>
#include "LongIntDigit.h"
#include "vector.h"

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

LongIntDigit operator+(const LongIntDigit& digit1, const LongIntDigit& digit2)
{
    LongIntDigit res = digit1;
    Vector<int> vec = digit1.getDigit();

    /*cout << "IN OPERATOR DIGIT" << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << ' ';
    }
    cout << endl;*/

    res += digit2;
    return res;
}

ostream& operator<<(ostream& ost, const LongIntDigit& digit)
{
    Vector<int> vec = digit.getDigit();
    for (int i = 0; i < vec.size(); i++)
    {
        ost << vec[i];
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

    LongIntDigit digit3 = digit1 + digit2;
    cout << "digit3 = " << digit3 << endl;

    return 0;
}
