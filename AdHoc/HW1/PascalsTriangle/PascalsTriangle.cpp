/*
Pascal's Triangle



Problem Statement:



Pascal’s triangle is a triangular array of the binomial coefficients. Write a function that takes an integer value n as

input and returns 2d Array representing pascal’s triangle.



pascalTriangleArray is a 2D array of size n*n, where

pascalTriangleArray[i][j] = BinomialCoefficient(i, j); if j<=i,

pascalTriangleArray[i][j] = 0; if j>i



Following are the first 6 rows of Pascal’s Triangle:



1

1 1

1 2 1

1 3 3 1

1 4 6 4 1

1 5 10 10 5 1



Input/Output Format For The Function:



Input Format:



There is only one argument n, denoting the number of lines of Pascal's triangle to be considered.



Output Format:



Return an 2d integer array result, denoting pascal’s triangle where each value of result 2d array must be modulo with (10^9 + 7).



Size of result[i] for 0 <= i < n should be (i + 1) i.e. 0s for pascalTriangleArray[i][j] = 0; if j>i, should be ignored.



Input/Output Format For The Custom Input:



Input Format:



There should be one line for input, containing a single integer n, denoting the number of lines of Pascal's triangle to be considered.



If n = 6, then input should be:



6



Output Format:



There will be 2d array of integers, where each row of result 2d array will denotes row of pascal’s triangle in same order.



For input n = 6, output will be:



1

1 1

1 2 1

1 3 3 1

1 4 6 4 1

1 5 10 10 5 1



Constraints:



1 <= n <= 1700


Sample Test Cases:



Sample Input 1:



4



Sample Output 1:



1

1 1

1 2 1

1 3 3 1



Explanation 1:



Pascal's Triangle for given n=4:

Using equation,

pascalTriangleArray[i][j] = BinomialCoefficient(i, j); if j<=i,

pascalTriangleArray[i][j] = 0; if j>i

Generated pascal’s triangle will be:

1

1 1

1 2 1

1 3 3 1



Sample Input 2:



6



Sample Output 2:



1

1 1

1 2 1

1 3 3 1

1 4 6 4 1

1 5 10 10 5 1



Explanation 2:



Pascal's Triangle for given n=6:

Using equation,

pascalTriangleArray[i][j] = BinomialCoefficient(i, j); if j<=i,

pascalTriangleArray[i][j] = 0; if j>i

Generated pascal’s triangle will be:

1

1 1

1 2 1

1 3 3 1

1 4 6 4 1

1 5 10 10 5 1
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

#define MAX_PRIME (1000000000 + 7)

/*
* Complete the 'findPascalTriangle' function below.
*
* The function accepts INTEGER as parameter.
* Return 2D INTEGER ARRAY.
*/
vector<vector<int>> findPascalTriangle(int n)
{
	vector<vector<int>> final;
	vector<int> temp;

	temp.push_back(1);
	final.push_back(temp);
		
	for (int i = 1; i < n; i++)
	{
		temp.clear();
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || i == j)
			{
				temp.push_back(1);
			}
			else
			{
				int val = (int)((long long int)(final[i - 1][j - 1] + final[i - 1][j]) % MAX_PRIME);
				temp.push_back(val);
			}
		}
		final.push_back(temp);
	}
	return final;
}

vector<vector<int>> findPascalTriangleDP(int n)
{
	vector<vector<int>> final;
	vector<int> temp;
	map<pair<int, int>, int> memMap;

	temp.push_back(1);
	final.push_back(temp);
	memMap.insert(make_pair(make_pair(0, 0), 1));
	
	for (int i = 1; i < n; i++)
	{
		temp.clear();
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || i == j)
			{
				temp.push_back(1);
				memMap.insert(make_pair(make_pair(i, j), 1));
			}
			else
			{
				//int val = memMap[{i - 1, j - 1}] + memMap[{i - 1, j}];
				int val = (int)((long long int)(memMap[{i - 1, j - 1}] + memMap[{i - 1, j}]) % MAX_PRIME);
				cout << "val = " << val << endl;
				memMap.insert(make_pair(make_pair(i, j), val));
				temp.push_back(val);
			}
		}
		final.push_back(temp);
	}
	return final;
}

int main()
{
	string n_temp;
	getline(cin, n_temp);

	int n = stoi(ltrim(rtrim(n_temp)));

	ostream &fout = cout;

	//vector<vector<int>> result = findPascalTriangle(n);
	vector<vector<int>> result = findPascalTriangleDP(n);
	
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			fout << result[i][j];

			if (j != result[i].size() - 1) {
				fout << " ";
			}
		}

		if (i != result.size() - 1) {
			fout << "\n";
		}
	}

	fout << "\n";
	system("pause");
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

vector<string> split(const string &str) {
	vector<string> tokens;

	string::size_type start = 0;
	string::size_type end = 0;

	while ((end = str.find(" ", start)) != string::npos) {
		tokens.push_back(str.substr(start, end - start));

		start = end + 1;
	}

	tokens.push_back(str.substr(start));

	return tokens;
}