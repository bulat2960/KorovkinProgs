#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "Vector.h"
#include "List.h"

using namespace std;

typedef Vector<unsigned char> CVector;

class Node
{
public:
    unsigned char ch;
    Node *Left, *Rigth, *Parent;
public:
    Node(Node *_Left = nullptr, Node *_Rigth = nullptr )
    {
        Left = _Left;
        if ( Left != nullptr )
            Left->Parent = this;
        Rigth = _Rigth;
        if ( Rigth != nullptr )
            Rigth->Parent = this;
        Parent = nullptr;
    };

    Node( unsigned char _ch, Node *_Left = nullptr, Node *_Rigth = nullptr )
    {
        ch = _ch;
        Left = _Left;
        if ( Left != nullptr )
            Left->Parent = this;
        Rigth = _Rigth;
        if ( Rigth != nullptr )
            Rigth->Parent = this;
        Parent = nullptr;
    };
    CVector Name();
    CVector Code( Node *_Tree );
};

CVector Node::Name()
{
    CVector sName;
    Node *Iter = this;
    if ( Iter->Left != nullptr )
        sName = Iter->Left->Name() + Iter->Rigth->Name();
    else
        sName.push_back( Iter->ch );
    return sName;
}

CVector Node::Code( Node *_Tree )
{
    CVector sName;
    Node *Iter = _Tree, *Parent;
    while( Iter->Parent != nullptr )
    {
        Parent = Iter->Parent;
        if ( Parent->Left == Iter )
            sName.push_front( '0' );
        else
            sName.push_front( '1' );
        Iter = Parent;
    }
    return sName;
}

class HavElementTable
{
public:
    Node *Tree;
    CVector Code;
    HavElementTable( Node *_Tree = nullptr ) { Tree = _Tree; }
};

typedef Vector<HavElementTable> HavTable;

class ElementList
{
public:
    Node *Tree;
    unsigned int Freq;
    ElementList( Node *_Tree = nullptr, unsigned int _Freq = 1 ) { Tree = _Tree; Freq = _Freq; }
    ElementList operator=( const ElementList& elOne ) { Tree = elOne.Tree; Freq = elOne.Freq; }
    void operator++( int )
    {
        Freq++;
    }
    bool operator>( const ElementList& elOne )
    {
        return Freq > elOne.Freq;
    }
    bool operator>=( const ElementList& elOne )
    {
        return Freq >= elOne.Freq;
    }
    bool operator==( const ElementList& elOne )
    {
        return Tree->ch == elOne.Tree->ch;
    }
};

typedef List<ElementList> EList;

int main()
{
    bool IsDebudPrint = false;

    //Ввод строки и создание строкового вектора исходной строки
    CVector cvInputString;
    unsigned char InputString[1000];
    cin >> InputString;

    for( int i = 0; i < 1000; i++ )
    {
        unsigned char ch = InputString[i];
        if ( ch == 0 ) break;
        cvInputString.push_back( ch );
    }

    //Создание списка кодируемых элементов
    EList *elList = nullptr;
    for( int i = 0; i < cvInputString.size(); i++ )
    {
        Node *nNode = new Node( cvInputString[i] );
        if ( i == 0 )
            elList = new EList( nNode );
        else
            elList->AddUnique( nNode );
    }
    // Сортировка списка по возрастанию
    elList->Sort();

    // Создание таблицы Хаффмана - которой кодируется строка данных
    HavTable DataHavTable;
    EList *elIter = elList->begin();
    while( elIter != nullptr )
    {
        if ( IsDebudPrint )
            cout << "*****" << elIter->Data.Tree->ch << "*****" << elIter->Data.Freq << "*****" << elIter->Data.Tree << endl;
        DataHavTable.push_back( HavElementTable( elIter->Data.Tree ) );
        elIter = elIter->Next;
    }

    // Создание дерева Хаффмана - которой декодируется закодированная строка данных
    Node *nHavTree;
    EList *One, *Two, *OneTwo;
    while( true )
    {
        One = elList->begin();
        Two = One->Next;
        if ( Two == nullptr )
            break;

        nHavTree = new Node(One->Data.Tree, Two->Data.Tree );
        OneTwo = new EList( ElementList( nHavTree, One->Data.Freq + Two->Data.Freq ) );

        elList->InsertSort( OneTwo );
        elList = OneTwo;
        elList->Delete( One );
        elList->Delete( Two );

        if ( IsDebudPrint )
        {
            EList *Iter = elList->begin();
            while( Iter != nullptr )
            {
                cout << Iter->Data.Tree->Name() << " = " << Iter->Data.Freq << endl;
                Iter = Iter->Next;
            }
        }
    }

    // Заполнение таблицы Хаффмана
    for( int i = 0; i < DataHavTable.size(); i++ )
    {
        Node* nTree = DataHavTable[i].Tree;
        DataHavTable[i].Code = nHavTree->Code( nTree );
        if ( IsDebudPrint )
            cout << nTree->ch << " - " << DataHavTable[i].Code << endl;
    }

    // Кодирование строки
    CVector cvCodeString;
    for( int i = 0; i < cvInputString.size(); i++ )
    {
        unsigned char ch = cvInputString[i];
        for( int j = 0; j < DataHavTable.size(); j++ )
        {
            Node* nTree = DataHavTable[j].Tree;
            if ( nTree->ch == ch )
            {
                CVector& Code = DataHavTable[j].Code;
                cvCodeString = cvCodeString + Code;
            }
        }
    }
    cout << "cvCodeString:" << endl << cvCodeString << endl;

    // Декодирование строки
    Node *nIter = nHavTree;
    CVector cvDecodeString;
    for( int i = 0; i < cvCodeString.size(); i++ )
    {
        if ( cvCodeString[i] == '0' )
            nIter = nIter->Left;
        else
            nIter = nIter->Rigth;
        if ( nIter->Left == nullptr )
        {
            cvDecodeString.push_back( nIter->ch );
            nIter = nHavTree;
        }
    }
    cout << "cvDecodeString:"  << endl << cvDecodeString << endl;

    return 0;
}
