/*
Implement Merge Sort


Problem Statement:



You are given an array of integers. You have to sort the array using merge sort algorithm.



Input/Output Format For The Function:



Input Format:



The function contains a single argument, an integer array arr.



Output Format:



Return the sorted integer array.



Input/Output Format For The Custom Input:



Input Format:



First line contains integer n, the number of integers. The next n lines contains an integer each.



If arr = [1,7,5,3] then input should be:



4

1

7

5

3



Output Format:



Output the sorted array of integers, with each integer in a new line.



For input arr = [1,7,5,3], output will be



1

3

5

7



Constraints:



1 <= n <= 10^5
-10^9 <= arr[i] <= 10^9 where 0<=i<=n-1


Sample Test Cases:



Sample Test Case 1:



Sample Input 1:



4

0

1

3

2



Sample Output 1:



0

1

2

3



Explanation 1:



Here 3>2>1>0, so after applying merge sort algorithm, the resultant array becomes [0,1,2,3].



Sample Test Case 2:



Sample Input 2:



3

1000000000

199999999

0



Sample Output 2:



0

199999999

1000000000



Explanation 2:



Here, 1000000000>199999999>0, so after applying merge sort algorithm, the resultant array becomes [0,199999999,1000000000].

vector<int>
_RMergsort(vector<int> &arr, int low, int high)
{
	if (low > high) {
		return {};
	}

	if (low == high) {
		return { arr[low] };
	}

	if (low + 1 == high) {
		if (arr[low] <= arr[high]) {
			return { arr[low], arr[high] };
		}
		else {
			return { arr[high], arr[low] };
		}
	}

	int mid = low + (high - low) / 2;
	auto left = _RMergsort(arr, low, mid);
	auto right = _RMergsort(arr, mid + 1, high);
	int i = 0, j = 0;
	vector<int> mergedArray;
	while (i < left.size() && j < right.size()) {
		if (left[i] <= right[j]) {
			mergedArray.push_back(left[i]);
			i++;
		}
		else {
			mergedArray.push_back(right[j]);
			j++;
		}
	}

	while (i < left.size()) {
		mergedArray.push_back(left[i]);
		i++;
	}

	while (j < right.size()) {
		mergedArray.push_back(right[j]);
		j++;
	}

	return mergedArray;
}

vector<int> merge_sort(vector<int> &arr) {

	return _RMergsort(arr, 0, arr.size() - 1);
}

*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'merge_sort' function below.
 *
 * The function accepts an integer array as parameter.
 */

vector<int> merge_sort(vector<int> &arr) {

}


int main()
{
	ostream &fout = cout;

	string n_temp;
	getline(cin, n_temp);

	int n = stoi(ltrim(rtrim(n_temp)));

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		string arr_item_temp;
		getline(cin, arr_item_temp);

		int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

		arr[i] = arr_item;
	}

	vector<int> result = merge_sort(arr);

	for (int i = 0; i < result.size(); i++) {
		fout << result[i];

		if (i != result.size() - 1) {
			fout << "\n";
		}
	}

	fout << "\n";


	return 0;
}


string ltrim(const string &str) {
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
	);

	return s;
}

string rtrim(const string &str) {
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end()
	);

	return s;
}

