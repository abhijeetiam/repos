/*
Shortest Path In 2D Grid With Keys And Doors



Problem Statement:



Given a 2D grid of size n * m, that represents a maze-like area, a start cell and a goal cell, you have to find the shortest path from start to the goal.



You can go up, down, left or right from a cell, but not diagonally.



Each cell in the grid can be either land or water or door or key to some doors.



You can only travel on land cells, key cells and door cells, and not on water cells.



Each type of key will open only one type of door. There can be multiple identical keys of the same type. There can also be multiple doors of the same type. You cannot travel through a door, unless you have picked up the key to that door before arriving there. If you have picked up a certain type of key, then it can be re-used on multiple doors of same kind.



It is allowed to revisit a cell.



Input/Output Format For The Function:



Input Format:



There is only one argument: String array rowStr.

rowStr describes the grid.



Cells in the grid can be described as:

'#' = Water.

'.' = Land.

'a' = Key of type 'a'. All lowercase letters are keys.

'A' = Door that opens with key 'a'. All uppercase letters are doors.

'@' = Starting cell.

'+' = Ending cell (goal).



Output Format:



Return a 2D integer array pathArr, containing the path from start cell to goal cell.



Suppose your path contains p cells, then output array should be of size p * 2, where (pathArr[i][0], pathArr[i][1]) describes a cell position.



Positioning of cells:

0-indexed.
Columns: Increasing from left to right.
Rows: Increasing from top to bottom.


There can be multiple shortest paths, so you are free to return any of them.



Input/Output Format For The Custom Input:



Input Format:



The first line of input should contain an integer n, denoting no. of rows in input grid, which is also a size of array rowStr. In next n lines, ith line should contain a string rowStr[i], denoting value at index i of rowStr.



If n = 3, m = 4 and rowStr = [“...B”, “.b#.”, “@#+.”], then input should be:



3

...B

.b#.

@#+.



Output Format:



Let’s denote p * 2 as dimensions of pathArr, where pathArr is the 2D array returned by solution function.



The first line of output contains a string (without quotes)   “<len> cells will be visited in shortest path.”, where “<len>”would have been replaced with value of p.

In next line, there will be a string (without quotes) “Actual path is:”.

In next p lines, ith line contains two space separated integers pathArr[i][0] and pathArr[i][1], denoting value at index (i,0) and (i,1) of pathArr respectively.



For input n = 3, m = 4 and rowStr = [“...B”, “.b#.”, “@#+.”], output will be:



9 cells will be visited in shortest path.

Actual path is:

2 0

1 0

1 1

0 1

0 2

0 3

1 3

2 3

2 2



Constraints:

1 <= n, m <= 100
There will be exactly one starting point and one goal.
It is guaranteed that there exists a path from start to goal.
'a' <= key <= 'j'
'A' <= door <= 'J'


Sample Test Case:



Sample Input:



...B

.b#.

@#+.



Sample Output:



[

   [2 0],

   [1 0],

   [1 1],

   [0 1],

   [0 2],

   [0 3],

   [1 3],

   [2 3],

   [2 2]

]



Explanation:



In order to pass through door 'B', we first need to collect key to open that door and that is 'b'.



'@' -> '.' -> 'b' -> '.' -> '.' -> 'B' -> '.' -> '.' -> '+'



Here position [2 0] is '@' in the grid above, which is the starting position.



Notes:

Maximum time allowed in interview: 20 Minutes.

const int MAX_ROWS = 100, MAX_COLS = 100, MAX_KEYS = 10, MAX_MASK = (1 << MAX_KEYS),
	INF = MAX_ROWS * MAX_COLS * (MAX_KEYS + 1);
const int add_r[4] = {-1, 0, 1, 0};
const int add_c[4] = {0, -1, 0, 1};

vector<vector<int>> build_path(vector<vector<vector<int>>> &dp,
	vector<vector<vector<pair<pair<int, int>, int>>>> &parent, int ring_of_keys,
	pair<int, int> &start, pair<int, int> &stop)
{
	vector<vector<int>> ans;
	ans.push_back(vector<int>(0));
	ans[0].push_back(stop.first);
	ans[0].push_back(stop.second);

	
	//stop only when ring_of_keys is 0. Both conditions are necessary. Consider input 1 5 "#a@A+#",
	//here @ -> a -> @ -> A -> + , so when reconstructing + -> A -> @ and still we need to continue!
	
	while (stop != start || ring_of_keys != 0)
	{
		pair<pair<int, int>, int> par = parent[stop.first][stop.second][ring_of_keys];
		stop = par.first;
		ring_of_keys = par.second;
		ans.push_back(vector<int>(0));
		ans[ans.size() - 1].push_back(stop.first);
		ans[ans.size() - 1].push_back(stop.second);
	}
		reverse(ans.begin(), ans.end());
		return ans;
}

bool is_start(char ch)
{
	return ch == '@';
}

bool is_stop(char ch)
{
	return ch == '+';
}

bool is_water(char ch)
{
	return ch == '#';
}

bool is_land(char ch)
{
	return ch == '.';
}

bool is_key(char ch)
{
	return ('a' <= ch && ch < ('a' + MAX_KEYS));
}

bool is_door(char ch)
{
	return ('A' <= ch && ch < ('A' + MAX_KEYS));
}

bool can_open_door(char door, int ring_of_keys)
{
	return (ring_of_keys >> (door - 'A')) & 1;
}

void add_neighbour_to_queue(int to_r, int to_c, int to_ring_of_keys,
	pair<pair<int, int>, int> from, vector<vector<vector<pair<pair<int, int>, int>>>> &parent,
	vector<vector<vector<int>>> &dp, vector<vector<vector<bool>>> &visited,
	queue<pair<pair<int, int>, int>> &q)
{
	parent[to_r][to_c][to_ring_of_keys] = from;
	dp[to_r][to_c][to_ring_of_keys] = dp[from.first.first][from.first.second][from.second] + 1;
	visited[to_r][to_c][to_ring_of_keys] = true;
	q.push({ {to_r, to_c}, to_ring_of_keys });
}

// better to pass vectors by reference
void bfs(vector<string> &grid, pair<int, int> &start, vector<vector<vector<int>>> &dp,
	vector<vector<vector<pair<pair<int, int>, int>>>> &parent,
	vector<vector<vector<bool>>> &visited)
{
	int rows = grid.size();
	int cols = grid[0].length();

	queue<pair<pair<int, int>, int>> q;
	// Starting point with no keys has 0 distance (itself). 
	q.push({ start, 0 });
	dp[start.first][start.second][0] = 0;
	visited[start.first][start.second][0] = true;

	while (q.empty() == false)
	{
		pair<pair<int, int>, int> from = q.front();
		q.pop();
		if (is_stop(grid[from.first.first][from.first.second]))
		{
			continue;
		}
		// Visit all four neighbours and update.
		for (int i = 0; i < 4; i++)
		{
			int to_r = from.first.first + add_r[i];
			int to_c = from.first.second + add_c[i];
			if (to_r < 0 || to_r >= rows || to_c < 0 || to_c >= cols)
			{
				continue;
			}
			if (is_water(grid[to_r][to_c]))
			{
				continue;
			}
			else if (is_land(grid[to_r][to_c]) || is_start(grid[to_r][to_c]) ||
				is_stop(grid[to_r][to_c]))
			{
				if (visited[to_r][to_c][from.second] == false)
				{
					add_neighbour_to_queue(to_r, to_c, from.second, from, parent, dp, visited, q);
				}
			}
			else if (is_key(grid[to_r][to_c]))
			{
				int new_ring_of_keys = from.second | (1 << (grid[to_r][to_c] - 'a'));
				if (visited[to_r][to_c][new_ring_of_keys] == false)
				{
					add_neighbour_to_queue(to_r, to_c, new_ring_of_keys, from, parent, dp,
						visited, q);
				}
			}
			else if (is_door(grid[to_r][to_c]))
			{
				// Can enter only if we have key for that door. 
				if (can_open_door(grid[to_r][to_c], from.second))
				{
					if (visited[to_r][to_c][from.second] == false)
					{
						add_neighbour_to_queue(to_r, to_c, from.second, from, parent, dp,
							visited, q);
					}
				}
			}
		}
	}
}

// node that start and stop are passed by reference hence change will be reflected. 
void get_start_and_stop_positions(vector<string> &grid, pair<int, int> &start,
	pair<int, int> &stop)
{
	int rows = grid.size();
	int cols = grid[0].length();
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			if (is_start(grid[r][c]))
			{
				start = { r, c };
			}
			else if (is_stop(grid[r][c]))
			{
				stop = { r, c };
			}
		}
	}
}

vector<vector<int>> find_shortest_path(vector<string> grid)
{
	int rows = grid.size();
	int cols = grid[0].length();
	pair<int, int> start, stop;
	// Get the starting and ending point.
	get_start_and_stop_positions(grid, start, stop);
	
	//dp[r][c][ring] denotes length of shortest path from starting point to (r, c) and we have
	//already got keys in the ring.
	
	vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(MAX_MASK, INF)));
	
	//parent[r][c][ring] denotes the last node through which dp[r][c][ring] is updated. This will
	//help to reconstruct the path.
	
	vector<vector<vector<pair<pair<int, int>, int>>>> parent(rows,
		vector<vector<pair<pair<int, int>, int>>>(cols, vector<pair<pair<int, int>, int>>
		(MAX_MASK, { {-1, -1}, -1 })));
	
	//visited[r][c][ring] keeps track of dp[r][c][ring] is visited or not. Though parent is enough
	//to track this, but for readability purpose I have added this also.
	
	vector<vector<vector<bool>>> visited(rows,
		vector<vector<bool>>(cols, vector<bool>(MAX_MASK, false)));
	// Do bfs.
	bfs(grid, start, dp, parent, visited);
	
	//As dp[r][c][ring] denotes shortest path from start point and we have already got keys in the
	//ring, we just need to find for which key path is shorter.
	
	int length = INF;
	int ring_of_keys;
	for (int i = 0; i < MAX_MASK; i++)
	{
		if (length > dp[stop.first][stop.second][i])
		{
			length = dp[stop.first][stop.second][i];
			ring_of_keys = i;
		}
	}
	// cout << length << endl;

	// Build the path from using parent. 
	return build_path(dp, parent, ring_of_keys, start, stop);
}

*/

#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the function below.
 */
vector < vector<int> > find_shortest_path(vector <string> grid) {

}

int main()
{
	ostream &fout = cout;

	vector < vector<int> > res;
	int grid_size = 0;
	cin >> grid_size;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	vector<string> grid;
	for (int i = 0; i < grid_size; i++) {
		string grid_item;
		getline(cin, grid_item);
		grid.push_back(grid_item);
	}

	res = find_shortest_path(grid);
	for (int res_i = 0; res_i < res.size(); res_i++) {
		for (int res_j = 0; res_j < res[res_i].size(); res_j++) {
			fout << res[res_i][res_j] << " ";;
		}
		fout << endl;
	}


	return 0;
}