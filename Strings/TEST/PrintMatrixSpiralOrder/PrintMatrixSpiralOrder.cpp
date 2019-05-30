/*
Print Matrix In Spiral Order



Problem Statement:



You are given a character matrix named matrix of size rows * cols. Print matrix in spiral order (Starting from top-left corner and going in clockwise direction.)



Input/Output Format For The Function:



Input Format:



There is only one argument denoting character matrix matrix.



Output Format:



Return a string res, of length rows * cols denoting the spiral order of matrix.



Input/Output Format For The Custom Input:



Input Format:



The first line of input should contain an integer rows, denoting no. of rows of matrix. Second line should contain an integer cols, denoting no. of columns of matrix. In next rows lines, iith line should contain cols space separated characters, where jth character in this iith line denotes character at matrix[i][j].



If row = 3, col = 3 and matrix = [ ['X' 'Y' 'A'], ['M' 'B' 'C'], ['P' 'Q' 'R'] ], then input should be:



3

3

X Y A

M B C

P Q R



Output Format:



There will be one line of output, containing a string res, denoting the string value returned by solution function.



For input row = 3, col = 3 and matrix = [ ['X' 'Y' 'A'], ['M' 'B' 'C'], ['P' 'Q' 'R'] ], output will be:



XYACRQPMB



Constraints:

1 <= rows, cols
1 <= rows * cols <= 10^5
Any character in matrix will be either uppercase letter ('A' - 'Z') or lowercase letter ('a' - 'z').
Avoid recursion.


Sample Test Case:



Sample Input:



[

['X' 'Y' 'A']

['M' 'B' 'C']

['P' 'Q' 'R']

]



Sample Output:



"XYACRQPMB"



Explanation:



For the given matrix rows = 3 and cols = 3. Spiral order is 'X' -> 'Y' -> 'A' -> 'C' -> 'R' -> 'Q' -> 'P' -> 'M' -> 'B'. So return string "XYACRQPMB" of length rows * cols = 9.



Notes:

* This problem is less about logic, but more about careful index manipulation.

* Hint - It may be faster to write this, if you name your variables clearly. Instead of i,j,k,l etc, try naming them like row, col, start, end etc. That will also help your interviewer follow along more easily.


string printSpirally(vector < vector < char > > matrix) {
	int rows = matrix.size();
	int cols = matrix[0].size();
	string result;
	int rs = 0, re = rows;
	int cs = 0, ce = cols;
	while (rs < re && cs < ce) {
		for (int c = cs; c < ce; c++) {
			result += matrix[rs][c];
		}
		rs++;
		for (int r = rs; r < re; r++) {
			result += matrix[r][ce-1];
		}
		ce--;
		if (rs < re) {
			for (int c = ce - 1; c >= cs; c--) {
				result += matrix[re - 1][c];
			}
			re--;
		}
		if (cs < ce) {
			for (int r = re - 1; r >= rs; r--) {
				result += matrix[r][cs];
			}
			cs++;
		}
	}
	return result;
}


*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * Complete the function below.
 */
string printSpirally(vector < vector < char > > matrix) {


}


int main() {
	ostream &fout = cout;
	string res;

	int _matrix_rows = 0;
	int _matrix_cols = 0;
	cin >> _matrix_rows >> _matrix_cols;
	vector< vector < char > > _matrix(_matrix_rows);
	for (int _matrix_i = 0; _matrix_i < _matrix_rows; _matrix_i++) {
		for (int _matrix_j = 0; _matrix_j < _matrix_cols; _matrix_j++) {
			char _matrix_tmp;
			cin >> _matrix_tmp;
			_matrix[_matrix_i].push_back(_matrix_tmp);
		}
	}

	res = printSpirally(_matrix);
	fout << res << endl;


	return 0;
}

