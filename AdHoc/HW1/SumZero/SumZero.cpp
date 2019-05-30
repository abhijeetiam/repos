/*Sum Zero





Problem Statement :



Given an array of integers arr of size n, find a non - empty subarray resSubArray such that sum of elements in resSubArray is zero.



Input / Output Format For The Function :



Input Format :



There is only one argument, arr denoting input array.



Output Format :



Return an array of integer res of size 2, where res[0] and res[1] denotes start index and end index(0 based indexing) (both inclusive) respectively for resSubArray in arr.



Note that :

If there is no such subarray, then return array res of size one and res[0] = -1.
If there are multiple such subarray, then return indices for any one of them.
If a matching subarray is a subarray of a larger matching subarray, then return indices for either one.
If there is a number '0' in the array arr, then it counts as a valid sum zero subarray.


Input / Output Format For The Custom Input :



Input Format :



The first line of the input should contain a single integer n, denoting the size of input array arr.

In the next n lines, ith line should contain an integer denoting arr[i].



If n = 6 and arr = [5, 1, 2, -3, 7, -4], then input should be :



6

5

1

2

- 3

7

- 4



If n = 5 and arr = [1, 2, 3, 5, -9], then input should be :



5

1

2

3

5

- 9



Output Format :



There are two cases here :

1. If a valid sum zero subarray exists in arr, then there will be two lines for output.First line will have an integer res[0] and second line will have an integer res[1], denoting starting index and ending index of required subarray(0 based indexing, both inclusive).

2. Otherwise if there is no valid sum zero subarray, there will be only one line for output, having an integer - 1.



For input n = 6 and arr = [5, 1, 2, -3, 7, -4], output will be :



1

3



For input n = 5 and arr = [1, 2, 3, 5, -9], output will be :



-1



Constraints :



	1 <= n <= 5 * 10 ^ 5
	- 10 ^ 9 <= arr[i] <= 10 ^ 9, (i = 0, 1, ..., (n - 1))


	Sample Test Cases :



Sample Input 1 :



	6

	5

	1

	2

	- 3

	7

	- 4



	Sample Output 1:



1

3



Explanation 1:



For given input array arr, arr[1] + arr[2] + arr[3] = 1 + 2 + (-3) = 0. So, subarray starting from index 1 upto index 3 (0 based indexing) is sum zero subarray.

(3, 5 and 1, 5 are the other correct solutions)



Sample Input 2:



5

1

2

3

5

- 9



Sample Output 2:



-1



Explanation 2:



For given input array arr, there is no subarray such that sum of integers in that subarray is 0.

So, -1 is printed as output.

HINT: Calculate the prefix sum

arr[] = {1, 4, -2, -2, 5, -4, 3}

If we consider all prefix sums, we can notice that there is a subarray with 0 sum when :
1) Either a prefix sum repeats or
2) Or prefix sum becomes 0.

Prefix sums for above array are:
1, 5, 3, 1, 6, 2, 5

Since prefix sum 1 repeats, we have a subarray with 0 sum.

y0 = x0
y1 = x0 + x1
y2 = x0 + x1+ x2
...
For instance, the prefix sums of the natural numbers are the triangular numbers:

input numbers	 1	 2	 3	 4	 5	 6	...
prefix sums		 1	 3	 6	10	15	21	...

vector<int> sumZero(vector<int> arr) {
	// 1,2,3,4,5,-12   N*N 1,3,6,10,15,3
	unordered_map<int64_t, int> sum_index;
	int64_t sum = 0;
	sum_index[0] = -1;
	vector<int> result_indexes;
	for (int i = 0; i < arr.size(); i++) {
		sum += arr[i];
		auto it = sum_index.find(sum);
		if (it != sum_index.end()) {
			result_indexes.push_back(it->second + 1);
			result_indexes.push_back(i);
			return result_indexes;
		}
		sum_index[sum] = i;
	}

	result_indexes.push_back(-1);
	return result_indexes;
}

*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;
                                                                                                            
// Complete the sumZero function below.
// You can also use a map here instead
vector<int> sumZero(vector<int> arr)
{
	vector<int> res;
	vector<long long> res_sum;
	unordered_set<long long> prefix_sum;
	long long sum = 0;
	bool bFound = false;
	
	if (arr.size() == 0) res.push_back(-1);
	else if (arr.size() == 1)
	{
		if (arr[0] == 0)
		{
			res.push_back(0);
			res.push_back(0);
		}
		else
			res.push_back(-1);
	}
	else
	{
		//Either a prefix sum repeats Or prefix sum becomes 0.
		for (int start = 0; start < arr.size(); start++)
		{
			sum += arr[start];
			
			if ((prefix_sum.find(sum) != prefix_sum.end()) || sum == 0)
			{
				res_sum.push_back(sum);
				bFound = true;
				break;
			}
			else
			{
				prefix_sum.insert(sum);
				res_sum.push_back(sum);
			}
		}

		if (bFound)
		{
			if (sum == 0)
			{
				res.push_back(0);
				res.push_back(res_sum.size() - 1);
			}
			else
			{
				for (int i = 0; i < res_sum.size(); i++)
				{
					if (res_sum[i] == sum)
					{
						if (res.empty())
							res.push_back(i + 1);
						else
							res.push_back(i);
					}
				}
			}
		}
	}

	if(res.empty())
		res.push_back(-1);

	return res;
}

vector<int> sumZeroUsingMap(vector<int> arr)
{
	vector<int> res;
	unordered_map<long long, int> prefix_sum;
	long long sum = 0;
	bool bFound = false;

	//Either a prefix sum repeats Or prefix sum becomes 0.
	for (int start = 0; start < arr.size(); start++)	//looping through all elements
	{
		if (arr[start] == 0)	//If you find a 0 just set index and return
		{
			res.push_back(start);
			res.push_back(start);
			return res;
		}

		sum += arr[start];

		if ((prefix_sum.find(sum) != prefix_sum.end()) || sum == 0)		//If any prefix sum already exists in map or if (sum == 0)
		{
			if(sum == 0)
				res.push_back(0);
			else
				res.push_back(prefix_sum[sum] + 1);		//add the mapped value for the sum in the map
			res.push_back(start);
			bFound = true;
			break;
		}
		else
		{
			prefix_sum[sum] = start;		//Adding sum into map with index
		}
	}

	if (!bFound)
		res.push_back(-1);

	return res;
}

int main()
{
	ostream &fout = cout;

	int arr_count;
	cin >> arr_count;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<int> arr(arr_count);

	for (int i = 0; i < arr_count; i++) {
		int arr_item;
		cin >> arr_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		arr[i] = arr_item;
	}

	//vector<int> res = sumZero(arr);
	vector<int> res = sumZeroUsingMap(arr);

	for (int i = 0; i < res.size(); i++) {
		fout << res[i];

		if (i != res.size() - 1) {
			fout << "\n";
		}
	}

	fout << "\n";
	system("pause");
	return 0;
}



