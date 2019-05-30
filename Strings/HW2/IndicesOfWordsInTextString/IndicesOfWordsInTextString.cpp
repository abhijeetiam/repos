/*
Indices Of Words In Text String



Problem Statement:



You are given a text string and q words. For all q words, You need to find out all words from text string which are matching with given word.



Input Format:



Two arguments. First is text string and second is list of words.



Output Format:



Return List of q lists, where ith list contains indices of first character of all the matching words in text string, for words[i], in sorted order.

If no word found in text string for given word then have -1 as only element of answer list for that word.



Constraints:



Text string and words of query can contain characters from a-z, A-Z, 0-9 and symbols from set {'$', '#', '@', '?' ,';'}. Additionally text string can contain spaces also.
Assume words in text string are single space separated. text string starts and ends with a word, not space(s). There will be no consecutive spaces in text string.
1 <= len(text) <= 1000000.
1<= q <= 100000.
Length of any word of query and text string l, 1<= l <= 10.
Every query word will be unique.
Consider indexing of character in text string from 0.
Returned list of indices must be sorted in increasing order.


Sample Test Case:



Sample Input:



text = “you are very very smart”

words = [“you”, “are”, “very”, “handsome”]



Sample Output:



[

[0],

[4],

[8, 13],

[-1]

]



Explanation:



For given text string = “you are very very smart”. “you” is matching with first word “you” which is starting from index 0 of text string so answer for “you” will be 0.

Similarly for “are” answer is 4.

“very” is matching with word at index 8 and 13 so answer for “very” will be 8 and 13.

“handsome” is not matching with any word so it’s answer is -1;

vector<vector<int>> find_words(string& text, vector<string>& words)
{
	unordered_map<string, vector<int>> umap;

	int i = 0, start = 0;
	while (i < text.length()) {
		while (i < text.length() && text[i] != ' ') {
			i++;
		}
		string w = text.substr(start, i - start);
		umap[w].push_back(start);

		while (i < text.length() && text[i] == ' ') {
			i++;
		}
		start = i;
	}
	vector<vector<int>> result;
	for (const auto& e: words) {
		if (umap.find(e) == umap.end()) {
			result.push_back(vector<int>{-1});
		} else {
			result.push_back(umap[e]);
		}
	}
	return result;
}

*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


/*
* Complete the 'find_words' function below.
*
* The function accepts STRING and STRING ARRAY as parameter.
* Return 2D INTEGER ARRAY.
*/
vector<vector<int>> find_words(string text, vector<string> words)
{
	// Write your code here
}


int main()
{
	string text;
	getline(cin, text);

	string q_temp;
	getline(cin, q_temp);

	int q = stoi(ltrim(rtrim(q_temp)));

	vector<string> words(q);

	for (int i = 0; i < q; i++) {
		string word;
		getline(cin, word);

		words[i] = word;
	}

	ostream &fout = cout;

	vector<vector<int>> result = find_words(text, words);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			fout << result[i][j];

			if (j != result[i].size() - 1) {
				fout << " ";
			}
		}

		if (i != result.size() - 1) {
			fout << "\n";
		}
	}

	fout << "\n";
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

vector<string> split(const string &str) {
	vector<string> tokens;

	string::size_type start = 0;
	string::size_type end = 0;

	while ((end = str.find(" ", start)) != string::npos) {
		tokens.push_back(str.substr(start, end - start));

		start = end + 1;
	}

	tokens.push_back(str.substr(start));

	return tokens;
}

