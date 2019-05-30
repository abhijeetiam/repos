/*
How Many Binary Search Trees With n Nodes?

Problem Statement:

Write a function that will return the number of binary search trees that can be constructed with n nodes.

There may be other iterative solutions, but for the purpose of this exercise, please use recursive solution.

The purpose of this problem is to learn recursion and not DP. So, you must write at least one recursive solution. After that, you can write a DP solution if you want.

Input/Output Format For The Function:

Input Format:

There is only one argument denoting integer n.

Output Format:

Return number of binary search trees that can be constructed, with n nodes.

Input/Output Format For The Custom Input:

Input Format:

The first and only line of input should contain an integer n.

If n = 3, then input should be:

3

Output Format:

There will be one line, containing an integer res, denoting the result returned by solution function.

For input n = 3, output will be:

5

Constraints:
1 <= n <= 16

Sample Test Cases:

Sample Test Case 1:

Sample Input 1:

1

Sample Output 1:

1

Explanation 1:

1) root (node val = 1)

Sample Test Case 2:

Sample Input 2:

2

Sample Output 2:

2

Explanation 2:

1) root (node val = 2), root->left (node val = 1)
2) root (node val = 1), root->right (node val = 2)

Sample Test Case 3:

Sample Input 3:

3

Sample Output 3:

5

Explanation 3:

1) root (node val = 3), root->left (node val = 2), root->left->left (node val = 1)
2) root (node val = 3), root->left (node val = 1), root->left->right (node val = 2)
3) root (node val = 1), root->right (node val = 2), root->right->right (node val = 3)
4) root (node val = 1), root->right (node val = 3), root->right->left (node val = 2)
5) root (node val = 2), root->left (node val = 1), root->right (node val = 3)

If you keep doing this, it will form a series called Catalan numbers. One can simply lookup the formula for Catalan numbers and write code for it. But that's not how we want to do this. We want to do this by understanding the underlying recursion. The recursion is based on tree-topology only, as you can see by examples above, contents of the nodes of the tree do not matter.
 
 int numTrees(int n, vector<int>& memory) 
 {
	if (n == 0)
		return 1;

	if ( n == 1)
		return 1;

	if (memory[n] != -1)
		return memory[n];

	int total = 0;
	for (int i = 0; i < n; ++i)
	{
		total += numTrees(i, memory) * numTrees(n - i - 1, memory);
	}

	memory[n] = total;

	return total;
}

long long int how_many_BSTs(int n) {
	vector<int> memory(n+1, -1);
	return numTrees(n, memory);
}

*/

#include <iostream>
#include <unordered_map>

using namespace std;

/*
 * Complete the function below.
 */
long long int how_many_BSTs(int n) 
{
	long long int nBSTCount = 0;

	if ((n == 0) || (n == 1)) return 1;						//Base cases for number of BST in case of 0,1,2 nodes
	if (n == 2) return 2;

	for (int i = 1; i <= n; i++)							//Loop through all n nodes from 1 --> n
	{
		nBSTCount += how_many_BSTs(i - 1) * how_many_BSTs(n - i);		//For node 'i', Left BST will contain (i-1) nodes and Right BST will contain (n-i) nodes
	}																	//So we keep recursing until base cases are met
	return nBSTCount;
}

long long int how_many_BSTs_memoized(int n, vector<int>& memory)
{
	long long int nBSTCount = 0;

	if(memory[n] > -1)
		return memory[n];

	if ((n == 0) || (n == 1)) return 1;
	if (n == 2) return 2;

	for (int i = 1; i <= n; i++)
	{
		nBSTCount += how_many_BSTs_memoized(i - 1, memory) * how_many_BSTs_memoized(n - i, memory);
	}

	memory[n] = nBSTCount;					//In this memoized version we store the count for upto the ith node and use it if available to avoid unecessary recursion

	return nBSTCount;
}

int main()
{
	ostream &fout = cout;

	long long int res;
	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<int> memory(n+1, -1);		//Used to initialize a vector of size (n+1) with value -1. This is used to store in memory the count of BST for upto n nodes

	//res = how_many_BSTs(n);					//Recursive version
	res = how_many_BSTs_memoized(n, memory);	//Recursive with Memoization version
	fout << res << endl;

	system("pause");
	return 0;
}
