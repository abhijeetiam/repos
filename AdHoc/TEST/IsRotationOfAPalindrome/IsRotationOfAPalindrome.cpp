/*
Is It A Rotation Of A Palindrome?



Problem Statement:



Given a string s of length N containing only lower case letters (a - z), we have to check if it is a rotation of some palindromic string or not.



Input/Output Format For The Function:



Input Format:



There is only one argument denoting string s.



Output Format:



Return one integer res. Return 1 if given string s is a rotation of some palindromic string else return 0.



Input/Output Format For The Custom Input:



Input Format:



There should be one line, containing input string s.



If s = “aab”, then input should be:



aab



Output Format:



There will be one line, containing the returned integer res.



For input s = “aab”, output will be:



1



Constraints:

1 <= N <= 4000
s will only contain lower case letters (a - z).
String may or may not be sorted.


Sample Test Case:



Sample Input:



aab



Sample Output:



1



Explanation:



Given string aab is a rotation of palindromic string aba. Right rotation on aba will give aab.



Notes:



Expected solution is O(N ^ 2). That will be very easy to write in an interview.



Maximum time allowed in interview: 20 Minutes.



Python: If getting run time error then try to use iterative version to check if string is a palindrome or not.


 bool isPalindrome(string str){
	 int l=0, r = str.length()-1;
	 while(l<=r){
		 if(str[l] != str[r])
			return false;
		l++;r--;

	 }
	 return true;
 }
int check_if_rotated(string s) 
{

	if (isPalindrome(s)) {
		return 1;
	}

	for (int i = 0; i < s.length(); ++i) 
	{
		string s1 = s.substr(0, i + 1);
		string s2 = s.substr(i + 1, s.length() - i - 1);

		if (isPalindrome(s2 + s1)) {
			return 1;
	}
}

return 0;

}

*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the check_if_rotated function below.
 */
int check_if_rotated(string s) {
	/*
	 * Write your code here.
	 */

}


int main()
{
	ostream &fout = cout;

	string s;
	getline(cin, s);

	int res = check_if_rotated(s);

	fout << res << "\n";

	return 0;
}



