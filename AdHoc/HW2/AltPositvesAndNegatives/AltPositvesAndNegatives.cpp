/*

Alternating Positives and Negatives





Problem Statement:



Given an array named array of size n, that contains both positive and negative numbers. Rearrange the array elements so that positive and negative numbers appear alternatively in the output. The order in which the positive elements appear should be maintained. Similarly, the order in which the negative elements appear should also be maintained.



Number of positive and negative integers may not be equal and extra positives or negatives have to appear in the end of the array.



Input Format:



There is only one argument in input, denoting integer array named array.



Output Format:



Return an integer array with alternate positive and negative numbers with order maintained.



Constraints:



1 <= n <= 500000
-2 * 10^9 <= array[i] <= 2 * 10^9
Consider 0 as a positive integer for this particular question.
Start the array with the positive integer unless all the integers in the input array are negative.




Sample Test Case:



Sample Input:



array = [2 3 -4 -9 -1 -7 1 -5 -6]



Sample Output:



[2 -4 3 -9 1 -1 -7 -5 -6]



Explanation:



Order of positive integers in the input array is [2 3 1] which is similar to order of positive integers in the output array.



Order of negative integers in the input array is [-4 -9 -1 -7 -5 -6] which is similar to order of negative integers in the output array.


The output array starts with a positive integer and keeps alternating with negative integers until all positive integers are exhausted. Rest of the output array is filled with leftover negative integers.

vector<int> alternating_positives_and_negatives(vector<int> array)
{
	vector<int> res;

	int sz = array.size();
	int pos = 0; int neg = 0;
	int dopos  = 1;
	while(pos < sz && neg < sz) {
		switch(dopos){
		case 1:
			for(;pos < sz; pos++) {
				if(array[pos] >= 0) {
					res.push_back(array[pos++]);
					break;
				}
			}
			dopos = 0;
			break;
		case 0:
			for( ; neg < sz; neg++) {
				if(array[neg] < 0) {
					res.push_back(array[neg++]);
					break;
				}
			}
			dopos = 1;
			break;
		}
	}
	for(;pos < sz; pos++) {
		if(array[pos] >= 0)
			res.push_back(array[pos]);
	}
	for(;neg < sz;neg++) {
		if(array[neg] < 0)
			res.push_back(array[neg]);
	}
	return res;
}

*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */
vector<int> alternating_positives_and_negatives(vector<int> array) {


}

int main()
{
	ostream &fout = cout;

	int array_size;
	cin >> array_size;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<int> array(array_size);
	for (int array_i = 0; array_i < array_size; array_i++) {
		int array_item;
		cin >> array_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		array[array_i] = array_item;
	}

	vector<int> res = alternating_positives_and_negatives(array);

	for (int res_itr = 0; res_itr < res.size(); res_itr++) {
		fout << res[res_itr];

		if (res_itr != res.size() - 1) {
			fout << "\n";
		}
	}

	fout << "\n";


	return 0;
}
