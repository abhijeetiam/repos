/*
Print All Paths of a Tree



Problem Statement:



Given a binary tree, print out all of its root-to-leaf paths one per line.

e.g. for a tree that's





Print:

1 2 4

1 2 5

1 3 6

1 3 7



Input format:



There is only one argument named root denoting the root of the input tree.



Output format:



Print the paths of the tree. You need not to worry about the order of paths in output, any valid answer will be accepted.



Constraints:



0 <= number of nodes <= 10000
1 <= values stored in the nodes <= 10^9


Sample Test Case:



Sample Input:







Sample Output:



1 2 4

1 2 5

1 3



(Order of paths in output does not matter. Hence,



1 3

1 2 5

1 2 4



will also be considered as correct answer.)



Explanation:



There are 3 paths in the tree.

The left most path contains values: 1 -> 2 -> 4

The right most path contains values: 1 -> 3

The other path contains values: 1 -> 2 -> 5



Tree node structure:



Class TreeNode {

int val;

TreeNode left_ptr;

TreeNode right_ptr;

}

**See Problem Definition

void printPaths(struct TreeNode* root, string currentPath )
{
	if(root->left_ptr == NULL && root->right_ptr == NULL)
	 {
		 //print current path


		cout<<currentPath<<endl;


		 return;
	 }
	 if(root->left_ptr)
		printPaths(root->left_ptr,currentPath + " " + to_string(root->left_ptr->val));
	 if(root->right_ptr)
		printPaths(root->right_ptr,currentPath + " " + to_string(root->right_ptr->val));

}
void printAllPaths(struct TreeNode* root){

	vector<int> currentPath;
	if(root)
		printPaths( root,to_string(root->val));

	return;

}


*/

#include <bits/stdc++.h>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left_ptr;
	TreeNode* right_ptr;

	TreeNode(int _val) {
		val = _val;
		left_ptr = NULL;
		right_ptr = NULL;
	}
};

class BinaryTree {
public:
	class Edge {
	public:
		int parentNodeIndex;
		int childNodeIndex;
		string leftRightFlag;

		Edge() {}

		Edge(int _parentNodeIndex, int _childNodeIndex, string _leftRightFlag) {
			parentNodeIndex = _parentNodeIndex;
			childNodeIndex = _childNodeIndex;
			leftRightFlag = _leftRightFlag;
		}
	};

	int noOfNodes;
	vector<int> nodeValues;
	int rootIndex;
	int noOfEdges;
	vector<Edge> edges;
	TreeNode* root;

	BinaryTree() {
		noOfNodes = 0;
		nodeValues.clear();
		rootIndex = -1;
		noOfEdges = 0;
		edges.clear();

		root = NULL;
	}

	void readRawValues() {
		cin >> noOfNodes;
		nodeValues.assign(noOfNodes, 0);
		for (int i = 0; i < noOfNodes; i++) {
			cin >> nodeValues[i];
		}

		cin >> rootIndex;

		Edge tempEdge;
		cin >> noOfEdges;
		edges.assign(noOfEdges, tempEdge);
		for (int i = 0; i < noOfEdges; i++) {
			cin >> edges[i].parentNodeIndex
				>> edges[i].childNodeIndex
				>> edges[i].leftRightFlag;
		}
	}

	void buildFromRawValues() {
		if (noOfNodes == 0) {
			root = NULL;
			return;
		}

		vector<TreeNode*> nodes(noOfNodes);
		for (int i = 0; i < noOfNodes; i++) {
			nodes[i] = new TreeNode(nodeValues[i]);
		}

		for (int i = 0; i < noOfEdges; i++) {
			if (edges[i].leftRightFlag == "L") {
				nodes[edges[i].parentNodeIndex]->left_ptr = nodes[edges[i].childNodeIndex];
			}
			else {
				nodes[edges[i].parentNodeIndex]->right_ptr = nodes[edges[i].childNodeIndex];
			}
		}

		root = nodes[rootIndex];
		return;
	}
};


TreeNode* readBinaryTree() {
	BinaryTree input_binary_tree;
	input_binary_tree.readRawValues();
	input_binary_tree.buildFromRawValues();
	return input_binary_tree.root;
}

/*
 * Complete the function below.
 */

void printPaths(Node* root, vector<int>& vec)
{
	if (root == NULL)
		return;

	vec.push_back(root->val);
	printPaths(root->left, vec);
	printPaths(root->right, vec);

	if ((root->left == NULL) && (root->right == NULL))   //Leaf Node
	{
		int i;
		for (i = 0; i < vec.size() - 1; i++)
			cout << vec[i] << " ";
		cout << vec[i];
		cout << endl;
	}

	vec.pop_back();
}

void printAllPaths(Node* root) {

	vector<int> vec;
	printPaths(root, vec);
}


int main() {
	TreeNode* root = readBinaryTree();
	printAllPaths(root);
	return 0;
}




