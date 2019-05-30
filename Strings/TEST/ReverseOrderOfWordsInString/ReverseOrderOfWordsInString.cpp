/*
Reverse The Ordering Of Words In A String



Problem Statement:



Given a string s containing a set of words, transform it such that the words appear in the reverse order. Words in s are separated by one or more spaces.

(See sample test cases for further clarifications.)



Input/Output Format For The Function:



Input Format:



There is only one argument denoting string s.



Output Format:



Return a string res, containing your answer.



Input/Output Format For The Custom Input:



Input Format:



The first and only line of input should contain a string s, denoting an input string.



If s = “I will do it.”, then input should be:



I will do it.



Output Format:



There will be one line, containing a string res, denoting the result value returned by solution function.



For input s = “I will do it.”, output will be:



it. do will I



Constraints:

1 <= |s| <= 10^5
s will contain characters only from lowercase alphabetical letters, uppercase alphabetical letters, space or punctuation marks. More specifically s will be made from string (double quotes excluded): ".,?!':;-aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ".
Punctuation mark is part of the word.
Usage of inbuilt string functions is NOT allowed.
An in-place linear solution is expected.
For languages that have immutable strings, convert the input string into a Character Array and work in-place on that array. Convert it back to the string before returning. (For the purpose of this problem, ignore the extra linear space used in that conversion, as long as you're only using constant space after conversion to character array.)


Sample Test Cases:



Sample Test Case 1:



Sample Input 1:



“I will do it.”



Sample Output 1:



“it. do will I”



Sample Test Case 2:



Sample Input 2:



"   word1  word2 " (Note: there are 3 spaces in the beginning, 2 spaces between the words and 1 space at the end.)



Sample Output 2:



" word2  word1 " (Note: there is 1 space in the beginning, 2 spaces between the words and 3 spaces at the end.)



Sample Test Case 3:



Sample Input 3:



"word1, word2;"



Sample Output 3:



"word2; word1,"



[Trivia: This is a very old interview question, which Google used last year as one of their qualifier questions in Google CodeJam]

void reverse_string(char *str, int len)
{
	for(int i = 0; i < len / 2; i++)
	{
		swap(str[i], str[len - 1 - i]);
	}
}

string reverse_ordering_of_words(string s)
{
	int len = s.length();
	// Reverse whole string.
	reverse_string(&s[0], len);
	int word_beginning = 0;
	// Find word boundaries and reverse word by word.
	for(int word_end = 0; word_end < len; word_end++)
	{
		if(s[word_end] == ' ')
		{
			reverse_string(&s[word_beginning] , word_end - word_beginning);
			word_beginning = word_end + 1;
		}
	}
	
	//If there is no space at the end then last word will not be reversed in the above for loop.
	//So need to reverse it.
	//Think about s = "hi".
	//Reverse the last word.
	
	reverse_string(&s[word_beginning], len - word_beginning);
	return s;
}

*/

#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the reverse_ordering_of_words function below.
 */
string reverse_ordering_of_words(string s) {
	/*
	 * Write your code here.
	 */

}


int main()
{
	ostream &fout = cout;

	string s;
	getline(cin, s);

	string res = reverse_ordering_of_words(s);

	fout << res << "\n";



	return 0;
}



