/*
Find Order Of Characters From Alien Dictionary



Problem Statement:



Given a sorted dictionary of an alien language, you have to find the order of characters in that language.



(This is a popular interview problem.)



Generally, dictionary does not contain duplicate values, but for the sake of this problem, assume that dictionary might have duplicate values. (Sometimes interviewer tricks the question, to see, how you will handle it.)



Input/Output Format For The Function:



Input Format:



There is only one argument, array of strings words, which denotes sorted dictionary of an alien language.



Output Format:



Return a string ordered, denoting order of characters in the alien language.



Length of the output string will be the number of different characters present in input dictionary.



For more clarity see the sample test cases.



Input/Output Format For The Custom Input:



Input Format:



The first line of input should contain an integer n, denoting size of input array words. In next n lines, ith line should contain a string words[i], denoting a value at index i of words.



If n = 5 and words = ["baa", "abcd", "abca", "cab", "cad"], then input should be:



5

baa

abcd

abca

cab

cad



Output Format:



There will be only one line of output, containing a string ordered, denoting the result returned by solution function.



For input n = 5 and words = ["baa", "abcd", "abca", "cab", "cad"], output will be:



bdac



Constraints:

1 <= total number of characters in dictionary (not words) <= 10^5
Character in any word will be lower case alphabet letter.
Input will be such that it is possible to determine the order uniquely.


Sample Test Cases:



Sample Test Case 1:



Sample Input 1:



words = ["baa", "abcd", "abca", "cab", "cad"]



Sample Output 1:



"bdac"



Sample Test Case 2:



Sample Input 2:



words = ["caa", "aaa", "aab"]



Sample Output 2:



"cab"



Notes:

Maximum time allowed in interview: 20 Minutes.



Here input is given such that it is possible to determine order uniquely. But in interview you should clarify these things with interviewer. Like if we are given words = ["z" "bc"] then we can only conclude that 'z' will come before 'b', but nothing about the order of 'c'!

void build_graph(vector<string> &words, unordered_map<char, vector<char>> &graph_adj_list) {

	int num_words = words.size();

	for (int i = 0; i < num_words; ++i) {
		for (int j = 0; j < words[i].length(); ++j) {
			graph_adj_list[words[i][j]] = vector<char>(0);
		}
	}

	for (int i = 0; i < num_words-1; ++i) {
		int min_word_len = min(words[i].length(), words[i+1].length());
		for (int j = 0; j < min_word_len; ++j) {
			if (words[i][j] != words[i+1][j]) {
				graph_adj_list[words[i][j]].push_back(words[i+1][j]);
				break;
			}
		}
	}
}

void dfs(char vertex, unordered_map<char, vector<char>> &graph_adj_list, string &topo_sort_order, unordered_set<char> &visited) {

	visited.insert(vertex);
	for(auto it = graph_adj_list[vertex].begin(); it != graph_adj_list[vertex].end(); ++it) {
		if (visited.find(*it) == visited.end()) {
			dfs(*it, graph_adj_list, topo_sort_order, visited);
		}
	}
	topo_sort_order = vertex + topo_sort_order;
}

string topological_sort(unordered_map<char, vector<char>> &graph_adj_list) {
	string topo_sort_order = "";
	unordered_set<char> visited;
	for (auto it = graph_adj_list.begin(); it != graph_adj_list.end(); ++it) {
		if (visited.find(it->first) == visited.end()) {
			dfs(it->first, graph_adj_list, topo_sort_order, visited);
		}
	}
	return topo_sort_order;
}

string find_order(vector <string> words) {
	// build a graph with given words
	unordered_map<char, vector<char>> graph_adj_list;
	build_graph(words, graph_adj_list);

	// topological sort on the graph and return result
	return topological_sort(graph_adj_list);
}


*/


#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the function below.
 */
string find_order(vector <string> words) {

}


int main()
{
	ostream &fout = cout;

	string res;
	int words_size = 0;
	cin >> words_size;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	vector<string> words;
	for (int i = 0; i < words_size; i++) {
		string words_item;
		//getline(cin, words_item);
		cin >> words_item;
		words.push_back(words_item);
	}

	res = find_order(words);
	fout << res << endl;


	return 0;
}
