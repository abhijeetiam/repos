/*
Kth Smallest Element Of BST



Problem Statement:



Given a BST (binary search tree), of size N, containing integer elements, and an integer k, you have to find kth smallest element of given BST.



Input/Output Format For The Function:



Input Format:



There are two arguments in the input. First one is the root of the BST and second one is an integer k.



Output Format:



Return an integer kmin, denoting kth smallest element of BST.



Input/Output Format For The Custom Input:



Input Format:



The first line of input should contain an integer N, denoting size of input array arr. In next N lines, ith line should contain an integer arr[i], denoting a value at index i of arr.

Input BST will be constructed by inserting elements of array arr to an empty BST in order arr[0], arr[1], …, arr[N-1].



If n = 3, k = 3 and arr = [1, 2, 3], then input should be:



3

2

3

1

3



Output Format:



There will be one line of output, containing an integer kmin, denoting the result returned by solution function.



For input n = 3, k = 3 and arr = [1, 2, 3], output will be:



3



Constraints:

1 <= N <= 6000
1 <= k <= N
-2 * 10^9 <= value stored in any node <= 2 * 10^9
BST need not to be balanced.
You are not allowed to alter the structure or data inside the given BST.


Sample Test Case:



Sample Input:



BST =

2 is the root node.

1 is 2's left child.

3 is 2's right child.



k = 3



Sample Output:



3



Explanation:



3rd smallest element is 3.



Notes:

Maximum time allowed in interview: 20 Minutes.

int inorderCount(TreeNode* n, int k, int count_sofar, int& out_value) {
	if (n == nullptr) return 0;

	int left_count = inorderCount(n->left_ptr, k, count_sofar, out_value);
	if (count_sofar + left_count > k) return left_count;
	left_count++;
	//cout << "Count = "  << left_count << " val=" << n->val << endl;
	if (count_sofar + left_count == k) out_value = n->val;
	return inorderCount(n->right_ptr, k, count_sofar + left_count,out_value) + left_count;
}

int kth_smallest_element(TreeNode* root, int k) {
	int kth_smallest = 0;
	inorderCount(root, k, 0, kth_smallest);
	return kth_smallest;
}


*/

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 6000, MAX_VAL = 2000000000;

struct TreeNode
{
	int val;
	TreeNode* left_ptr;
	TreeNode* right_ptr;

	TreeNode(int _val = 0)
	{
		val = _val;
		left_ptr = NULL;
		right_ptr = NULL;
	}
};

TreeNode* bst_insert(TreeNode* root, int val)
{
	if (root == NULL)												// destination.
	{
		return new TreeNode(val);
	}
	if (val <= root->val)											// element is <= hence insert it in left subtree.
	{
		root->left_ptr = bst_insert(root->left_ptr, val);			// if root->left_ptr is null then new TreeNode will be created and root->left_ptr is assigned its address else it will be assigned to the same value as previouly stored.
	}
	else  															// element is > hence insert it in right subtree.
	{
		root->right_ptr = bst_insert(root->right_ptr, val);			// if root->right_ptr is null then new TreeNode will be created and root->right_ptr is assigned its address else it will be assigned to the same value as previouly stored.
	}
	return root;
}


/*
 * Complete the function below.
 */

 /*
	 For your reference.

	 struct TreeNode
	 {
		 int val;
		 TreeNode* left_ptr;
		 TreeNode* right_ptr;

		 TreeNode(int _val = 0)
		 {
			 val = _val;
			 left_ptr = NULL;
			 right_ptr = NULL;
		 }
	 };
 */

int kth_smallest_element(TreeNode* root, int k) {

}


int main()
{
	ostream &fout = cout;

	int N;
	cin >> N;
	assert(1 <= N);
	assert(N <= MAX_N);
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	TreeNode* root = NULL;

	for (int i = 0; i < N; i++)
	{
		int data;
		cin >> data;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		assert(-MAX_VAL <= data);
		assert(data <= MAX_VAL);

		root = bst_insert(root, data);
	}

	int k;
	cin >> k;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	assert(1 <= k);
	assert(k <= k);

	int ans = kth_smallest_element(root, k);
	fout << ans << endl;


	return 0;
}

