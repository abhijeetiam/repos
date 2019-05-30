/*
Post-order Traversal of a Tree Without Recursion



Problem Statement:



Write a function to traverse a binary tree Post-order, without using recursion. As you traverse, please print contents of the nodes.



e.g. for a tree that's 

../../../../../Desktop/Screen%20Shot%202019-01-20%20at%2010.4



Print:

4 5 2 6 7 3 1



Input/Output Format For The Function:



Input format:



There is only one argument named root denoting the root of the input tree.



Output format:



Return an array containing the node values in post-order traversal of the tree.



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

4 5 2 3 1





Constraints:



0 <= number of nodes <= 100000
1 <= values stored in the nodes <= 10^9


Sample Test Case:



Sample Input:



../../../../../Desktop/Screen%20Shot%202019-01-20%20at%2010.5



Sample Output:



4 5 2 3 1



Explanation:



There are 5 nodes in the tree. As post-order traversal sequence is left_node -> right_node -> parent_node, so from root (1) it goes to left node (2). Left node has two children. So, it goes to left (4) again which is a leaf node. Print the content of this node. Go to parent’s right (5) node which is also a leaf node. Print the content and go back to parent (2) node, print the content and go back to its parent (1). Repeat this process for right side and print the root node (1) at last.



Tree node structure:



Class TreeNode {

int val;

TreeNode left_ptr;

TreeNode right_ptr;

**See Problem Definition

void postorderTraversal(struct TreeNode* root){
	if (root == nullptr) {
		return;
	}

	std::stack<TreeNode*> in, out;
	in.push(root);

	while(!in.empty())
	{
		auto t = in.top();
		in.pop();

		out.push(t);

		if (t->left_ptr) {
			in.push(t->left_ptr);
		}

		if (t->right_ptr) {
			in.push(t->right_ptr);
		}
	}

	std::stringstream str;
	while(!out.empty()) {
		str << out.top()->val << " ";
		out.pop();
	}
	std::string s = str.str();
	s.pop_back();
	std::cout << s;

}


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

void printArray(vector<int>result) {
	for (int i = 0; i < result.size(); i++) {
		if (i > 0) cout << " ";
		cout << result[i];
	}
	cout << endl;
}

/*
 * Complete the function below.
 */
void postorderTraversal(Node* root) {


}

int main() {
	TreeNode* root = readBinaryTree();
	vector<int> result = postorderTraversal(root);
	printArray(result);
	return 0;
}





