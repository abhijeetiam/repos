/*
Clone a Binary Tree

Problem Statement:

Given a binary tree (represented by its root node, like usual), clone it. Return the root node of the cloned tree.

Remember: Cloning or copying a tree is best done recursively. Notice how clean and succinct the code is. Some of you may be tempted to do it breadth-first. But that's more complicated to handle in implementation.

Input/Output Format For The Function:

Input format:

There is only one argument named root denoting the root of the input tree.

Output format:

Return the root of cloned tree.

Input/Output Format For The Custom Input:

Input Format:

line number 1: <noOfNodes> denoting number of nodes of the tree.
line number 2: <noOfNdoes space seprated integers> denoting the values of the nodes. Please make sure there are not leading or trailing spaces and between two integers there must be a single space.
line number 3: <rootIndex> denoting the root of the tree. value of rootIndex must be between -1 to noOfNodes-1
line number 4: <noOfEdges> denoting the number of edges of the tree
next noOfEdges line: <parentNodeIndex><space><childNodeIndex><space><leftOrRightFlag>. Here <parentNodeIndex> and <childNodeIndex> are the node indexes ranging from 0 to noOfNodes-1. <leftOrRighFlag> is either "L" or "R" (without quotes) denoting the left or right child where "L" stands for left child and "R" stands for right child.

For the below tree:


Raw input will be:

5
1 2 3 4 5
0
4
0 1 L
0 2 R
1 3 L
1 4 R

Output Format:

It is exactly same as raw input format.

For the below tree:


Raw output will be:

5
1 2 3 4 5
0
4
0 1 L
0 2 R
1 3 L
1 4 R

Constraints:
0 <= number of nodes <= 100000
1 <= values stored in the nodes <= 10^9

Sample Test Case:

Sample Input:



Sample Output:



Tree node structure:

Class TreeNode {
int val;
TreeNode left_ptr;
TreeNode right_ptr;
}


TreeNode* cloneTree(TreeNode* root){
	if (root == NULL) return NULL;

	TreeNode* copy = new TreeNode(root->val);

	copy->left_ptr = cloneTree(root->left_ptr);
	copy->right_ptr = cloneTree(root->right_ptr);

	return copy;
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

TreeNode* readBinaryTree() {
	BinaryTree input_binary_tree;
	input_binary_tree.readRawValues();
	input_binary_tree.buildFromRawValues();
	return input_binary_tree.root;
}

void printBinaryTree(TreeNode* root) {
	BinaryTree output_binary_tree;
	output_binary_tree.root = root;
	output_binary_tree.populateRawValuesFromTree();
	output_binary_tree.writeRawValues();
}

bool isOutputTreeCloned(TreeNode *inputTreeRoot, TreeNode *outputTreeRoot) {
	if (inputTreeRoot == NULL || outputTreeRoot == NULL) {
		return true;
	}
	if (inputTreeRoot == outputTreeRoot) {
		return false;
	}
	bool isLeftSubtreeCloned = isOutputTreeCloned(inputTreeRoot->left_ptr, outputTreeRoot->left_ptr);
	bool isRightSubtreeCloned = isOutputTreeCloned(inputTreeRoot->right_ptr, outputTreeRoot->right_ptr);

	return (isLeftSubtreeCloned & isRightSubtreeCloned);
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
TreeNode* cloneTree(TreeNode* root) {

}


int main() {
	TreeNode* root = readBinaryTree();
	TreeNode* result = cloneTree(root);
	if (!isOutputTreeCloned(root, result)) {
		cerr << "Input tree is not cloned!" << endl;
	}
	else {
		printBinaryTree(result);
	}
	return 0;
}
