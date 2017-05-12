#ifndef RINGBUFFER_H_INCLUDED
#define RINGBUFFER_H_INCLUDED

template <typename T>
class RingBuffer
{
    private:
        T* stor; // Массив с хранимым буфером
        int elementsCount; // Текущее количество элементов в буфере
        int maxSize; // Максимальное количество
        int head; // Счетчик головы
        int tail; // Счетчик хвоста
    public:
        RingBuffer(int _maxSize) // Задаем буфер с указанным количеством элементов, инициализация -1 для определенности
        {
            maxSize = _maxSize;
            stor = new T[maxSize];
            for (int i = 0; i < maxSize; i++)
            {
                stor[i] = -1;
            }
            elementsCount = 0;
            head = 0;
            tail = 0;
        }
        T& operator[](int index) const // Получаем index-тый элемент, начиная с головы буфера
        {
            if ((index < 0) || (index >= maxSize))
            {
                throw std::out_of_range("Index is outside the array");
            }
            return stor[(head + index - 1) % maxSize];
        }
        int bufferSize() // Вернуть текущую длину буфера
        {
            return elementsCount;
        }
        void flush() // Очистить буфер, вернуть всем элементам значение -1
        {
            tail = 0;
            head = 0;
            elementsCount = 0;
            for (int i = 0; i < maxSize; i++)
            {
                stor[i] = -1;
            }
        }
        bool isFull() // Проверка, заполнен ли буфер
        {
            return (elementsCount == maxSize);
        }
        bool isEmpty() // Проверка, пуст ли буфер
        {
            return (elementsCount == 0);
        }
        void add(T data) // Добавить элемент в конец буфера
        {
            if (elementsCount != maxSize) // Если буфер не полон, увеличиваем текущее количество элементов на 1
            {
                elementsCount++;
            }

            stor[tail] = data; // Записываем элемент по текущему значению хвоста
            tail = (tail + 1) % maxSize; // Если хвост не в конце, то растет на 1, иначе вернется в ноль

            if (elementsCount == maxSize) // Если буфер полон, меняем значение головы, чтобы она была на 1 элемент впереди хвоста
            {
                head = (tail + 1) % maxSize;
            }
        }
        ~RingBuffer()
        {
            delete[] stor;
        }
        T* getStor() const
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
