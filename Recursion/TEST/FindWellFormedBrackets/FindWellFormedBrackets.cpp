/*
Find All Well Formed Brackets



Problem Statement:



Given a positive integer n, find ALL well formed round brackets string of length 2*n.



The purpose of this problem is to learn recursion and not DP. So, you must write at least one recursive solution. After that, you can write a DP solution if you want.



Input/Output Format For The Function:



Input Format:



There is only one argument denoting integer n.



Output Format:



Return array of strings res, containing all possible well formed round brackets string. (Length of each string will be 2*n).



You need not to worry about the order of strings in res.

E.g. For n = 2, ["(())", "()()"] or ["()()", "(())"], both will be accepted.



Input/Output Format For The Custom Input:



Input Format:



There should be one line for input, containing an integer n.



If n = 3, then input should be:



3



Output Format:



Let’s denote the size of res is m, where res is the resultant array of string returned by the solution function.

Then, there will be m lines of output, where ith line contains res[i], denoting string at index i of res.



For input n = 3, output will be:



((()))

(()())

(())()

()(())

()()()



Constraints:



1 <= n <= 13
Only use round brackets. '(' and ')'.


Sample Test Case:



Sample Input:



3



Sample Output:



[

   "((()))",

   "(()())",

   "(())()",

   "()(())",

   "()()()"

]



(This is one of the possible outputs. Array containing these five string in any order, will be accepted.)


void find_all_well_formed_brackets(vector<string>& results, string& prefix, int l, int r, int k)
{
	if(l == k && r == k)
	{
		results.push_back(prefix) ;
		return;
	}

	int next{l + r};

	if (l < k)
	{
		prefix[next] = '(';
		find_all_well_formed_brackets(results, prefix, l+1, r, k);
	}
	if(l > r )
	{
		prefix[next] = ')';
		find_all_well_formed_brackets(results, prefix, l, r+1, k);
	}
}

vector<string> find_all_well_formed_brackets(int n)
{
	vector<string> results;
	string prefix(2*n, 0);
	find_all_well_formed_brackets(results, prefix, 0, 0,n) ;
	return results ;
}


*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */
vector <string> find_all_well_formed_brackets(int n) {

}

int main()
{
	ostream &fout = cout;

	vector <string> res;
	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	res = find_all_well_formed_brackets(n);
	for (int res_i = 0; res_i < res.size(); res_i++) {
		fout << res[res_i] << endl;;
	}


	return 0;
}
