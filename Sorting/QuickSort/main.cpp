#include <iostream>

#include "QuickSort.h"

int main()
{
	int n, elem;
	vector<int> arr;
	cout << "Enter the number of elements to be inserted into the vector: " << endl;
	cin >> n;
	cout << "Enter the elements to be inserted into the vector: " << endl;
	
	while(arr.size()!= n)
	{
		cin >> elem;
		arr.push_back(elem);
	}
	
	cout << "Original vector: ";
	QuickSort::Print(arr);
	
	cout << endl;

	vector<int> vec = QuickSort::QSort(arr, 0, arr.size()-1);
	
	cout << "Sorted vector: ";
	QuickSort::Print(vec);
			
	system("pause");
	return 1;
}