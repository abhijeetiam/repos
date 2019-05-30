/*
Nearest Neighbours



Problem Statement:



Given a point p, and other n points in two-dimensional space, find k points out of n points which are nearest to p.

NOTE: Distance between two points is measured by the standard Euclidean method.



Input/Output Format For The Function:



Input Format:



There are 4 arguments in input, an integer p_x, which is the x coordinate of point p, integer p_y, which is the y coordinate of point p, an integer k and a 2D integer array of points n_points.



Output Format:



Return a 2D integer array result, which contains k points, nearest to point p.



Input/Output Format For The Custom Input:



Input Format:



The first line of input contains x coordinate of point p, p_x. The next line contains y coordinate of point p, p_y. The next line contains integer k. The next line contains the number of rows n in array points and the following line contains c, the number of columns in array points. It is guaranteed that c = 2 always. The following n lines contain 2 integers each, the x and y coordinates of a point.



Example:



0

0

2

3

2

1 1

0 1

1 0



Output Format:



Output k lines, each line contains two integers each representing x and y coordinates.



For the above input, the output will be:


0 1

1 0



Constraints:



1 <= n <= 100000
-1000000000 <= coordinates of the points <=1000000000
k <= total number of points in array points.


Sample Test Cases:



Sample Test Case 1:



Sample Input 1:



1

1

1

2

2

0 0

1 0



Sample Output 1:



1 0



Explanation 1:



The distance of point {0,0} from point p{1,1} is sqrt(2) and that of point {1,0} is 1. We need to choose 1(k) point having the minimum distance from point p. So it is {1,0}.


Sample Test Case 2:



Sample Input 2:



1

1

2

3

2

1 0

2 1

0 1



Sample Output 2:



1 0

2 1



Explanation 2:



Here, we can see that there are all the points are at the same distance from point p. So the answer can be any 2 points. Here {{1,0},{0,1}} and {{2,1},{0,1}} are equally acceptable answers.

//Python

import heapq
import math

def distance(x1,y1,x2,y2):
	res = (y2-y1) * (y2-y1) + (x2-x1) * (x2-x1)
	return math.sqrt(res);

def nearest_neighbours(p_x, p_y, k, n_points):
	# Write your code here
	distances = {}
	heap = []
	i = 0
	for point in n_points:
		d = distance(p_x,p_y,point[0], point[1])
		d = d * -1
		if i < k:
			heapq.heappush(heap,(d, point))
		else:
			min = heap[0][0]
			if d > min:
				heapq.heappop(heap)
				heapq.heappush(heap, (d, point))
		i = i + 1

	out = []
	for tup in heap:
		out.append(tup[1])
	return out;
	
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

vector<string> split(const string &);

/*
 * Complete the 'nearest_neighbours' function below.
 *
 * The function accepts integer p_x, p_y, k and a 2D integer array n_points as parameter.
 */

vector<vector<int> > nearest_neighbours(int p_x, int p_y, int k, vector<vector<int> > &n_points) {

}


int main()
{
	ostream &fout = cout;

	string p_x_temp;
	getline(cin, p_x_temp);

	int p_x = stoi(ltrim(rtrim(p_x_temp)));

	string p_y_temp;
	getline(cin, p_y_temp);

	int p_y = stoi(ltrim(rtrim(p_y_temp)));

	string k_temp;
	getline(cin, k_temp);

	int k = stoi(ltrim(rtrim(k_temp)));

	string n_points_rows_temp;
	getline(cin, n_points_rows_temp);

	int n_points_rows = stoi(ltrim(rtrim(n_points_rows_temp)));

	string n_points_columns_temp;
	getline(cin, n_points_columns_temp);

	int n_points_columns = stoi(ltrim(rtrim(n_points_columns_temp)));

	vector<vector<int> > n_points(n_points_rows);

	for (int i = 0; i < n_points_rows; i++) {
		n_points[i].resize(n_points_columns);

		string n_points_row_temp_temp;
		getline(cin, n_points_row_temp_temp);

		vector<string> n_points_row_temp = split(rtrim(n_points_row_temp_temp));

		for (int j = 0; j < n_points_columns; j++) {
			int n_points_row_item = stoi(n_points_row_temp[j]);

			n_points[i][j] = n_points_row_item;
		}
	}

	vector<vector<int> > result = nearest_neighbours(p_x, p_y, k, n_points);

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

