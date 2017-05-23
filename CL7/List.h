#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdexcept>

template <typename T>
class List
{
public:
    T Data;
    List<T> *Prev, *Next;
public:
    List( const T& _Data )
    {
        Data = _Data;
        Prev = Next = nullptr;
    }
    ~List()
    {
        Prev = Next = nullptr;
        Data = T(0);
    }
    List<T>* begin()
    {
        List<T> *Iter = this;
        while( Iter->Prev != nullptr )
            Iter = Iter->Prev;
        return Iter;
    }
    List<T>* end()
    {
        List<T> *Iter = this;
        while( Iter->Next != nullptr )
            Iter = Iter->Next;
        return Iter;
    }
    void push_front( List<T>* _lNode )
    {
        List<T> *Beg = begin();
        Beg->Prev = _lNode;
        _lNode->Next = Beg;
    }
    void push_back( List<T>* _lNode )
    {
        List<T> *End = end();
        End->Next = _lNode;
        _lNode->Prev = End;
    }
    // ����� ������� � ������
    List<T>* Find( const T& _Data )
    {
        List<T> *Iter = begin();
        do
        {
            if ( Iter->Data == _Data ) break;
            Iter = Iter->Next;
        }
        while( Iter != nullptr );
        return Iter;
    }
    // ���������� ������� � ������
    void Add( const T& _Data )
    {
        List<T> *lNode = new List<T>( _Data );
        push_back( lNode );
    }
    // ���������� ������� � ������, ���� ���, ���� ���������� ��������
    void AddUnique( const T& _Data )
    {
        List<T> *lNode = Find( _Data );
        if ( lNode == nullptr )
            Add( _Data );
        else
            lNode->Data++;
    }
    // �������� ������� �� ������
    void Delete( List<T> *_lNode )
    {
        if ( _lNode->Next != nullptr )
        {
            List<T>* A2 = _lNode->Next;
            A2->Prev = _lNode->Prev;
        }
        if ( _lNode->Prev != nullptr )
        {
            List<T>* A0 = _lNode->Prev;
            A0->Next = _lNode->Next;
        }
        delete _lNode;
    }
    // ������� ������� � ������, �������� ����������
    void InsertSort( List<T> *_lNode  )
    {
        List<T> *Iter = begin();
        while( Iter->Next != nullptr )
        {
            if ( Iter->Next->Data > _lNode->Data )
                break;
            Iter = Iter->Next;
        }
        List<T> *One, *Two;
        One = Iter;
        Two = Iter->Next;
        One->Next = _lNode;
        _lNode->Prev = One;
        _lNode->Next = Two;
        if ( Two != nullptr )
            Two->Prev = _lNode;
    }
    // ���������� ������
    void Sort()
    {
        List<T>
            *One,
            *End = end();
        while( End != nullptr )
        {
            One = begin();
            while( One != End )
            {
                List<T> *Two = One->Next;
                if ( One->Data >= Two->Data )
                    Change( One, Two );
                else
                    One = Two;
                if ( Two == End ) break;
            }
            End = One->Prev;
        }
    }
    // ������ ������� ���� ��������� � ������
    void Change( List<T> *A1, List<T> *A2 )
    {
        List<T> *A0 = A1->Prev;
        List<T> *A3 = A2->Next;
        if ( A0 != nullptr )
            A0->Next = A2;
        A1->Prev = A2;
        A1->Next = A3;
        A2->Prev = A0;
        A2->Next = A1;
        if ( A3 != nullptr )
            A3->Prev = A1;
    }
};

#endif // LIST_H_INCLUDED
