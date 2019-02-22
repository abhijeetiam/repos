/*
Permutations of a string say "ABC". 
Fix the first char and the swap by looping over the remaining element. Then recurse over the same function
*/

#include <iostream>
#include <string>

using namespace std;

void Permute(string str, int i)
{
	int length = str.length();
	
	if (i == length - 1)
	{
		cout << "Printing str = " << str << " since i = " << i << ", length-1 = " << length-1 << endl;
		return;
	}

	for (int j = i; j <= length - 1; j++)
	{
		//cout << "Swapping i = " << i << ", str[i] = " << str[i] << ", j = " <<  j << ", str[j] = " << str[j] << ", str = " << str << endl;
		std::swap(str[i], str[j]);
		cout << "Swapped i = " << i << ", str[i] = " << str[i] << ", j = " << j << ", str[j] = " << str[j] << ", str = " << str << endl;
		cout << "Permute str = " << str << ", i+1 = " << i+1 << ", str[i+1] = " << str[i+1] << endl;

		Permute(str, i + 1);
		//cout << "UN-Swapping i = " << i << ", str[i] = " << str[i] << ", j = " << j << ", str[j] = " << str[j] << ", str = " << str << endl;
		std::swap(str[i], str[j]);
		cout << "UN-Swapped i = " << i << ", str[i] = " << str[i] << ", j = " << j << ", str[j] = " << str[j] << ", str = " << str << endl;
	}
}

int main()
{
	string str;

	cout << "Enter the string for permutations: ";
	cin >> str;
	if (str.length() == 0)
	{
		cout << "Cannot find permutations for an empty string" << endl;
		return 0;
	}
	Permute(str, 0);

	system("pause");
	return 1;
}