/*
You are given n types of coin denominations of values v(1) < v(2) < ... < v(n) (all integers). Give an algorithm which makes change for an amount of money C with as few coins as possible.



* Assume there are multiple coins of every denomination.

* Assume v(1) = 1, (i.e. there is always a combination that leads to C).

* There may be multiple ways of reaching C. We want a solution that leads to the method using least number of coins.

* Input: C and Denominations Array



In order to solve the problem you should try to:

1. Find the minimum number of coins needed (a correct, but inefficient recursive solution).

2. Optimize the solution with DP or caching.

3. Adjust the solution of part 2 so that instead of finding the minimum number of coins, find which coins those are.

4. Adjust the solution of part 3 to output all such combinations. (Hint: You'll need to do recursion on the DP table.)



Input:

Denominations: 1,2,3

C: 4

Output on two lines:

1,3

2,2



Note that test-case output is for the extra-credit case. If you're not doing that (at first, you should ignore extra credit), then read the output appropriately.



Note:



This problem is under development according to IK standards. If you'd like to contribute, then please feel free to email soham@interviewkickstart.com



Till we finish developing this problem, you can look at:

https://leetcode.com/problems/coin-change/

Solution with explanation: https://discuss.leetcode.com/topic/35720/easy-to-understand-recursive-dp-solution-using-java-with-explanations

More efficient solution, but with no explanation: https://discuss.leetcode.com/topic/32475/c-o-n-amount-time-o-amount-space-dp-solution/4

More solutions can be found in our Github Repo: https://github.com/InterviewKickstart/CodingProblemsIK/tree/master/DynamicProgramming

No solution is provided for extra credit. Run it by the TA or the instructor :-) It's harder than what is expected in interviews.

//NOT SURE IF THIS WORKS !!!

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Solution {
  private static int[] coins = {1,2,3};

  public static void main(String[] args) {
	int amount=5;
	int numCoins = coinChangeDP(amount);

	System.out.println(numCoins);
  }

  private static int coinChangeDP(int amount) {
	int numCoins = coinChange(amount);
	if(numCoins == Integer.MAX_VALUE)
	  return -1;
	else return numCoins;
  }

  private static int coinChange(int amount) {
	int[] dpTable = new int[amount + 1];
	dpTable[0] = 0;

	for (int i = 1; i <= amount; i++) {
	  int minCoins = Integer.MAX_VALUE;
	  for (int d=0; d<coins.length; d++) {
		if (coins[d] <= i) {
		  int numCoins = dpTable[i-coins[d]];
		  if (numCoins != Integer.MAX_VALUE && numCoins+1<minCoins)
			minCoins=numCoins+1;
		}
		dpTable[i] = minCoins;
	  }
	}
	return dpTable[amount];
  }
}




*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <climits>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

/*
 * Complete the function below.
 */
void makeChange(int C, vector < int > intDenominations) {


}


int main() 
{
	int _C;
	cin >> _C;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	int _intDenominations_size;
	cin >> _intDenominations_size;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	vector<int> _intDenominations;
	int _intDenominations_item;
	for (int _intDenominations_i = 0; _intDenominations_i < _intDenominations_size; _intDenominations_i++) {
		cin >> _intDenominations_item;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		_intDenominations.push_back(_intDenominations_item);
	}

	makeChange(_C, _intDenominations);

	return 0;
}
