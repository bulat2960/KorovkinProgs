#include <iostream>
#include <cstdlib>
#include <ctime>
#include "MergeSort.h"

using namespace std;

int main()
{
	srand(time(0));

	int* arr1 = new int[15];
	for (int i = 0; i < 15; i++)
    {
		arr1[i] = rand() % 1000;
	}
	Merger<int> example(arr1, 15);
	example.print();
	example.sortArr();
	example.print();

	char* arr2 = new char[15];
	for (int i = 0; i < 15; i++)
    {
		arr2[i] = 65 + rand() % 26;
	}
	Merger<char> example2(arr2, 15);
	example2.print();
	example2.sortArr();
	example2.print();

    delete[] arr1;
    delete[] arr2;
}
