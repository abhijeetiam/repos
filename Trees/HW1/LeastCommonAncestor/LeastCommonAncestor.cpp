/*

Least Common Ancestor (LCA)



Problem Statement



You are given a binary tree of n nodes, rooted at T. The lowest common ancestor between two nodes n1 and n2 is defined as the lowest node in T that has both n1 and n2 as descendants. (For this problem, we allow a node to be an ancestor/descendant of itself.) You are also given reference of two nodes a & b, You need to find the LCA of both the nodes.



From wikipedia the definition of LCA is as follows:



The LCA of n1 and n2 in T is the shared ancestor of n1 and n2 that is located farthest from the root. Computation of lowest common ancestors may be useful, for instance, as part of a procedure for determining the distance between pairs of nodes in a tree: the distance from n1 to n2 can be computed as the distance from the root to n1, plus the distance from the root to n2, minus twice the distance from the root to their lowest common ancestor.



Input Format:



There are three arguments in input, denoting the pointer to the root of the tree T and reference of two nodes a & b for which you need to return the LCA.

Structure of tree node is as :



class Node {

   public:

	   int data;

	   Node *left;

	   Node *right;

};



Output Format:



Return an integer denoting the LCA for the given nodes a and b.



Constraints:



1 <= N <= 100000

1 <= Value at a <= n

1 <= Value at b <= n

Given the value stored at any node will be between 1 to n and unique.



Sample Test Case:



Sample Input:



Let us assume this is the tree, you are given the pointer to 1(Root), and two nodes 8,9











Sample Output:



5



Explanation:



Parent of 8 = 5

Parent of 9 = 5


Clearly we can see that the LCA(8,9) = 5



More examples,

LCA(2,5) = 2

LCA(2,3) = 1

** See Problem Definition


int lca(Node head, Node a, Node b)
{
	if(head==null) return 0;

	if(head.data==a.data||head.data==b.data) return head.data;

	int right = lca(head.right,a,b);
	int left = lca(head.left,a,b);

	if(right==0) return left;
	if(left==0) return right;

	return head.data;

}


*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node *left;
	Node *right;
	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

void parse_input(vector< pair< int, int > >&edges, struct Node * arr_stub[])
{
	for (int i = 0; i < edges.size(); i++)
	{
		int from = edges[i].first;
		int to = edges[i].second;
		if ((arr_stub[from]->left) == NULL)
			arr_stub[from]->left = arr_stub[to];
		else
			arr_stub[from]->right = arr_stub[to];
	}
}
void pre_order(Node * head)
{
	if (head == NULL)
		return;
	pre_order(head->left);
	pre_order(head->right);
}

/* you only have to complete the function given below.
Node is defined as

class Node {
	public:
	int data;
	Node *left;
	Node *right;
	Node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

*/

int lca(Node *root, Node *a, Node *b)
{
	return 0;
}


int main()
{
	int i, n, a, b;
	vector< pair< int, int > >edges;
	cin >> n >> a >> b;
	struct Node * arr_stub[100020];

	for (i = 1; i <= n; i++)
		arr_stub[i] = new Node(i);
	for (i = 1; i < n; i++)
	{
		int st, en;
		cin >> st >> en;
		edges.push_back(make_pair(st, en));
	}
	parse_input(edges, arr_stub);
	int answer = lca(arr_stub[1], arr_stub[a], arr_stub[b]);
	// we passed the head pointer basically which is arr_stub[1]
	cout << answer << endl;
	return 0;
}

