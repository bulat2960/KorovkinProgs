#include <iostream>
#include "Polynom.h"

using namespace std;

int main()
{
    int* arr1 = new int[5];
    for (int i = 0; i < 5; i++)
    {
        arr1[i] = i + 2;
    }

    int* arr2 = new int[4];
    for (int i = 0; i < 4; i++)
    {
        arr2[i] = i + 1;
    }

    Polynom<int> poly1(arr1, 4);
    Polynom<int> poly2(arr2, 3);
    Polynom<int> poly3 = poly1 + poly2;
    return 0;
}
