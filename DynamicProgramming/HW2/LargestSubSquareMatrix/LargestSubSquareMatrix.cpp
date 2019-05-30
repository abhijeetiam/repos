/*
Largest sub-square matrix with all 1s



Problem Statement:



Given a 2D matrix mat of integers with n rows and m columns. All the elements in the matrix mat are either 0 or 1. Your task is to determine the largest sub-square size of the matrix that contains only 1s.



Input/Output Format For The Function:



Input Format:



There are three arguments, n, m, mat denoting the number of rows of matrix, number of columns of matrix and 2D matrix respectively.



Output Format:



Return an integer denoting the largest size of sub-square matrix that contains only 1s in the input 2D matrix mat.



Input/Output Format For The Custom Input:



Input Format:



The first line of input should contain a single number n, denoting the number of rows of input matrix mat. Second line should contain a single integer m, denoting the number of columns of input matrix mat. In the next n lines, each line should contain m space separated numbers. jth number in ith line of these n lines is mat[i][j], denoting the number at ith row and jth column of matrix.

If n=3, m=3 and mat=[ [1,0,0], [0,1,1], [0,1,1]], then input should be:



3

3

1 0 0

0 1 1

0 1 1



Output Format:



There should be a single number representing result.

If n=3, m=3 and mat=[ [1,0,0], [0,1,1], [0,1,1]], then output should be:



2



Constraints:



1 <= n, m <= 1000
mat[i][j] can be 0 or 1 where 0<=i<n and 0<=j<m.


Sample Test Case:



Sample Input:



n = 3

m = 3

mat = [ [1,0,0] , [0,1,1] , [0,1,1] ]



Sample Output:



2



Explanation:



The given matrix is represented below:



1 0 0

0 1 1

0 1 1



Here, we can easily infer that the 1s in bold form a sub-square matrix and is of the largest size(2*2) in the matrix such that all the elements in the sub-matrix are 1. Hence, the answer is 2.


// @param n : number of rows in mat
// @param m : number of columns in mat
// @param mat: 2D matrix of zeros and ones
int largest_sub_square_matrix(int n, int m, vector<vector<int>> &mat)
{
	vector<vector<int>> table(n+1, vector<int>(m+1, 0));
	int largest = 0;

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (mat[i-1][j-1]) {
				table[i][j] = min(table[i][j-1], min(table[i-1][j-1], table[i-1][j])) + 1;
			}
			largest = max (largest, table[i][j]);
		}
	}
	return largest;
}


*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


// @param n : number of rows in mat
// @param m : number of columns in mat
// @param mat: 2D matrix of zeros and ones
int largest_sub_square_matrix(int n, int m, vector<vector<int>> &mat)
{

}

int main()
{
	string mat_rows_temp;
	getline(cin, mat_rows_temp);

	int n = stoi(ltrim(rtrim(mat_rows_temp)));

	string mat_columns_temp;
	getline(cin, mat_columns_temp);

	int m = stoi(ltrim(rtrim(mat_columns_temp)));

	vector<vector<int>> mat(n);

	for (int i = 0; i < n; i++)
	{
		mat[i].resize(m);
		string mat_row_temp_temp;
		getline(cin, mat_row_temp_temp);

		vector<string> mat_row_temp = split(rtrim(mat_row_temp_temp));

		for (int j = 0; j < m; j++)
		{
			int mat_row_item = stoi(mat_row_temp[j]);
			mat[i][j] = mat_row_item;
		}
	}
	ostream &fout = cout;
	int ans = largest_sub_square_matrix(n, m, mat);
	cout << ans << endl;

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

vector<string> split(const string &str)
{
	vector<string> tokens;

	string::size_type start = 0;
	string::size_type end = 0;

	while ((end = str.find(" ", start)) != string::npos)
	{
		tokens.push_back(str.substr(start, end - start));

		start = end + 1;
	}

	tokens.push_back(str.substr(start));

	return tokens;
}
