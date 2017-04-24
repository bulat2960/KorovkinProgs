#include <iostream>
#include "Data.h"

using namespace std;

int main()
{
    Data data1("01 01 2017");
    cout << data1.getDay() << endl;
    cout << data1.getMonth() << endl;
    cout << data1.getYear() << endl;
    cout << "-----------------------" << endl;

    Data data2("01 02 2018");
    cout << data2.getDay() << endl;
    cout << data2.getMonth() << endl;
    cout << data2.getYear() << endl;
    cout << "-----------------------" << endl;

    cout << data1.diff(data2);

    return 0;
}
