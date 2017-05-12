#ifndef STACK_H
#define STACK_H

template<typename T>
class Stack
{
    private:
        struct Node // Узел стека
        {
            Node* next;
            T data;
        };
        Node* tail; // Хвост стека
        int stackSize; // Текущая длина
        int maxSize; // Максимальная длина
    public:
        Stack(int _maxSize) // Создание стека
        {
            tail = nullptr; // Инициализируем хвост нулем(нет элементов)
            maxSize = _maxSize; // Задаем размер стека
            stackSize = 0;
        }

        ~Stack()
        {
            Node* temp = tail; // Сохраняем указатель на хвост
            while (tail != nullptr) // Пока хвост не обратится в ноль
            {
                tail = tail->next; // Перемещаем хвост на элемент ниже
                delete temp; // Удаляем ранее сохраненный хвост
                temp = tail; // Сохраняем новый хвост, продолжаем цикл
            }
        }

        void push(T element) // Добавление элементов в стек
        {
            if (stackSize == maxSize) // Если стек полон, бросить исключение
            {
                throw std::out_of_range("Stack is full!");
            }
            Node* node = new Node; // Создаем узел стека
            node->data = element;
            if (tail == nullptr) // Если хвост нулевой(стек пуст)
            {
                tail = node; // Хвост получает новый узел
                tail->next = nullptr; // Первый элемент будет указывать в пустоту(конец стека)
            }
            else // Если стек не пуст
            {
                node->next = tail; // Связываем новый элемент с хвостом
                tail = node; // Теперь хвост на новом элементе
            }
            stackSize++; // Размер стека растет с каждым добавлением
        }

        T top() // Получить верхушку(хвост) стека
        {
            if (tail == nullptr) // Если стек пуст
            {
                throw ("Stack is empty!");
            }
            return tail->data;
        }

        void pop() // Удалить элемент с хвоста
        {
            if (tail == nullptr) // Если удалять нечего
            {
                throw ("Stack is empty!");
            }
            Node* node = tail; // Сохраняем указатель на хвост
            tail = tail->next; // Перемещаем хвост на предыдущий элемент
            delete node; // Удаляем конец стека
        }

        void print() // Печать
        {
            if (tail == nullptr) // Если печатать нечего
            {
                throw ("Stack is empty!");
            }
            for (Node* it = tail; it != nullptr; it = it->next) // Итерируем по стеку и печатаем поле data
            {
                std::cout << it->data << std::endl;
            }
        }
};

#endif // STACK_H
