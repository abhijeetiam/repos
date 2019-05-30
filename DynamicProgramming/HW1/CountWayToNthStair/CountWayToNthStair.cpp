/*
Count ways to reach the N’th stair



Problem Statement:



(This is simple. Make me proud.)



There are n stairs, a person standing at the bottom wants to reach the top. He can climb a certain number of steps at once. For instance, the person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top.



Note: Solve the problem for general case i.e. for n stairs, and different kinds of steps that can be taken (e.g. instead of only 1 or 2 steps, it could be 2, 3 and 5 steps at a time).



Input/Output Format For The Function:



Input Format:



There will be two arguments: steps and n.

An array of integer steps denotes the steps the person can climb at a time and an integer n denotes the total number of stairs to be climbed.



Note: Answer is guaranteed to fit in long integer.



Output Format:



Return an integer ways, denoting the number of ways to reach the last staircase.



Input/Output Format For The Custom Input:



Input Format:



The first line should contain m(let say), denoting size of steps array. In next m lines, ith line should contain steps[i], denoting ith value in array steps. In the next line, there should be an integer, denoting n.



If n = 7 and steps = [2, 3], then input should be:



2

2

3

7



Output Format:



There will be one line, containing an integer ways, denoting the number of ways to reach the last staircase.



For input n = 7 and steps = [2, 3], output will be:



3



Constraints:



1 <= n <= 100
1 <= steps <= 10000
All values in steps will be unique. There are no duplicate entries.


Sample Test Cases:



Sample Test Case 1:



Sample Input 1:



n = 1

steps = [1, 2]



Sample Output 1:



1



Explanation 1:



Only one way to reach = [{1}]



Sample Test Case 2:



Sample Input 2:



n = 2

steps = [1, 2]



Sample Output 2:



2



Explanation 2:



Two ways to reach = [{1, 1}, {2}]



Sample Test Case 3:



Sample Input 3:



n = 7

steps = [2, 3]



Sample Output 3:



3



Explanation 3:



Three ways to reach = [{2, 2, 3}, {2, 3, 2}, {3, 2, 2}]

// Complete the countWaysToClimb function below.
long long int countWaysToClimb(vector<int> steps, int n) {
	vector<long long int> table(n+1,0);
	table[0] = 1;
	for(int i=1; i<= n; i++)
	{
		for(int k=0; k<steps.size(); k++)
		{
			table[i] += ((i>=steps[k])?table[i-steps[k]]:0);
		}
	}
	return table[n];
}

*/

#include <bits/stdc++.h>

using namespace std;

// Complete the countWaysToClimb function below.
long long int countWaysToClimb(vector<int> steps, int n) {


}

int main()
{
	ostream &fout = cout;

	int steps_count;
	cin >> steps_count;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<int> steps(steps_count);

	for (int i = 0; i < steps_count; i++) {
		int steps_item;
		cin >> steps_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		steps[i] = steps_item;
	}

	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	long long int res = countWaysToClimb(steps, n);

	fout << res << "\n";
	   
	return 0;
}
