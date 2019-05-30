/*
Lexicographical Order



Problem Statement:



You are given a string array named arr, of size N, containing KEYS and VALUES separated by a space.



Your task is to find, for each unique KEY, the number of VALUES with that key and the VALUE with the highest lexicographical order (also called alphabetical order OR dictionary order).



(Have a look at the sample test cases for more clarity.)



Input/Output Format For The Function:



Input Format:



There is only one argument: String array arr.



Output Format:



Return a string array res, with an entry for each unique key. Each entry should contain key, number of values corresponding to that key and value with the highest lexicographical order in the below format:



"<KEY>:<COUNT>,<HIGHEST_LEXICOGRAPHICAL_VALUE>"



Order of the output does not matter.



Input/Output Format For The Custom Input:



Input Format:



The first line of input should contain an integer N, denoting size of input array arr. In next N lines, ith line should contain a string arr[i], denoting a value at index i of arr.



If N = 5 and arr = [“key1 abcd”, “key2 zzz”, “key1 hello”,

“key3 world”, "key1 hello"], then input should be:



5

key1 abcd

key2 zzz

key1 hello

key3 world

key1 hello



Output Format:



There will be N lines of output, where ith line contains a string res[i], denoting value at index i of res.

Here, res is the result array returned by solution function.



For input N = 5 and arr = [“key1 abcd”, “key2 zzz”, “key1 hello”,

“key3 world”, "key1 hello"], output will be:



key3:1,world

key2:1,zzz

key1:3,hello



Constraints:

1 <= N <= 10^4
1 <= Length(KEYS) <= 256
1 <= Length(VALUES) <= 800
KEYS can repeat.
VALUES can repeat.
Keys and values will contain only lower case letters and numerics.


Sample Test Case:



Sample Test Case 1:



Sample Input 1:



arr = [

   “key1 abcd”,

   “key2 zzz”,

   “key1 hello”,

   “key3 world”,

   "key1 hello"

]



Sample Output 1:



One possible output (you can return strings in any order):



[

   "key1:3,hello",

   "key2:1,zzz",

   "key3:1,world"

]



Sample Test Case 2:



Sample Input 2:



arr = [

   “mark zuckerberg”,

   “tim cook”,

   “mark twain”

]



Sample Output 2:



One possible output (you can return strings in any order):



[

   "mark:2,zuckerberg",

   "tim:1,cook"

]


vector<string> solve(vector<string> arr) 
{
	vector<string>::reverse_iterator it;
	string str, key, val;
	int cnt, pos;
	vector<string> res;
	stringstream ss;

	if (arr.size() == 0)
	return res;

	std::sort(arr.begin(), arr.end());

	for (it = arr.rbegin(); it != arr.rend(); ++it) {
		str = *it;
		pos = str.find(" ");
		if (key != str.substr(0, pos)) {
			if (key != "") {
				ss << key << ":" << cnt << "," << val;
				res.push_back(ss.str());
				ss.str("");
			}
			key = str.substr(0, pos);
			val = str.substr(pos + 1);
			cnt = 1;
		}
		else {
			cnt++;
		}
	}
	ss << key << ":" << cnt << "," << val;;
	res.push_back(ss.str());
	return res;
}

*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the solve function below.
 */
vector<string> solve(vector<string> arr) {
	/*
	 * Write your code here.
	 */

}


int main()
{
	ostream &fout = cout;

	int arr_count;
	cin >> arr_count;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<string> arr(arr_count);

	for (int arr_itr = 0; arr_itr < arr_count; arr_itr++) {
		string arr_item;
		getline(cin, arr_item);

		arr[arr_itr] = arr_item;
	}

	vector<string> res = solve(arr);

	for (int res_itr = 0; res_itr < res.size(); res_itr++) {
		fout << res[res_itr];

		if (res_itr != res.size() - 1) {
			fout << "\n";
		}
	}

	fout << "\n";



	return 0;
}


