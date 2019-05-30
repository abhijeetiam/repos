/*
Is It A BST



Problem Statement:



This is a very well-known interview problem: Given a Binary Tree, check if it is a Binary Search Tree (BST). A valid BST doesn't have to be complete or balanced.



Input/Output Format For The Function:



Input format:



There is only one argument named root denoting the root of the input tree.



Output format:



You have to return true if the input tree is a BST or false otherwise.



Input/Output Format For The Custom Input:



Input Format:



line number 1: <noOfNodes> denoting number of nodes of the tree.

line number 2: <noOfNdoes space seprated integers> denoting the values of the nodes. Please make sure there are not leading or trailing spaces and between two integers there must be a single space.

line number 3: <rootIndex> denoting the root of the tree. value of rootIndex must be between -1 to noOfNodes-1

line number 4: <noOfEdges> denoting the number of edges of the tree

next noOfEdges line: <parentNodeIndex><space><childNodeIndex><space><leftOrRightFlag>

Here <parentNodeIndex> and <childNodeIndex> are the node indexes ranging from 0 to noOfNodes-1. <leftOrRighFlag> is either "L" or "R" (without quotes) denoting the left or right child where "L" stands for left child and "R" stands for right child.



Raw input of sample 1:

3

1 2 3

0

2

0 1 L

0 2 R



Output Format:



line number 1: 1 or 0 based on whether it's a BST or not.



Raw output of sample 1:

0



Constraints:



0 <= number of nodes <= 100000
1 <= values stored in the nodes <= 10^9
Return value must be boolean


Sample Test Case:



Sample Input 1:



  ../../../../Desktop/Screen%20Shot%202019-04-30%20at%2012.14.1



Sample Output 1:



  0



Explanation 1:



In the input tree, left child value(2) is greater than parent node value(1) which is a violation of BST definition.



Sample Input 2:

		2
		|
	   / \
	  /   \
	 1	   3
 

Sample Output 2:



  1



Explanation 2:

In the input tree, left child value is less than parent node value and right child value is greater than parent node value. Also both left subtree(node having value 1) and right subtree(node having value 3) is valid BST as they are leaf nodes. So, this is a BST.



Tree node structure:



Class TreeNode {

int val;

TreeNode left_ptr;

TreeNode right_ptr;

}

**See Problem Definition


#define INT_MAX 2147483647
#define INT_MIN -2147483648
int helper(struct TreeNode* root, int MIN, int MAX) {
	if(!root) {
		return 1;
	}
	if(root->val < MIN || root->val > MAX) {
		return 0;
	}
	return (helper(root->left_ptr, MIN, root->val) &&
			helper(root->right_ptr, root->val, MAX));
}
int isBST(struct TreeNode* root){
   return helper(root, INT_MIN, INT_MAX);
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
bool isBST(Node *root)
{
	if (root == NULL) return true;

	//First level case left
	if (root->left)
	{
		if (root->left->val >= root->val)
			return false;
	}

	//First level case right
	if (root->right)
	{
		if (root->right->val <= root->val)
			return false;
	}

	//Recurse left and right subtrees
	return(isBST(root->left) && isBST(root->right));
}


int main() {
	TreeNode* root = readBinaryTree();
	bool result = isBST(root);
	if (result == true) {
		cout << 1 << endl;
	}
	else {
		cout << 0 << endl;
	}
	return 0;
}
