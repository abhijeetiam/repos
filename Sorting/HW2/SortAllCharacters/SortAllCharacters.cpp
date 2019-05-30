/*
Sort All Characters


Problem Statement:



You have to sort an array of characters containing alphanumeric characters along with some other characters - ‘!’, ’@’, ’#’, ’$’, ’%’, ’^’, ’&’, ’*’, ’(‘, ’)’. You are given a character array named arr.



Input/Output Format For The Function:



Input Format:

There is only one argument in input, a character array named arr.



Output Format:

Return a character array result, containing characters in sorted order of their ASCII values. You can overwrite the existing array.



Input/Output Format For The Custom Input:



Input Format:

The first line contains the size, n, of the character array. Next n lines each contain the characters present in the array, with each character of the array in a new line.



If arr = {a,z,i,#,&,l,c} then input should be:



7

a

z

i

#

&

l

c



Output Format:



Output each character of the array on a new line, in sorted order of their ASCII values.



For above input - arr = {a,z,i,#,&,l,c}, output will be:



#

&

a

c

i

l

z



Constraints:

1 <= length(arr) <= 100000


Sample Test Case:



Sample Input:



10

a

s

d

f

g

*

&

!

z

y



Sample Output:



!

&

*

a

d

f

g

s

y

z



Explanation:

Ascii values of the characters present in the character array are:

a: 97, s: 115, d: 100, f: 102, g: 103, *: 42, &: 38, !: 33, z: 122, y: 121.

Now sorting them according to their ascii values results in the given output.


vector<char> sort_array(vector<char> inString) {
	vector<int> counts(256, 0);

	for (auto elem:inString)
		counts[elem]++;

	vector<char> ans;

	for (int i = 0; i < counts.size(); i++) {
		while (counts[i]) {
			ans.push_back(i + '\0');
			counts[i]--;
		}
	}

	return ans;
}


*/

#include <bits/stdc++.h>


using namespace std;


string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'sort_array' function below.
 *
 * The function accepts Character array arr as parameter.
 */

vector<char> sort_array(vector<char> arr) {


}


int main()
{
	ostream &fout = cout;

	string arr_count_temp;
	getline(cin, arr_count_temp);

	int str_count = stoi(ltrim(rtrim(arr_count_temp)));

	vector<char> arr(str_count);

	for (int i = 0; i < str_count; i++) {
		string arr_item_temp;
		getline(cin, arr_item_temp);

		char arr_item = arr_item_temp[0];

		arr[i] = arr_item;
	}

	vector<char> result = sort_array(arr);

	for (int i = 0; i < result.size(); i++) {
		fout << result[i];

		if (i != result.size() - 1) {
			fout << "\n";
		}
	}

	fout << "\n";


	return 0;
}


string ltrim(const string &arr) {
	string s(arr);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
	);

	return s;
}

string rtrim(const string &arr) {
	string s(arr);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end()
	);

	return s;
}

