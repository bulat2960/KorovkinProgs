#include <iostream>
#include "RingBuffer.h"

using namespace std;

int main()
{
    RingBuffer<int> buffer(5);

    for (int i = 0; i < 4; i++)
    {
        buffer.add(i + 2);
        cout << "TAIL: " << buffer.getTail() << " HEAD: " << buffer.getHead() << endl;
    }
    buffer.add(10);
    cout << "TAIL: " << buffer.getTail() << " HEAD: " << buffer.getHead() << endl;
    buffer.add(12);
    cout << "TAIL: " << buffer.getTail() << " HEAD: " << buffer.getHead() << endl;
    int* stor = buffer.getStor();
    for (int i = 0; i < 5; i++)
    {
        cout << stor[i] << ' ';
    }
    cout << endl;
    buffer[3] = 123;
    stor = buffer.getStor();
    for (int i = 0; i < 5; i++)
    {
        cout << stor[i] << ' ';
    }
    cout << endl;

}
