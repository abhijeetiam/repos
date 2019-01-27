/* Find a missing number in an array with all integers between
   1 to N except 1 integer
	Solution1 : 2 for loops (1->N, 0->N-1)
				Time Complexity = O(n^2), Space Complexity = 0(1)
	Solution2 : Add array elements to a set and then use a loop (1->N) to check for its absence
				Time Complexity = O(n), Space Complexity = 0(n)
	Solution3 : If you don't want to use space then sort the array and use Bitwise XOR operator
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

void MissingNumberSol2(int[], int);
void MissingNumberSol3(int[], int);

int main()
{
	int arr[] = {1,8,2,7,3,4,5,9,10};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Number of elements in the array = " << n << endl;
	MissingNumberSol2(arr, n);
	MissingNumberSol3(arr, n);
	system("pause");
	return 0;
}

//Time Complexity = O(n), Space Complexity = 0(n)
void MissingNumberSol2(int arr[], int size)
{
	std::unordered_set<int> elem;
	for (int i = 0; i < size; i++)
		elem.insert(arr[i]);
	
	for (int i = 1; i <= size+1; i++)
	{
		if (elem.find(i) == elem.end())
			cout << "Missing element is: " << i << endl;
	}
}

//Time Complexity = O(n), Space Complexity = 0(1)
void MissingNumberSol3(int arr[], int size)
{
	int missing_num = 0;

	//Looping through arrray first and XOR'ing them
	for (int i = 0; i < size-1; i++)
		missing_num ^= arr[i];

	//Looping through all number 1->N and XOR'ing them
	for (int i = 1; i <= size; i++)
		missing_num ^= i;

	cout << "Missing element is: " << missing_num << endl;
}