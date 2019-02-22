/*                                                                                   
Subsets of a string say "ABC".

Logic: Works on the concept that for every element there are 2 choices. Either the set is "with it" or "without it". 
You need to have an extra buffer passed to store the result since the length of the output string is going to have 
different elements and differ in size

*/

#include <iostream>
#include <string>

using namespace std;

void PrintSubsets(string str, string output)
{
	cout << "Entering str = " << str << ", output = " << output << endl;
	
	int i = 0;
	if (str.length() == 0)
	{
		cout << "Printing output = " << output << endl;
		return;
	}

	PrintSubsets(str.substr(i + 1), output);
	//cout << "Adding str[" << i << "] = " << str[i] << " to output" << endl;
	output += str[i];
	cout << "Output = " << output << endl;
	PrintSubsets(str.substr(i + 1), output);
}

int main()
{
	string str;
	string output;

	cout << "Enter the string (set of characters) whose subsets have to be found: ";
	cin >> str;
	if (str.length() == 0)
	{
		cout << "Cannot find subsets for an set" << endl;
		return 0;
	}
	PrintSubsets(str, output);

	system("pause");
	return 1;
}