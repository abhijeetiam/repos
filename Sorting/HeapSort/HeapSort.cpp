#include "HeapSort.h"

int HeapSort::size_ = 0;
bool HeapSort::bMinFlag_ = false;

HeapSort::HeapSort()
{
}

HeapSort::~HeapSort()
{
}

void HeapSort::SetHeapSize(int size)
{
	HeapSort::size_ = size;
}

int HeapSort::GetHeapSize()
{
	return HeapSort::size_;
}

bool HeapSort::GetSortOrder()
{
	return HeapSort::bMinFlag_;
}

void HeapSort::SetSortOrder(bool bMinFlag)
{
	HeapSort::bMinFlag_ = bMinFlag;
}

void HeapSort::Sort(array_int& heap)
{
	int size = HeapSort::GetHeapSize();
	cout << "Total nodes: " << size << endl;
	
	for (int i = size / 2; i > 0; i--)
		HeapSort::MinMaxHeap(heap, i);

	cout << "Final MinHeap: ";
	HeapSort::Print(heap);
}

void HeapSort::MinMaxHeap(array_int& heap, const int i)
{
	int parent = i;
	int left_child = 2 * i;
	int right_child = 2 * i + 1;
	int total_nodes = HeapSort::GetHeapSize();
	bool bFlag = HeapSort::GetSortOrder();

	//cout << "BEFORE: Parent: " << parent << ", left_child: " << left_child << ", right_child: " << right_child << ", total nodes: " << total_nodes << endl;

	if (bFlag)
	{
		if (left_child <= total_nodes)
		{
			if (heap[parent] > heap[left_child])
			{
				parent = left_child;
				if ((right_child <= total_nodes) && (heap[right_child] < heap[left_child]))
					parent = right_child;
			}
			else if ((right_child <= total_nodes) && (heap[parent] > heap[right_child]))
				parent = right_child;
		}
	}
	else
	{
		if (left_child <= total_nodes)
		{
			if (heap[parent] < heap[left_child])
			{
				parent = left_child;
				if ((right_child <= total_nodes) && (heap[right_child] > heap[left_child]))
					parent = right_child;
			}
			else if ((right_child <= total_nodes) && (heap[parent] < heap[right_child]))
				parent = right_child;
		}
	}

	//cout << "AFTER: Parent: " << parent << ", left_child: " << left_child << ", right_child: " << right_child << ", total nodes: " << total_nodes << endl;

	//Sometime due to swapping of parent node i the sub-tree nodes get messed up and you need recursively call MinHeap procedure on the swapped parent node
	if (parent != i)
	{
		swap(heap[parent], heap[i]);
		MinMaxHeap(heap, parent);
	}
		
	cout << "MinHeap array: ";
	HeapSort::Print(heap);
}

int HeapSort::GetMinMax(array_int& heap)
{
	if (heap.size() > 0)
		return heap[1];
	else
		return 0;
}

void HeapSort::SetLast(array_int& heap, int next)
{
	if (heap.size() > 0)
		heap[1] = next;
}

void HeapSort::DeleteMinMax(array_int& heap, vec_int& sorted_heap)
{
	sorted_heap.push_back(HeapSort::GetMinMax(heap));
	
	cout << "Sorted Array: ";
	HeapSort::Print(sorted_heap);
	cout << "=======================================" << endl << endl;

	int size = HeapSort::GetHeapSize();
	HeapSort::SetLast(heap, heap[size]);
	HeapSort::SetHeapSize(size - 1);
	if(size > 1)
		HeapSort::Sort(heap);
}

void HeapSort::Print(array_int& heap)
{
	for (int i = 1; i <= HeapSort::GetHeapSize(); i++) {
		cout << heap[i] << " | ";
	}
	cout << endl;
}

void HeapSort::Print(vec_int& heap)
{
	for (const auto& i : heap) {
		if(i!=0)
			cout << i << " | ";
	}
	cout << endl;
}