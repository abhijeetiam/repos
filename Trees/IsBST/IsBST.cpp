/*
This is a very well known interview problem: Given a Binary Tree, check if it is a Binary Search Tree (BST). A valid BST doesn't have to be complete or balanced. Duplicate elements are not allowed in a BST.
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

	int _str_size = 0;
	cin >> _str_size;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	vector<string> _str;
	string _str_item;
	getline(cin, _str_item);

	Node* root = createTree(_str_item);
	cout << isBST(root) << endl;

	system("pause");
	return 0;
}
