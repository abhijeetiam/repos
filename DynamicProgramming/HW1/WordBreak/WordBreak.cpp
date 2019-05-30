/*
Word Break



Problem Statement:



You are given a dictionary set dictionary that contains dictionaryCount distinct words and another string txt. Your task is to segment the txt string in such a way that all the segments occur in a continuous manner in the original txt string and all these segments (or words) exists in our dictionary set dictionary.



In short you have to split the string txt using ‘ ‘(single white space delimiter) in such a way that every segment(or word exists in our dictionary.



Same word from the dictionary can be used multiple times when splitting the given string.



Example: Suppose our Dictionary is {“to”, “do”, “todo”}

and txt is “totodo” then it can also be segmented as

“to to do”. Here the word “to” from the dictionary is being used twice.



Input Format:



First parameter of the function that is to be implemented is an integer dictionaryCount denoting, the number of words in our dictionary. Second parameter is a vector(array) of strings dictionary, denoting the list of words in our dictionary and the last parameter is a string txt, denoting the text string that is to be segmented.



Output Format:



Return array of strings containing all different possible segmentation arrangements for the txt string.



Constraints:



1 <= dictionaryCount <= 500

1 <= |txt| <= 19

1<= lengths of words in dictionary <= 19

All the characters in txt and words in dictionary are lower case English alphabets.



Sample Test Case:



7

kick

start

kickstart

is

awe

some

awesome

kickstartisawesome



Sample Output:



kick start is awe some

kick start is awesome

kickstart is awe some

kickstart is awesome



Explanation:



There are only 4 possible segmentations possible for the given txt. All of which are mentioned above.



Consider first segmented string: “kick start is awe some”

Here all the words: kick, start, is, awe and some exists in our dictionary and these words are continuous substrings of the txt string “kickstartisawesome”.



Similarly, other three segmentations satisfy the same conditions and hence are valid segmentations of the given string



Note:



This problem asks to print ALL different possible segmentation arrangements, hence solution will be exponential. But, if we are just asked to find count or one such possibility, then its time complexity will be much lower (better). We are working on one new problem which asks only to find count.

//Less memory version
vector<string> solver(int n, vector<string> dict, string text){
	unordered_set<string> dict_hash_set(dict.begin(), dict.end());
	int text_len = text.length();

	vector<vector<string>> ans(text_len, vector<string>(0));

	for (int i = 0; i < text_len; i++){
		for (int j = 0; j <= i; j++){
			string sub_text = text.substr(j, i - j + 1);

			if (dict_hash_set.find(sub_text) != dict_hash_set.end()){
				if (j == 0){
					ans[i].push_back(sub_text);
				}else{
					for (const string& s : ans[j - 1]){
						ans[i].push_back(s + " " + sub_text);
					}
				}
			}
		}
	}

	return ans[text_len - 1];
}


//Less Execution time version
void wordBreak(string txt, unordered_set<string> &dict, vector<string> &ret, string sofar )
{
	//cout << " txt " << txt << " sofar " << sofar << endl;
	int len = txt.length();
	if( len == 0)
	{
		ret.push_back(sofar);
		//sofar.pop_back();
		return;
	}
	for(int i=1; i<=len; i++)
	{
		string sub = txt.substr(0,i);
		if(dict.find(sub) != dict.end())
		{
			string sub2 = txt.substr(i,len-i);
		
			if(sofar=="")
				wordBreak(sub2, dict, ret, sub );
			else
				wordBreak(sub2, dict, ret, sofar + ' ' + sub );
			//cout << "sub2-" << sub2 << "-sofar-" << sofar << endl;
		}
	}
}

vector < string > solver(int dictionaryCount,vector<string> &dictionary,string txt)
{
	vector<string> ret;
	unordered_set<string> dict;
	for(int i=0; i<dictionaryCount; i++)
	{
		dict.insert(dictionary[i]);
	}
	if(txt.length() == 0) return ret;
	string sofar = "";
	wordBreak(txt,dict,ret,sofar);
	return ret;
}

*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
/*
 * Complete the solver function below.
 *
 * The function accepts STRING_ARRAY dictionary as parameter.
 * and string txt on which segmentation is to be
 * performed.
 * The function returns the list of all possible segmentation
 */

vector<string> solver(vector<string> &dictionary, string txt)
{
}
int main()
{
	int dictionary_count;
	cin >> dictionary_count;

	vector<string> dictionary(dictionary_count);

	for (int i = 0; i < dictionary_count; i++)
	{
		string dictionary_item;
		cin >> dictionary_item;
		dictionary[i] = dictionary_item;
	}

	string txt;
	cin >> txt;

	ostream &fout = cout;

	vector<string> result = solver(dictionary, txt);

	for (int i = 0; i < result.size(); i++)
	{
		fout << result[i];

		if (i != (result.size() - 1))
		{
			fout << "\n";
		}
	}
	fout << "\n";

	return 0;
}

string ltrim(const string &str)
{
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

	return s;
}

string rtrim(const string &str)
{
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end());

	return s;
}

