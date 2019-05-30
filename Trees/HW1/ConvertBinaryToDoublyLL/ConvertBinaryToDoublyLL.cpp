/*
Convert a Binary Tree into a Circular Doubly Linked List



Problem Statement:



Write a recursive function BTtoLL(TreeNode root) that takes a binary tree and rearranges the internal pointers to make a circular doubly linked list out of the tree nodes. The "previous" pointers should be stored in the "left_ptr" field and the "next" pointers should be stored in the "right_ptr" field. The list should be arranged so that the nodes are in increasing order. Print (space separated) the resulting linked list starting from its head node. (see	test-case output to understand the formatting). The operation can be done in O(n) time



e.g. for a tree that's

../../../../../Desktop/Screen%20Shot%202019-02-11%20at%2010.4



../../../../Desktop/Screen%20Shot%202019-03-26%20at%208.12.2





Input/Output Format For The Function:

Input format:



There is only one argument named root denoting the root of the input tree.



Output format:



Return the root of the converted binary tree.



Input/Output Format For The Custom Input:



Input Format:



line number 1: <noOfNodes> denoting number of nodes of the tree.

line number 2: <noOfNdoes space seprated integers> denoting the values of the nodes. Please make sure there are not leading or trailing spaces and between two integers there must be a single space.

line number 3: <rootIndex> denoting the root of the tree. value of rootIndex must be between -1 to noOfNodes-1

line number 4: <noOfEdges> denoting the number of edges of the tree

next noOfEdges line: <parentNodeIndex><space><childNodeIndex><space><leftOrRightFlag>

Here <parentNodeIndex> and <childNodeIndex> are the node indexes ranging from 0 to noOfNodes-1. <leftOrRighFlag> is either "L" or "R" (without quotes) denoting the left or right child where "L" stands for left child and "R" stands for right child.



Raw input of sample:

5

1 2 3 4 5

0

4

0 1 L

0 2 R

1 3 L

1 4 R



Output Format:



Space separated integer denoting the values in postorder traversal.



Raw output of sample:

4 2 5 1 3



Constraints:

0 <= number of nodes <= 100000
1 <= values stored in the nodes <= 10^9
Input tree will be a binary tree


Sample Test Case:



Sample Input:



../../../../Desktop/Screen%20Shot%202019-04-30%20at%2011.44.0



Sample Output:



../../../../Desktop/Screen%20Shot%202019-04-30%20at%2012.00.3



Explanation:



Left most node will be the head of the resultant circular doubly linked list and right most node will be the tail node of the circular linked list. The circular list will look like the following:

../../../../Desktop/Screen%20Shot%202019-04-30%20at%2012.02.0



Tree node structure:



Class TreeNode {

int val;

TreeNode left_ptr;

TreeNode right_ptr;

}

** See Problem Definition

void BSTToLLHelper(TreeNode *root, TreeNode **head, TreeNode **currentTail){
	if(root == NULL){
		return;
	}
	BSTToLLHelper(root->left_ptr, head, currentTail);
	if(*head == NULL){
		*head = root;
	}
	if(*currentTail == NULL){
		*currentTail = root;
	} else{
		(*currentTail)->right_ptr = root;
		root->left_ptr = *currentTail;
	}
	*currentTail = root;
	BSTToLLHelper(root->right_ptr, head, currentTail);
}

TreeNode* BSTtoLL(TreeNode* root){
	if(root == NULL){
		return root;
	}
	TreeNode *head = NULL;
	TreeNode *tail = NULL;
	BSTToLLHelper(root, &head, &tail);
	tail->right_ptr = head;
	head->left_ptr = tail;
	return head;
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

void printCircularList(TreeNode *circularListHead) {
	if (circularListHead == NULL) {
		printf("\n");
		return;
	}
	TreeNode *tmpHead = circularListHead;
	while (tmpHead->right_ptr != circularListHead) {
		printf("%d ", tmpHead->val);
		tmpHead = tmpHead->right_ptr;
	}

	printf("%d\n", tmpHead->val);
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
TreeNode* BTtoLL(TreeNode* root) {

}


int main() {
	TreeNode* root = readBinaryTree();
	TreeNode *result = BTtoLL(root);
	printCircularList(result);
	return 0;
}
