#include <iostream>
#include <algorithm>
using namespace std;

//char inp[] = {'a','b','c'};
char inp[] = { 'a','b','b', 'b' };
int length = sizeof(inp) / sizeof(inp[0]);

void printPermutations1(char array[], int i)
{
	cout << "Length is: " << length << endl;
		
	if (i != length)
	{
		cout << "PRINTING : i = " << i << ", Length = " << length << ", Array = " << array << endl;
		return;
	}
	
	for (int j = i; j < length; ++j) 
	{
		cout << "BEFORE SWAP1: i = "<< i << ", j = " << j << ", Array = " << array << endl;
		std::swap(array[i], array[j]);
		cout << "AFTER SWAP1: i = " << i << ", j = " << j << ", Array = " << array << endl;
		printPermutations1(array, i + 1);
		cout << "BEFORE SWAP2: i = " << i << ", j = " << j << ", Array = " << array << endl;
		std::swap(array[i], array[j]);
		cout << "AFTER SWAP2: i = " << i << ", j = " << j << ", Array = " << array << endl;
	}
}

void printPermutations2 (char array[], int i)
{
	//cout << "Length is: " << length << endl;

	if (i == length - 1)
	{
		cout << "PRINTING : i = " << i << ", Length = " << length << ", Array = " << array << endl;
		return;
	}

	for (int j = i; j < length; ++j)
	{
		//cout << "BEFORE SWAP1: i = " << i << ", j = " << j << ", Array = " << array << endl;
		std::swap(array[i], array[j]);
		//cout << "AFTER SWAP1: i = " << i << ", j = " << j << ", Array = " << array << endl;
		printPermutations2(array, i + 1);
		//cout << "BEFORE SWAP2: i = " << i << ", j = " << j << ", Array = " << array << endl;
		std::swap(array[i], array[j]);
		//cout << "AFTER SWAP2: i = " << i << ", j = " << j << ", Array = " << array << endl;
	}
}

void printPermutations3(char array[], int i)
{
	if (i == 0)
	{
		cout << "PRINTING : i = " << i << ", Length = " << length << ", Array = " << array << endl;
		return;
	}
	for (int j = i; j >= 0; --j) 
	{
//		cout << "BEFORE SWAP1: i = " << i << ", j = " << j << ", Array = " << array << endl;
		std::swap(array[i], array[j]);
	//	cout << "AFTER SWAP1: i = " << i << ", j = " << j << ", Array = " << array << endl;
		printPermutations3(array, i - 1);
		//cout << "BEFORE SWAP2: i = " << i << ", j = " << j << ", Array = " << array << endl;
		std::swap(array[i], array[j]);
//		cout << "AFTER SWAP2: i = " << i << ", j = " << j << ", Array = " << array << endl;
	}
}

void printPermutations4(char array[], int i)
{
	//cout << "Length is: " << length << endl;

	if (i == length - 1)
	{
		cout << "PRINTING : i = " << i << ", Length = " << length << ", Array = " << array << endl;
		return;
	}
	for (int j = i; j < length; ++j)
	{
		//cout << "BEFORE SWAP1: i = " << i << ", j = " << j << ", Array = " << array << endl;
		std::swap(array[i], array[j]);
		//cout << "AFTER SWAP1: i = " << i << ", j = " << j << ", Array = " << array << endl;
		printPermutations4(array, i + 1);
		//cout << "BEFORE SWAP2: i = " << i << ", j = " << j << ", Array = " << array << endl;
		std::swap(array[i], array[j]);
		//cout << "AFTER SWAP2: i = " << i << ", j = " << j << ", Array = " << array << endl;
	}
}

int main()
{
	//printPermutations1(inp, 0);
	//printPermutations2(inp, 0);
	//printPermutations3(inp, length-1);
	printPermutations4(inp, 0);
	system("pause");
	return 1;
}
