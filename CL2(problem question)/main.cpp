#include <iostream>
#include <cstdlib>
#include "LongIntDigit.h"
#include "vector.h"

using namespace std;

void generateDigit(Vector<int>& vec)
{
    while (true)
    {
        char element = cin.get();
        if (element != '\n')
        {
            vec.push_back(element - char(48));
        }
        else
        {
            break;
        }
    }
}

int main()
{
    Vector<int> dig1;
    Vector<int> dig2;

    generateDigit(dig1);
    generateDigit(dig2);

    LongIntDigit digit1(dig1);
    LongIntDigit digit2(dig2);

    return 0;
}
