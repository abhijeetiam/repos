#include "MergeSort.h"

MergeSort::MergeSort()
{
}


MergeSort::~MergeSort()
{
}

void MergeSort::Sort(array<int, MAX_SIZE>& arr, int start, int end)
{
	if (arr.size() < 2) return;
	if (start >= end) return;
	
	int mid = start + ((end - start) / 2);	//used to avoid overflow for large start and end values
	Sort(arr, start, mid);
	Sort(arr, mid + 1, end);
	Merge(arr, start, mid, end);
}

void MergeSort::Merge(array<int, MAX_SIZE>& arr, int start, int mid, int end)
{
	int nL = (mid - start) + 1;	//length of the left array (L)
	int nR = (end - mid);	//length of the right array (R)

	int i, j, k;		//start indexes for L, R, arr

	i = j = 0;
	
	array<int, MAX_SIZE> L = {0};
	array<int, MAX_SIZE> R = {0};
		
	for (int i = 0; i < nL; i++)
		L[i] = arr[start + i];
	
	for (int i = 0; i < nR; i++)
		R[i] = arr[mid + 1 + i];

	cout << "Printing Left (L): ";
	MergeSort::Print(L);
	cout << "Printing Right (R): ";
	MergeSort::Print(R);
	cout << endl;

	i = j = 0;
	k = start;

	while ((i < nL) && (j < nR))
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < nL)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < nR)
	{
		arr[k] = R[j];
		j++;
		k++;
	}

	cout << "Printing Merged (arr): ";
	MergeSort::Print(arr);
	cout << endl << endl;
}
 
void MergeSort::Print(array<int, MAX_SIZE>& arr)
{
	for (const auto& i : arr) {
		if(i > 0)
			cout << i << " | ";
	}
}
