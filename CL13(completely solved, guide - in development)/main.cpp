#include <iostream>
#include "RingBuffer.h"

using namespace std;

int main()
{
    RingBuffer<int> buffer(5);

    for (int i = 0; i < 4; i++)
    {
        buffer.add(i + 2);
    }
    buffer.add(10);
    buffer.add(12);
    Vector<int> stor = buffer.getStor();
    cout << stor << endl;
    buffer[3] = 123;
    stor = buffer.getStor();
    cout << stor << endl;

}
