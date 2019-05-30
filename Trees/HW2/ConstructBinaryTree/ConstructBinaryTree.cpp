/*
Construct_Binary_Tree



Problem Statement:



Inorder traversal - Process all nodes of a binary tree by recursively processing the left subtree, then processing the root, and finally the right subtree.

Preorder traversal - Process all nodes of a binary tree by recursively processing the root, then processing the left subtree, and finally the right subtree.



Given the inorder and preorder traversal of a valid binary tree, you have to construct the binary tree.



[Interesting article to read: http://www.geeksforgeeks.org/if-you-are-given-two-traversal-sequences-can-you-construct-the-binary-tree/]





Input Format:



You are given two integer array named inorder and preorder of size n, containing positive values <= 10^5



Output Format:



Return root pointer of the constructed binary tree.



Constraints:



0 <= n <= 10^5
1 <= inorder[i], preorder[i] <= 10^5
Values stored in the binary tree are unique.


Sample Test Cases:



Sample Test Case 1:



Sample Input 1:



inorder = [2, 1, 3] and preorder = [1, 2, 3]



Sample Output 1:



  1

/ \

2 3



Explanation 1:



In this case, Binary tree will be look like as given above.



Return the pointer of root node of constructed binary tree. In this case root treenode has value '1'.



Sample Test Case 2:



Sample Input 2:



inorder = [3, 2, 1, 5, 4, 6] and preorder = [1, 2, 3, 4, 5, 6]



Sample Output 2:



	1

   / \

 2 4

 / / \

3 5    6

int findIdxInInorder(vector<int> &in, int key, int inS, int inE) {
	for (int i = inS; i <= inE; i++) {
		if (in[i] == key)
			return i;
	}

	return -1;
}

TreeNode* createBinaryTree(vector<int> &in, vector<int> &pre, int inS, int inE, int preS, int preE, unordered_map<int, int> &inMap)
{
	if (inS > inE)
		return NULL;

	TreeNode *cur = new TreeNode(pre[preS]);
	int idx = inMap[pre[preS]];
	int width = idx - inS;
	cur->left = createBinaryTree(in, pre, inS, idx - 1, preS + 1, preS + width, inMap);
	cur->right = createBinaryTree(in, pre, idx + 1, inE, preS + width + 1, preE, inMap);
	return cur;
}

TreeNode* constructBinaryTree(vector<int> inorder, vector<int> preorder) {
	TreeNode* root;
	unordered_map<int, int> inMap;

	if (inorder.size() == 0)
		return NULL;

	for (int i = 0; i < inorder.size(); i++) {
		inMap[inorder[i]] = i;
	}

	root = createBinaryTree(inorder, preorder, 0, inorder.size() - 1, 0, preorder.size() - 1, inMap);
	return root;
}



*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

struct TreeNode {
	int value;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

void printPreOrder(TreeNode* tr) {
	if (tr == NULL) {
		cout << "#";
		return;
	}
	cout << tr->value;
	printPreOrder(tr->left);
	printPreOrder(tr->right);
}

/*
 * Complete the 'constructBinaryTree' function below.
 *
 * The function accepts INTEGER_ARRAY inorder and preorder as parameter and return Root pointer of constructed binary tree.
 *
 * Definition for binary tree
 * struct TreeNode {
 *     int value;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : value(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* constructBinaryTree(vector<int> inorder, vector<int> preorder) {
	// Write your code here

	return NULL;
}

int main() {

	string temp_arr_len;
	getline(cin, temp_arr_len);

	int arr_len = stoi(ltrim(rtrim(temp_arr_len)));

	vector<int> inorder(arr_len);
	vector<int> preorder(arr_len);

	for (int i = 0; i < arr_len; i++) {
		string arr_item_temp;
		getline(cin, arr_item_temp);

		int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

		inorder[i] = arr_item;
	}

	getline(cin, temp_arr_len);
	arr_len = stoi(ltrim(rtrim(temp_arr_len)));

	for (int i = 0; i < arr_len; i++) {
		string arr_item_temp;
		getline(cin, arr_item_temp);

		int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

		preorder[i] = arr_item;
	}

	TreeNode *root = constructBinaryTree(inorder, preorder);

	printPreOrder(root);
	cout << endl;
	return 0;
}

string ltrim(const string &str) {
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
	);

	return s;
}

string rtrim(const string &str) {
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end()
	);

	return s;
}
