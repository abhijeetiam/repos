/*
Snakes and Ladders Matrix



Problem Statement:



Given a snake and ladder rectangular board-game, find the minimum number of dice throws required to reach the final cell from the 1st cell.



Rules are as usual: If after a dice-throw, the player reaches a cell where the ladder starts, the player has to climb up that ladder and if the player reaches a cell that has the mouth of the snake, s/he has to go down to the tail of snake.



For example, in the board given below, it will take minimum 2 throws to reach from 1 to 20. That can be done with the following sequence of throws: (1,1). There may be more such sequences of the same length.



Input/Output Format For The Function:



Input Format:



You will be given an integer n, denoting the size of the board and an array of integer moves of length n, denoting if there is a ladder or a snake as follows:



moves[i] = -1, No ladder and no snake

moves[i] < i, Snake from i to moves[i]

moves[i] > i, Ladder from i to moves[i]



Note that moves array has one-based indexing.



Output Format:



Return an integer minMoves, denoting the minimum number of dice rolls required to reach the last cell.



Return -1 if there is no possible way.



Input/Output Format For The Custom Input:



Input Format:



The first line of input should contain an integer n, denoting size of board.

The second line of input should also contain an integer n, denoting size of input array moves. In next n lines, ith line should contain an integer moves[i], denoting a value at index i of moves.



If n = 20 and moves = [-1, 19, -1, -1, -1, -1, -1, -1, 3, -1, -1, 16, -1, -1, -1, -1, -1, -1, -1, -1], then input should be:



20

20

-1

19

-1

-1

-1

-1

-1

-1

-1

-1

-1

-1

-1

-1

-1

-1

-1

-1

-1

-1



Output Format:



There will be one line of output, containing an integer minMoves, denoting the result returned by solution function.



If n = 20 and moves = [-1, 19, -1, -1, -1, -1, -1, -1, 3, -1, -1, 16, -1, -1, -1, -1, -1, -1, -1, -1], output will be:



2



Constraints:

1 <= n <= 10^5
1 <=  moves[i] <= n
There is no snake at the last cell and no ladder at the first cell.
No snake starts at the top of a ladder or bottom of a snake. No ladder starts at the bottom of the snake or top of a ladder.


Sample Test Case:



Sample Input:



n = 20



moves = [-1, 19, -1, -1, -1, -1, -1, -1, 3, -1, -1, 16, -1, -1, -1, -1, -1, -1, -1, -1]



Sample Output:



2



Explanation:



You start at cell 1. You roll 1 to go to cell 2 to take the stairs to cell 19. You roll 1 again to reach the last cell, 20.



1 --> (2~19) --> 20

int minNumberOfRolls( int N, const vector<int> &moves )
{
	if( N==1 ) return 0;
	vector<int> M( N+1, -1 );
	for( int i=0; i<N; ++i ) M[i+1] = moves[i];
	vector<bool> visited( N+1, false );
	queue< pair<int, int> > store;
	pair<int, int> node( {1, 0} );
	store.push( node );

	while( !store.empty() ) {
		node = store.front();
		store.pop();
		int k = node.first, dist = node.second;
		int k2 = k, dist2 = dist+1;

		for( int n=1; n<=6; ++n ) {
			k2 = k+n;
			if( k2 > N ) break;
			if( visited[k2] ) continue;
			visited[k2] = true;
			if( M[k2] != -1 ) {
				k2 = M[k2];
				if( visited[k2] ) continue;
				visited[k2] = true;
			}
			if( k2 == N ) return dist2;
			store.push( { k2, dist2 } );
		}
	}
	return -1;
}

*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the minNumberOfRolls function below.
int minNumberOfRolls(int n, vector<int> moves) {


}


int main()
{
	ostream &fout = cout;

	string n_temp;
	getline(cin, n_temp);

	int n = stoi(ltrim(rtrim(n_temp)));

	string moves_count_temp;
	getline(cin, moves_count_temp);

	int moves_count = stoi(ltrim(rtrim(moves_count_temp)));

	vector<int> moves(moves_count);

	for (int i = 0; i < moves_count; i++) {
		string moves_item_temp;
		getline(cin, moves_item_temp);

		int moves_item = stoi(ltrim(rtrim(moves_item_temp)));

		moves[i] = moves_item;
	}

	int res = minNumberOfRolls(n, moves);

	fout << res << "\n";



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

