#include <iostream>
#include <fstream>
#include <cstdlib>
#include "VectorDictionary.h"
#include "String.h"

using namespace std;

void findWord(VectorDictionary<String>& vec)
{
    String str;
    cout << "Your word: ";
    cin >> str;
    try
    {
        cout << "Translate: " << vec.searchKey(str) << endl;
    }
    catch(...)
    {
        cout << "WORD NOT FOUND" << endl;
    }
}

void addWord(VectorDictionary<String>& vec)
{
    String buffer1, buffer2;
    cout << "Enter word(English) and translate(Russian): ";
    cin >> buffer1 >> buffer2;
    cout << buffer1 << ' ' << buffer2 << endl;
    vec.push_back(buffer1, buffer2);
}

void writeDictionary(VectorDictionary<String>& vec, ofstream& out)
{
    out << vec;
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");

    ifstream in(argv[1]);
    ofstream out(argv[2]);

    VectorDictionary<String> vec;

    String buffer1, buffer2;
    while (!in.eof())
    {
        in >> buffer1 >> buffer2;
        vec.push_back(buffer1, buffer2);
    }

    findWord(vec);
    addWord(vec);
    writeDictionary(vec, out);
    return 0;
}
