/*
Tree Iterator



Problem Statement:



Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.



1. Calling next() will return the next smallest number in the BST.

2. Calling hasNext() should return whether the next element exists.



Both functions should run in average O(1) time and uses O(h) memory, where h is the height of the tree.



[Iterator is a concept in higher level languages like C++ or Java. You probably can tell what it is. If you want to know more, please feel free to Google for the concept.]



Input/Output Format For The Function:



Input format:



There is only one argument named root denoting the root of the input tree.



Output format:



There is nothing to return as a whole. What the given method will do is described below:

Constructor/initializer: Initialize the iterator.

next(): Returns an integer denoting the next node value.

hasNext(): Returns a boolean denoting the next nodes presence.



Input/Output Format For The Custom Input:



Input Format:



line number 1: <noOfNodes> denoting number of nodes of the tree.

line number 2: <noOfNdoes space seprated integers> denoting the values of the nodes. Please make sure there are not leading or trailing spaces and between two integers there must be a single space.

line number 3: <rootIndex> denoting the root of the tree. value of rootIndex must be between -1 to noOfNodes-1

line number 4: <noOfEdges> denoting the number of edges of the tree

next noOfEdges line: <parentNodeIndex><space><childNodeIndex><space><leftOrRightFlag>

Here <parentNodeIndex> and <childNodeIndex> are the node indexes ranging from 0 to noOfNodes-1. <leftOrRighFlag> is either "L" or "R" (without quotes) denoting the left or right child where "L" stands for left child and "R" stands for right child.



Raw input of sample:

3

2 1 3

0

2

0 1 L

0 2 R



Output Format:



Space separated integer denoting the values in iterator order



Raw output of sample:

1 2 3



Constraints:



0 <= number of nodes <= 100000
1 <= values stored in the nodes <= 10^9


Sample Test Case:



Sample Input:



../../../../../Desktop/Screen%20Shot%202019-02-25%20at%203.3



Sample Output:



1 2 3



Tree node structure:



Class TreeNode {

int val;

TreeNode left_ptr;

TreeNode right_ptr;

}

**See Problem Definition


class BSTIterator{

private:
	stack<TreeNode*> iteratorStack;
	void insertLeftNodes(TreeNode *root){
		while(root != NULL){
			iteratorStack.push(root);
			root = root->left_ptr;
		}
	}

public:
	BSTIterator(TreeNode *root){
		insertLeftNodes(root);
	}

	bool hasNext(){
		return (!iteratorStack.empty());
	}

	int next(){
		TreeNode *currentRoot = iteratorStack.top();
		iteratorStack.pop();
		insertLeftNodes(currentRoot->right_ptr);
		return currentRoot->val;
	}
};



*/

// #include <bits/stdc++.h>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cassert>
#include <unordered_set>

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
class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		// initialize here
	}

	bool hasNext() {

	}

	int next() {

	}
};


void printIterator(TreeNode *root) {
	BSTIterator iterator = BSTIterator(root);
	int isFirst = 1;
	while (iterator.hasNext()) {
		if (!isFirst) {
			cout << " ";
		}
		cout << iterator.next();
		isFirst = 0;
	}
	cout << endl;
}

int main() {
	TreeNode* root = readBinaryTree();
	printIterator(root);
	return 0;
}
