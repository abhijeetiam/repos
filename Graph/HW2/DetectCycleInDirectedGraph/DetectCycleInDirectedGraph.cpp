/*
Detect cycle in Directed Graph





Problem Statement:



You are given Directed Graph G. You need to find out whether at least one cycle exist in the graph or not.



Input Format:



Three arguments for function, N, M and 2D Array of size M*2 where N denotes number of vertices and M denotes number of directed edges and 2D array of size M*2 represent M directed edges.

For array of size M*2, each row will represent directed edge, where value in column 1 and column 2 will be index (0-based) of starting vertex and ending vertex respectively of that directed edge.



Output Format:



Return boolean true if at least one cycle exist in graph else boolean false.



Constraints:



2 <= N <= 100000

1 <= M <= 100000

Indexing of vertices starting from 0.

No multiple edges i.e. if an edge is present which is directed from vertex u to vertex v, then no other edge will present which is directed from vertex u to vertex v.

Graph can have multiple components.



Sample Test Case:



Sample Input:



N = 5, M = 7, edges = [[0,1],[0,3],[1,3],[1,2],[2,3],[4,0],[2,4]]



Sample Output:



true



Explanation:



Graph formed from 5 vertices and given 7 directed edges have 1 cycle (0 --> 1 --> 2 --> 4 --> 0) So, Output will be true.


bool dfs(const unordered_map<int, vector<int> >& matrix, int i, vector<int>& visited)
{
	visited[i]  = 1;

	auto itr = matrix.find(i);
	if (itr == matrix.end()) {
		visited[i] = 2;
		return false;
	}

	for (int neighbour : itr->second) {
		if (visited[neighbour]  == 0) {
			bool has_cycles = dfs(matrix, neighbour, visited);
			if (has_cycles) return true;
		} else if(visited[neighbour] == 1) {
			return true;
		}
	}

	visited[i] = 2;
	return false;
}


bool hasCycle(int N, int M, vector<vector<int>> edges) {
	// Write your code here
	vector<int> visited(N, 0);

	unordered_map<int, vector<int> > matrix;
	for (vector<int> edge : edges) {
		matrix[edge[0]].push_back(edge[1]);
	}

	for (int i = 0; i < N; i++) {
		if (visited[i] == 0) {
			bool has_cycles = dfs(matrix, i, visited);
			if (has_cycles) return true;
		}
	}

	return false;

}


*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'hasCycle' function below.
 *
 * The function accepts INTEGER N, INTEGER M and 2D_INTEGER_ARRAY edges as parameter.
 * The function is expected to return a BOOLEAN.
 */

bool hasCycle(int N, int M, vector<vector<int>> edges) {
	// Write your code here
}

int main()
{
	string vertices;
	getline(cin, vertices);

	int N = stoi(ltrim(rtrim(vertices)));

	string no_edges;
	getline(cin, no_edges);

	int M = stoi(ltrim(rtrim(no_edges)));

	vector<vector<int>> edges(M);

	for (int i = 0; i < M; i++) {
		edges[i].resize(2);

		string edge;
		getline(cin, edge);

		vector<string> end_points = split(rtrim(edge));

		for (int j = 0; j < 2; j++) {
			int vertex = stoi(end_points[j]);

			edges[i][j] = vertex;
		}
	}

	ostream &fout = cout;

	bool result = hasCycle(N, M, edges);

	fout << result << "\n";

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