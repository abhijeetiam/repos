/*
n Queen Problem

Problem Statement:

The n-queen problem is the problem of placing n chess queens on an n * n chessboard, so that no two queens attack each other.

Your task is to find ALL possible arrangements for the n-queen problem.

You have to solve this problem using recursion. (There may be other ways of solving this problem, but for the purpose of this exercise, please use recursion only).

A queen can move horizontally, vertically, or diagonally.

Input/Output Format For The Function:

Input Format:

There is only one argument denoting integer n.

Output Format:

Return 2D string array res, of size m * n, where length of each string is n and m is the total no. of distinct arrangements possible.

Each character in res[i][j] describes a square on chessboard. So, any character in string should be one of {'q', '-'}. Character 'q' means queen is present on it and character '-' means it is empty.

To be precise, character at kth position of string res[i][j] describes content of square in kth column of jth row of chessboard in ith arrangement.

(To be more clear about the output, look at the sample test case.)

Input/Output Format For The Custom Input:

Input Format:

The first and only line of input should contain an integer n.

If n = 4, then input should be:

4

Output Format:

There will be (m*(n+1)) lines of output, describing m different possible arrangements. Order of printing of arrangements will be as per order in res array, i.e. res[0], res[1], …, res[m-1].

For ith arrangement (described by res[i]):
There will be total n + 1 lines. In first n lines, jth line contains a string res[i][j], denoting string at index j of res[i]. Last line will be an empty line.

For input n = 4, output will be:

-q--
---q
q---
--q-

--q-
q---
---q
-q--


Constraints:
1 <= n <= 13

Sample Test Case:

Sample Input:

4

Sample Output:

Suppose name of the returned array is ret.

ret [0] =

[
"--q-",
"q---",
"---q",
"-q--"
]

ret [1] =

[
"-q--",
"---q",
"q---",
"--q-"
]

Explanation:

There are 2 possible solutions for 4 queen problem, hence size of ret is 2 * 4, and length of each string is 4.

ret [i] will denote ith arrangement.
ret [i][j] will denote jth row of ith arrangement.
ret [i][j][k] will denote kth character (if it is a queen or empty cell) of jth row in ith arrangement.

You need not to worry about the order of arrangements in your returned. So output

ret [0] =

[
"-q--",
"---q",
"q---",
"--q-"
]

ret [1] =

[
"--q-",
"q---",
"---q",
"-q--"
]

will also be considered as a valid answer.

Notes:
Suggested time in interview: 30 minutes; this is only a variation of permutations problems
The “Suggested Time” is the time expected to complete this question during a real-life interview, not now in homework i.e. For the first attempt of a given homework problem, the focus should be to understand what the problem is asking, what approach you are using, coding it, as well as identifying any gaps that you can discuss during a TC session. Take your time, but limit yourself to 2 one hour sessions for most problems.

For slow languages like Python, test case having n = 13, might not pass, so if your solution passes all other test cases, then consider your solution as correct solution.

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
void genRes(vector<int>& info, vector<vector<string>>& res) {
 vector<string> ans;
 for (int i = 0; i < info.size(); i++) {
  string str = "";
  for (int j = 0; j < info.size(); j++) {
   if ( j == info[i]) str += "q";
   else str += "-";
  }
  ans.push_back(str);
 }
 res.push_back(ans);
}

bool isValid(vector<int>& info, int row, int col) {
 for (int i = 0; i < row; i++) {
  // check col
  if (info[i] == col) return false;
  // check diagonal
  if (abs(info[i]-col) == abs(i-row)) return false;
 }
 return true;
}

void findQ(int i, vector<int>& info, vector<vector<string>>& res) {
 // base
 if (i == info.size()) {
  genRes(info, res);
 }
 for (int j = 0; j < info.size(); j++) {
  if (isValid(info, i, j)) {
   info[i] = j;
   findQ(i+1, info, res);
  }
 }
}

vector < vector<string> > find_all_arrangements(int n) {
 vector<vector<string>> res;
 vector<int> info(n, -1); //  if info[a] = b, queen is in (a,b)
 findQ(0, info, res);
 return res;
}

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<vector<string>>	TwoDArray;

//Funtion to check if the new Queen being placed is on a safe position or not
bool IsSafe(TwoDArray& board, int r, int c)
{
	//cout << "Number of rows = " << board.size() << ", Number of cols = " << board[0].size() << endl;
	//cout << "IsSafe n = " << board.size() << ", r = " << r << ", c = " << c << endl;

	//Check for base cases
	if (r > board.size() || c > board[0].size())
		return false;

	int n = board.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == "q")
			{
				if ((i == r) || (j == c))		//Takes care of condition wherein Queen is on the same row or same column
					return false;
				if ((abs(r - i)) == (abs(c - j)))	//Takes care of condition wherein Queen is diagonally present
					return false;
			}	
		}
	}
	return true;
}

void InitializeBoard(int n, TwoDArray& board)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			board[i][j] = "-";
		}
	}
}
TwoDArray NQueens(TwoDArray& board, int r, int c)
{
	int n = board.size();
	cout << "NQueens n = " << board.size() << ", r = " << r << ", c = " << c << endl;

	if (IsSafe(board, r, c))
	{
		cout << "Position r,c = " << r << "," << c << " is safe" << endl;
		board[r][c] = "q";
		//r++;
		//c=0;
		if (r + 1 == n)
		{
			InitializeBoard(n, board);
			return board;
		}
		NQueens(board, r+1, 0);
		//return true;
	}
	else
	{
		cout << "Position r,c = " << r << "," << c << " is NOT safe" << endl;
		//c++;
		if (c + 1 == n)
		{
			InitializeBoard(n, board);
			return board;
		}

		NQueens(board, r, c+1);
		//return false;
	}

	/*for (int i = r; i+1 < n; i++)
	{
		for (int j = c; j+1 < n; j++)
		{
			NQueens(board, r, c);
		}
	}*/
}

TwoDArray find_all_arrangements(int n)
{
	//TwoDArray board initiliazed using size n and value "="
	TwoDArray board (n, vector<string>(n, "-"));	//Initializing whole vector to "-" initially
	TwoDArray ret;
	int c = 0;

	for (int c = 0; c < n; c++)
	{
		ret = NQueens(board, 0, c);
	}
	return ret;
}
	
int main()
{
	ostream &fout = cout;

	vector < vector<string> > res;
	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	res = find_all_arrangements(n);
	for (int res_i = 0; res_i < res.size(); res_i++) {
		for (int res_j = 0; res_j < res[res_i].size(); res_j++) {
			fout << res[res_i][res_j] << " ";
		}
		fout << endl;
	}

	system("pause");
	return 0;
}
