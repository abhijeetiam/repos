/*
Group the numbers



Problem Statement:



You are given an integer array arr, of size n. Group and rearrange them (in-place) into evens and odds in such a way that group of all even integers appears on the left side and group of all odd integers appears on the right side.



Input/Output Format For The Function:



Input Format:



There is only one argument: Integer array arr.



Output Format:



Return the same integer array, with evens on left side and odds on the right side.

There is no need to preserve order within odds or within evens.



Input/Output Format For The Custom Input:



Input Format:



The first line of input should contain an integer n, denoting size of input array arr. In next n lines, ith line should contain an integer arr[i], denoting a value at index i of arr.



If n = 4 and arr = [1, 2, 3, 4], then input should be:



4

1

2

3

4



Output Format:



There will be n lines of output, where ith line contains an integer res[i], denoting value at index i of res.

Here, res is the result array returned by solution function.



For input n = 4 and arr = [1, 2, 3, 4], output will be:



4

2

1

3



Constraints:

1 <= n <= 10^5
arr contains only positive integers.
arr may contains duplicate numbers.
Solution with linear time complexity and constant auxiliary space is expected.


Sample Test Case:



Sample Input:



[1, 2, 3, 4]



Sample Output:



[4, 2, 1, 3]



Explanation:



Order does not matter. Other valid solution are

[2, 4, 1, 3]

[2, 4, 3, 1]

[4, 2, 3, 1]

//Less Execution time

vector <int> solve(vector <int> arr) {

	// int num = sizeof(arr)/sizeof(arr[0]);

	int num = arr.size();

	int left = 0;
	int right = num-1;

	while (left < right)
	{
		while (arr[left] % 2 == 0 && left < num) ++left;
		while (arr[right] %2 == 1 && right >= 0) --right;

		if (left < right)
		{
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
	return arr;

}


//Less Memory usage


void swap (int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

vector <int> solve(vector <int> arr) 
{

	vector<int> odds;
	vector<int> evens;
	vector <int> out;

	int left = 0;
	int right = arr.size() - 1;
	int n;

	while (left <= right)
	{
		n = arr.at(right);

		if (n % 2 == 0)
		{
			swap(&arr.at(left), &arr.at(right));
			left++;
		}
		else
		{
			right--;
		}
	}

	return arr;

}

*/

#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the function below.
 */
vector <int> solve(vector <int> arr) {

}


int main()
{
	ostream &fout = cout;

	vector <int> res;
	int arr_size = 0;
	cin >> arr_size;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	vector<int> arr;
	for (int i = 0; i < arr_size; i++) {
		int arr_item;
		cin >> arr_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		arr.push_back(arr_item);
	}

	res = solve(arr);
	for (int res_i = 0; res_i < res.size(); res_i++) {
		fout << res[res_i] << endl;;
	}

	return 0;
}

