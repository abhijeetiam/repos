#include "HeapSort.h"

int main()
{
	array_int heap = { 0 };
	vec_int sorted_heap = { 0 };
	
	int n;
	int count = 0;
	bool bMinFlag = false;
	
	cout << "Please enter the number of elements in the array to be sorted: ";
	cin >> n;

	cout << "Please enter 1 for ascending order or 0 for descending order: ";
	cin >> bMinFlag;

	if (n > MAX_SIZE)
	{
		cout << "Only " << MAX_SIZE << " elements allowed" << endl;
		system("pause");
		return 1;
	}

	HeapSort::SetHeapSize(n);	//store the total number of elements in size_
	HeapSort::SetSortOrder(bMinFlag);	//setting sorting order

	cout << "Please enter the elements in the array to be sorted: " << endl;
	
	while (count != HeapSort::GetHeapSize()) {
		cin >> heap[++count];	//has to be ++count pre-increment operator as heap index start from 1 and not 0 in an array
		//cout << heap[count] << " => " << count << endl;
	}
	   
	cout << "Original array: ";
	HeapSort::Print(heap);

	HeapSort::Sort(heap);

	while(HeapSort::GetHeapSize() != 0)
		HeapSort::DeleteMinMax(heap, sorted_heap);

	system("pause");
	return 1;
}