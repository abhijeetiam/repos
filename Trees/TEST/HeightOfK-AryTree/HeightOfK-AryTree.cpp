/*
Height Of K-Ary Tree



Problem Statement:



Given a k-ary tree T, containing N nodes. You have to find height of the tree. (Length of the longest path from root to any node.)



(We are looking for number of edges on longest path from root to any node, not number of nodes on longest path from root to any node.)



Definition from Wikipedia: A k-ary tree is a rooted tree in which each node has no more than k children. A binary tree is the special case where k=2.



Input/Output Format For The Function:



Input Format:



There is only one argument denoting the root of the k-ary tree.



From any node, you can access all its children using node's property named children, which is an array of nodes.



For 3-ary tree:

1 is the root of the tree.

2's parent is 1.

3's parent is 1.

5's parent is 1.

4's parent is 5.



children of node 1 = [node 2, node 3, node 5].

children of node 2 = [].

children of node 3 = [].

children of node 4 = [].

children of node 5 = [node 4].



Look at the comment in the code editor, to know implementation details of the node, in your preferred language.



Output Format:



Return an integer hmax, denoting height of the k-ary tree.



Input/Output Format For The Custom Input:



Input Format:



The first line of input should contain an integer k, denoting that input tree is an k-ary tree T.

In next line, there should be an integer (N-1), denoting no of edges in T. In next (N-1) lines, ith line should contain an integer from[i], denoting value at one endpoint of an edge.

In next line, there should be an integer (N-1), denoting no of edges in T. In next (N-1) lines, ith line should contain an integer to[i], denoting value at other endpoint of an edge.



If k = 3, N = 5, from = [1, 1, 1, 5] and to = [3, 2, 5, 4], then input should be:



3

4

1

1

1

5

4

3

2

5

4



Output Format:



There will be one line of output, containing an integer hmax, denoting the result returned by solution function.



For input k = 3, N = 5, from = [1, 1, 1, 5] and to = [3, 2, 5, 4], output will be:



2



Constraints:

1 <= N <= 10^5
0 <= k <= N - 1


Sample Test Case:



Sample Input:



3-ary tree:

1 is the root of the tree.

2's parent is 1.

3's parent is 1.

5's parent is 1.

4's parent is 5.



Sample Output:



2



Explanation:



Given a 3-ary tree with 5 nodes. Node 1 has 3 children 2, 3 and 5, and node 5 has one child 4.

Longest path from root is 1 -> 5 -> 4 and it's length is 2.



int find_height(TreeNode* root) {

	if(!root)
		return 0;

	int height=0;

	for (int i=0; i < root->children.size();i++)
	{
		int newHeight = 1+find_height(root->children[i]);
		height = max(height,newHeight);
	}
	return height;
}

*/

#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 100000;

struct TreeNode
{
	//int val;														    // To find height of tree, value stored in nodes does not matter. So in input also we are not given this field. 
	vector<TreeNode*> children;											// Address of children nodes. 
	TreeNode()
	{
		children.clear();
	}
};


/*
 * Complete the function below.
 */

 /*
	 For your reference:

	 struct TreeNode
	 {
		 vector<TreeNode*> children;										// Address of children nodes.
		 TreeNode()
		 {
			 children.clear();
		 }
	 };
 */

int find_height(TreeNode* root) {

}


unordered_map<int, TreeNode*> address; 									// To build k-ary tree use this to speed up the insertion process. 

TreeNode* build_tree(vector<int> from, vector<int> to)
{
	int N = from.size() + 1;
	address.clear();												   // Clear the global variable. 
	for (int i = 1; i <= N; i++)
	{
		address[i] = new TreeNode();									// Create N nodes. 
	}
	for (int i = 0; i < N - 1; i++)
	{
		address[from[i]]->children.push_back(address[to[i]]);		    // Link the nodes. (Build the k-ary tree.)
	}
	return address[1];
}

int main()
{
	ostream &fout = cout;

	int k;
	cin >> k;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	int edges;
	cin >> edges;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	int N = edges + 1;
	assert(1 <= N);
	assert(N <= MAX_N);
	assert(0 <= k);
	assert(k <= N - 1);

	vector<int> from(edges, 0);
	for (int i = 0; i < edges; i++)
	{
		cin >> from[i];
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		assert(1 <= from[i]);
		assert(from[i] <= N);
	}

	cin >> edges;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	assert(edges == N - 1);

	vector<int> to(edges, 0);
	for (int i = 0; i < edges; i++)
	{
		cin >> to[i];
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		assert(1 <= to[i]);
		assert(to[i] <= N);
	}

	unordered_map<int, int> no_of_in_edges;
	for (int i = 0; i < edges; i++)
	{
		no_of_in_edges[to[i]]++;
	}
	assert(no_of_in_edges.size() == N - 1);

	for (auto it = no_of_in_edges.begin(); it != no_of_in_edges.end(); it++)
	{
		assert(it->second == 1);
	}

	TreeNode* root = build_tree(from, to);

	int h = find_height(root);
	assert(0 <= h);
	assert(h <= N - 1);

	fout << h << endl;


	return 0;
}

