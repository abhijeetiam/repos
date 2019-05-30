/*
Implement a power function to raise a double to an int power, including negative powers.

e.g. pow(double d, int p) should give 'd' raised to power 'p'.

Of course, please don't use in-built methods like pow(). Idea is to implement that using recursion.

Note:
This problem is under development according to IK standards. If you'd like to contribute, then please feel free to email soham@interviewkickstart.com

Till we finish developing this problem, you can look at:

https://leetcode.com/problems/powx-n/

http://stackoverflow.com/questions/101439/the-most-efficient-way-to-implement-an-integer-based-power-function-powint-int

*/

/*
#include <map>
#include <set>
#include <list>
#include <ctime>
#include <deque>
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
*/

#include <iostream>
#include <string>
#include <vector>


using namespace std;

/*
 * Complete the function below.
 */
float power(float dblbase, int ipower) 
{
	float res = 0;

	if (ipower == 0) return 1;				//Base case: Any number raised to 0 is 1
	if (ipower == 1) return dblbase;		//Base case: Any number raised to 1 is itself

	if (ipower < 0)							//Explanation: 2^(-2) = (1/2)^2 = 1/4 = 0.25
	{					
		dblbase = 1 / dblbase;				//In case of negative (-ve) power we do the above
		ipower = abs(ipower);				// (1/base) ^ (+ve powed)
	}

	res =  dblbase * power(dblbase, ipower - 1);	//Recurse: f(2^n) = 2 * f(2^n-1)
	return res;
}

int main() {
	ostream &fout = cout;
	float res;
	float _dblbase;
	cin >> _dblbase;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	int _ipower;
	cin >> _ipower;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	res = power(_dblbase, _ipower);
	fout << res << endl;

	system("pause");
	return 0;
}

