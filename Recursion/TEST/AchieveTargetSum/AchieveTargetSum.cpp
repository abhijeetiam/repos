/*
Possible To Achieve Target Sum?



Problem Statement:



Given an integer array arr of size n and a target sum k, you have to determine, whether there exists a non-empty group of numbers (numbers need not to be contiguous) in arr such that their sum equals to k.



The purpose of this problem is to learn recursion and not DP. So, you must write at least one recursive solution. After that, you can write a DP solution if you want.



Input/Output Format For The Function:



Input Format:



There are two argument. First one is arr and second one is k.



Output Format:



Return a boolean flag, denoting your answer.



Input/Output Format For The Custom Input:



Input Format:



The first line of input should contain an integer n, denoting size of input array arr. In next n lines, ith line should contain an integer arr[i], denoting value at index i of arr. In the next line, there should be an integer k, denoting the target sum value.



If n = 3, arr = [2, 4, 8] and k = 6, then input should be:



3

2

4

8

6



Output Format:



There will be one line of output, containing “0” or “1” (without quotes), corresponding to the result returned by solution function. “0” denotes flag = False and “1” denotes flag = True.



For input n = 3, arr = [2, 4, 8] and k = 6, output will be:



1



Constraints:

1 <= n <= 18
-10^17 <= arr[i], k <= 10^17


Sample Test Cases:



Sample Test Case 1:



Sample Input 1:



arr = [2 4 8]

k = 6



Sample Output 1:



True



Explanation 1:



arr[0] + arr[1] = 6



Sample Test Case 2:



Sample Input 2:



arr = [2 4 6]

k = 5



Sample Output 2:



False



Explanation 2:



There does not exists any group such that its sum equals to k.



Notes:

Maximum time allowed in interview: 20 Minutes.

bool check_if_sum_possible_Rec(vector<long long int>& arr, int i, long long int target, bool& picked)
{
	if ((target == 0) && picked == true)
	{
		return true;
	}

	if (i == arr.size())
	{
		return false;
	}

	if (check_if_sum_possible_Rec(arr, i+1, target, picked) == true)
		return true;

	picked = true;
	if (check_if_sum_possible_Rec(arr, i+1, target-arr[i],picked) == true)
		return true;

	return false;
}

bool check_if_sum_possible(vector <long long int> arr, long long int k) {
	bool picked = false;
	return check_if_sum_possible_Rec(arr, 0, k, picked);
}

//Time:O(2^n)
//Space:O(n)

*/





#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the function below.
 */
bool check_if_sum_possible(vector <long long int> arr, long long int k) {

}


int main()
{
	ostream &fout = cout;

	bool res;
	int arr_size = 0;
	cin >> arr_size;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	vector<long long int> arr;
	for (int i = 0; i < arr_size; i++) {
		long long int arr_item;
		cin >> arr_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		arr.push_back(arr_item);
	}

	long long int k;
	cin >> k;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	res = check_if_sum_possible(arr, k);
	fout << res << endl;


	return 0;
}

