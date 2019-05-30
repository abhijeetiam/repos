/*
Nuts and Bolts!



Problem Statement:



A disorganized carpenter has a mixed pile of bolts and nuts and would like to find the corresponding pairs of bolts and nuts. Each nut matches exactly one bolt and vice versa. By trying to match a bolt and a nut, the carpenter can see which one is bigger, but she cannot compare two bolts or two nuts directly. Can you help the carpenter match the nuts and bolts quickly?



In other words: You are given a collection of N nuts of different size and N corresponding bolts. You can choose to compare any nut & any bolt to determine whether the nut is larger than the bolt, smaller than the bolt or matches the bolt exactly. However, there is no way to compare two nuts together or two bolts together. (i.e. you cannot sort all nuts or sort all bolts). Write an algorithm to match each bolt to its matching nut.



Note that:

No two nuts are of same size. Similarly, no two bolts are of same size.
A given nut uniquely matches a bolt. i.e. There are no extra unmatched nuts or extra bolts. Every nut has one and only one matching bolt and vice-versa.


Input Format:



You will be given two integer arrays, NUTS[] and BOLTS[] of size N.



Output Format:



Return a string array res, of size N, with an entry for each pair of Nut and its corresponding Bolt separated by a single space.



Format: “Nut Bolt”



Order of the output does not matter.



Input/Output Format For The Custom Input:



Input Format:



The first line of input should contain an integer N, denoting no. of nuts. In next N lines, ith line should contain an integer NUTS[i], denoting size of ith nut.

Next line should contain an integer N, denoting no. of bolts. In next N lines, ith line should contain an integer BOLTS[i], denoting size of ith bolt.



If N = 4, NUTS = [4, 32, 5, 7] and BOLTS = [32, 7, 5, 4], then input should be:



4

4

32

5

7

4

32

7

5

4



Output Format:



There will be N lines of output, where ith line contains a string res[i], denoting value at index i of res.

Here, res is the result array returned by solution function.



For input N = 4, NUTS = [4, 32, 5, 7] and BOLTS = [32, 7, 5, 4], output will be:



4 4

32 32

5 5

7 7



Constraints:

1 <= N <= 10^5
1 <= NUTS <= 10^9
1 <= BOLTS <= 10^9


Sample Test Case:



Sample Input:



NUTS = [4, 32, 5, 7]

BOLTS = [32, 7, 5, 4]



Sample Output:



4 4

32 32

5 5

7 7


  * 1. Understanding problem took, 5 minutes.
  * 2. Can think of bruteforce solution o(n^2)
  * 3. Thinking of better approach.
  * 4. One approach is to use a hash map
  * 4a. Store the values from nuts into hashmap with the count
  * 4b. Then check the bolts in the map if exist add to result.
 
vector<string> solve(vector<int> nuts, vector<int> bolts) {
	vector<string> res;

	if (nuts.size() != bolts.size()) return res;

	for (auto e : nuts) {
		res.push_back(to_string(e));
		res.push_back(to_string(e));
	}

	return res;
}

OR

 #include <string>
vector<string> solve(vector<int> nuts, vector<int> bolts) 
{

	vector<string> result;
	for (int num : nuts) {
		string str_num = std::to_string(num) + " " + std::to_string(num);
		result.push_back(str_num);
	}

	return result;
}

*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the solve function below.
 */
vector<string> solve(vector<int> nuts, vector<int> bolts) {
	/*
	 * Write your code here.
	 */

}


int main()
{
	ostream &fout = cout;

	int nuts_count;
	cin >> nuts_count;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<int> nuts(nuts_count);

	for (int nuts_itr = 0; nuts_itr < nuts_count; nuts_itr++) {
		int nuts_item;
		cin >> nuts_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		nuts[nuts_itr] = nuts_item;
	}

	int bolts_count;
	cin >> bolts_count;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<int> bolts(bolts_count);

	for (int bolts_itr = 0; bolts_itr < bolts_count; bolts_itr++) {
		int bolts_item;
		cin >> bolts_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		bolts[bolts_itr] = bolts_item;
	}

	vector<string> res = solve(nuts, bolts);

	for (int res_itr = 0; res_itr < res.size(); res_itr++) {
		fout << res[res_itr];

		if (res_itr != res.size() - 1) {
			fout << "\n";
		}
	}

	fout << "\n";



	return 0;
}

