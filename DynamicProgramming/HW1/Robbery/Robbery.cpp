/*
Robbery



Problem Statement:



There are n houses built in a line, each of which contains some value in it. A thief is going to steal the maximal value in these houses, but he cannot steal in two adjacent houses because the owner of a stolen house will tell his two neighbors on the left and right side. What is the maximal stolen value?



For example, if there are four houses with values [6, 1, 2, 7], the maximal stolen value is 13, when the first and fourth houses are stolen.



Input/Output Format For The Function:



Input Format:



You will be given an array of integer values, containing the value in each house.



Output Format:



Return an integer max, denoting the maximum possible robbery.



Input/Output Format For The Custom Input:



Input Format:



The first line of input should contain a number n, denoting the number of houses. In next n lines, ith line should contain a number values[i], denoting ith index entry in values, i=(0,1,...,n-1).



If n = 4 and values = [6, 1, 2, 7], then input should be:



4

6

1

2

7



Output Format:



There will be one line, containing a number max, denoting the result returned by solution function.



For input n = 4 and values = [6, 1, 2, 7], output will be:



13



Constraints:



1 <= n <= 10^5
1 <= values[i] <= 10^4


Sample Test Case:



Sample Test Case 1:



Sample Input 1:



values = [6, 1, 2, 7]



Sample Output 1:



13



Explanation 1:



Steal from the first and the last house.



Sample Test Case 2:



Sample Input 2:



values = [1, 2, 4, 5, 1]



Sample Output 2:



7



Explanation 2:



Steal from the second and the fourth house.

int maxStolenValue(std::vector<int> values)
{
	vector<int> stolenValue(values.size(), 0);

	for (int i = 0; i < values.size(); ++i)
	{
		// Max Value is either one before previous + current OR max will be the previous itself without adding current.
		// in example 6 1 2 7, storedValue[0] = 6
		// storedValue[0] = 6
		// storedValue[1] = 6 (we decided to not take 1 and just pick 6
		// storedValue[2] = 8  ( 1 + 3)
		// storedValue[3] = 13 (storedValue[1] (which is 6 and not 1) + storedValue[3]
		int maxValue = values[i];
		if (i - 1 >= 0)
		{
			maxValue = max(maxValue, stolenValue[i - 1]);
		}

		if (i - 2 >= 0)
		{
			maxValue = max(maxValue, stolenValue[i - 2] + values[i]);
		}

		stolenValue[i] = maxValue;
	}

	//cout << "Max Store Value is: " << stolenValue[values_count - 1] << endl;

	return stolenValue[values.size() - 1];
}

*/

#include <bits/stdc++.h>

using namespace std;

// Complete the maxStolenValue function below.
int maxStolenValue(vector<int> values) {


}

int main()
{
	ostream &fout = cout;

	int values_count;
	cin >> values_count;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<int> values(values_count);

	for (int i = 0; i < values_count; i++) {
		int values_item;
		cin >> values_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		values[i] = values_item;
	}

	int res = maxStolenValue(values);

	fout << res << "\n";



	return 0;
}

