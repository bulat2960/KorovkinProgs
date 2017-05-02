#include <iostream>
#include <string>
#include "Data.h"

using namespace std;

int main()
{
    string str;
    getline(cin, str);

    Data data1(str.c_str());
    cout << "-----------------------" << endl;

    getline(cin, str);

    Data data2(str.c_str());
    cout << "-----------------------" << endl;

    cout << data1.diff(data2);

    return 0;
}
