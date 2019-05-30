/*


Valid Expression



Problem Statement:



You have to check whether a given string is a valid mathematical expression or not. The given string is considered to be valid if it contains matching opening and closing parenthesis as well as valid mathematical operations. The string contains the following set of parentheses ‘(‘, ’)’, ’[’, ’]’, ’{’, ’}’, numbers from 0 to 9 and following operators ‘+’, ’-’ and ‘*’. A expression containing only parentheses is considered to be valid if it contains correct opening and closing parenthesis. Example: “{()}” is considered valid.



Input/Output Format For The Function:



Input Format:



There is a single argument in the input, a string named expression.



Output Format:



Return a Boolean value of true if the expression is valid else return the value false.



Input/Output Format For The Custom Input:



Input Format:



The first line of input contains string expression.



If expression = “(1+2)*3” then input should be:



(1+2)*3



Output Format:



Output in a single line an integer value which is either 1 or 0 if the result is true and false respectively.



For input expression = “(1+2)*3”


1



Constraints:

1 <= length(expression) <= 100000
Characters in expression string can be from ‘+’, ‘-’, ‘*’ and [0-9].


Sample Test Cases:



Sample Test Case 1:



Sample Input 1:



{(1+2)*3}+4



Sample Output 1:



1



Explanation 1:



We can clearly see that the above expression is a valid mathematical expression, as well as the parentheses, are valid.



Sample Test Case 2:



Sample Input 2:



((1+2)*3*)



Sample Output 2:



0



Explanation 2:

Here the parentheses are valid but the mathematical expression is not valid. There is an operator ‘*’ without any operand after it.

enum
{
	OPERAND = 1 << 0,
	OPERATOR = 1 << 1,
	OPENING_BRACKET = 1 << 2,
	CLOSING_BRACKET = 1 << 3 ,
	EXPRESSION = 1 << 4,
	UNKNOWN = 1 << 5,
};

int
classify(char c)
{
	//cout << "classifying " << c << endl;
	if (c == 'V') {
		return EXPRESSION;
	}

	if (c >= '0' && c <= '9') {
		return OPERAND;
	} else if (c == '+' || c == '-' || c == '*') {
		return OPERATOR;
	} else if (c == '(' || c == '{' || c == '[') {
		return OPENING_BRACKET;
	} else if (c == ')' || c == '}' || c == ']') {
		return CLOSING_BRACKET;
	}

	return UNKNOWN;
}

bool is_valid(string expression) {
	stack<char> running;
	stack<char> brackets;
	bool valid;
	char running_top;
	char brackets_top;

	expression.push_back(')');
	running.push('(');
	brackets.push('(');

	valid = true;
	for (char c : expression) {

		if (!valid) {
			break;
		}

		int classification = classify(c);
		//cout << "Classify : " << c << "as " << classification << endl;
		switch (classification) {
			case OPENING_BRACKET:
				brackets.push(c);
				// fall through
			case OPERATOR:
			case OPERAND:
				running.push(c);
				break;
			case CLOSING_BRACKET:
				if (brackets.empty()) {
					valid = false;
				} else {
				   brackets_top = brackets.top();
				   //cout << "Brackets top " << brackets_top << endl;
				   if (((c == ')' && brackets_top != '(') ||
					   (c == '}' && brackets_top != '{') ||
					   (c == ']' && brackets_top != '['))) {
						valid = false;
					} else {
					   int expected = OPERAND | EXPRESSION | CLOSING_BRACKET;
					   valid = true;
					   int current;
					   //cout << "Running top " << running.top() << endl;
					   if (running.top() == brackets_top) {
						  running.pop();
						  brackets.pop();
						  running.push('V');
						 // cout << "oushing 9 " << endl;
					   } else {
						   while (valid && ((running_top = running.top()) != brackets_top))  {
							   running.pop();
							   current = classify(running_top);
							   switch (current) {
								   case EXPRESSION:
									 if (expected && EXPRESSION) {
										 expected = EXPRESSION | OPERATOR | CLOSING_BRACKET;
									 } else {
										 valid = false;
									 }
									 break;
								case OPERAND:
								   if (expected & OPERAND) {
									   expected =  OPERATOR | CLOSING_BRACKET;
								   } else {
									   valid = false;
								   }
								   break;
								case OPERATOR:
								   if (expected & OPERATOR) {
									   expected = OPERAND | EXPRESSION;
								   } else {
									   valid = false;
								   }
								   break;
								default:
								   valid = false;
								   break;
							   }
						   }
						   if (valid && (expected & CLOSING_BRACKET)) {
							  running.pop();
							  brackets.pop();
							  running.push('V');
						   }
					   }
				   }
				}
				break;
			default :
				valid = false;
				break;
		}
	}

	if (!valid) {
		return valid;
	}

	//cout << "size " << running.size() << " char [" << running.top() << "]" << endl;
	if (!running.empty()) {
		running_top = running.top();
		//cout << "stack : " << running_top << endl;
		running.pop();
		if (!(classify(running_top) == EXPRESSION && running.empty())) {
			valid = false;
		}
	}

	return valid;
}

*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'is_valid' function below.
 *
 * The function accepts STRING expression as parameter.
 */

bool is_valid(string expression) {

}

int main()
{
	ostream &fout = cout;

	string expression;
	getline(cin, expression);

	bool result = is_valid(expression);

	fout << result << "\n";

	return 0;
}
