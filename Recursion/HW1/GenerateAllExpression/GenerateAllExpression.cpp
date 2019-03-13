/*
Generate All Possible Expressions That Evaluate To The Given Target Value



Problem Statement:



You are given a string s of length n, containing only numerical characters ('0' - '9'). You are also given a non-negative number target.



You have to put between each pair of numerical characters, one of ("", "*", "+") operators such that the expression you get will evaluate to the target value.

You have to return ALL possible strings(expressions) that evaluate to target value.



Putting "" (an empty string) operator between two numerical characters means, that the they are joined (e.g. 1""2 = 12). Also the join can be extended further (e.g. 1""2""3 = 123).



Precedence of the operators matters. In higher to lower precedence:

Join ("") > Multiplication ("*") > Addition ("+")



Input/Output Format For The Function:



Input Format:



There are two arguments.

1) String s.

2) Long integer target.



Output Format:



Return array of strings res, containing ALL possible strings that evaluate to the target value.



You need not to worry about the order of strings in your output array. Like for s = "22" and target = 4, arrays ["2+2", "2*2"] and ["2*2", "2+2"] both will be accepted.



Any string in the returned array should not contain any spaces. In the above example string "2+2" is expected, other strings containing any space like " 2+2", "2 + 2", "2 +2" etc. will give wrong answer.



Input/Output Format For The Custom Input:



Input Format:



The first line of input should contain a string s, denoting input string. The second line should contain an integer target, denoting the target value as explained in problem statement section.



If s = “222” and target = 24, then input should be:



222

24



Output Format:



Let’s denote the size of res as m, where res is the resultant array of strings returned by solution function.

Then, there will be m lines of output, where ith line contains a string res[i], denoting value at index i of res.



For input s = “222” and target = 24, output will be:



2+22

22+2



Constraints:



1 <= n <= 13
s contains only numerical characters ('0' - '9').
0 <= target < 10^13


Sample Test Cases:



Sample Input:



s = "222"

target = 24



Sample Output:



["22+2", "2+22"]



Explanation:



1) 22 + 2 = 24 (Here, we put "" operator between the first two characters and then put "+" operator between the last two characters.)

2) 2 + 22 = 24 (Here, we put "+" operator between the first two characters and then put "" operator between the last two characters.)



Notes:

Suggested time in interview: 40 minutes.

The “Suggested Time” is the time expected to complete this question during a real-life interview, not now in homework i.e. For the first attempt of a given homework problem, the focus should be to understand what the problem is asking, what approach you are using, coding it, as well as identifying any gaps that you can discuss during a TC session. Take your time, but limit yourself to 2 one hour sessions for most problems.

Recursion Tree
==============
222 -> 2"2, 2*2, 2+2
2"2 -> 2"2"2, 2"2*2, 2"2+2
2*2 -> 2*2"2, 2*2*2, 2*2+2
2+2 -> 2+2"2, 2+2*2, 2+2+2

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <boost/algorithm/string.hpp>

using namespace std;

long long int EvaluateExpression(string expr)		//Example: 1+2*3+4""4
{
	std::vector<std::string> addParts;
	
	//cout << "BEFORE Expression = " << expr << endl;
	expr.erase(remove(expr.begin(), expr.end(), '\"'), expr.end());		//Remove all occurences of "
	
	//cout << "AFTER Expression = " << expr << endl;
	boost::split(addParts, expr, boost::is_any_of("+"));		//Split by + 
	
	long long int sum = 0;
	for (auto & parts: addParts) 
	{
		std::vector<std::string> prodParts;
		boost::split(prodParts, parts, boost::is_any_of("*"));		//Split by * and get the product
		long long int product = 1;
		for (auto & elem : prodParts)
		{
			product *= atol(elem.c_str());
		}
		sum += product;
	}
	//cout << "SUM = " << sum << endl;
	return sum;
}

void GenerateExpressions(string s, long long int target, int i, string expr, vector<string>& res)
{
	//cout << "s = " << s << ", target = " << target << ", index = " << i << ", length = " << s.length() << endl;

	if (i == s.length())			//BASE condition: When i reaches the length of the target string 
	{
		if (target == EvaluateExpression(expr))
		{
			//cout << "Expression == target " << " <--> " << expr << " == " << target << endl;
			expr.erase(remove(expr.begin(), expr.end(), '\"'), expr.end());		//When adding to vector erase all occurences of "
			res.push_back(expr);
		}
		return;
	}
	else if(i == s.length()-1)			//Condition: When i reaches the length-1 of the target string lets not add operator to the string like 2+ or 2*, 2"")
		GenerateExpressions(s, target, i + 1, expr + s[i], res);
	else
	{
		//cout << expr + s[i] + "\"\"" << endl;
		GenerateExpressions(s, target, i + 1, expr + s[i] + "\"\"", res);
		//cout << expr + s[i] + "*" << endl;
		GenerateExpressions(s, target, i + 1, expr + s[i] + "*", res);
		//cout << expr + s[i] + "+" << endl;
		GenerateExpressions(s, target, i + 1, expr + s[i] + "+", res);
	}
}

/*
 * Complete the function below.
 */
vector <string> generate_all_expressions(string s, long long int target) {

	vector<string> res;
	string expr;
	GenerateExpressions(s, target, 0, expr, res);
	return res;
}

int main()
{
	ostream &fout = cout;

	vector <string> res;
	string s;
	getline(cin, s);

	long long int target;
	cin >> target;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	res = generate_all_expressions(s, target);
	for (int res_i = 0; res_i < res.size(); res_i++) {
		fout << res[res_i] << endl;;
	}

	system("pause");
	return 0;
}
