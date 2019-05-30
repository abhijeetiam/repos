/*
String Transformation Using Given Dictionary Of Words



Problem Statement:



You are given a dictionary of words named words, and two strings named start and stop. All given strings have equal length. Dictionary words are not in any particular order, there may be duplicates, too.



You need to transform string start to string stop using given dictionary words. In each transformation, you can only change one character of the current string. e.g. "abc" -> "abd" is a valid transformation, because only one character 'c' is changed to 'd', but, "abc" -> "axy" is not a valid transformation, because two characters are changed, character 'b' is changed to 'x' and character 'c' is changed to 'y'.



In other words, you need to find out the least amount of transformations between two words start and stop, given a specific set of allowed transformations words. In other words, you need to find the shortest possible sequence of strings (two or more strings) such that:

First string is start.
Last string is stop.
Every  string (except the first one) differs from the previous one by exactly one character.
Every string (except, possibly, first and last ones) are in the dictionary of words.


If two or more such sequences exist, any one of them is a correct answer.

If no such sequence is there to be found, [“-1”] (a sequence of one string, “-1”) is the correct answer.



Constraints:



All input strings consist of lowercase Latin characters only.
0 <=  total number of characters in all dictionary words combined <= 10^5.


Input/Output Format For The Function:



Input Format:



There are three arguments:

Array of strings words,
String start,
String stop.


Output Format:



Function must return an array of strings of length >= 2, where the first string is start and the last string is stop, if the transformation is possible. Else return an array of strings containing only one string "-1", i.e. return ["-1"].



Input/Output Format For The Custom Input:



Input Format:



The first line of input should contain an integer n, denoting size of input array words. In next n lines, ith line should contain a string words[i], denoting a value at index i of words.

In next line, there should be a string start, denoting the start string. In next line, there should be a string stop, denoting the stop string.



If n = 4, words = ["cat", "hat", "bad", "had"], start = “bat” and stop = “had”, then input should be:



4

cat

hat

bad

had

bat

had



Output Format:



Let’s denote the size of ans array as m, where ans is the output string array returned by solution function.



There will be m lines of output, where ith line contains a string ans[i], denoting a value at index i of ans.



For input n = 4, words = ["cat", "hat", "bad", "had"], start = “bat” and stop = “had”, output will be:



bat

hat

had



Sample Test Cases:



Sample Test Case 1:



Sample Input 1:



words = ["cat", "hat", "bad", "had"]

start = "bat"

stop = "had"



Sample Output 1:



["bat", "bad", "had"]



or



["bat", "hat", "had"]



Explanation 1:



From "bat" change character 't' to 'd', so new string will be "bad".

From "bad" change character 'b' to 'h', so new string will be "had".



or



From "bat" change character 'b' to 'h', so new string will be "hat".

From "hat" change character 't' to 'd', so new string will be "had".



Sample Test Case 2:



Sample Input 2:



words = []

start = bbb

stop = bbc



Sample Output 2:



["bbb", "bbc"]



Explanation 2:



From "bbb" change the last character 'b' to 'c', so new string will be "bbc".



Sample Test Case 3:



Sample Input 3:



words = []

start = "zzzzzz"

stop = "zzzzzz"



Sample Output 3:



[-1]



Explanation 3:



Function must return an array of strings of length >= 2, where the first string is start and the last string is stop, if the transformation is possible. Else return an array of strings containing only one string "-1", i.e. return ["-1"].



Here, the words dictionary is empty and ["zzzzzz", "zzzzzz"] is not a valid transformation hence return ["-1"].


vector<string> restore_path(string& start, string& stop, unordered_map<string, string>& visited_path) {
	deque<string> path;
	path.push_front(stop);
	string current = visited_path[stop];

	while (current != start) {
		path.push_front(current);
		current = visited_path[current];
	}
	path.push_front(current);

	vector<string> v_path(path.begin(), path.end());
	return v_path;
}

bool one_diff(string& s1, string& s2) {
	if (s1.size() != s2.size()) {
		return false;
	}

	bool has_diff = false;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] != s2[i]) {
			if (has_diff) return false;
			has_diff = true;
		}
	}

	return has_diff;
}

bool add_generated_words(string& current, string& stop, unordered_set<string>& dict,
				unordered_map<string, string>& visited_path, queue<string>& toVisit) {
	string next = current;
	for (int i = 0; i < next.size(); i++) {
		char old = next[i];
		for (int j = 0; j < 26; j++) {
			char next_char = 'a' + j;
			if (next_char == old) continue;
			next[i] = 'a' + j;
			if (next == stop) {
				visited_path[next] = current;
				return true;
			}
			if (dict.find(next) != dict.end() && visited_path.find(next) == visited_path.end()) {
				toVisit.push(next);
				//cout << "toVisit " << next << endl;
				visited_path[next] = current;
			}
		}
		next[i] = old;
	}

	return false;
}

bool add_dict_words(string& current, string& stop, vector<string>& dict,
				unordered_map<string, string>& visited_path, queue<string>& toVisit) {
	if (one_diff(current, stop)) {
		//cout << "found current " << current << endl;
		visited_path[stop] = current;
		return true;
	}
	for (string& next : dict) {
		//cout << "next " << next << endl;
	
		if (visited_path.find(next) == visited_path.end() && one_diff(current, next) && next != current) {
			toVisit.push(next);
			//cout << "toVisit " << next << endl;
			visited_path[next] = current;
		}
	}

	return false;
}

vector<string> string_transformation(vector<string> words, string start, string stop) {
	vector<string> not_found;
	not_found.push_back("-1");

	if (start.size() != stop.size()) {
		return not_found;
	}

	unordered_set<string> dict(words.begin(), words.end());
	queue<string> toVisit;
	unordered_map<string, string> visited_path;
	toVisit.push(start);
	visited_path[start] = "";

	while (!toVisit.empty()) {
		string current = toVisit.front();
		toVisit.pop();
		//cout << "current " << current << endl;
		if (dict.size() > 26) {
			if (add_generated_words(current, stop, dict, visited_path, toVisit)) {
				return restore_path(start, stop, visited_path);
			}
		}
		else {
			if (add_dict_words(current, stop, words, visited_path, toVisit)) {
				return restore_path(start, stop, visited_path);
			}
		}
	}

	return not_found;
}


*/

#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the function below.
 */
vector<string> string_transformation(vector<string> words, string start, string stop) {


}

int main()
{
	ostream &fout = cout;

	int words_size;
	cin >> words_size;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<string> words(words_size);
	for (int words_i = 0; words_i < words_size; words_i++) {
		string words_item;
		getline(cin, words_item);

		words[words_i] = words_item;
	}

	string start;
	getline(cin, start);

	string stop;
	getline(cin, stop);

	vector<string> res = string_transformation(words, start, stop);

	for (int res_itr = 0; res_itr < res.size(); res_itr++) {
		fout << res[res_itr];

		if (res_itr != res.size() - 1) {
			fout << "\n";
		}
	}

	fout << "\n";


	return 0;
}