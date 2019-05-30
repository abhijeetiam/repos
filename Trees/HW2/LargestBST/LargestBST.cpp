/*
Largest BST



Problem Statement:



Given a binary tree, find the largest Binary Search Tree (BST), where largest means BST with largest number of nodes in it. The largest BST must include all of its descendants.



Input/Output Format For The Function:



Input format:



There is only one argument named root denoting the root of the input tree.



Output format:



Return an integer denoting the size of the largest BST.



Input/Output Format For The Custom Input:



Input Format:



line number 1: <noOfNodes> denoting number of nodes of the tree.

line number 2: <noOfNdoes space seprated integers> denoting the values of the nodes. Please make sure there are not leading or trailing spaces and between two integers there must be a single space.

line number 3: <rootIndex> denoting the root of the tree. value of rootIndex must be between -1 to noOfNodes-1

line number 4: <noOfEdges> denoting the number of edges of the tree

next noOfEdges line: <parentNodeIndex><space><childNodeIndex><space><leftOrRightFlag>

Here <parentNodeIndex> and <childNodeIndex> are the node indexes ranging from 0 to noOfNodes-1. <leftOrRighFlag> is either "L" or "R" (without quotes) denoting the left or right child where "L" stands for left child and "R" stands for right child.



Raw input of sample:

7

1 3 5 2 4 6 7

0

6

0 1 L

0 2 R

1 3 L

1 4 R

2 5 L

2 6 R



Output Format:



An integer denoting the size of the largest BST.



Raw output of sample:

3



Constraints:

0 <= number of nodes <= 100000
1 <= values stored in the nodes <= 10^9


Sample Test Case:



Sample Input:



../../../../../Desktop/Screen%20Shot%202019-02-17%20at%2011.3



Sample Output:



3



Explanation:



In the input tree, left subtree of node 1 is a BST. It has 3 nodes and this is the largest BST. So, result is 3.



Tree node structure:



Class TreeNode {

int val;

TreeNode left_ptr;

TreeNode right_ptr;

}

int findLargestBSTHelper(TreeNode* root, bool &isBST, int &minval, int &maxval){
	if (root == NULL) {
		isBST = true;
		minval = INT_MAX; // note MIN has to be MAX to make the parent a BST
		maxval = INT_MIN;
		return 0;
	}
	if ((root->left_ptr == NULL) && (root->right_ptr == NULL)) {
		isBST = true;
		minval = root->val; // return the node's value
		maxval = root->val;
		return 1;
	}

	// do postorder traversal O(n)
	int lmin, lmax, rmin, rmax;
	bool isBSTl, isBSTr;

	int lsize = findLargestBSTHelper(root->left_ptr, isBSTl, lmin, lmax);
	int rsize = findLargestBSTHelper(root->right_ptr, isBSTr, rmin, rmax);

	// now visit node
	if ((isBSTl && isBSTr) && (lmax <= root->val) && (root->val <= rmin)) {
		// BST
		isBST = true;
		if (lsize == 0) {
			// no left child
			minval = root->val;
		} else {
			minval = lmax;
		}
		if (rsize == 0) {
			// no right child
			maxval = root->val;
		} else {
			maxval = rmin;
		}
		return (lsize + rsize + 1);
	} else {
		// not BST
		isBST = false;
		minval = 0;
		maxval = 0;
		return (max(lsize, rsize));
	}
}

int findLargestBST(TreeNode* root) {
	bool isBST=false;
	int minSize=INT_MIN, maxSize=INT_MAX;
	return findLargestBSTHelper(root, isBST, minSize, maxSize);
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
	class TreeNode{
		int val;
		TreeNode* left_ptr;
		TreeNode* right_ptr;
	};
*/

/*
	Complete the function below
*/
int findLargestBST(TreeNode* root) {

}


int main() {
	TreeNode* root = readBinaryTree();
	int result = findLargestBST(root);
	cout << result << endl;
	return 0;
}
