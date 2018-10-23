#include "MergeSort.h"

int main()
{
	int n;
	int count = 0;
	std::array<int,MAX_SIZE> arr;
	cout << "Please enter the number of elements you in the array to be sorted: ";
	cin >> n;

	if(n > MAX_SIZE)
	{
		cout << "Only " << MAX_SIZE << " elements allowed" << endl;
		system("pause");
		return 1;
	}
	
	cout << "Please enter the elements in the array to be sorted: " << endl;

	for (int i=0; i < n; i++)
		arr.at(i) = 0;

	while (count != n)
	{
		cin >> arr.at(count++);
		//cout << "ArraySize->n = " << count << "->" << n << endl;
	}
	
	cout << "Original array: ";
	MergeSort::Print(arr);

	cout << endl << endl;

	MergeSort::Sort(arr, 0, n - 1);

	cout << "Sorted array: ";
	MergeSort::Print(arr);

	system("pause");
	return 1;
}