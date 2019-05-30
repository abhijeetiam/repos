/*
Cut The Rope



Problem Statement:



Given a rope with length n, find the maximum value maxProduct, that can be achieved for product len[0] * len[1] * ... * len[m - 1], where len[] is the array of lengths obtained by cutting the given rope into m parts.



Note that

there should be atleast one cut, i.e. m >= 2.
All m parts obtained after cut should have non-zero integer valued lengths.


Input/Output Format For The Function:



Input Format:



There is only one argument, an integer denoting n.



Output Format:



Return a number maxProduct, denoting maximum possible product as asked in the problem.



Input/Output Format For The Custom Input:



Input Format:



There should be only one line, containing an integer n, denoting length of rope.



If n = 5, then input should be:



5



Output Format:



There will be one line, containing an integer maxProduct.



For input n = 5, output will be:



6



Constraints:

2 <= n <= 111
We have to cut at least once. (2 <= m).
Length of the rope, as well as the length of each part are in positive integer value. (i.e. can't do partial cuts.)


Sample Test Case:



Sample Input:



4



Sample Output:



4



Explanation:

For n = 4, there are two cuts possible: 1 + 3 and 2 + 2.

We'll pick 2 + 2, because their product 2 * 2 = 4 is greater than product of the first one 1 * 3 = 3.

(So our m = 2, n[0] = 2 and n[1] = 2 and product is n[0] * n[1] = 4.)

long long int max_product_from_cut_pieces(int n) 
{
	vector<long long int> dp(n + 1, 0);
	long long int pmax = 0, maxprod = 0;
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			maxprod = max((long long int)j*(i - j), dp[i - j] * j);
			pmax = max(pmax, maxprod);
		}

		dp[i] = pmax;
		pmax = 0;
	}

	return dp[n];
}

*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the max_product_from_cut_pieces function below.
 */
long long int max_product_from_cut_pieces(int n) {
	/*
	 * Write your code here.
	 */

}

int main()
{
	ostream &fout = cout;

	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	long long int res = max_product_from_cut_pieces(n);

	fout << res << "\n";

	return 0;
}
