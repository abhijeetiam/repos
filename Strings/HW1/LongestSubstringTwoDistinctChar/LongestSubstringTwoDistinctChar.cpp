/*
Longest Substring With Exactly Two Distinct Characters





Problem Statement:



Given a string s of length n, find the length of the longest substring ss, that contains exactly two distinct characters.

There will be t test cases.



Input/Output Format For The Function:



Input Format:



There is only one argument s, denoting the input string.



Output Format:



Return an integer len, denoting length of ss.

(If there are no such substrings, then return 0)



Input/Output Format For The Custom Input:



Input Format:



The first line of the input should contain an integer t, denoting no. of test cases.

In the next t lines, ith line should contain a string si, denoting an input string s for ith test case.



If t = 3, s for 1st test case = �ababababa�, s for 2nd test case = �e� and s for 3rd test case = �baabcbab�, then input should be:



3

ababababa

e

baabcbab



Output Format:



There will be t lines for output, where ith line contains an integer leni, denoting resultant value len for ith test case.



For input t = 3, s for 1st test case = �ababababa�, s for 2nd test case = �e� and s for 3rd test case = �baabcbab�, output will be:



9

0

4



Constraints:



1 <= t <= 80
1 <= n <= 10^5
s may contain upper case alphabets, lower case alphabets and numerical values.


Sample Test Cases:



Sample Input 1:



2

eceba

abcdef



Sample Output 1:



3

2



Explanation 1:



In first case, 'ece' is the largest substring with exactly 2 distinct characters.

In second case, 'ab' is the largest substring with exactly 2 distinct characters. Also, 'bc', 'cd', 'de', 'ef' can be considered as substring with exactly 2 distinct characters.



Sample Input 2:



3

ababababa

e

baabcbab



Sample Output 2:



9

0

4



Explanation 2:



In first case, whole string 'ababababa' is the largest substring with exactly 2 distinct characters.

In second case, there is no substring with exactly 2 distinct characters.

In third case, 'baab' is the largest substring with exactly 2 distinct characters.

int getLongestSubstringLengthExactly2DistinctChars(string s) {
	int len = s.size();
	int maxLen = 0;
	int right = 0;
	int left = 0;
	map<char,int> cmap;
	while(right < len){
		if(cmap.find(s[right]) != cmap.end())
			cmap[s[right]]++;
		else
			cmap[s[right]] = 1;

		while(cmap.size() > 2){
			cmap[s[left]]--;
			if(cmap[s[left]] == 0){
				cmap.erase(s[left]);
			}
			left++;
		}
		if(cmap.size() == 2){
			maxLen = max(maxLen, right-left+1);
		}
		right++;
	}
	return maxLen;
}

*/

#include <bits/stdc++.h>

using namespace std;

// Complete the getLongestSubstringLengthExactly2DistinctChars function below.
int getLongestSubstringLengthExactly2DistinctChars(string s) {


}

int main()
{
	ostream &fout = cout;

	int q;
	cin >> q;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int i = 0; i < q; ++i)
	{
		string s;
		getline(cin, s);

		int res = getLongestSubstringLengthExactly2DistinctChars(s);

		fout << res << "\n";
	}



	return 0;
}

