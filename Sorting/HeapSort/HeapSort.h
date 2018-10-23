#pragma once

#include <iostream>
#include <algorithm>
#include <utility>  
#include <array>
#include <vector>

#define MAX_SIZE 15

using namespace std;

typedef array<int, MAX_SIZE> array_int;
typedef vector<int> vec_int;

class HeapSort
{
public:
	HeapSort();
	~HeapSort();

	static int GetHeapSize();
	static void SetHeapSize(int size);
	static bool GetSortOrder();
	static void SetSortOrder(bool bMinFlag);
	static int GetMinMax(array_int&);
	static void SetLast(array_int&, int);
	static void Sort(array_int&);
	static void Print(array_int&);
	static void Print(vec_int& heap);
	static void	MinMaxHeap(array_int&, const int node);
	static void DeleteMinMax(array_int&, vec_int&);
	
private:
	static int size_;
	static bool bMinFlag_;		//true/1 for ascending order and false/0 for descending order
};