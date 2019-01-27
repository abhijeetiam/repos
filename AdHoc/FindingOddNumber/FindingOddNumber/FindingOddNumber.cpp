/* Given a set of numbers where all elements occur even number of times except one number, find the odd occurring number
   This problem can be efficiently solved by just doing XOR of all numbers.
   Solution : If you don't want to use space then sort the array and use Bitwise XOR operator
			  A XOR A = 0 (When you XOR a number with itself it will always be 0)
			  A XOR 0 = A (When you XOR a number with 0 it will always be itself)
			  Time Complexity = O(n), Space Complexity = 0(1)
			  When you XOR a number with itself it will always be 0
	***READ: https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/
*/
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

void FindingOddNumber(int[], int);

int main()
{
	int arr[] = { 1,1,7,7,3,4,4,9,9 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Number of elements in the array = " << n << endl;
	FindingOddNumber(arr, n);
	system("pause");
	return 0;
}

//Time Complexity = O(n), Space Complexity = 0(1)
void FindingOddNumber(int arr[], int size)
{
	int odd_num = 0;

	//Looping through arrray first and XOR'ing them
	for (int i = 0; i < size; i++)
		odd_num ^= arr[i];
		
	cout << "Odd number out element is: " << odd_num << endl;
}