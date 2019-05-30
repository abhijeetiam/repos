/*
Merge Two BSTs



Problem Statement:



Given two BSTs (Binary Search Trees), one with N1 number of nodes and other one with N2 number of nodes.



Your task is to merge them such that:

   - Resultant tree is height balanced.

   - Resultant tree is a BST.

   - Resultant tree contains all values from given BST-1.

   - Resultant tree contains all values from given BST-2.

   - Size of the resultant tree is N1 + N2.

   - For any value, no of occurrences in resultant tree = no of occurrences in BST-1 + no of occurrences in BST-2. (If BST-1 contains 3 nodes with value 50 and BST-2 contains 4 nodes with value 50, then resultant tree should contain exactly 7 nodes with value 50.)



Any resultant tree, satisfying all the above conditions will be considered as valid answer.



Input Format:



There are two arguments, first one is the root of the first BST with N1 number of nodes and second one is the root of the second BST with N2 number of nodes.



Output Format:



Return root of the resultant BST.



Constraints:



1 <= N1, N2 <= 100000

Node value of the BSTs: 1 <= key1, key2 <= 1000000000

You are not allowed to modify the structure of the given BSTs.



Sample Test Case:



Sample Input:



Tree-1:



  1

   \

	2

	 \

	  3



Tree-2:



   7

  /  \

 6   8



Sample Output:



(one possible resultant tree)

	6

   /  \

  2   7

 /  \   \

1   3   8



Tree node structure:



class Node {

  public:

	int key;

	Node* left;

	Node* right;

	Node(int k) {

	  key = k;

	  left = NULL;

	  right = NULL;

	}

};



void inorder (Node *root, vector<int> &a) {
	if ( root == NULL ) return;

	inorder (root->left, a);
	a.push_back (root->key);
	inorder (root->right, a);
}

void merge (vector <int> &a1, vector<int> &a2, vector<int> &res) {

	int i=0, j=0;
	while ( i < a1.size() && j < a2.size() ) {
		if (a1[i] < a2[j]) {
			res.push_back ( a1[i] );
			++i;
		} else {
			res.push_back( a2[j] );
			++j;
		}
	}

	while ( i < a1.size() ) {
		res.push_back ( a1[i]); ++i;
	}

	while ( j < a2.size() ) {
		res.push_back ( a2[j]); ++j;
	}
}

Node *createBST ( vector<int> &arr, int st, int end ) {
	if ( st > end ) return NULL;

	int mid = st + (end - st) / 2;
	Node *root = new Node ( arr[mid] );

	root->left = createBST (arr, st, mid - 1);
	root->right = createBST (arr, mid+1, end);

	return root;
}

Node* mergeTwoBSTs(Node* root1, Node* root2) {
	vector<int> a1, a2, a;
	inorder ( root1, a1 );
	inorder ( root2, a2 );

	// array a1 and a2 are sorted arrays now. 
	merge(a1, a2, a);

	// create tree from the sorted arr a 
	return createBST(a, 0, a.size() - 1);
}


*/

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
	int key;
	Node* left;
	Node* right;
	Node(int k) {
		key = k;
		left = NULL;
		right = NULL;
	}
};

Node* mergeTwoBSTs(Node* root1, Node* root2) {

	// Write your code here.
}

Node* buildTree(int idx, int key[], int tree[][2]) {
	Node* root = new Node(key[idx]);
	if (tree[idx][0] != -1) {
		root->left = buildTree(tree[idx][0], key, tree);
	}
	if (tree[idx][1] != -1) {
		root->right = buildTree(tree[idx][1], key, tree);
	}
	return root;
}

int max(int a, int b) {
	return a >= b ? a : b;
}

int abs(int a) {
	return a > 0 ? a : -a;
}

class Height {
public:
	int height;
	Height() { height = 0; }
};

bool isBalanced(Node* temp, Height* height) {
	if (temp == NULL) {
		height->height = 0;
		return true;
	}

	Height* lh = new Height();
	Height* rh = new Height();

	bool l = isBalanced(temp->left, lh);
	bool r = isBalanced(temp->right, rh);

	height->height = max(lh->height, rh->height) + 1;

	if (abs(lh->height - rh->height) <= 1 && l && r)
		return true;
	return false;
}

void inOrderTraversal(Node* temp, vector<int> &list) {
	if (temp == NULL)
		return;
	inOrderTraversal(temp->left, list);
	list.push_back(temp->key);
	inOrderTraversal(temp->right, list);
}

int parent1[100001];
int key1[100001];
int child1[100001];
int parent2[100001];
int key2[100001];
int child2[100001];

int main() {
	ostream &fout = cout;

	int N1;
	cin >> N1;

	for (int i = 0; i < N1; i++) {
		cin >> parent1[i];
	}

	for (int i = 0; i < N1; i++) {
		cin >> child1[i];
	}

	for (int i = 0; i < N1; i++) {
		cin >> key1[i];
	}

	int N2;
	cin >> N2;

	for (int i = 0; i < N2; i++) {
		cin >> parent2[i];
	}

	for (int i = 0; i < N2; i++) {
		cin >> child2[i];
	}

	for (int i = 0; i < N2; i++) {
		cin >> key2[i];
	}

	int tree1[N1][2];
	int tree2[N2][2];
	for (int i = 0; i < N1; i++)
		tree1[i][0] = tree1[i][1] = -1;

	for (int i = 0; i < N2; i++)
		tree2[i][0] = tree2[i][1] = -1;

	int r1 = -1;
	for (int i = 0; i < N1; i++) {
		if (parent1[i] == -1)
			r1 = i;
		else {
			if (child1[i] == 0) {
				tree1[parent1[i]][0] = i;
			}
			else if (child1[i] == 1) {
				tree1[parent1[i]][1] = i;
			}
		}
	}

	int r2 = -1;
	for (int i = 0; i < N2; i++) {
		if (parent2[i] == -1)
			r2 = i;
		else {
			if (child2[i] == 0) {
				tree2[parent2[i]][0] = i;
			}
			else if (child2[i] == 1) {
				tree2[parent2[i]][1] = i;
			}
		}
	}

	Node* root1 = buildTree(r1, key1, tree1);
	Node* root2 = buildTree(r2, key2, tree2);
	vector<int> list;

	Node* root = mergeTwoBSTs(root1, root2);

	Height* height = new Height();

	if (isBalanced(root, height)) {
		vector<int> list;
		inOrderTraversal(root, list);
		for (auto it = list.begin(); it != list.end(); it++)
			fout << *it << "\n";
	}
	else {
		fout << "Returned tree is not height balanced\n";
	}

	return 0;
}
