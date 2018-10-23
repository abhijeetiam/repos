#include "QuickSort.h"

QuickSort::QuickSort()
{
}

QuickSort::~QuickSort()
{
}

vector<int>& QuickSort::QSort(vector<int>& vec, int start, int end)
{
	if (start < end)
	{
		int partitionIndex = QuickSort::Partition(vec, start, end);
		QSort(vec, start, partitionIndex - 1);		//Recursively sort left of partitionIndex
		QSort(vec, partitionIndex + 1, end);		//Recursively sort right of partitionIndex
	}
	return vec;
}

int QuickSort::Partition(vector<int>& vec, int start, int end)
{
	int partitionIndex = start;		//just point partitionIndex to start
	int pivot = vec.at(end);	//choosing last element as the pivot
	
	for (int i = start; i < end; i++)
	{
		if (vec.at(i) <= pivot)
		{
			swap(vec.at(partitionIndex), vec.at(i));	//swap partition index element as long as i th element is smaller than pivot and advance the index
			QuickSort::Print(vec);
			partitionIndex++;
		}
	}
	
	QuickSort::Print(vec);
	swap(vec.at(partitionIndex), vec.at(end));		//finally swap the pivot with the partition index after 1 full run across the array
	return partitionIndex;
}

void QuickSort::Print(vector<int>& vec)
{
	for (const auto& elem : vec) 
		cout << elem << " | ";
	cout << endl;
}