/*
Word Wrap



Problem Statement:



Given a sequence of words (strings), and a limit on the number of characters that can be put in one line (line width), put line breaks in the given sequence such that the lines are printed neatly.



The word processors like MS Word do task of placing line breaks. The idea is to have balanced lines. In other words, not have few lines with lots of extra spaces and some lines with small amount of extra spaces.

The extra spaces means spaces put at the end of every line.

Put line breaks such that the following total cost is minimized:



Cost of a line = (Number of extra spaces in the line)^3

Total Cost = Sum of costs for all lines



Each word belong to a single line and no word can be partially in one line and other part in a different line.
Assume that the length of each word is smaller than or equal to the line width.
Extra spaces means spaces put at the end of every line means white spaces between two words need to be ignored.
Two words in a line will have exactly one space in between.
Ignore extra white spaces at the end of last line.
Note that the total cost function is not sum of extra spaces, but sum of cubes of extra spaces.


Input Format



There are two arguments: words and limit, denoting list of words (strings) as mentioned in problem statement and limit on number of characters in a single line.



Output Format



Return the minimum total cost min_cost.



Constraints



1 <= n <= 1000
1 <= limit <= 15000
1 <= length(words[i]) <= limit, for 0 <= i <= (n-1).
words[i] can be composed of [a-z, A-Z], for 0 <= i <= (n-1).


Sample Test Cases



Sample Test Case 1



Sample Input 1



words = [abcdefghijkl, abcdefg, abcdefgh, abcdefghijklmnopqrstuv]

limit = 23



Sample Output 1



result = 1674



Explanation 1



Following arrangement of words in lines will have least cost:

Line1: “abcdefghijkl           ”

Line2: “abcdefg abcdefgh       ”

Line3: “abcdefghijklmnopqrstuv”

Note that we need to ignore the extra white spaces at the end of last line. So, in the last line there will be 0 extra white spaces.

Cost for this configuration:

(23 - 12)^3 + (23 - (7+1+8))^3 + (0)^3 = 1674



Sample Test Case 2



Sample Input 2



words = [omg, very, are, extreme]

limit = 10



Sample Output 2



result = 351



Explanation 2



Following arrangement of words in lines will have least cost:

Line1: “omg very  ”

Line2: “are       ”

Line3: “extreme”

Note that we need to ignore the extra white spaces at the end of last line. So, in the last line there will be 0 extra white spaces.

Cost for this configuration:

(10 - (3+1+4))^3 + (10 - 3)^3 + (0)^3 = 351

int
calculate_cost(int len, int limit) {
	if (len > limit) {
		return -1;
	} else {
		return ( pow(limit - len, 3));
	}
	return -1;
}

long solveBalancedLineBreaks(vector<string> words, int limit) {
	vector<long> dp(words.size(), 0);
	long cost  = 0;

	for (int i = words.size() - 2; i>=0; i--) {
		long min_val  = LONG_MAX;
		int curr_len = 0;
		for (unsigned int j = i;  j< words.size(); j++) {
			if (i!=j) {
				curr_len += 1;
			}
			curr_len += words[j].length();
			if (curr_len > limit) {
				cost = -1;
			} else {
				cost = pow((limit - curr_len),3); // * (limit - curr_len) * (limit - curr_len);
			}
			//cost =calculate_cost(curr_len, limit);
			//cout << "cost " << cost << "\n";

			if (cost >= 0) {
				cost += dp[j+1];
				if (j == words.size()-1) {
					cost = 0;
				}
				min_val = min(min_val, cost);
			}
		}
		//cout << "i" << i << "\n";
		dp[i] = min_val;
	}
	return dp[0];

}

*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
* Complete the 'solveBalancedLineBreaks' function below.
*
* The function accepts STRING ARRAY and INTEGER as parameter.
* Return LONG.
*/

long solveBalancedLineBreaks(vector<string> words, int limit) {

}


int main()
{
	string n_temp;
	getline(cin, n_temp);

	int n = stoi(ltrim(rtrim(n_temp)));

	vector<string> words(n);

	for (int i = 0; i < n; i++) {
		string word;
		getline(cin, word);

		words[i] = word;
	}

	string limit_temp;
	getline(cin, limit_temp);

	int limit = stoi(ltrim(rtrim(limit_temp)));

	ostream &fout = cout;

	long result = solveBalancedLineBreaks(words, limit);

	fout << result << "\n";

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

