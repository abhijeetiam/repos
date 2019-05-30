/*
Upside Down

Problem Statement:

Given a binary tree where all the right nodes are leaf nodes, flip it upside down and turn it into a binary tree with left leaf nodes.

Keep in mind: ALL RIGHT NODES IN ORIGINAL TREE ARE LEAF NODE.

For example, turn these:





into these:




where 6 is the new root node for the first tree, and 2 for the second tree.

oriented correctly:




Input/Output Format For The Function:

Input format:

There is only one argument named root denoting the root of the input tree.

Output format:

You have to return the root of the flipped upside down tree.

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
1 2 3
0
2
0 1 L
0 2 R

Output Format:

It is exactly same as raw input format.

Raw output of the sample:
3
2 3 1
0
2
0 1 L
0 2 R

Constraints:
0 <= number of nodes <= 100000
1 <= values stored in the nodes <= 100000
Every node either has 0 or 2 children.
Solution should use only constant extra space.

Sample Test Case:

Sample Input:



Sample Output:



Tree node structure:

Class TreeNode {
int val;
TreeNode left_ptr;
TreeNode right_ptr;
}

** See Problem Definition

TreeNode* flipUpsideDown(TreeNode* root){
	TreeNode *new_root;

	if(!root){
		return root;
	}

	if(!root->left_ptr && !root->right_ptr){
		return root;
	}

	new_root = flipUpsideDown(root->left_ptr);

	root->left_ptr->left_ptr = root->right_ptr;
	root->left_ptr->right_ptr = root;
	root->left_ptr = root->right_ptr = NULL;
	return new_root;

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

	void considerEdge(
		string lOrR, TreeNode* parent, TreeNode* child,
		unordered_map<TreeNode*, int>& nodeToId, int& id, bool& edge_creates_cycle
	) {
		if (child) {
			if (nodeToId.find(child) == nodeToId.end()) {
				nodeToId[child] = id++;
				nodeValues.push_back(child->val);
			}
			else {
				edge_creates_cycle = true;
				cerr << "Cycle detected in the tree. Cycle contains the edge: "
					<< nodeToId[parent] << " " << nodeToId[child]
					<< " " << lOrR << endl;
			}
			edges.push_back(Edge(nodeToId[parent], nodeToId[child], lOrR));
		}
	}

	void getNodeValuesAndEdges(
		TreeNode* root, unordered_map<TreeNode*, int>& nodeToId, int& id
	) {
		if (root == NULL) {
			return;
		}

		bool left_edge_creates_cycle = false;
		bool right_edge_creates_cycle = false;

		considerEdge(
			"L", root, root->left_ptr,
			nodeToId, id, left_edge_creates_cycle
		);
		considerEdge(
			"R", root, root->right_ptr,
			nodeToId, id, right_edge_creates_cycle
		);

		if (left_edge_creates_cycle == false) {
			getNodeValuesAndEdges(root->left_ptr, nodeToId, id);
		}
		if (right_edge_creates_cycle == false) {
			getNodeValuesAndEdges(root->right_ptr, nodeToId, id);
		}
	}

	void populateRawValuesFromTree() {
		noOfNodes = 0;
		nodeValues.clear();
		rootIndex = -1;
		noOfEdges = 0;
		edges.clear();

		if (root != NULL) {
			int id = 0;
			unordered_map<TreeNode*, int> nodeToId;

			rootIndex = id;  // That is 0.
			nodeToId[root] = id++;
			nodeValues.push_back(root->val);

			getNodeValuesAndEdges(root, nodeToId, id);
			noOfNodes = nodeValues.size();
			noOfEdges = edges.size();
		}
	}

	void writeRawValues() {
		cout << noOfNodes << endl;
		for (int i = 0; i < noOfNodes; i++) {
			if (i) {
				cout << " ";
			}
			cout << nodeValues[i];
		}
		if (noOfNodes > 0) {
			cout << endl;
		}

		cout << rootIndex << endl;

		cout << noOfEdges << endl;
		for (int i = 0; i < noOfEdges; i++) {
			cout << edges[i].parentNodeIndex
				<< " " << edges[i].childNodeIndex
				<< " " << edges[i].leftRightFlag
				<< endl;
		}
	}
};

void printBinaryTree(TreeNode* root) {
	BinaryTree output_binary_tree;
	output_binary_tree.root = root;
	output_binary_tree.populateRawValuesFromTree();
	output_binary_tree.writeRawValues();
}

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
TreeNode* flipUpsideDown(TreeNode* root) {

}


int main() {
	TreeNode* root = readBinaryTree();
	TreeNode* result = flipUpsideDown(root);
	printBinaryTree(result);
	return 0;
}
