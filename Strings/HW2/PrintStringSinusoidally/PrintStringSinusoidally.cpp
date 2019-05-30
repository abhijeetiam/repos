/*
Print A String Sinusoidally



Problem Statement:



[This is just a stupid problem, that has no relation to anything else. It's there primarily because we see it on and off. It's a string puzzle disguised as a programming problem]



Also called "SnakeString". For example, the phrase "Google Worked" should be printed as follows (where ~ is the word separator):



	o     ~         k

  o  g  e  W   r   e

G     l        o       d



Input format:



There is only one argument named s denoting the input string.



Output format:



Print the string in sinusoidally. Format is:

→ There will be 3 rows

→ Print ~ for spaces

→ First character is printed in 1st column of 3rd row

→ Second character is printed in 2nd column of 2nd row

→ Third character is printed in 3rd column of 1st row

→ Fourth character is printed in 4th column of 2nd row

→ Fifth character is printed in 5th column of 3rd row

→ Sixth character is printed in 6th column of 2nd row

→ This process goes on…



Constraints:

String consists of alphanumeric characters and spaces
3 <= length_of_input_string <= 10000


Sample Test Case:



Sample Input:



Google Worked



Sample Output:



	o     ~         k

  o  g  e  W   r   e

G     l        o       d


void printzigzag(string &input, int K)
{
	int sz = input.size();
	vector<string> output(K, string(sz, ' '));
	int k = K-1;
	int inc = 1;
	for (int i = 0; i < sz; i++)
	{
		if (k == 0) inc = 1;
		output[k][i] = input[i]==' '?'~':input[i];
		if (k + inc >= K) inc = -1;
		k += inc;
	}

	for (int i = 0; i < K; i++)
		cout << output[i] << endl;
}

void printStringSinusoidally(string s) 
{
	printzigzag(s, 3);
}

*/

// #include <bits/stdc++.h>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cassert>
#include <unordered_set>

using namespace std;

/*
	Complete the function below
*/

void printStringSinusoidally(string s) {

}


int main() {
	string s;
	getline(cin, s);
	printStringSinusoidally(s);
	return 0;
}

