/*

Divide An Integer By Another Integer



Problem Statement:



Given two integers a and b, you have to find quotient q, when a is divided by b.



Input/Output Format For The Function:



Input Format:



Two integers a and b.



Output Format:



A integer q, denoting quotient of a / b.



Input/Output Format For The Custom Input:



Input Format:



The first line should contain an integer, denoting a.

Second line should contain an integer, denoting b.



If a = 5 and b = 2, then input should be:



5

2



Output Format:



There will be one line, containing a integer q, denoting quotient value of a / b.



For input a = 5 and b = 2, output will be:



2



Constraints:



-10^18 <= a, b <= 10^18
b != 0
You are not allowed to use division (/) operator.
You are not allowed to use multiplication (*) operator.
You are not allowed to use mod (%) operator.


Sample Test Case:



Sample Input:



a = 5, b = 2



Sample Output:



2



Notes:



Here we have mentioned explicitly that b != 0, but in interview you should clarify this with the interviewer and handle the case accordingly.



Maximum time allowed in interview: 20 Minutes.

long long int bitwise_divide(long long int dividend, long long int divisor) 
{
	long long int quotient = 1;
	long long int origDivisor = divisor;

	if (dividend < divisor)
		return 0;
	if (dividend == divisor)
		return 1;

	while (divisor < dividend) {
		divisor = divisor << 1;
		quotient = quotient <<1;
	}
	if (divisor > dividend) {
		divisor = divisor >> 1;
		quotient = quotient >> 1;
	}
	return (quotient + bitwise_divide(dividend-divisor, origDivisor));
}


long long int divide(long long int a, long long int b) 
{
	
	int multiplier = 1;
	long long int quotient = 0;

	if (a < 0) {
		multiplier = -1;
		a = 0 - a;
	}
	if (b < 0) {
		multiplier = 0 - multiplier;
		b = 0 - b;
	}
	if (b == 1)
		quotient = a;
	else
		quotient = bitwise_divide(a, b);
	
	if (multiplier == -1)
		return (0 - quotient);
	else
		return quotient;
}

*/

#include <bits/stdc++.h>

using namespace std;
/*
 * Complete the divide function below.
 */
long long int divide(long long int a, long long int b) {
	/*
	 * Write your code here.
	 */


}

int main()
{
	ostream &fout = cout;

	long long int a;
	cin >> a;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	long long int b;
	cin >> b;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	long long int res = divide(a, b);

	fout << res << "\n";

	return 0;
}