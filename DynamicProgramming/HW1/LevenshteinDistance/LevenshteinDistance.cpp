/*
Levenshtein Distance



Problem Statement:



Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)



You have the following 3 operations permitted on a word:



a) Insert a character

b) Delete a character

c) Replace a character



The minimum no of steps required to convert word1 to word2 with the given set of allowed operations is called edit distance.



e.g. Minimum edit distance between the words 'kitten' and 'sitting', is 3.



kitten → sitten (substitution of "s" for "k")

sitten → sittin (substitution of "i" for "e")

sittin → sitting (insertion of "g" at the end)



Read more about edit distance here:

https://en.wikipedia.org/wiki/Edit_distance



Input/Output Format For The Function:



Input Format:



You will be given two strings word1 and word2.



Output Format:



Return an integer editDist, denoting the edit distance between given two input strings.



Input/Output Format For The Custom Input:



Input Format:



The first line should contain a string denoting word1.

The second line should contain a string denoting word2.



If word1 = “cat” and word2 = “bat”, then input should be:



cat

bat



Output Format:



There will be one line, containing an integer editDist, denoting the result returned by solution function.



For input word1 = “cat” and word2 = “bat”, output will be:



1



Constraints:

1 <= length(word1), length(word2) <= 1000
word1 and word2 contains lower case alphabets from a to z.


Sample Test Cases:



Sample Test Case 1:



Sample Input 1:



cat

bat



Sample Output 1:



1



Explanation 1:



1: Replace c with b.



Sample Test Case 2:



Sample Input 2:



qwe

q



Sample Output 2:



2



Explanation 2:



1: Add w

2: Add e

int levenshteinDistance(const string& s1, const string& s2)
{
	int rows{static_cast<int>(s1.size())};
	int cols{static_cast<int>(s2.size())};

	vector<vector<int>> table(rows+1, vector<int>(cols+1, 0));

	for(int i{rows}; i >= 0; --i)
		table[i][cols] = rows - i;

	for(int j{cols}; j >= 0; --j)
		table[rows][j] = cols - j;

	for(int i{rows-1}; i >= 0; --i)
		for(int j{cols-1}; j >= 0; --j)
		{
			if(s1[i] == s2[j])
				table[i][j] = table[i+1][j+1];
			else
				table[i][j] = std::min(std::min(table[i][j+1], table[i+1][j]), table[i+1][j+1]) + 1;
		}

	return table[0][0];
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
#include <unordered_map>

using namespace std;


/*
 * Complete the function below.
 */
int levenshteinDistance(string strWord1, string strWord2) {


}


int main() {
	ostream &fout = cout;
	int res;
	string _strWord1;
	getline(cin, _strWord1);

	string _strWord2;
	getline(cin, _strWord2);

	res = levenshteinDistance(_strWord1, _strWord2);
	fout << res << endl;


	return 0;
}