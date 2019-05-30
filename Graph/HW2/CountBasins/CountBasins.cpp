/*
Count Basins



Problem Statement:



You are given a matrix where each number represents altitude of that cell, such that, water flows towards lower altitudes. If a cell’s four neighboring cells all have higher altitudes, we call this cell a sink; water collects in sinks.



Otherwise, water will flow to the neighboring cell with the lowest altitude. If a cell is not a sink, you may assume it has a unique lowest neighbor and that this will be lower than the cell.



Cells that drain into the same sink – directly or indirectly – are said to be part of the same basin. Your challenge is to partition the map into basins. Your code should output the sizes of the basins, in descending order.



Input/Output Format For The Function:



Input Format:



There will be only one argument matrix denoting the matrix of size row_count * col_count, with the altitude represented as int in each cell.



Output Format:



Return an array of integers in descending order., denoting the sizes of basins.



Input/Output Format For The Custom Input:



Input Format:



The first line of the input contains a number row_count, denoting the number of rows of the matrix. The second line of the input contains a number col_count, denoting the number of columns of the matrix. Next row_count lines, contains col_count numbers denoting matrix[i][j] where 0<=i<row_count and 0<=j<col_count.

For row_count=3, col_count=3 and matrix = [ [1, 5, 2], [2, 4, 7], [3, 6, 9]]



3

3

1 5 2

2 4 7

3 6 9



Output Format:



The output contains an array of numbers basin_sizes. Values of the basin_sizes array will be represented as one on a line, and they will be in descending order.

For row_count=3, col_count=3 and matrix = [ [1, 5, 2], [2, 4, 7], [3, 6, 9]], output will be:



7

2



Constraints:

1 <= row_count, col_count <= 1000.
0 <= matrix[i][j] <= 100000 where 0<=i<row_count, 0<=j<col_count.


Sample Test Cases:



Sample Input:



3

3

1 5 2

2 4 7

3 6 9



Sample Output:



7

2



Explanation:



The basins, labeled with A’s and B’s, are:

A A B

A A B

A A A



Every cell labeled with A will sink at (0, 0), whereas B will sink at (1, 2).



Sample Input 2:



4

4

0 2 1 3

2 1 0 4

3 3 3 3

5 5 2 1



Sample Output 2:



7

5

4



Explanation:



The basins, labeled with A’s and B’s, are:

A A B B

A B B B

A B B C

A C C C



Every cell labeled with A will sink at (0, 0), B will sink at (1, 2) and C will sink at (3, 3).

int getBasin(vector<vector<int>> &ele_map, vector<vector<int>> &basins, int row, int col, int &basin) {
	int new_row = row, new_col = col;

	if (basins[row][col] != -1) {
		return basins[row][col];
	}

	// left
	if (row > 0 && ele_map[row - 1][col] < ele_map[new_row][new_col]) {
		new_row = row - 1;
		new_col = col;
	}

	// right
	if (row < ele_map.size() - 1 && ele_map[row + 1][col] < ele_map[new_row][new_col]) {
		new_row = row + 1;
		new_col = col;
	}

	// up
	if (col > 0 && ele_map[row][col - 1] < ele_map[new_row][new_col]) {
		new_row = row;
		new_col = col - 1;
	}

	if (col < ele_map[0].size() - 1 && ele_map[row][col + 1] < ele_map[new_row][new_col]) {
		new_row = row;
		new_col = col + 1;
	}

	if (new_row == row && new_col == col) {
		if (basins[new_row][new_col] == -1) {
			basins[new_row][new_col] = basin++;
		}
		return basins[new_row][new_col];
	}

	basins[row][col] = getBasin(ele_map, basins, new_row, new_col, basin);
	return basins[row][col];

}

vector<int> find_basins(vector<vector<int>> elevation_map) {
	int n = elevation_map.size(), m = elevation_map[0].size(), basin = 0;
	vector<vector<int>> basins(n, vector<int>(m, -1));
	vector<int> ret;
	unordered_map<int, int> count;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			getBasin(elevation_map, basins, i, j, basin);
			count[basins[i][j]]++;
		}
	}

	for (pair<int, int> e : count) {
		ret.push_back(e.second);
	}

	sort(ret.rbegin(), ret.rend());
	return ret;
}


*/

#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

void printMatrix(int row_count, int col_count, vector< vector<int> > matrix) {
	for (int i = 0; i < row_count; i++) {
		for (int j = 0; j < col_count; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


vector<int> find_basins(vector< vector<int> > matrix) {
	//Write your code here
}


int main() {
	string row_count_temp;
	getline(cin, row_count_temp);

	int row_count = stoi(ltrim(rtrim(row_count_temp)));

	string col_count_temp;
	getline(cin, col_count_temp);

	int col_count = stoi(ltrim(rtrim(col_count_temp)));

	vector< vector<int> > matrix(row_count);
	for (int i = 0; i < row_count; i++) {
		matrix[i].resize(col_count);

		string row;
		getline(cin, row);

		vector<string> values = split(rtrim(row));

		for (int j = 0; j < col_count; j++) {
			matrix[i][j] = stoi(values[j]);
		}
	}

	ostream &fout = cout;

	// printMatrix(row_count, col_count, matrix);

	vector<int> basin_sizes = find_basins(matrix);

	for (int i = 0; i < basin_sizes.size(); i++)
		fout << basin_sizes[i] << endl;

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
