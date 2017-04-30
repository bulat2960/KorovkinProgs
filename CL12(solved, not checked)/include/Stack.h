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
        Node* first;
        Node* last;
        int stackSize;
        int maxSize;
    public:
        Stack(int _maxSize)
        {
            last = nullptr;
            first = nullptr;
            maxSize = _maxSize;
            stackSize = 0;
        }
        ~Stack()
        {
            while (last != nullptr)
            {
                Node* temp = last;
                last = last->next;
                delete temp;
                temp = last;
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
            if (last == nullptr)
            {
                last = node;
                last->next = nullptr;
            }
            else
            {
                node->next = last;
                last = node;
            }
            stackSize++;
        }
        T top()
        {
            if (last == nullptr)
            {
                throw ("Stack is empty!");
            }
            return last->data;
        }
        void pop()
        {
            if (last == nullptr)
            {
                throw ("Stack is empty!");
            }
            Node* node = last;
            last = last->next;
            delete node;
        }

        void print()
        {
            if (last == 0)
            {
                throw ("Stack is empty!");
            }
            for (Node* it = last; it != nullptr; it = it->next)
            {
                std::cout << it->data << std::endl;
            }
        }
};

#endif // STACK_H
