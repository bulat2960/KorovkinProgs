#ifndef RINGBUFFER_H_INCLUDED
#define RINGBUFFER_H_INCLUDED

#include "Vector.h"

template <typename T>
class RingBuffer
{
    private:
        Vector<T> stor;
        int elementsCount;
        int maxSize;
        int head;
        int tail;
    public:
        RingBuffer(int _maxSize)
        {
            maxSize = _maxSize;
            stor = Vector<T>(maxSize);
            for (int i = 0; i < maxSize; i++)
            {
                stor[i] = -1;
            }
            elementsCount = 0;
            head = 0;
            tail = 0;
        }
        T& operator[](int index) const
        {
            if ((index < 0) || (index >= maxSize))
            {
                throw std::out_of_range("Index is outside the array");
            }
            return stor[(head + index - 1) % maxSize];
        }
        int bufferSize()
        {
            return elementsCount;
        }
        void flush()
        {
            tail = 0;
            head = 0;
            elementsCount = 0;
            for (int i = 0; i < maxSize; i++)
            {
                stor[i] = -1;
            }
        }
        bool isFull()
        {
            return (elementsCount == maxSize);
        }
        bool isEmpty()
        {
            return (elementsCount == 0);
        }
        void add(T data)
        {
            if (elementsCount != maxSize)
            {
                elementsCount++;
            }

            stor[tail] = data;
            tail = (tail + 1) % maxSize;

            if (elementsCount == maxSize)
            {
                head = (tail + 1) % maxSize;
            }
        }
        Vector<T> getStor() const
        {
            return stor;
        }
        int getTail() const
        {
            return tail;
        }
        int getHead() const
        {
            return head;
        }
};

#endif // RINGBUFFER_H_INCLUDED
