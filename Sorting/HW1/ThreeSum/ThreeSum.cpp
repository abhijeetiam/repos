/*
3 Sum



Problem Statement:



Given an integer array arr of size N, find all magical triplets in it.



Magical triplet is the group of 3 integers, whose sum is zero.



Note that magical triplets may or may not be made of consecutive numbers in arr.



Input/Output Format For The Function:



Input Format:



There is only one argument: integer array arr.



Output Format:



Return a string array res.

Each string in res array corresponds to a magical triplet in arr.



Note that:

Order of strings(magical triplets) in res does not matter.
Order of elements inside a magical triplet does not matter. i.e. if your output triplet have same elements, but only in different order, then it's an acceptable triplet and will lead to an acceptable solution.
There should be no duplicate triplets in res. Eg: 1,1,-2 and 1,-2,1 are duplicates.
If no such triplets are found, then return an empty array as res.


Input/Output Format For The Custom Input:



Input Format:



The first line of input should contain an integer N, denoting size of input array arr. In next N lines, ith line should contain an integer arr[i], denoting a value at index i of arr.



If N = 6 and arr = [10, 3, -4, 1, -6, 9], then input should be:



6

10

3

-4

1

-6

9



Output Format:



Let’s denote size of res as m, where res is the array of strings returned by solution function.

Then, there will be m lines of output, where ith line contains res[i], denoting value at index i of res.



For input N = 6 and arr = [10, 3, -4, 1, -6, 9], output will be:



10,-4,-6

3,-4,1



Constraints:

1 <= N <= 2000
-10^3 <= arr[i] <= 10^3, for all valid i
arr may contain duplicate numbers.
arr is not necessarily sorted.


Sample Test Case:



Sample Test Case 1:



Sample Input 1:



arr = [10, 3, -4, 1, -6, 9];



Sample Output 1:



10,-4,-6

3,-4,1



Sample Test Case 2:



Sample Input 2:



arr = [12, 34, -46];



Sample Output 2:



12,-46,34



Sample Test Case 3:



Sample Input 3:



arr = [0, 0, 0];



Sample Output 3:



0,0,0



Sample Test Case 4:



Sample Input 4:



arr = [-2, 2, 0 -2, 2];



Sample Output 4:



2,-2,0


vector<string> findZeroSum(vector<int> arr) {
	vector<string> res;
	if (arr.size() == 0) return res;

	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++) {
		if (i && arr[i - 1] == arr[i]) continue;

		int j = i + 1, k = arr.size() - 1;

		while (j < k) {
			int a = arr[i], b = arr[j], c = arr[k];
			int sum = a + b + c;
			if (sum == 0) {

				res.push_back( to_string(a) + "," + to_string(b) + "," + to_string(c));

				while (j < k && arr[j] == b) j++;
				while (j < k && arr[k] == c) k--;

			} else if (sum < 0) {
				j++;
			} else {
				k--;
			}
		}
	}
	return res;
}


*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */
vector<string> findZeroSum(vector<int> arr) {
	// Write your code here.


}


int main()
{
	ostream &fout = cout;

	int arr_size;
	cin >> arr_size;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<int> arr(arr_size);
	for (int arr_i = 0; arr_i < arr_size; arr_i++) {
		int arr_item;
		cin >> arr_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		arr[arr_i] = arr_item;
	}

	vector<string> res = findZeroSum(arr);

	for (int res_itr = 0; res_itr < res.size(); res_itr++) {
		fout << res[res_itr];

		if (res_itr != res.size() - 1) {
			fout << "\n";
		}
	}

	fout << "\n";



	return 0;
}

