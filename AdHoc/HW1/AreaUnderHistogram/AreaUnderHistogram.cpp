
/*Area under histogram





Problem Statement :



You will be given an array arr of height of bars, of size n.You have to answer q queries, where in each query, you will be given left index l and right index r.For each query, return largest rectangular area possible in a histogram formed using (right - left + 1) bars with array of heights as[arr[left], arr[left + 1], arr[left + 2], ..., arr[right]].Largest rectangle can be made of a number of contiguous bars.For simplicity, you can assume that all bars have same width and the width is 1 unit.



For example, consider the following histogram with 7 bars of heights[6, 2, 5, 4, 5, 1, 6].The largest possible rectangle possible is 12 (see the below figure, the max area rectangle is highlighted in red).





(source: https://goo.gl/fTcCTK)





Input / Output Format For The Function :



Input Format :



There are three arguments : arr, denoting input array of height of bars, l denoting left and r denoting right as explained in problem statement.



Output Format :



Return a number maxArea, denoting maximum rectangular area possible in a histogram formed as explained in problem statement.



Input / Output Format For The Custom Input :



Input Format :



The first line of the input should contain a single integer n, denoting the size of input array arr.In the next n lines, ith line should contain a number arr[i], denoting ith number of the input array arr, i = (1, 2, ..., n).

Next line should contain q, denoting no.of queries that need to be answered.In next 2 * q lines, (2 * i - 1)th line should contain left value for ith query and (2 * i)th line should contain right value for ith query, i = (1, 2, ..., q), i.e. 1st and 2nd line should contain left and right values for 1st query, 3rd and 4th line should contain left and right values for 2nd query, and so on...



If n = 5, arr = [2, 4, 6, 5, 8], q = 2, for 1st query : l = 0 and r = 4 and for 2nd query : l = 3 and r = 3, then input should be :



5

2

4

6

5

8

2

0

4

3

3



Output Format :



There will be q lines, where ith line contains a number maxArea[i], denoting result of ith query.



For input n = 5, arr = [2, 4, 6, 5, 8], q = 2, for 1st query : l = 0 and r = 4 and for 2nd query : l = 3 and r = 3, output will be :



16

5



Constraints:



1 <= n <= 2 * 10 ^ 5
1 <= q <= 10
1 <= arr[i] <= 10 ^ 9, i = (0, 1, 2, 3, ..., n - 1)
0 <= l <= r < n for each query.


	Sample Test Cases :



Sample Input 1 :



	arr = [6, 2, 5, 4, 5, 1, 6]

	q = 1

	For 1st query : l = 0 and r = 6.



	Sample Output 1 :



	12



	Explanation 1:



1st query : A rectangle of area 12 can be formed using 2nd to 4th bar(0 - based indexing) and has maximum area possible in histogram out of all possible rectangles that can be formed using contiguous bar with given array of heights[arr[0], …, arr[6]] = [6, 2, 5, 4, 5, 1, 6] as l = 0 and r = 6.



Sample Input 2 :



	arr = [2, 4, 6, 5, 8]

	q = 2

	For 1st query : l = 0 and r = 4.

	For 2nd query : l = 3 and r = 3.



	Sample Output 2 :



	16

	5



	Explanation 2:



1st query : A rectangle of area 16 can be formed using 1st to 4th bar(0 - based indexing) and has maximum area possible in histogram out of all possible rectangles that can be formed using contiguous bar with given array of heights[arr[0], …, arr[4]] = [2, 4, 6, 5, 8] as l = 0 and r = 4.

2nd query : A rectangle of area 5 can be formed using 3rd to 3rd bar(0 - based indexing) and has maximum area possible in histogram out of all possible rectangles that can be formed using contiguous bar with given array of heights[arr[3]] = [5] as l = 3 and r = 3.



Suggestions :



	Suggested time in interview : 30 minutes.

	The “Suggested Time” is the time expected to complete this question during a real - life interview, not now in homework i.e.For the first attempt of a given homework problem, the focus should be to understand what the problem is asking, what approach you are using, coding it, as well as identifying any gaps that you can discuss during a TA session.

	Take your time, but limit yourself to 2 one hour sessions for most problems.


void popBarAndCheckArea( stack<int> &store, const vector<long long int> &H, int l, int r, int i, long long int &maxArea ) 
{
	// cout << "store size before pop: " << store.size() << endl;
	int topVal = store.top();
	store.pop();
	long long int leftIdx = store.empty() ? l-1:store.top(), rightIdx = i;
	long long int area = H[ topVal ]*( rightIdx-leftIdx -1 );
	// cout << "topVal, left, right: " << topVal << ',' << leftIdx << ',' << rightIdx << endl;
	// cout << "i, area: " << i << ',' << area << endl;
	maxArea = max( maxArea, area );
	// maxArea = max( maxArea, H[ topVal ]*( rightIdx-leftIdx -1 ) );
}

long long int findMaxPossibleArea( const vector<long long int> &H, int l, int r ) {
	stack<int> store;
	long long int maxArea = 0;
	int i = l;
	for( ; i<=r; ++i ) {
		while( !store.empty() && H[i]<H[store.top()] ) popBarAndCheckArea( store, H, l, r, i, maxArea );
		// cout << "push: " << i << endl;
		store.push( i );
	}
	while( !store.empty() )  popBarAndCheckArea( store, H, l, r, i, maxArea );
	return maxArea;
}

*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

// Complete the findMaxPossibleArea function below.
//Time Complexity = O(n^2)
long long int findMaxPossibleAreaBruteForce(vector<long long int> heights, int l, int r)
{
	if (heights.empty())
		return 0;

	if(l < 0 || r < 0)
		return 0;

	if (heights.size() == 1)
		return heights[0];

	if (l == r)
		return heights[l];

	long long int area = 0;
	long long int maxArea = 0;
		
	for (int i = l; i < r+1; i++)
	{
		for (int j = i + 1; j <= r+1; j++)
		{
			cout << "Minimum element between l = " << i << ", and r = " << j << " is " << *std::min_element(heights.begin() + i, heights.begin() + j)
				<< " and Length = " << (j - i) << endl;					//min_element will not include the last element in the calculation
			area = *std::min_element(heights.begin() + i, heights.begin() + j) *(j - i);	//calculating the minimum between range l-->r
			maxArea = std::max(area, maxArea);													//finding maxArea
			cout << "Area = " << area << ", MaxArea = " << maxArea << endl;
		}
	}
	return maxArea;
}

//Time Complexity = O(n^2)
//https://www.geeksforgeeks.org/largest-rectangle-under-histogram/
long long int findMaxPossibleArea(vector<long long int> heights, int l, int r)
{
	if (heights.empty())
		return 0;

	if (l < 0 || r < 0)
		return 0;

	if (heights.size() == 1)
		return heights[0];

	if (l == r)
		return heights[l];

	long long int area = 0;
	long long int maxArea = 0;

	std::stack<int> st;
	int pop_index = 0;
	int left_index = 0;
	int right_index = 0;

	while (l <= r)
	{
		//cout << "LOOP l = " << l << " and value = " << heights[l] << endl;
		if (st.empty() || (heights[l] > heights[st.top()]))
		{
			cout << "PUSHING l = " << l << " for element = " << heights[l] << endl;
			st.push(l++);
		}
		else
		{
			pop_index = st.top();
			st.pop();

			//cout << "LOOP pop_index = " << pop_index << endl;

			//left_index = (st.empty()) ? 0 : st.top();
			left_index = (st.empty()) ? pop_index-1 : st.top();
			right_index = (st.empty()) ? l : l - 1;
			area = heights[pop_index] * (right_index - left_index);

			/*if (!st.empty())
				area = heights[pop_index] * (l - st.top() - 1);
			else
				area = heights[pop_index] * (l);*/

			cout << "POPPING l = " << l << ", r = " << r << ", left_index = " << left_index << ", right_index = " << right_index << ", pop_index = " << pop_index 
					<< ", Area = " << area << ", MaxArea = " << maxArea << endl;
		}
		maxArea = max(area, maxArea);
	}

	while (!st.empty())
	{
		pop_index = st.top();
		st.pop();

//		cout << "STACK pop_index = " << pop_index << endl;

		//left_index = (st.empty()) ? 0 : st.top();
		left_index = (st.empty()) ? pop_index - 1 : st.top();
		right_index = (st.empty()) ? l : l - 1;
		area = heights[pop_index] * (right_index - left_index);

		/*if (!st.empty())
			area = heights[pop_index] * (l - st.top() - 1);
		else
			area = heights[pop_index] * (l);*/

		cout << "STACK l = " << l << ", r = " << r << ", left_index = " << left_index << ", right_index = " << right_index << ", pop_index = " << pop_index
			<< ", Area = " << area << ", MaxArea = " << maxArea << endl;

		maxArea = max(area, maxArea);
	}

	return maxArea;
}

int main()
{
	ostream &fout = cout;

	int heights_count;
	cin >> heights_count;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<long long int> heights(heights_count);

	for (int heights_itr = 0; heights_itr < heights_count; heights_itr++) {
		long long int heights_item;
		cin >> heights_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		heights[heights_itr] = heights_item;
	}

	int q;
	cin >> q;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int i = 0; i < q; ++i)
	{
		int l;
		cin >> l;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		int r;
		cin >> r;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		//long long int res = findMaxPossibleAreaBruteForce(heights, l, r);
		long long int res = findMaxPossibleArea(heights, l, r);

		fout << res << "\n";
	}

	system("pause");

	return 0;
}