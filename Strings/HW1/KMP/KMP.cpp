/*
KMP



Problem Statement:



Given a text string t of length n and a pattern string p of length m, return start indices of all occurrences of p in t.

You have to answer q such queries.



Input/Output Format For The Function:



Input Format:



There are two arguments, t and p, denoting text string and pattern string respectively.



Output Format:



Return an array of integer pos[], where pos[i] is the start index of ith occurrence of p in t(0-based indexing).



Input/Output Format For The Custom Input:



Input Format:



The first line should contain a string t, denoting text string. Next line should contain an integer q, denoting no. of queries to be answered. In the next q lines, ith line contains a string pi, denoting pattern string for ith query, i=(1,2,...,q).



If

t = "Ourbusinessisourbusinessnoneofyourbusiness",

q = 3,

p in 1st query = "business",

p in 2nd query = "our",

p in 3rd query = "daisy",

then input should be:



Ourbusinessisourbusinessnoneofyourbusiness

3

business

our

daisy



Output Format:



Output will be printed in the sequence of queries asked. So, output of 1st query will be printed first, followed by output of 2nd query and so on, upto output of qth query.



For ith query, let say length of resultant array posi[] is leni.

Then, for ith query, there will be leni lines, where jth line of these leni lines contains a number posi[j], denoting number at jth index of posi.

So, in total, no. of lines will be = (len1 + len2 + len3 + … + lenq)



For input:

t = "Ourbusinessisourbusinessnoneofyourbusiness",

q = 3,

p in 1st query = "business",

p in 2nd query = "our",

p in 3rd query = "daisy",

output will be:



3

16

34

13

31

-1



Note:

If there is no occurrence of p in t, then return array pos of size one with pos[0] = -1.

If there are multiple occurrences of p in t, then return an array of start indices(sorted in increasing order).



Constraints:



1 <= q <= 5
1 <= n <= 2*10^5
1 <= m <= 2*10^5
t and p may contain lower case characters, upper case characters and numeric characters.


Sample Test Cases:



Sample Input 1:



t = "Ourbusinessisourbusinessnoneofyourbusiness"

q = 3 (t will be same for all 3 queries)

p in 1st query = "business"

p in 2nd query = "our"

p in 3rd query = "daisy"



Sample Output 1:



4

20

43

16

39

-1



Sample Input 2:



t = "IfyouthinkyouthinktoomuchthenyoumightbewrongThinkaboutit"

q = 4 (t will be same for all 4 queries)

p in 1st query = "aaaa"

p in 2nd query = "think"

p in 3rd query = "you"

p in 4th query = "be"



Sample Output 2:



-1

7

17

3

13

37

47


void computeArray(const string &p, vector<int> &arr) {
	int m = p.size();
	int i=0;
	int j=1;
	while(j < m){
		if(p[i] == p[j]){
			arr[j] = i+1;
			i++;
			j++;
		}
		else{
			if(i != 0)
				i = arr[i-1];
			else{
				arr[j]=0;
				j++;
			}
		}
	}
}


vector<int> KMP(string t, string p) {

	int n = t.size();
	int m = p.size();

	vector<int> arr(m);
	arr[0] = 0;

	vector<int> ret;

	computeArray(p,arr);
	
	//cout << "k -> ";
	//for(int k=0 ; k < arr.size(); k++)
	//	cout << arr[k];
	//cout << endl;

	int i = 0, j = 0;
	while (i < n && j < m) {
		if (t[i] == p[j]) {
			i++;
			j++;
			if (j == m)
			{
				//cout << "i " << i << " j " << j << endl;
				ret.push_back(i - m);
				//i = i-m+1;
				j = arr[j - 1];
			}
		}
		else {
			if (j != 0)
				j = arr[j - 1];
			else
				i++;
		}
	}

	if (ret.size() == 0)
	ret.push_back(-1);
	return ret;

}

*/

#include <bits/stdc++.h>

using namespace std;

// Complete the KMP function below.
vector<int> KMP(string t, string p) {


}


int main()
{
	ostream &fout = cout;

	string t;
	getline(cin, t);

	int q;
	cin >> q;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int i = 0; i < q; ++i)
	{
		string p;
		getline(cin, p);

		vector<int> res = KMP(t, p);

		for (int i = 0; i < res.size(); i++) {
			fout << res[i];

			if (i != res.size() - 1) {
				fout << "\n";
			}
		}

		fout << "\n";
	}


	return 0;
}

