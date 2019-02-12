/*2D Array Search



Problem Statement:



You are given a sorted 2D array arr of size r * c, where all the numbers (integers) in the array are in non decreasing order from left to right and top to bottom. ( i.e. arr[i][j] <= arr[i+1][j] and arr[i][j] <= arr[i][j+1] for all i = 0,1,...,(r - 2) and j = 0,1,...,(c - 2) )



Check if a given number x exists in arr or not.



Given an arr, you have to answer q such queries.



Input/Output Format For The Function:



Input Format:



There are two arguments, arr and x, denoting input 2D array and a number to be searched as mentioned in problem statement respectively



Output Format:



Return string "present" if x is present in arr, string "not present" otherwise.



Input/Output Format For The Custom Input:



Input Format:



The first line of the input should contain a single integer r, denoting the no. of rows of input array arr. Second line should contain a single integer c, denoting the no. of columns of arr.

In the next r lines, each line should contain c space separated numbers. jth number in ith line of these r lines is arr[i][j], denoting the number at ith row of the jth column of arr.

Next line should contain q, denoting no of queries to be answered. In next q lines, each line should contain xi, denoting x for ith query



If r = 3, c = 4, arr = [[1, 2, 3, 12], [4, 5, 6, 45], [7, 8, 9, 78]], q = 3, x for 1st query = 6, x for 2nd query = 7 and x for 3rd query = 23, then input should be:



3

4

1 2 3 12

4 5 6 45

7 8 9 78

3

6

7

23



Output Format:



There will be q lines, ith line of which contains the result for ith query as "present" or "not present"



For input r = 3, c = 4, arr = [[1, 2, 3, 12], [4, 5, 6, 45], [7, 8, 9, 78]], q = 3, x for 1st query = 6, x for 2nd query = 7 and x for 3rd query = 23, output will be:



present

present

not present



Constraints:



1 <= r <= 10^3
1 <= c <= 10^3
1 <= q <= 10^4
-10^9 <= arr[i][j] <= 10^9, (i = 0,1,...,(r - 1) and j = 0,1,...,(c - 1))
-10^9 <= x <= 10^9


Sample Test Cases:



Sample Input 1:



arr = [[1, 2, 3, 12], [4, 5, 6, 45], [7, 8, 9, 78]]

queries = [6, 7, 23]



Sample Output 1:



result = [“present”, “present”, “not present”]



Explanation 1:



Given number x=6 is present at arr[1][2] and x=7 is present at arr[2][0]. Hence, "present" returned for them, while

x=23 is not present in arr, hence "not present" returned



Sample Input 2:



arr = [[3, 4], [5, 10]]

queries = [12, 32]



Sample Output 2:



result = [“not present”, “not present”]



Explanation 2:



Given number x=12 and x=32 are not present in arr. Hence, "not present" returned for both of the queries

*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 * Complete the isPresent function below.
 * Time Completxity = O(n^2)
 */
string isPresentBruteForce(vector<vector<int>> arr, int x)
{
	int rows = arr.size();
	int cols = arr[0].size();

	cout << "Rows = " << rows << ", Columns = " << cols << endl;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] == x)
				return "present";
		}
	}
	return "not present";
}

//Time Completxity = O(n ^ 2)
string isPresent(vector<vector<int>> arr, int x)
{
	int rows = arr.size();
	int cols = arr[0].size();
	//cout << "Rows = " << rows << ", Columns = " << cols << endl;

	if (arr.empty())
		return "not present";

	int i = 0;		//i=Row index
	int j = cols - 1;	//j = Column index
	while (j >= 0 && i < rows)
	{
		if (x == arr[i][j])
			return "present";
		else if (x > arr[i][j])
			++i;
		else if (x < arr[i][j])
			--j;
	}
	return "not present";
}

//Recursive Binary Search. If condtion and you need to **return** from every case
bool binarySearch(vector<int>& arr, int low, int high, int x)
{
	//don't use (low+high/2) to avoid integer overflow in case of large numbers
	int mid = low + ((high - low) / 2);
		
	if (high >= low)
	{
		if (x == arr[mid])
			return true;
		else if (x < arr[mid])
			return binarySearch(arr, low, mid - 1, x);
		else if (x > arr[mid])
			return binarySearch(arr, mid + 1, high, x);
	}
	return false;
}

//Iterative Binary Search. "While" condition and just change high/low accordingly
bool binarySearchIterative(vector<int>& arr, int low, int high, int x)
{
	while (high >= low)
	{
		//don't use (low+high/2) to avoid integer overflow in case of large numbers
		int mid = low + ((high - low) / 2);

		if (x == arr[mid])
			return true;
		else if (x < arr[mid])
			high = mid - 1;
		else if (x > arr[mid])
			low = mid + 1;
	}
	return false;
}

//Time Complexity = O(nlogn)
string isPresentBinarySearch(vector<vector<int>> arr, int x)
{
	int rows = arr.size();
	int cols = arr[0].size();
	bool found = false;

	for (int i = 0; i < rows; i++)
	{
		found = binarySearchIterative(arr[i], 0, cols - 1, x);
		if (found) break;
	}

	if (found)
		return "present";
	else
		return "not present";
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

	int q;
	cin >> q;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int i = 0; i < q; ++i) {
		int x;
		cin >> x;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		string res = isPresent(arr, x);
		//string res = isPresentBruteForce(arr, x);
		//string res = isPresentBinarySearch(arr, x);

		fout << res << "\n";
	}
	system("pause");
	return 0;
}


