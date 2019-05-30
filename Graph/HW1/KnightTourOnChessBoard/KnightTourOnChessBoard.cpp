/*
Knight's Tour On A Chess Board





Problem Statement:



You are given a rows * cols chessboard and a knight that moves like in normal chess.



Currently knight is at starting position denoted by start_row th row and start_col th col, and want to reach at ending position denoted by end_row th row and end_col th col.



The goal is to calculate the minimum number of moves that the knight needs to take to get from starting position to ending position.



start_row, start_col, end_row and end_col are 0-indexed.



Input Format:



There are six arguments. First is an integer denoting rows, second is an integer denoting cols, third is an integer denoting start_row, fourth is an integer denoting start_col, fifth is an integer denoting end_row and sixth is an integer denoting end_col.



Output Format:



Return an integer.



If it is possible to reach from starting position to ending position then return minimum number of moves that the knight needs to take to get from starting position to ending position.



If it is not possible to reach from starting position to ending position then return -1.



Constraints:



1 <= rows * cols <= 10^5
0 <= start_row, end_row < rows
0 <= start_col, end_col < cols


Sample Test Case:



Sample Input:



rows = 5

cols = 5

start_row = 0

start_col = 0

end_row = 4

end_col = 1



Sample Output:



3



Explanation:



3 moves to reach from (0, 0) to (4, 1):



(0, 0) -> (1, 2) -> (3, 3) -> (4, 1).

const int MIN_SIZE = 1, MAX_SIZE = 100000;

// -------------------------- START --------------------------

const int no_of_possible_moves = 8;
// 8 possible moves of knight.
const int add_row[] = {-2, -2, -1, 1, 2, 2, 1, -1};
const int add_col[] = {-1, 1, 2, 2, 1, -1, -2, -2};

//Check if position described by new_row th row and new_col th col, is inside the chess board or not.

bool is_valid_position(int rows, int cols, int new_row, int new_col)
{
	return ((0 <= new_row) && (new_row < rows) && (0 <= new_col) && (new_col < cols));
}

int find_minimum_number_of_moves(int rows, int cols, int start_row,
	int start_col, int end_row, int end_col)
{
	// If starting and ending positions are same.
	if (start_row == end_row && start_col == end_col)
	{
		return 0;
	}
	
	//If dist[i][j] = -1, cell described by ith row and jth col is not visited till now.
	//If dist[i][j] != -1, cell described by ith row and jth col can be reached from
	//starting position in minimum dist[row][col] moves.
	
	vector<vector<int>> dist(rows, vector<int>(cols, -1));
	// Starting position can be reached from starting position in 0 moves.
	dist[start_row][start_col] = 0;
	queue<pair<int, int>> bfs_q;
	// Add starting position. 
	bfs_q.push({ start_row, start_col });
	while (bfs_q.empty() == false)
	{
		// Remove first element from queue. 
		int cur_row = bfs_q.front().first;
		int cur_col = bfs_q.front().second;
		bfs_q.pop();
		// Update neighbours that are not visited till now. 
		for (int i = 0; i < no_of_possible_moves; i++)
		{
			// Neighbour's position. 
			int new_row = cur_row + add_row[i];
			int new_col = cur_col + add_col[i];
			if (is_valid_position(rows, cols, new_row, new_col))
			{
				// If neihbour is not visited till now.
				if (dist[new_row][new_col] == -1)
				{
					
					//From starting position we can reach current position in dist[cur_row][cur_col]
					//moves.
					//From current position we reach the neighbour in 1 move.
					//So, from starting position, the neighbour can be reached in
					//dist[cur_row][cur_col] + 1 moves.
					
					dist[new_row][new_col] = dist[cur_row][cur_col] + 1;
					// If we have found the ending position. 
					if (new_row == end_row && new_col == end_col)
					{
						return dist[end_row][end_col];
					}
					// Add the neighbour in queue. 
					bfs_q.push({ new_row, new_col });
				}
			}
		}
	}
	// If ending position can not be reached from starting position.
	return -1;
}


*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */
int find_minimum_number_of_moves(int rows, int cols, int start_row, int start_col, int end_row, int end_col) {
	// Write your code here.


}

int main()
{
	ostream &fout = cout;

	int rows;
	cin >> rows;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	int cols;
	cin >> cols;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	int start_row;
	cin >> start_row;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	int start_col;
	cin >> start_col;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	int end_row;
	cin >> end_row;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	int end_col;
	cin >> end_col;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	int res = find_minimum_number_of_moves(rows, cols, start_row, start_col, end_row, end_col);

	fout << res << "\n";

	return 0;
}