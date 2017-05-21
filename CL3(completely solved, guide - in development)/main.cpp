#include <iostream>
#include <string>
#include "Data.h"

using namespace std;

void generateData(char* str)
{
    int i = 0;
    while (true)
    {
        char element = cin.get(); // Читаем символ из потока ввода
        if (element == '\n') // Если конец строки(нажат Enter) выходим, иначе записываем и читаем дальше
        {
            break;
        }
        else
        {
            str[i] = element;
            i++;
        }
    }
}

int main()
{
    char* str1 = new char[10];
    char* str2 = new char[10];
    generateData(str1);
    generateData(str2);

    Data data1(str1);
    Data data2(str2);

    cout << "DIFF = " << data1.diff(data2);

    return 0;
}
