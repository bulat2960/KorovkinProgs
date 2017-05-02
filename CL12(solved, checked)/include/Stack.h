#ifndef STACK_H
#define STACK_H

template<typename T>
class Stack
{
    private:
        struct Node
        {
            Node* next;
            T data;
        };
        Node* tail;
        int stackSize;
        int maxSize;
    public:
        Stack(int _maxSize)
        {
            tail = nullptr;
            maxSize = _maxSize;
            stackSize = 0;
        }

        ~Stack()
        {
            while (tail != nullptr)
            {
                Node* temp = tail;
                tail = tail->next;
                delete temp;
                temp = tail;
            }
        }

        void push(T element)
        {
            if (stackSize == maxSize)
            {
                throw std::out_of_range("Stack is full!");
            }
            Node* node = new Node;
            node->data = element;
            if (tail == nullptr)
            {
                tail = node;
                tail->next = nullptr;
            }
            else
            {
                node->next = tail;
                tail = node;
            }
            stackSize++;
        }

        T top()
        {
            if (tail == nullptr)
            {
                throw ("Stack is empty!");
            }
            return tail->data;
        }

        void pop()
        {
            if (tail == nullptr)
            {
                throw ("Stack is empty!");
            }
            Node* node = tail;
            tail = tail->next;
            delete node;
        }

        void print()
        {
            if (tail == 0)
            {
                throw ("Stack is empty!");
            }
            for (Node* it = tail; it != nullptr; it = it->next)
            {
                std::cout << it->data << std::endl;
            }
        }
};

#endif // STACK_H
