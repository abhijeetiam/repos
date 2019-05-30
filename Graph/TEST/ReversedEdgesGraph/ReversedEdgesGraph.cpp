/*
Given A Graph, Build A New One With Reversed Edges



Problem Statement:



Given a strongly connected directed graph G, containing n nodes and m edges, you have to build a new graph containing n nodes, where edges are reversed than the original graph G.



This is also called Transposing the graph.



Input/Output Format For The Function:



Input Format:



There is only one argument pointing to a random node of the graph G.



Output Format:



Return any node in the new graph.



As input is a strongly connected graph, you will be able to visit all the nodes, given any random node.



Also when we reverse all the edges of strongly connected graph it will remain strongly connected graph, hence returning any one node is sufficient.



Input/Output Format For The Custom Input:



Input Format:



The first line of input should contain two space separated integers n and m, denoting no. of nodes and no. of edges in input graph G. In next m lines, each line should contain two space separated integers fromNode and toNode, denoting that there is an edge from fromNode to toNode in G.



If n = 3, m = 3 and edges = [(1 -> 2), (2 -> 3), (3 -> 1)], then input should be:



3 3

1 2

2 3

3 1



Output Format:



There will be one line of output, containing a string "Wrong Answer!" OR "Correct Answer!", depending on the evaluation of your solution’s output.



For input n = 3, m = 3 and edges = [(1 -> 2), (2 -> 3), (3 -> 1)], if your solution is correct, output will be:



Correct Answer!



Constraints:

1 <= n <= 315
Given graph does not contain multi edges (there will not be more than one edge connecting same pair of vertices in the same direction) and self loops.
Each node contains distinct values.
1 <= value stored in node <= n
You are not allowed to modify the given graph. Return completely new graph.


Sample Test Case:



Sample Input:



Any node of the graph where:

For n = 3

nodes = [1 2 3]

edges = [(1 -> 2), (2 -> 3), (3 -> 1)]



you could be given any node (1, 2 or 3) as input.



Sample Output:



Any node of the new graph where:

For n = 3

nodes = [1 2 3]

edges = [(2 -> 1), (3 -> 2), (1 -> 3)]



you could return any node as output.



Notes:

Maximum time allowed in interview: 20 Minutes.

Node *build_other_graph_helper( Node *root, unordered_map<Node*, Node*> &mapping ) {
	if( !root ) return root;
	if( mapping.count( root ) > 0 ) return mapping[ root ];
	Node* root2 = new Node( root->val );
	mapping[ root ] = root2;
	if( root->neighbours.empty() ) return root2;
	for( int i=0; i<root->neighbours.size(); ++i ) {
		Node *tmp = build_other_graph_helper( root->neighbours[i], mapping );
		tmp->neighbours.push_back( root2 );
	}
	return root2;
}

Node *build_other_graph( Node *root ) {
	unordered_map<Node*, Node*> mapping;
	return build_other_graph_helper( root, mapping );
}

*/

#include<bits/stdc++.h>

using namespace std;

const int MAX_NODES = 315;

struct Node
{
	int val;
	vector<Node *> neighbours;
	Node(int _val = 0)
	{
		val = _val;
		neighbours.clear();
	}
};


/*
 * Complete the function below.
 */

 /*
	 For your reference:

	 struct Node
	 {
		 int val;
		 vector<Node *> neighbours;
		 Node(int _val = 0)
		 {
			 val = _val;
			 neighbours.clear();
		 }
	 };
 */

Node *build_other_graph(Node *node)
{

}

void helper_dfs(Node *reversed_node, unordered_map<int, Node *> &reversed)
{
	reversed[reversed_node->val] = reversed_node;
	int n = reversed_node->neighbours.size();
	for (int i = 0; i < n; i++)
	{
		if (reversed.find(reversed_node->neighbours[i]->val) == reversed.end())
		{
			helper_dfs(reversed_node->neighbours[i], reversed);
		}
	}
}

unordered_map<int, Node *> helper_get_all_addresses_in_reversed_graph(Node * reversed_node)
{
	unordered_map<int, Node *> reversed;
	helper_dfs(reversed_node, reversed);
	return reversed;
}

string helper(int graph_nodes, vector<int> graph_from, vector<int> graph_to)
{
	unordered_map<int, Node *> original;
	for (int i = 1; i <= graph_nodes; i++)
	{
		original[i] = new Node(i);
	}
	set<pair<int, int>> edges;
	int graph_edges = graph_from.size();
	for (int i = 0; i < graph_edges; i++)
	{
		original[graph_from[i]]->neighbours.push_back(original[graph_to[i]]);

		edges.insert({ graph_from[i], graph_to[i] });
	}

	// Student will return only one node. Do a dfs and get all the nodes.
	unordered_map<int, Node *> reversed = helper_get_all_addresses_in_reversed_graph(build_other_graph(original[1]));

	cerr << "In returned graph: " << endl;

	for (auto it = reversed.begin(); it != reversed.end(); it++)
	{
		int n = it->second->neighbours.size();
		cerr << "Neighbours of node " << it->first << " = [";
		for (int i = 0; i < n; i++)
		{
			cerr << it->second->neighbours[i]->val;
			if (i != n - 1) {
				cerr << ", ";
			}
		}
		cerr << "]" << endl;
	}

	if (reversed.size() != graph_nodes)
	{
		cerr << "Wrong answer because no of nodes in returned graph != no of nodes in original graph." << endl;
		return "Wrong Answer!";
	}

	for (auto it = reversed.begin(); it != reversed.end(); it++)
	{
		if (1 > it->first || it->first > graph_nodes)
		{
			cerr << "Wrong answer because value of node is out of range." << endl;
			return "Wrong Answer!";
		}
		// New graph should not contain node from original graph. 
		if (original[it->first] == reversed[it->first])
		{
			cerr << "Wrong answer because instead of creating new node, you have used node from original graph." << endl;
			return "Wrong Answer!";
		}
		int n = it->second->neighbours.size();
		//cout << "no of edges of node " << it->first << " = " << n << endl;
		for (int i = 0; i < n; i++)
		{
			int val = it->second->neighbours[i]->val;
			//cout << "to = " << val << endl;
			auto itttt = edges.find({ val, it->first });
			if (itttt == edges.end())
			{
				cerr << "Wrong answer because returned graph contains edge that is not present in original graph." << endl;
				return "Wrong Answer!";
			}
			edges.erase(itttt);
		}
	}
	// All the edges should be present in the new graph. 
	if (edges.size() > 0)
	{
		cerr << "Wrong answer because returned graph contains extra edge that is not present in original graph" << endl;
		return "Wrong Answer!";
	}
	return "Correct Answer!";
}

int main()
{
	ostream &fout = cout;

	string res;
	int graph_nodes = 0;
	int graph_edges = 0;

	cin >> graph_nodes >> graph_edges;

	vector<int> graph_from(graph_edges);
	vector<int> graph_to(graph_edges);

	for (int graph_i = 0; graph_i < graph_edges; graph_i++) {
		cin >> graph_from[graph_i] >> graph_to[graph_i];
	}

	res = helper(graph_nodes, graph_from, graph_to);
	fout << res << endl;


	return 0;
}