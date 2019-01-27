/*Find triplets from array that add upto 0. (Essentially K=0)
  Another variant also wherein the triplet adds upto K*/

#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

void TwoSum(int[], int, int);
void ThreeSum(int[], int, int);

int main()
{
	int arr[] = { -2, -3, 4, -1, 2, 1, 5, 3, 0 };
	//int arr[] = { -2, -3, -4, -1, -2, -1, -5, -3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k;
	cout << "Enter the value of K = ";
	cin >> k;
	cout << "Elements with a total of K = " << k << endl;
	TwoSum(arr, k, n);
	ThreeSum(arr, k, n);
	system("pause");
	return 0;
}

//O(n) algorithm by looking for K-array elements in the set with array elements
//Complexity: Time = O(n), Space = O(n). 
//Space can be O(1) if you sort it first and use left and right index and check 
//the total to k and move the index accordingly
void TwoSum(int arr[], int k, int size)
{
	std::unordered_set<int> elem;
	for (int i = 0; i < size; i++)
	{
		if (elem.find(k - arr[i]) != elem.end())
			cout << arr[i] << "," << k - arr[i] << endl;
		elem.insert(arr[i]);
	}
}

//O(n^2) algorithm by looking for K-array elements in the set with array elements
void ThreeSum(int arr[], int k, int size)
{
	std::unordered_set<int> elem;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (elem.find(k - (arr[i] + arr[j])) != elem.end())
				cout << arr[i] << "," << arr[j] << "," << (k - (arr[i] + arr[j])) << endl;
			else
				elem.insert(arr[j]);
		}
	}
}
