#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    print();
    // Создаем стек, пушим несколько элементов, печатаем их, ловим брошенные злобными методами исключения
    Stack<char> st(4);
    try
    {
        st.push('a');
        st.push('b');
        st.push('c');
        st.push('d');
        st.print();
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
