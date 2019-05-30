/*

Knight's tour!



Problem Statement:



Given a phone keypad as shown below:



1 2 3

4 5 6

7 8 9

- 0 -



How many different phone numbers of given length can be formed starting from the given digit? The constraint is that the movement from one digit to the next is similar to the movement of the Knight in a chess game.



For eg. if we are at 1 then the next digit can be either 6 or 8 if we are at 6 then the next digit can be 1, 7 or 0.



Repetition of digits are allowed - 1616161616 is a valid number.

The problem requires us to just give the count of different phone numbers and not necessarily list the numbers.

Find a polynomial-time solution, based on Dynamic Programming.



Input/Output Format For The Function:



Input Format:



You will be given 2 integer values, startdigit and phonenumberlength, denoting starting digit and the required length respectively.



Output Format:



Return a long integer count, denoting the total number of valid phone numbers that can be formed.



Input/Output Format For The Custom Input:



Input Format:



The first line should contain an integer startdigit, denoting the digit from which the phone number should start. The second line should contain phonenumberlength, denoting the length of phone number to be formed.



If startdigit = 1 and phonenumberlength = 3, then input should be:



1

3



Output Format:



There will be one line, containing an integer count, denoting result returned by the solution function.



For input startdigit = 1 and phonenumberlength = 3, output will be:



5



Constraints:

0 <= startdigit <= 9
1 <=  phonenumberlength <= 30


Sample Test Cases:



Sample Test Case 1:



Sample Input 1:



startdigit = 1

phonenumberlength = 2



Sample Output 1:



2



Explanation 1:



Two possible numbers of length 2: 16, 18



Sample Test Case 2:



Sample Input 2:



startdigit = 1

phonenumberlength = 3



Sample Output 2:



5



Explanation-2:



Possible numbers of length 3: 160, 161, 167, 181, 183


vector <vector<int>> paths = {{4,6}, {6,8}, {7,9}, {4,8}, {0,3,9}, {}, {0,1,7}, {2,6}, {1,3}, {2,4} };

void printDPTable (vector <vector<long long int>>& dpTable) {
	for (int i = 0; i < dpTable.size(); i++) {
		for (int j = 1; j < dpTable[0].size(); j++)
			std::cout << "dpTable[" << i << "][" << j << "]" << dpTable[i][j];
		std::cout << std::endl;
	}
}

void  initializeDPT (vector <vector<long long int>>& dpTable)
{
	for (int i = 0; i < dpTable.size(); i++)
		for (int j = 1; j< dpTable[0].size(); j++)
			dpTable[i][j] = 0;

	for (int i = 0; i < dpTable.size(); i++)
		dpTable[i][1] = 1;

}

long long int numPhoneNumbers(int startdigit, int phonenumberlength) {

	vector <vector<long long int>> dpTable (10, vector<long long int> (phonenumberlength+1));

	initializeDPT(dpTable);

	for (int l = 2; l <= phonenumberlength; l++)
	{
		for (int d = 0; d <=9; d++)
		{

			for (int k=0; k < paths[d].size(); k++)
			{

				dpTable[d][l] += dpTable[paths[d].at(k)][l-1];
			}

		}
	}

return dpTable[startdigit][phonenumberlength];

}


*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */
long long int numPhoneNumbers(int startdigit, int phonenumberlength) {

}


int main()
{
	ostream &fout = cout;

	long long int res;
	int startdigit;
	cin >> startdigit;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	int phonenumberlength;
	cin >> phonenumberlength;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	res = numPhoneNumbers(startdigit, phonenumberlength);
	fout << res;


	return 0;
}
