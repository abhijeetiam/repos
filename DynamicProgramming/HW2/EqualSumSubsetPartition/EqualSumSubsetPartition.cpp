/*
Equal Sum Subset Partition



Problem Statement :



Given an array s of n integers.Your task is to partition the given set s into two subsets, say s1 and s2 such that sum of all elements in s1 is equal to the sum of all elements in set s2.If it is not possible to partition the array s then returns a blank array else return a boolean array of size n where i(0 <= i < n) element is true if it is part of s1 and false if it is part of s2.



	Input / Output Format For The Function :



Input Format :



The first and only parameter of the function that is to be implemented is the array of integers s, that is to be partitioned.



Output Format :



If it is possible to partition the given array s in an above - said manner then return a boolean array of size n, where its i(0 <= i < N) element is true if it is the part of s1 else false if it is the part of s2.In case it is not possible to partition the array s, then return an empty array.



	Input / Output Format For The Custom Input :



Input Format :



The first line of the text file contains one single integer n, denoting number of elements in array s.

Next n lines of the input, each line contains single integer denoting the ith element in the array s.



If n = 3 and s = [1, 0, -1], then custom input format will be :



3

1

0

- 1



Output Format :



If a valid partition exists, then the first line contains an integer s1, denoting the size of the first subset and next S1 line contains

ith elements in the set s1 in the order they appear in the input array s.Next line contains an integer s2, denoting the size of the second subset.Next s2 lines will contain integers denoting the ith element in the set s2 in the order they appear in the input array s.

In case a valid partition is not possible the output contains only one line having integer - 1.



For the above - provided custom input, one possible custom output could be :



2

1

- 1

1

0



Constraints:



1 <= n <= 100
- 100 <= elements in s <= 100


Sample Test Case :



n = 6

s = [10, -3, 7, 2, 1, 3]



Sample Output :



[True, True, False, False, False, True]



Explanation :



	For the above sample output.There is only one possible partition to satisfy the equal subset sum condition.The two subsets are as follows :

			For s1 we pick the 0, 1 and 5 indexed elements

				s1 = [10, -3, 3]

				Here, the sum elements of s1 is 10 + 3 – 3 = 10

				For s2 we pick the 2, 3 and 4 indexed elements

				s2 = [7, 2, 1]

				Here, the sum elements of s1 is 7 + 2 + 1 = 10

				Hence, the sum of both the subsets s1 and s2 is 10.

vector<bool> equalSubSetSumPartition(vector<int> &s)
{
    // store min and max sum possible for given array
    int sum_neg = 0, sum_pos = 0;
    // calculate min and max subset sums
    for (auto val : s)
    {
        if (val < 0)
            sum_neg += val;
        else
            sum_pos += val;
    }

    // total sum of the array
    int sum = sum_pos + sum_neg;
    // Partition not possible
    if (sum & 1)
    {
        vector<bool> ret;
        // return empty array
        return ret;
    }

    int n = s.size();

    // dp state
    unordered_map<int, bool> dp[n];

    // base state
    // for idx 0 only one sum s[0] is possible
    dp[0][s[0]] = true;

    // iterate on all idx
    for (int i = 1; i < n; i++)
    {
        // iterate on all possible subset sum
        for (int val = sum_neg; val <= sum_pos; val++)
        {
            // dp state-transition

            // 1) state(i,val) = state(i-1,val) without taking current element
            dp[i][val] = dp[i - 1][val];

            // 2) if val == s[i], just taking ith element is sufficient
            if (val == s[i])
                dp[i][val] = true;
            else if (val - s[i] >= sum_neg)
            {
                // 3) state(i,val) = state(i-1,val-s[i]) when taking current element
                dp[i][val] |= dp[i - 1][val - s[i]];
            }
        }
    }

    int required = sum / 2;
    int idx = n - 1;

    // parition not possible
    if (!dp[idx][required])
    {
        vector<bool> ret;
        return ret;
    }

    // tracks partition elements
    vector<bool> resultSubset(s.size(), 0);
    // tracks count of elements included in S1
    int cnt = 0;
    while (idx >= 0)
    {
        if (idx != 0)
        {
            // reverse dp transition
            if (dp[idx][required] and !dp[idx - 1][required])
            {
                resultSubset[idx] = 1;
                cnt++;
                required -= s[idx];
                if (required == 0)
                    break;
            }
        }
        else
        {
            resultSubset[idx] = 1;
            cnt++;
        }
        idx--;
    }

    // if all elements are included in S1
    // All elements will be in S1 if total_sum = 0
    // case when s = [-2,2]
    // partition is not possible in this case
    if (cnt == n)
    {
        resultSubset.clear();
    }
    return resultSubset;
}


*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the equalSubSetSumPartition function below.
 *
 * @param s : input array as parameter.
 */

vector<bool> equalSubSetSumPartition(vector<int> &s)
{
}


int main()
{
	int n;
	cin >> n;

	vector<int> s(n);

	for (int i = 0; i < n; i++)
	{
		int S_item;
		cin >> S_item;
		s[i] = S_item;
	}

	ostream &fout = cout;

	vector<bool> result = equalSubSetSumPartition(s);

	if (result.size() == 0)
	{
		fout << -1 << endl;
		return 0;
	}

	int s1 = 0, s2 = 0;

	for (int i = 0; i < result.size(); i++)
	{
		if (result[i]) {
			s1++;
		}
		else {
			s2++;
		}
	}

	fout << s1 << endl;
	for (int i = 0; i < result.size(); i++)
	{
		if (result[i]) {
			fout << s[i] << endl;
		}
	}

	fout << s2 << endl;
	for (int i = 0; i < result.size(); i++)
	{
		if (!result[i]) {
			fout << s[i] << endl;
		}
	}

	return 0;
}

string ltrim(const string &str)
{
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

	return s;
}

string rtrim(const string &str)
{
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end());

	return s;
}