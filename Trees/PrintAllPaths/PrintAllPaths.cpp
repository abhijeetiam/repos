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


void printInorder(Node* n) {
	if (!n) return;
	printInorder(n->left);
	cout << n->val << " ";
	printInorder(n->right);
}

/*
 * Complete the function below.
 */

void printPaths(Node* root, vector<int>& vec)
{
	if (root == NULL)
		return;

	vec.push_back(root->val);
	printPaths(root->left, vec);
	printPaths(root->right, vec);

	if ((root->left == NULL) && (root->right == NULL))   //Leaf Node
	{
		int i;
		for (i = 0; i < vec.size() - 1; i++)
			cout << vec[i] << " ";					//Upto last element
		cout << vec[i];								//Last element
		cout << endl;
	}

	vec.pop_back();
}

void printAllPaths(Node* root) {

	vector<int> vec;
	printPaths(root, vec);
}

int main() {
	int _size;
	cin >> _size;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	string _str;
	getline(cin, _str);

	Node* root = createTree(_str);
	printAllPaths(root);

	system("pause");
	return 0;
}


