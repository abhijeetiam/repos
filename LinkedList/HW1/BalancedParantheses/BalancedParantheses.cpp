/*Longest Substring With Balanced Parentheses
#include <iostream>
#include <stack>
#include <string>

using namespace std;
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