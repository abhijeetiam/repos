/*
Join Words To Make A Palindrome



Problem Statement:



Given a list of strings words, of size n, check if there is any pair of words, that can be joined (in any order) to form a palindrome then return the pair of words forming palindrome.



Input Format:



Only argument for function, list of strings words.



Output Format:



Return a pair of words (i.e. list of string result of size 2 such that result[0] + result[1] is a palindrome).

In case of multiple answer return any one of them.

In case of no answer return list [“NOTFOUND”, “DNUOFTON”].



Constraints:



Length l for each word of words list, 1<= l <= 30.

Size of list words n, 2 <= n <= 20000.

Characters for each word can be from [a-z], [A-Z], [0-9].



Sample Test Case:



Sample Input 1:



words = [ “bat”, “tab”, “zebra” ]



Sample Output 1:



result = [ “bat”, “tab” ]



Explanation 1:



As “bat” + “tab” = “battab”, which is a palindrome.



Sample Input 2:



words = [ “ant”, “dog”, “monkey” ]



Sample Output 2:



result = [ “NOTFOUND”, “DNUOFTON” ]



Explanation 2:



As for each 6 combinations of string of words, there is no single generated word which is a palindrome hence result list will be [ “NOTFOUND”, “DNUOFTON” ].


bool isPalindrome(const string& s) {
	int lo = 0;
	int hi = s.size() - 1;

	while (lo < hi) {
		if (s[lo] != s[hi]) return false;
		lo++;
		hi--;
	}

	return true;
}

vector<string> join_words_to_make_a_palindrome(vector<string> words) {
	unordered_map<string, int> reversed_index;
	static vector<string> kNotFound = { "NOTFOUND", "DNUOFTON" };

	for (int i = 0; i < words.size(); i++) {
		string word = words[i];
		reverse(word.begin(), word.end());
		reversed_index[word] = i;
	}

	for (int i = 0; i < words.size(); i++) {
		string word = words[i];
		for (int j = 0; j < word.size(); j++) {
			string suffix = word.substr(0, j);
			string prefix = word.substr(j);
			auto suffix_it = reversed_index.find(suffix);
			if (isPalindrome(prefix) && suffix_it != reversed_index.end() && i != suffix_it->second) {
				if (i < suffix_it->second) return { word, words[suffix_it->second] };
				else return { words[suffix_it->second], word };
			}
			auto prefix_it = reversed_index.find(prefix);
			if (isPalindrome(suffix) && prefix_it != reversed_index.end() && i != prefix_it->second) {
				if (i < prefix_it->second) return { word, words[prefix_it->second] };
				else return { words[prefix_it->second], word };
			}
		}
	}

	return kNotFound;
}




*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the join_words_to_make_a_palindrome function below.
 */
vector<string> join_words_to_make_a_palindrome(vector<string> words) {
	/*
	 * Write your code here.
	 */

}

int main()
{
	ostream &fout = cout;

	int words_count;
	cin >> words_count;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<string> words(words_count);

	for (int words_itr = 0; words_itr < words_count; words_itr++) {
		string words_item;
		getline(cin, words_item);

		words[words_itr] = words_item;
	}

	vector<string> res = join_words_to_make_a_palindrome(words);

	for (int res_itr = 0; res_itr < res.size(); res_itr++) {
		fout << res[res_itr];

		if (res_itr != res.size() - 1) {
			fout << "\n";
		}
	}

	fout << "\n";



	return 0;
}

