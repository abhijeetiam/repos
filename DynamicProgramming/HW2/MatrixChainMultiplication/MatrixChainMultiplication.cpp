/*
Matrix Chain Multiplication



Problem Statement:



Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications.



We have many options to multiply a chain of matrices because matrix multiplication is associative. In other words, no matter how we parenthesize the product, the result will be the same. For example, if we had four matrices A, B, C, and D, we would have:



(ABC)D = (AB)(CD) = A(BCD) = ....



However, the order in which we parenthesize the product affects the number of simple arithmetic operations needed to compute the product, or the efficiency. For example, suppose A is a 10 × 30 matrix, B is a 30 × 5 matrix, and C is a 5 × 60 matrix. Then,



(AB)C = (10×30×5) + (10×5×60) = 1500 + 3000 = 4500 operations



A(BC) = (30×5×60) + (10×30×60) = 9000 + 18000 = 27000 operations.



Clearly, the first parenthesization requires less number of operations.



Given an array mtxSizes[], which represents the chain of matrices such that the ith matrix Ai is of dimension mtxSizes[i-1] x mtxSizes[i], we need to write a function that should return the minimum number of multiplications needed to multiply the chain. Length of chain of matrices is n, and thus size of mtxSizes is (n+1).



Input/Output Format For The Function:



Input Format:



You will be given an integer array mtxSizes.



Output Format:



Return an integer minOps, denoting the minimum number of operations needed.



Input/Output Format For The Custom Input:



Input Format:



The first line of input should contain a number, denoting the size of mtxSizes, which is (n+1).

In next (n+1) lines, ith line should contain ith entry of mtxSizes, i=(1,...,n+1).



If n = 4 and mtxSizes = [10, 30, 5, 60], then input should be:



4

10

30

5

60



Output Format:



There will be one line, containing an integer minOps, denoting the result returned by solution function.



For input n = 4 and mtxSizes = [10, 30, 5, 60], output will be:



4500



Constraints:



3 <= len(mtxSizes) <= 100
0 <= mtxSizes[i] <= 100
For any matrix, either both the dimensions will be zero, or both the dimensions will be non zero.


Sample Test Case:



Sample Input:



4

10

30

5

60



Sample Output:



4500



Explanation:



As explained in problem statement section.

int minMultiplicationCost(vector < int > mtxSizes) {
	// 12:25
	// dp[i][j] = min cost to multiply matrices i to j, i & j inclusive.
	//          = min over all k between i & j (dp[i][k] + dp[k+1][j] + mtxSize[i]*mtxSizes[k+1]*mtxSizes[j+1])
	//          = 1 if i == j
	int n = mtxSizes.size();
	int result = 0;
	if (n <= 2)
		return 0;
	vector<vector<int>> dp(n - 1, vector<int>(n - 1, 0));
	for (int gap = 1; gap < n - 1; gap++) {
		for (int i = 0; i < n - 1 - gap; i++) {
			int j = i + gap;
			dp[i][j] = INT_MAX;
			for (int k = i; k < j; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + mtxSizes[i] * mtxSizes[k + 1] * mtxSizes[j + 1]);
			}
		}
	}
	return dp[0][n - 2];

}

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

using namespace std;

/*
 * Complete the function below.
 */
int minMultiplicationCost(vector < int > mtxSizes) {


}


int main() {
	ostream &fout = cout;
	int res;

	int _mtxSizes_size = 0;
	cin >> _mtxSizes_size;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	vector<int> _mtxSizes;
	int _mtxSizes_item;
	for (int _mtxSizes_i = 0; _mtxSizes_i < _mtxSizes_size; _mtxSizes_i++) {
		cin >> _mtxSizes_item;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		_mtxSizes.push_back(_mtxSizes_item);
	}

	res = minMultiplicationCost(_mtxSizes);
	fout << res << endl;


	return 0;
}
