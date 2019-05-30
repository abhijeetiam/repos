/*
(This is a popular interview problem, from Programming Pearls)



Given an input file with four billion integers, provide an algorithm to generate an integer which is not contained in the file. Assume you have 1 GiB memory. Follow up with what you would do if you have only 10 MiB of memory.



Note:



This problem is under development according to IK standards. If you'd like to contribute, then please feel free to email soham@interviewkickstart.com



Till we finish developing this problem, you can look at:

http://stackoverflow.com/questions/7153659/find-an-integer-not-among-four-billion-given-ones?rq=1


*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the find_an_integer_not_among_given_integers function below.
 */
int find_an_integer_not_among_given_integers(vector<int> nos) {
	/*
	 * Write your code here.
	 */

}

int main()
{
	ostream &fout = cout;

	int nos_count;
	cin >> nos_count;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<int> nos(nos_count);

	for (int nos_itr = 0; nos_itr < nos_count; nos_itr++) {
		int nos_item;
		cin >> nos_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		nos[nos_itr] = nos_item;
	}

	int res = find_an_integer_not_among_given_integers(nos);

	fout << res << "\n";



	return 0;
}


