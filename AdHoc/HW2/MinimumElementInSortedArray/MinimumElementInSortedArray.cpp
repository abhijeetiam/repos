/*Minimum Element In A Sorted And Rotated Array



Problem Statement :



You are given a sorted array arr which is rotated by unknown pivot k.You need to find minimum element from given array using fastest possible way which uses only constant space.



Input Format :



Only argument for function, integer array named arr.



Output Format :



Return integer which is minimum element in given array.



Constraints :



	1 <= n <= 10 ^ 5 where n is number elements in given array.

	Every element of array will be unique.

	For every element arr[i],

	-10 ^ 9 <= arr[i] <= 10 ^ 9 where 0 <= i <= (n - 1)



	Sample Test Case :



Sample Input :



arr = [4, 5, 6, 7, 8, 1, 2, 3]



Sample Output :



1



Explanation :



	For given arr = [4, 5, 6, 7, 8, 1, 2, 3] which is sorted in ascending order and right rotated by pivot 5 has minimum value as 1 at index 5.

int find_minimum(vector<int> arr)
{
	int s = 0, e = arr.size()-1, m = 0;
	int minV = arr[0];
	while (s <= e)
	{
		m = s + (e-s)/2;
		minV = min(minV, arr[m]);
		if (arr[e] > arr[m])
			e = m-1;
		else
			s = m+1;
	}
	s = 0, e = arr.size()-1, m = 0;
	while (s <= e)
	{
		m = s + (e-s)/2;
		minV = min(minV, arr[m]);
		if (arr[s] < arr[m])
			e = m-1;
		else
			s = m+1;
	}
	return minV;
}


*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


/*
* Complete the 'find_minimum' function below.
*
* The function accepts INTEGER ARRAY as parameter.
* Return INTEGER.
*/
int find_minimum(vector<int> arr)
{
	// Write your code here
}

int main()
{
	string n_temp;
	getline(cin, n_temp);

	int n = stoi(ltrim(rtrim(n_temp)));

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		string num_temp;
		getline(cin, num_temp);

		int num = stoi(ltrim(rtrim(num_temp)));

		arr[i] = num;
	}
	ostream &fout = cout;

	int result = find_minimum(arr);
	fout << result << endl;

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
