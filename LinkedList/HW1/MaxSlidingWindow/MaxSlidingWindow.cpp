/*Maximum In Sliding Window

Problem Statement :

An integer array named arr is given to you.Size of arr is n and assume that it is very large.
There is a sliding window of size w, which is moving from the very left of the array to the very right.
You can only see the w numbers in the window.Each time the sliding window moves rightwards by one position.
You have to find maximum number in the window each time.

Input / Output Format For The Function :

Input Format :
There are two arguments in input.First is an integer array arr.Second is the window width w.

Output Format :
Return an array res, of size(n - w + 1), where i - th number of the returned array contains the maximum number in
window from arr[i] to arr[i + w - 1].

Input / Output Format For The Custom Input :

Input Format :
The first line of input should contain an integer n, denoting the length of input array arr.In next n lines, 
ith line should contain an integer arr[i], denoting value at index i of arr.In the next line, there should
be an integer w, denoting size of window.

If n = 8, arr = [1, 3, -1, -3, 5, 3, 6, 7] and w = 3, then input should be :

8
1
3
-1
-3
5
3
6
7
3

Output Format :
There will be(n - w + 1) lines, where ith line contains an integer res[i], denoting the value at index i of res.res is the result returned by the solution function.
For input n = 8, arr = [1, 3, -1, -3, 5, 3, 6, 7] and w = 3, output will be :

3
3
5
5
6
7

Constraints:

1 <= n <= 10 ^ 5
- 2 * 10 ^ 9 <= arr[i] <= 2 * 10 ^ 9
1 <= w <= n

Sample Test Case :

Sample Input :
arr = [1 3 - 1 - 3 5 3 6 7]
w = 3

Sample Output :
[3, 3, 5, 5, 6, 7]

Explanation :

Window Position->Max

1)[1 3 - 1] - 3 5 3 6 7 -> 3
2) 1[3 - 1 - 3] 5 3 6 7 -> 3
3) 1 3[-1 - 3 5] 3 6 7 -> 5
4) 1 3 - 1[-3 5 3] 6 7 -> 5
5) 1 3 - 1 - 3[5 3 6] 7 -> 6
6) 1 3 - 1 - 3 5[3 6 7] -> 7

Notes:

Suggested time in interview : 20 minutes.

The “Suggested Time” is the time expected to complete this question during a real - life interview, 
not now in homework i.e.For the first attempt of a given homework problem, the focus should be to understand what
the problem is asking, what approach you are using, coding it, as well as identifying any gaps that you can discuss
during a TC session.Take your time, but limit yourself to 2 one hour sessions for most problems.
*/

//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Complete the function below.
 */
vector <int> max_in_sliding_window(vector <int> arr, int w)
{
	int temp_max = 0;
	int win_max = 0;
	std::vector<int> res;

	int n = arr.size();

	cout << "n = " << n << " and w = " << w << endl;

	for (int i = 0; i < (n - w + 1); i++)
	{
		if (w == 1)
			win_max = arr[i];
		else if (w == 2)
			win_max = max(arr[i], arr[i+1]);
		else
		{
			for (int j = i; j < (i + w - 1); j++)
			{
				{
					temp_max = max(arr[j], arr[j + 1]);
					win_max = max(win_max, temp_max);
				}
			}
		}
		res.push_back(win_max);
	}
	return res;
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

	int w;
	cin >> w;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	res = max_in_sliding_window(arr, w);
	for (int res_i = 0; res_i < res.size(); res_i++) {
		fout << res[res_i] << endl;;
	}

	system("pause");
	return 0;
}