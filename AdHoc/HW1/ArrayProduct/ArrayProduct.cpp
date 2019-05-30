/*Array Product

Problem Statement :

Given an array of numbers nums of size n, find an array of numbers products of size n, such that products[i] is the product of all 
numbers nums[j], where j != i.

Input / Output Format For The Function :

Input Format :
There is only one argument : nums, denoting input array.

Output Format :
Return an array of numbers products, denoting the required product array where products[i] is the(product of all numbers nums[j])
% (10 ^ 9 + 7), where j != i.

Input / Output Format For The Custom Input :

Input Format :
The first line of the input should contain a single integer n denoting the size of input array.
In the next n lines, each line should contain a number Ai, denoting ith number of the input array A, (0 <= i < n).
If n = 5 and nums = [1, 2, 3, 4, 5], then input should be :

5
1
2
3
4
5

Output Format :
There will be n lines, each line containing a number Pi, denoting ith number of the resultant product array P.
For input n = 5 and nums = [1, 2, 3, 4, 5], output will be :

120
60
40
30
24

Constraints:
You can't use division anywhere in solution.
2 <= n <= 100000
- 10 ^ 9 <= nums[i] <= 10 ^ 9, i = 0, 1, 2, …, n - 1
products[i] >= 0, i = 0, 1, 2, ..., n - 1
You are allowed to use only constant extra space and resultant product array will not be considered as extra space.

Notes:
Usage of resultant products array will not be considered as extra space used.
Without using division is the key constraint to remember.

Sample Test Cases :

Sample Input 1 :

5
1
2
3
4
5

Sample Output 1:

120
60
40
30
24

Explanation 1:

Resultant Product array products = [products[0], products[1], products[2], products[3], products[4]]
= [(nums[1] * nums[2] * nums[3] * nums[4]), (nums[0] * nums[2] * nums[3] * nums[4]), (nums[0] * nums[1] * nums[3] * nums[4]), (nums[0] * nums[1] * nums[2] * nums[4]), (nums[0] * nums[1] * nums[2] * nums[3])]
= [(2 * 3 * 4 * 5), (1 * 3 * 4 * 5), (1 * 2 * 4 * 5), (1 * 2 * 3 * 5), (1 * 2 * 3 * 4)]
= [120, 60, 40, 30, 24]


Sample Input 2:

3
4
9
10

Sample Output 2:

90
40
36

Explanation 2:

Resultant Product array products = [products[0], products[1], products[2]]
= [(nums[1] * nums[2]), (nums[0] * nums[2]), (nums[0] * nums[1])]
= [(9 * 10), (4 * 10), (4 * 9)]
= [90, 40, 36]

Suggestions:

Suggested time in interview : 20 minutes.
The “Suggested Time” is the time expected to complete this question during a real - life interview, not now in homework i.e.
For the first attempt of a given homework problem, the focus should be to understand what the problem is asking, what approach you are using, 
coding it, as well as identifying any gaps that you can discuss during a TC session.Take your time, but limit yourself to 2 one hour sessions 
for most problems.


vector<int> getProductArray(vector<int> nums) {
	// Write your code here.
	if (nums.size() == 1) return vector<int>();
	const int cmod = 1000000007;

	vector<int> res(nums.size(), 1);
	int64_t product = 1;
	for (size_t i = 0; i < nums.size(); i++)
	{
		res[i] = product;
		product = (product*nums[i] % cmod);
	}

	product = 1;
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		int64_t tmp = product * res[i] % cmod;
		if (tmp < 0) tmp += cmod;
		res[i] = tmp;

		product = (product*nums[i] % cmod);
	}

	return res;
}

*/

#include <iostream>
#include <vector>

using namespace std;

/*
 Algorithm:
1) Construct a temporary array left[] such that left[i] contains product of all elements on left of arr[i] excluding arr[i].
2) Construct another temporary array right[] such that right[i] contains product of all elements on on right of arr[i] excluding arr[i].
3) To get prod[], multiply left[] and right[].
Time Complexity: O(n)
Space Complexity: O(n)
Auxiliary Space: O(1)
*/
vector<int> getProductArray(vector<int> nums) 
{
	int temp = 1;
	std::vector<int> product;

	/* In this loop, temp variable contains product of
    elements on left side excluding arr[i] */
	for (int i = 0; i < nums.size(); i++)
	{
		product.push_back(temp);		//Important to push into vector before accessing using at(i)
		temp *= nums.at(i);
	}

	/* Initialize temp to 1 for product on right side */
	temp = 1;

	/* In this loop, temp variable contains product of
   elements on right side excluding arr[i] */
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		product.at(i) *= temp;
		temp *= nums.at(i);
	}

	return product;
}

int main()
{
	ostream &fout = cout;

	int nums_size;
	cin >> nums_size;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<int> nums(nums_size);
	for (int nums_i = 0; nums_i < nums_size; nums_i++) {
		int nums_item;
		cin >> nums_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		nums[nums_i] = nums_item;
	}

	vector<int> res = getProductArray(nums);

	for (int res_itr = 0; res_itr < res.size(); res_itr++) {
		fout << res[res_itr];

		if (res_itr != res.size() - 1) {
			fout << "\n";
		}
	}

	fout << "\n";

	system("pause");
	return 0;
}