/*
Tower Of Hanoi


Problem Statement:



Tower of Hanoi is a mathematical puzzle where we have three pegs and n disks. The objective of the puzzle is to move the entire stack to another peg, obeying the following simple rules:



Only one disk can be moved at a time.
Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
No disk may be placed on top of a smaller disk.


Here, we are given n denoting the number of disks in the first peg, we need to return all the steps taken to move all disks from the first peg to the third peg.



There can be multiple possibilities to complete the given objective. Every valid possibility to achieve objective will be a valid answer.



Input/Output Format For The Function:



Input Format:



There is only one argument in the input, an integer named n denoting the number of disks in the first peg.



Output Format:



Return a 2d integer array denoting steps taken to move disks from the first peg to the third peg. Each row will have two integers denoting from peg and to peg, for example, if the ith row is [2, 3], then it means in this step, we moved top disk on peg 2 to peg 3.



For input n = 4, the output will be a 2d array result = [ [1, 2], [1, 3], [2, 3], [1, 2], [3, 1], [3, 2], [1, 2], [1, 3], [2, 3], [2, 1], [3, 1], [2, 3], [1, 2], [1, 3], [2, 3] ]



Input/Output Format For The Custom Input:



Input Format:



There should be one line for input, containing a single integer n, denoting the number of disks in the first peg.



If n = 4 then input should be:



4



Output Format:


There will be a 2d array of integers, where ith row of result 2d array will denote ith step taken to reach the objective. Each row will have two integers denoting from peg and to peg, for example, if the ith row is "2 3" then it means, in this step, we moved top disk on peg 2 to peg 3.



For input n = 4, the output will be as follows:



1 2

1 3

2 3

1 2

3 1

3 2

1 2

1 3

2 3

2 1

3 1

2 3

1 2

1 3

2 3



Constraints:



1 <= n <= 20


Sample Test Case:



Input:



n = 4



Output:



[ [1, 2], [1, 3], [2, 3], [1, 2], [3, 1], [3, 2], [1, 2], [1, 3], [2, 3], [2, 1], [3, 1], [2, 3], [1, 2], [1, 3], [2, 3] ]



Explaination:



Following steps:



[1, 2] = Shift top disk of the first peg to top of the second peg.

Picture after this step will be:

First peg: 2 3 4

Second peg: 1

Third peg: Empty


[1, 3] = Shift top disk of the first peg to top of the third peg.

Picture after this step will be:

First peg: 3 4

Second peg: 1

Third peg: 2



Similarly after following remaining steps will find that the final configuration will be

First peg: Empty

Second peg: Empty

Third peg: 1 2 3 4



which is our objective.

void
_RTowerOfHanoi(int n, int source, int destination, int other, vector<vector<int>> &steps)
{
	if (n == 0) return;

	_RTowerOfHanoi(n - 1, source, other, destination, steps);
	steps.push_back({source, destination});
	_RTowerOfHanoi(n - 1, other, destination, source, steps);
}

vector<vector<int>> tower_of_hanoi(int no_of_disks) 
{
	vector<vector<int>> steps;
	_RTowerOfHanoi(no_of_disks, 1, 3, 2, steps);

	return steps;
}
*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


void tower_of_hanoi_rec(int n, int n1, int n3, int n2, vector<vector<int>>& moves)
{
	if (n == 0) return;		//Do this as long as n == 0 no more deisks left
		
	//Move top (n-1) needles from n1 --> n2 using n3 as the auxillary. Consider n==3 disks example
	tower_of_hanoi_rec(n - 1, n1, n2, n3, moves);
	//Move disk n from needle n1 --> n3
	moves.push_back({ n1, n3 });
	//Move top (n-1) needles from n2 --> n3 using n1 as the auxillary
	tower_of_hanoi_rec(n - 1, n2, n3, n1, moves);
}

/*
* Complete the 'tower_of_hanoi' function below.
*
* The function accepts INTEGER as parameter.
* Return 2D INTEGER ARRAY.
*/
vector<vector<int>> tower_of_hanoi(int n)
{
	// Write your code here
	vector<vector<int>> moves;
	tower_of_hanoi_rec(n, 1, 3, 2, moves);
	return moves;
}

int main()
{
	string n_temp;
	getline(cin, n_temp);

	int n = stoi(ltrim(rtrim(n_temp)));

	ostream &fout = cout;

	vector<vector<int>> result = tower_of_hanoi(n);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			fout << result[i][j];

			if (j != result[i].size() - 1) {
				fout << " ";
			}
		}

		if (i != result.size() - 1) {
			fout << "\n";
		}
	}

	fout << "\n";

	system("pause");
	return 0;
}

string ltrim(const string &str) {
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
	);

	return s;
}

string rtrim(const string &str) {
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end()
	);

	return s;
}

vector<string> split(const string &str) {
	vector<string> tokens;

	string::size_type start = 0;
	string::size_type end = 0;

	while ((end = str.find(" ", start)) != string::npos) {
		tokens.push_back(str.substr(start, end - start));

		start = end + 1;
	}

	tokens.push_back(str.substr(start));

	return tokens;
}


