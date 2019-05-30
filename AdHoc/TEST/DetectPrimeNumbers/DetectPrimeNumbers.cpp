/*
Detect Prime Numbers



Problem Statement:



Given an integer array a of size N. For each integer in a we have to check if it is a prime number or not.



Input/Output Format For The Function:



Input Format:



There is only one argument denoting integer array a.



Output Format:



Return a string res of size N, where ith character of string contains '1' if a[i] is a prime number else it should contain '0'. (1 is neither a prime nor a composite number, hence according to the previous statement, it should go in else part, i.e. ith character should contain '0', when a[i] = 1.)



Input/Output Format For The Custom Input:



Input Format:



The first line should contain a number N, denoting the number of elements in the array a. In next N lines, ith line should contain a number a[i], denoting ith element in a.



If N = 4 and a = [6, 2, 5, 8], then input should be:



4

6

2

5

8



Output Format:



There will be one line, containing a resultant string res.



For input N = 4 and a = [6, 2, 5, 8], output will be:



0110



Constraints:



1 <= a[i] <= 4 * 10^6
1 <= N <= 3 * 10^5


Sample Test Case:



Sample Input:



[6, 2, 5, 8]



Sample Output:



0110



Explanation:



6 is not a prime number. (6 = 2 * 3)

2 is a prime number.

5 is a prime number.

8 is not a prime number. (8 = 2 * 4)



Notes:

Maximum time allowed in interview: 20 Minutes.

const int MAX_N = 300000, MAX_A = 4000000;
bool is_prime[MAX_A + 1];

void pre_process(int N, int max_value)
{
	fill_n(&is_prime[0], max_value + 1, true);
	// IMP. 1 is not a prime no.
	is_prime[1] = false;
	// i <= max_value is also correct but this is more efficient.
	for (int i = 2; i * i <= max_value; i++)
	{
		
		//If not a prime no, then its multiples would have been already visited by
		//its prime factors previously. e.g. for i = 4, its multiples would have
		//been already visited by its prime factor 2.
		
		if (!is_prime[i])
		{
			continue;
		}

	//In most of the implementations people start from j = i + i, but
	//this will be just  waste of time. Think when i = 5 now we can visit
	//like 10, 15, 20, 25, 30, 35... but here note that 10 = 2 * 5 so
	//when i = 2 we have already marked it, same for 15 = 3 * 5 so when
	//i = 3 we have already marked it! So it is same as starting from
	//i * i. But directly starting from i * i will save time!

		for (int j = i * i; j <= max_value; j += i)
		{
			is_prime[j] = false;
		}
	}
}

string detect_primes(vector<int> a)
{
	int N = a.size();

	pre_process(N, *max_element(a.begin(), a.end()));

	string ans(N, '0');
	for (int i = 0; i < N; i++)
	{
		if (is_prime[a[i]])
		{
			ans[i] = '1';
		}
	}
	return ans;
}

*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the detect_primes function below.
 */
string detect_primes(vector<int> a) {
	/*
	 * Write your code here.
	 */

}

int main()
{
	ostream &fout = cout;

	int a_count;
	cin >> a_count;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<int> a(a_count);

	for (int a_itr = 0; a_itr < a_count; a_itr++) {
		int a_item;
		cin >> a_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		a[a_itr] = a_item;
	}

	string res = detect_primes(a);

	fout << res << "\n";



	return 0;
}
