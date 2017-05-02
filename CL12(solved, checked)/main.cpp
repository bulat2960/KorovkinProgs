#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    Stack<char> St(4);
    try
    {
        St.push('a');
        St.push('b');
        St.push('c');
        St.push('d');
        St.push('a');
        St.print();
    }
    catch (const out_of_range& e)
    {
        cout << e.what() << endl;
    }
    catch (const char* e)
    {
        cout << e << endl;
    }
    return 0;
}
