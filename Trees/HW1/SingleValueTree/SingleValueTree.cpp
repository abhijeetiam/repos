/*

Single Value Tree



Problem Statement:



Given a binary tree, find number of unival subtrees (unival tree is a tree which have same value for every node in it).



Input/Output Format For The Function:



Input Format:



There is only one argument named root denoting the root of the input tree.



Output Format:



Return an integer denoting the number of unival subtrees in given tree.



Input/Output Format For The Custom Input:



Input Format:



The first line of the input contains an integer noOfNodes, denoting number of nodes of the tree.

In second line of the input, it contains noOfNodes integers, denoting the values of the nodes. Please make sure there are not leading or trailing spaces and between two integers there must be a single space.

In third line of the input, it contains a single integer rootIndex, denoting the root of the tree. value of rootIndex must be between 0 to noOfNodes-1.

In fourth line of the input, it contains a single integer noOfEdges, denoting the number of edges of the tree.

Next noOfNodes-1 lines, each line contains parentNodeIndex, childNodeIndex, leftOrRightFlag separated by space. Here parentNodeIndex and childNodeIndex are the node indexes ranging from 0 to noOfNodes-1. leftOrRighFlag is either "L" or "R" (without quotes) denoting relationship between parent and child, the left or right child where "L" stands for left child and "R" stands for right child.



If noOfNodes= 6, values = [5, 5, 5, 5, 5, 5], root_index = 0, noOfEdges=5, tree = [ {Node: 0, LeftChild: 1, RightChild: 2}, {Node: 1, LeftChild: 3, RightChild: 4}, {Node: 2, RightChild: 5}]:



6

5 5 5 5 5 5

0

5

0 1 L

0 2 R

1 3 L

1 4 R

2 5 R



Output Format:



Single integer denoting answer of the problem i.e. number of unival subtrees in given tree.



For input, noOfNodes= 6, values = [5, 5, 5, 5, 5, 5], root_index = 0, noOfEdges=5, tree = [ {Node: 0, LeftChild: 1, RightChild: 2}, {Node: 1, LeftChild: 3, RightChild: 4}, {Node: 2, RightChild: 5}], output will be:



6



Constraints:

0 <= n <= 100000, where n denotes number of nodes of tree.
1 <= value of node <= 100000.
0 <= root_index <= n-1 where n denotes number of nodes of tree and root_index denotes root index of tree.
Solution should use only constant extra space.


Sample Test Case:



Sample Input:



6

5 5 5 5 5 5

0

5

0 1 L

0 2 R

1 3 L

1 4 R

2 5 R



Sample Output:



6



Explanation:





https://s3.amazonaws.com/istreet-assets/ZCry_llL6wcS6fdhcbjUrA/untitled-3.jpg



There are 6 nodes i.e. 6 subtrees and for each subtree value is 5 for each node. Means each subtree of this tree is a unival tree hence answer will be 6.



Tree node structure:



Class TreeNode {

int val;

TreeNode left_ptr;

TreeNode right_ptr;

}

**See Problem Definition


bool countUnivalSubTrees(TreeNode* root, int* count)
{
	if (root == NULL)
		return true;
	if (root->left_ptr == NULL && root->right_ptr == NULL) { // leaf node
		(*count)++;
		return true;
	}
	bool found1 = countUnivalSubTrees(root->left_ptr, count);
	bool found2 = countUnivalSubTrees(root->right_ptr, count);
	if (found1 && found2)
	{
		if (root->left_ptr != NULL)
		{
			if (root->left_ptr->val != root->val)
				return false;
		}
		if (root->right_ptr != NULL)
		{
			if (root->right_ptr->val != root->val)
				return false;
		}
		(*count)++;
		return true;
	}
	return false;
}

int findSingleValueTrees(TreeNode* root) {
	int count =0;
	countUnivalSubTrees(root, &count);
	return count;
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
enum NodeType
{
	LEAF,
	SINGLE_PARENT,
	DOUBLE_PARENT
};

int findSingleValueTrees(Node* node);

NodeType CheckNodeType(Node* root)
{
	if (root->left == NULL && root->right == NULL)
		return NodeType::LEAF;
	else if (root->left != NULL && root->right != NULL)
		return NodeType::DOUBLE_PARENT;
	else
		return NodeType::SINGLE_PARENT;
}

void CountUniValueSubtrees(Node* node, int* nUnivalSubtrees)
{
	int nodeType = CheckNodeType(node);

	if (node == NULL)
		*nUnivalSubtrees += 0;
	else if (nodeType == NodeType::LEAF)
		*nUnivalSubtrees += 1;
	else if (nodeType == NodeType::SINGLE_PARENT)
	{
		if (node->left->val == node->val)
			*nUnivalSubtrees += findSingleValueTrees(node->left);
		else if (node->right->val == node->val)
			*nUnivalSubtrees += findSingleValueTrees(node->right);
	}
	else if (nodeType == NodeType::DOUBLE_PARENT)
	{
		if (node->val == node->left->val == node->right->val)
			*nUnivalSubtrees += findSingleValueTrees(node->left);
	}

	cout << "Number of unival subtrees = " << *nUnivalSubtrees << endl;
}

int findSingleValueTrees(Node* node)
{
	int nUnivalSubtrees = 0;
	CountUniValueSubtrees(node, &nUnivalSubtrees);
	return nUnivalSubtrees;
}

int main() {
	TreeNode* root = readBinaryTree();
	int result = findSingleValueTrees(root);
	cout << result << endl;
	return 0;
}
