/*Longest Substring With Balanced Parentheses

Problem Statement:

Given a string brackets, containing only '(' and ')', you have to find the length of the longest substring that has balanced parentheses.
You need to find length only, not the substring itself.

Input/Output Format For The Function:

Input Format:
There is only one argument in input brackets, denoting input string.

Output Format:
Return an integer res, denoting the length of the longest  substring that has balanced parentheses.

Input/Output Format For The Custom Input:

Input Format:
There should be only one line of input, containing a string brackets, denoting input string of parentheses.

If brackets = “((((())(((()”, then input should be:
((((())(((()

Output Format:
There will be one line, containing an integer res, denoting the result returned by the solution function.

For input brackets = “((((())(((()”, output will be:
4

Constraints:

1 <= | brackets | <= 10^5
Input string only contains '(' and ')' characters.

Sample Test Case 1:

Sample Input 1:
"((((())(((()"

Sample Output 1:
4

Explanation 1:
"(())"

Sample Test Case 2:

Sample Input 2:
"()()()"

Sample Output 2:
6

Explanation 2:
"()()()"

int find_max_length_of_matching_parentheses(string brackets)
{
	int n = brackets.length();
	
	//One observation to make is that, if a matching '(' isn’t found for any ')', then string
	//till ')' can no longer be part of the substring we are looking for. i.e. "(()))()()" now at
	//4th position no maching '(' is found for ')', hence part "(()))" is not needed in further
	//calculations!
	//valid_from variable keeps track of that.
	
	int max_len = 0, valid_from = 0;
	// Stores the indices of the opening brackets.
	stack<int> opening_brackets;
	for (int i = 0; i < n; i++)
	{
		if (brackets[i] == '(')
		{
			// Store the index of opening bracket.
			opening_brackets.push(i);
		}
		else
		{
			// For ')' no matching '(' is found hence update the valid_from variable.
			if (opening_brackets.empty())
			{
				valid_from = i + 1;
			}
			else
			{
				// Remove the matched '('.
				opening_brackets.pop();
				// Try "(())))(())()" and "((((())(((()" to understand the following steps.
				if (opening_brackets.empty())
				{
					
					//In "(())))(())()" when we are at last ')', stack will become empty and
					//valid_from will be at 6th position, so answer that needs to be checked is
					//11 - 6 + 1 = 6 corresponding to "(())()".
					
					max_len = max(max_len, i - valid_from + 1);
				}
				else
				{
					
					//In "((((())(((()" when we are at last ')', stack will contain
					//[0, 1, 21 7, 8, 9], so answer that needs to be checked is 11 - 9 = 2
					//corresponding to "()".
					
					max_len = max(max_len, i - opening_brackets.top());
				}
			}
		}
	}
	return max_len;
}

*/

//#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

/*
 * Complete the function below.
 */
int find_max_length_of_matching_parentheses(string brackets)
{
	std::stack<char> st;
	char o_b = '(';
	int max_count = 0;
	int count = 0;

	if (brackets.length() < 1)
		return 1;

	for (int i = 0; i < brackets.length(); i++)
	{
		if (st.empty())
			st.push(brackets[i]);
		else
		{
			if ((st.top() != brackets[i]) && (st.top() == o_b))
			{
				st.pop();
				count++;
				if (count > max_count) max_count = count;
			}
			else
			{
				st.push(brackets[i]);
				count = 0;
			}
		}
	}

	if (st.empty())
		return brackets.length();
	else
		return (2 * max_count);
}

int main()
{
	ostream &fout = cout;

	int res;
	string brackets;
	getline(cin, brackets);

	res = find_max_length_of_matching_parentheses(brackets);
	fout << res << endl;

	system("pause");
	return 0;
}
