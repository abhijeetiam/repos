#pragma once

#include <iostream>
#include <array>

#define MAX_SIZE	10

using namespace std;

class MergeSort
{
public:
	MergeSort();
	~MergeSort();

	static void Print(array<int, MAX_SIZE>& arr);
	static void Sort(array<int, MAX_SIZE>& arr, int start, int end);
	static void Merge(array<int, MAX_SIZE>& arr, int start, int mid, int end);
};

