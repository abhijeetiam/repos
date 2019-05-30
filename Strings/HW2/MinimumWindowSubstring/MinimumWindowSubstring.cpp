/*
Minimum Window Substring


Problem Statement:



You are given an alphanumeric string ‘s’ and an alphanumeric string ‘t’. Find the minimum window (substring) in s which will contain all the characters of t.



Input/Output Format For The Function:



Input Format:



There are 2 arguments in the input, a string named s and a string named t.



Output Format:



Return a string result, which is the minimum window (substring) in string s that contains all characters of string t.

If no such window exists, then return an “-1” string and if there are multiple minimum windows of the same length, then return leftmost window.



Input/Output Format For The Custom Input:



Input Format:



The first line of input contains string s. The next line contains string t.



If s = “azisdflc” and t = “zsd” then input should be:



azisdflc

zsd



Output Format:



Output in a single line a string which is the minimum window that contains all the characters of string t.



For input s = “azisdflc” and t = “zsd”, output will be:


zisd



Constraints:

1 <= lenght(s) <= 100000
1 <= length(t) <=100000


Sample Test Cases:



Sample Test Case 1:



Sample Input 1:



AYZABOBECODXBANC

ABC



Sample Output 1:



BANC



Explanation 1:



The minimum window is "BANC", which contains all letters - A B and C. We cannot find a window of smaller length than “BANC”.



Sample Test Case 2:



Sample Input 2:



BACRDESDFBAER

BAR



Sample Output 2:



BACR



Explanation 2:



Here, we can see that there are 2 smallest windows - “BACR” and “BAER”. However, the output is “BACR” because it is the leftmost one.


string minimum_window(string s, string t) {
	string minWindow = "-1";

	if (t.length() == 0) {
		return s;
	}

	if ( s.length() < t.length() ) {
		// Return an empty string?
		return minWindow;
	}

	// We can represent this as a simple int array where
	// the counts of each character occurrence are stored.  No
	// need for a hashmap here.
	vector<int> patternChars(256, 0);
	vector<int> stringChars(256, 0);

	// First add all the chars from the substring to the
	// map with counts.
	for (int i = 0; i < (int)t.length(); i ++) {

		char currentChar = t[i];
		patternChars[currentChar] ++;

	}


	int count = 0;

	int left = 0;
	int leftIndex = -1;
	int minWindowLength = INT_MAX;

	for (int i = 0; i < (int)s.length(); i++) {

		char currentStrChar = s[i];

		// Add this char to the vector of input string characters.
		stringChars[currentStrChar] ++;

		// Is this string char in our pattern array?
		if (patternChars[currentStrChar] > 0 &&
			stringChars[currentStrChar] <= patternChars[currentStrChar]) {

			count ++;
		}

		// If our count reaches the length of t, then we've found
		// a window.  Determine whether we can eliminate any characters
		// from the input string starting from the left - these characters
		// are either ones that aren't in the pattern (1) or the input string has more
		// occurrences of the given character than the pattern (2)
		if (count == (int)t.length() ) {

			// The candidate for removal - really unnecessary to easier
			// to debug...

			int candidate = s[left];

			while (stringChars[candidate] > patternChars[candidate] ||
				   patternChars[candidate] == 0 ) {

				// If it's case 2, decrement the count and at the
				// same time, move the left index by 1.
				if (stringChars[candidate] > patternChars[candidate]) {
					stringChars[candidate] --;
				}

				left++;

				// Move onto the next candidate.
				candidate = s[left];
			}

			// Update the current minimum window.
			int currentMin = i - left + 1;
			if (minWindowLength > currentMin ) {

				minWindowLength = currentMin;
				leftIndex = left;
			}
		}
	}

	if (leftIndex == -1) {
		return minWindow;
	}

	minWindow = s.substr(leftIndex, minWindowLength);
	return minWindow;

}


*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'minimum_window' function below.
 *
 * The function accepts STRING s and STRING t as parameter.
 */

string minimum_window(string s, string t) {

}


int main()
{
	ostream &fout = cout;

	string s;

	string t;

	getline(cin, s);
	getline(cin, t);

	string result = minimum_window(s, t);

	fout << result << "\n";

	return 0;
}




