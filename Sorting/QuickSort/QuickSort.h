#pragma once
#include <vector>
#include <iostream>

using namespace std;

class QuickSort
{
public:
	QuickSort();
	~QuickSort();

	static vector<int>& QSort(vector<int>&, int start, int end);
	static int Partition(vector<int>&, int start, int end);
	static void Print(vector<int>&);
};

