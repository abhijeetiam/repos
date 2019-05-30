/*
Merge First Sorted Array Into Second Sorted Array



Problem Statement:



Given two arrays:



1) arr1 of size n, which contains n positive integers sorted in increasing order.

2) arr2 of size (2*n) (twice the size of first), which contains n positive integers sorted in increasing order in its first half. Second half of this array arr2 is empty. (Empty elements are marked by 0).



Write a function that takes these two arrays, and merges the first one into second one, resulting in an increasingly sorted array of (2*n) positive integers.



Input Format:



There are two arguments. First one is an integer array denoting arr1 and second one is also an integer array denoting arr2.



Output Format:



Return arr2, containing (2*n) increasingly sorted integers.



Input/Output Format For The Custom Input:



Input Format:



The first line of input should contain an integer n, denoting size of input array arr1. In next n lines, ith line should contain an integer arr1[i], denoting value at index i of arr1.

In next line, there should be an integer (2*n), denoting size of input array arr2. In next (2*n) lines, ith line should contain an integer arr2[i], denoting value at index i of arr2.



If n = 3, arr1 = [1, 3, 5] and arr2 = [2, 4, 6, 0, 0, 0], then input should be:



3

1

3

5

6

2

4

6

0

0

0



Output Format:



There will (2*n) lines of output, where ith line contains an integer res[i], denoting value at index i of res.

Here, res is the result array returned by solution function.



For input n = 3, arr1 = [1, 3, 5] and arr2 = [2, 4, 6, 0, 0, 0], output will be:



1

2

3

4

5

6



Constraints:

1 <= n <= 10^5
1 <= arr1[i] <= 2 * 10^9
1 <= arr2[i] <= 2 * 10^9 (for the first half)
arr2[i] = 0 (for the second half)
You can use only constant extra space.
0 denotes an empty space.


Sample Test Case:



Sample Input:



n = 3

arr1 = [1 3 5]

arr2 = [2 4 6 0 0 0]



Sample Output:



arr2 = [1 2 3 4 5 6]



Notes:

Maximum time allowed in interview: 20 Minutes.

vector<int> merger_first_into_second(vector<int> arr1, vector<int> arr2) {
	int k = arr2.size() - 1; // write index into arr2
	int i = arr1.size() - 1; // read index into arr2
	int j = i;               // read index into arr1

	while (i >= 0 && j >= 0) {
		if (arr1[j] > arr2[i]) {
			arr2[k] = arr1[j];
			j--;
		} else {
			arr2[k] = arr2[i];
			i--;
		}
		k--;
	}

	// Copy remainder, if needed
	if (i < 0) {
		while (j >= 0) {
			arr2[k] = arr1[j];
			j--;
			k--;
		}
	}

	return arr2;
}

*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the merger_first_into_second function below.
 */
vector<int> merger_first_into_second(vector<int> arr1, vector<int> arr2) {
	/*
	 * Write your code here.
	 */

}


int main()
{
	ostream &fout = cout;

	int arr1_count;
	cin >> arr1_count;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<int> arr1(arr1_count);

	for (int arr1_itr = 0; arr1_itr < arr1_count; arr1_itr++) {
		int arr1_item;
		cin >> arr1_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		arr1[arr1_itr] = arr1_item;
	}

	int arr2_count;
	cin >> arr2_count;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<int> arr2(arr2_count);

	for (int arr2_itr = 0; arr2_itr < arr2_count; arr2_itr++) {
		int arr2_item;
		cin >> arr2_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		arr2[arr2_itr] = arr2_item;
	}

	vector<int> res = merger_first_into_second(arr1, arr2);

	for (int res_itr = 0; res_itr < res.size(); res_itr++) {
		fout << res[res_itr];

		if (res_itr != res.size() - 1) {
			fout << "\n";
		}
	}

	fout << "\n";



	return 0;
}

