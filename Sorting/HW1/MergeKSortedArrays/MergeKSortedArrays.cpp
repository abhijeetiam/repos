/*
Merge_K_sorted_arrays



Problem Statement:



This is a popular facebook problem.

Given K sorted arrays arr, of size N each, merge them into a new array res, such that res is a sorted array.


Assume N is very large compared to K. N may not even be known. The arrays could be just sorted streams, for instance, timestamp streams.



All arrays might be sorted in increasing manner or decreasing manner. Sort all of them in the manner they appear in input.



Note:

Repeats are allowed.
Negative numbers and zeros are allowed.
Assume all arrays are sorted in the same order. Preserve that sort order in output.
It is possible to find out the sort order from at least one of the arrays.


Input/Output Format For The Function:



Input Format:



There is only one argument: 2D Integer array arr.

Here, arr[i][j] denotes value at index j of ith input array, 0-based indexing. So, arr is K * N size array.



Output Format:



Return an integer array res, containing all elements from all individual input arrays combined.



Input/Output Format For The Custom Input:



Input Format:



The first line of input should contain an integer K. The second line should contain an integer N, denoting size of each input array.

In next K lines, ith line should contain N space separated integers, denoting content of ith array of K input arrays, where jth element in this ith line is nothing but arr[i][j], i.e. value at index j of ith array, 0-based indexing.



If K = 3, N = 4 and arr = [

[1, 3, 5, 7],

			[2, 4, 6, 8],

			[0, 9, 10, 11]

], then input should be:



3

4

1 3 5 7

2 4 6 8

0 9 10 11



Output Format:



There will be (N*K) lines of output, where ith line contains an integer res[i], denoting value at index i of res.

Here, res is the result array returned by solution function.



For input K = 3, N = 4 and arr = [

[1, 3, 5, 7],

			[2, 4, 6, 8],

			[0, 9, 10, 11]

], output will be:



0

1

2

3

4

5

6

7

8

9

10

11



Constraints:

1 <= N <= 500
1 <= K <= 500
-10^6 <= arr[i][j] <= 10^6, for all valid i,j


Sample Test Case:



Sample Input:



K = 3, N =  4

arr[][] = { {1, 3, 5, 7},

		   {2, 4, 6, 8},

		   {0, 9, 10, 11}} ;



Sample Output:



[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]



 * k size min or max heap
 * Time: O(nk log(k))
 * Space: O(k)
 

struct Node {
	int val;
	int arrIdx;
	int idx;
};

struct compareGreater {
	bool operator () (Node a, Node b) {
		return a.val > b.val;
	}
};

struct compareSmaller {
	bool operator () (Node a, Node b) {
		return a.val < b.val;
	}
};

template <typename T>
void merge(vector<vector<int>> &arr, T heap, vector<int> &ret)
{
	int k = arr.size();

	for (int i = 0; i < k; i++) {
		if (arr[i].size())
			heap.push({ arr[i][0], i, 0 });
	}

	while (heap.size()) {
		Node cur = heap.top();
		ret.push_back(cur.val);
		heap.pop();
		cur.idx++;
		if (cur.idx < arr[cur.arrIdx].size()) {
			cur.val = arr[cur.arrIdx][cur.idx];
			heap.push(cur);
		}
	}
}

bool findSortOrder(vector<vector<int>> &arr) {
	if (arr[0].size() >= 2) {
		if (arr[0][0] < arr[0][1])
			return true;
		else if (arr[0][0] > arr[0][1])
			return false;

		if (arr[0].size() >= 3) {
			if (arr[0][1] < arr[0][2])
				return true;
			else if (arr[0][1] > arr[0][2])
				return false;
		}
	}
}


vector<int> mergeArrays(vector<vector<int>> arr) {
	bool isAscend;
	vector<int> ret;
	priority_queue<Node, vector<Node>, compareGreater> minHeap;
	priority_queue<Node, vector<Node>, compareSmaller> maxHeap;
	if (!arr.size() || !arr[0].size())
		return {};

	isAscend = findSortOrder(arr);
	if (isAscend) {
		merge(arr, minHeap, ret);
	}
	else {
		merge(arr, maxHeap, ret);
	}

	return ret;
}


*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the mergeArrays function below.
 */
vector<int> mergeArrays(vector<vector<int>> arr) {
	/*
	 * Write your code here.
	 */

}


int main()
{
	ostream &fout = cout;

	int arr_rows;
	cin >> arr_rows;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	int arr_columns;
	cin >> arr_columns;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<vector<int>> arr(arr_rows);
	for (int arr_row_itr = 0; arr_row_itr < arr_rows; arr_row_itr++) {
		arr[arr_row_itr].resize(arr_columns);

		for (int arr_column_itr = 0; arr_column_itr < arr_columns; arr_column_itr++) {
			cin >> arr[arr_row_itr][arr_column_itr];
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	vector<int> res = mergeArrays(arr);

	for (int res_itr = 0; res_itr < res.size(); res_itr++) {
		fout << res[res_itr];

		if (res_itr != res.size() - 1) {
			fout << "\n";
		}
	}

	fout << "\n";



	return 0;
}


