/*
Given a binary tree, write a program to count the number of Single Valued Subtrees. A Single Valued Subtree is one in which all the nodes have same value. Expected time complexity is O(n).

Example:

Input: root of below tree
			  5
			 / \
			1   5
		   / \   \
		  5   5   5
Output: 4
There are 4 subtrees with single values.


Input: root of below tree
			  5
			 / \
			4   5
		   / \   \
		  4   4   5
Output: 5
There are five subtrees with single values.
We strongly recommend you to minimize your browser and try this yourself first.

A Simple Solution is to traverse the tree. For every traversed node, check if all values under this node are same or not. If same, then increment count. Time complexity of this solution is O(n2).

An Efficient Solution is to traverse the tree in bottom up manner. For every subtree visited, return true if subtree rooted under it is single valued and increment count. 
So the idea is to use count as a reference parameter in recursive calls and use returned values to find out if left and right subtrees are single valued or not.
*/

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

using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
	Node(int v) :val(v), left(nullptr), right(nullptr) {}
};

int findSingleValueTrees(Node* node);

Node* deserialize(istringstream& in) {
	if (in.eof()) return nullptr;

	string val;
	in >> val;

	if (val.empty()) return nullptr;

	if (val == "#")
		return nullptr;

	Node* root = new Node(stoi(val));
	root->left = deserialize(in);
	root->right = deserialize(in);
	return root;
}

Node* createTree(string data) {
	if (data.empty()) return nullptr;
	istringstream in(data);
	return deserialize(in);
}

bool CountSingleValueTrees(Node* node, int& nCountSingleValue)
{
	if (node == NULL)
		return true;

	bool left = CountSingleValueTrees(node->left, nCountSingleValue);
	bool right = CountSingleValueTrees(node->right, nCountSingleValue);

	// If any of the subtrees is not singly, then this cannot be singly. 
	if (left == false || right == false)
		return false;

	// If left subtree is singly and non-empty, but data doesn't match 
	if (node->left && node->val != node->left->val)
		return false;

	// Same for right subtree 
	if (node->right && node->val != node->right->val)
		return false;
	
	nCountSingleValue++;
	return true;
}

/*
 * Complete the function below.
 */

int findSingleValueTrees(Node* node)
{
	int nCountSingleValue = 0;
	CountSingleValueTrees(node, nCountSingleValue);
	return nCountSingleValue;
}

int main() 
{
	ostream &fout = cout;
	int res;
	int _size;
	cin >> _size;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	string _str;
	getline(cin, _str);

	Node* root = createTree(_str);

	res = findSingleValueTrees(root);
	fout << res << endl;

	system("pause");
	return 0;
}