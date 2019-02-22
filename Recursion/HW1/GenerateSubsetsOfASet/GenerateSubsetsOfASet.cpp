/*
Generate All Subsets Of A Set



Problem Statement:



Given a set (in form of string s containing only distinct lowercase letters ('a' - 'z')), you have to generate ALL possible subsets of it .



Note that:

empty set is always a subset of any set.
whole set s should also be considered as its subset here.


Input/Output Format For The Function:



Input Format:



There is only one argument denoting string s.



Output Format:



Return array of strings res, containing ALL possible subsets of given string.



You need not to worry about order of strings in your output array. E.g. s = "a", arrays ["", "a"] and ["a", ""]  both will be accepted.



Order of characters in any subset must be same as in the input string. For s = "xy", array ["", "x", "y", "xy"] will be accepted, but ["", "x", "y", "yx"] will not be accepted.



Input/Output Format For The Custom Input:



Input Format:



The first and only line of input should contain a string s, denoting the input string.



If s = “xy”, then input should be:



xy



Output Format:



Let’s denote the size of res as m, where res is the resultant array of strings returned by the solution function.

Then, there will be m lines of output, where ith line contains string at index i of res.



For input s = “xy”, output will be:

----------- START of output -----------



x

y

xy

----------- END of output ---------------

(Note that the first line of output is an empty line, corresponding to empty set [“”].)



Constraints:

﻿﻿﻿

0 <= |s| <= 20
s only contains distinct lowercase alphabetical letters ('a' - 'z').


Sample Test Cases:



Sample Input:



"xy"



Sample Output:



["", "x", "y", "xy"]



Notes:



Suggested time in interview: 20 minutes

The “Suggested Time” is the time expected to complete this question during a real-life interview, not now in homework i.e. For the first attempt of a given homework problem, the focus should be to understand what the problem is asking, what approach you are using, coding it, as well as identifying any gaps that you can discuss during a TC session. Take your time, but limit yourself to 2 one hour sessions for most problems.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void GenerateSubsets(string str, string output, vector<string>& res)
{
	int i = 0;
	if (str.length() == 0)
	{
		res.push_back(output);
		return;
	}

	GenerateSubsets(str.substr(i + 1), output, res);
	output += str[i];
	GenerateSubsets(str.substr(i + 1), output, res);
}

/*
 * Complete the function below.
 */
vector <string> generate_all_subsets(string s)
{
	vector<string> res;
	string output;

	GenerateSubsets(s, output, res);
	return res;
}

int main()
{
	ostream &fout = cout;

	vector <string> res;
	string s;
	getline(cin, s);

	res = generate_all_subsets(s);
	for (int res_i = 0; res_i < res.size(); res_i++) {
		fout << res[res_i] << endl;;
	}

	system("pause");
	return 0;
}
