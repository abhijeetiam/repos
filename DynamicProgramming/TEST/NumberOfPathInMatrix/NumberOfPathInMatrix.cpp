/*
Consider a maze mapped to a matrix with an upper left corner at coordinates (row, column) = (0, 0). Any movement must be in increasing row or column direction. You must determine the number of distinct paths through the maze. You will always start at position (0, 0), the top left, and end up at (max(row), max(column)), the bottom right.

As an example, consider the following diagram where '1' indicates an open cell and '0' indicates blocked. You can only travel through open cells, so no path can go through the cell at (0, 2). There are two distinct paths to the goal.



PS example

There are two possible paths from cell (0, 0) to cell (1, 3) in this matrix.





Function Description

Complete the function numberOfPaths in the editor below. The function must return the number of paths through the matrix, modulo (10^9 + 7).

[By doing a modulo, we get around overflow. By doing it with a prime number, we maximize chances of uniform distribution of remainders. By doing it with a large prime like 10^9 + 7, we minimize chances of repeats altogether]





numberOfPaths has the following parameter(s):

2D array of integers a.



Constraints

1 ≤ n, m ≤ 1000
Each cell in matrix a contains either a 0 or a 1.


Input Format for Custom Testing

Input from stdin will be processed as follows and passed to the function.



The first line contains an integer n, the number of rows in matrix a.

The next line contains an integer m, the number of columns in matrix a.

The next n lines each contain space separated m integer values, for row a[i] where 0 ≤ i < n.



Sample Case 0

Sample Input 0

3
4
1 1 1 1
1 1 1 1
1 1 1 1
Sample Output 0

10
Explanation 0

Sample Case 0

There are 10 possible paths from cell (0, 0) to cell (2, 3).





Sample Case 1

Sample Input 1

2
2
1 1
0 1
Sample Output 1

1
Explanation 1

Sample Case 0

There is 1 possible path from cell (0, 0) to cell (1, 1).

//Less Memory
int numberOfPaths(vector<vector<int>> a)
{

	int rows = a.size() , cols = a[0].size();

	// Table to store number of paths
	vector<vector<long long int>> pathsTable(rows+1,vector<long long int>(cols+1,0));

	// Modulo to handle overflow
	long long int moduloFactor = 1e9 + 7;

	// Set so as to handle base case of pathsTable[1][1] = 1
	pathsTable[0][1] = 1;

	// Build table
	for(int i = 1 ; i <= rows ; ++i)
		for(int j = 1 ; j <= cols ; ++j)
			if(a[i-1][j-1])
				pathsTable[i][j] = (pathsTable[i-1][j] + pathsTable[i][j-1])%moduloFactor;

	// Solution is stored in pathsTable[rows][cols]
	return int(pathsTable[rows][cols]%moduloFactor);

}

//Less Execution time
int numberOfPaths(vector<vector<int>> a)
{
	int n = a.size();
	int m = a[0].size();
	int bigNum = pow(10,9)+7;

	if(a[0][0] == 0 || a[n-1][m-1] == 0)
	   return 0;

	vector<vector<uint64_t>> table(n+1, vector<uint64_t>(m+1));

	for(int i = n; i>=0; i--)
	{
		for(int j = m; j>=0; j--)
		{
			if(i == n-1 && j == m-1)
			   table[i][j] = 1;
			else if (i == n || j == m)
				table[i][j] = 0;
			else if(a[i][j]==0)
				table[i][j] = 0;
			else
				table[i][j]= (table[i+1][j]+table[i][j+1]) % bigNum;
		}
	}

	return (int)(table[0][0]);
}


*/

#include <bits/stdc++.h>

using namespace std;

// Complete the numberOfPaths function below.
int numberOfPaths(vector<vector<int>> a) 
{


}

int main()
{
	ostream &fout = cout;

	int a_rows;
	cin >> a_rows;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	int a_columns;
	cin >> a_columns;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<vector<int>> a(a_rows);
	for (int i = 0; i < a_rows; i++) {
		a[i].resize(a_columns);

		for (int j = 0; j < a_columns; j++) {
			cin >> a[i][j];
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	int res = numberOfPaths(a);

	fout << res << "\n";
	return 0;
}

