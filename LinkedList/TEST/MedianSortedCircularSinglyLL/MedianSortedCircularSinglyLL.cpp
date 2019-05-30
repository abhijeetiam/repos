/*
Find Median Of Sorted Circular Singly Linked List



Problem Statement:



Given a pointer ptr to an arbitrary node of a sorted circular singly linked list L, having n nodes, containing only even integers, you have to find the median value M of L.



When n is an even number, then the median M is average of two middle elements in a sequence of elements in L, arranged in sorted order.



Input/Output Format For The Function:



Input Format:



There is only one argument, ptr, denoting a pointer to an arbitrary node of L.



Output Format:



Return one integer denoting the median M.



Input/Output Format For The Custom Input:



Input Format:



The first line of input should contain an integer n, denoting the number of nodes in L. In next n lines, ith line should contain an integer(even number) Li, denoting value in ith node of L.

In next line, there should be an integer x, denoting index of a node in L, address of which is referenced as a pointer ptr in problem statement section. (0-based indexing for x.)



If n = 5, L: 2 -> 4 -> 6 -> 8 -> 10 (and pointer back to first node i.e. 2) and x = 1, then input should be:



5

2

4

6

8

10

1



Output Format:



There will be one line, containing an integer M, denoting the result returned by the solution function.



For input n = 5, L: 2 -> 4 -> 6 -> 8 -> 10 (and pointer back to first node i.e. 2) and x = 1, then output will be:



6



Constraints:



1 <= n <= 10^5
- 2 * 10^9 <= Li <= 2 * 10^9, i = (1,2,3,...,n)
Value contained in nodes will be even number.
(Hence when even number of elements in L, median M will be an integer. (even + even) / 2 will result in an integer value. So answer will always be integer (never float).)



Sample Test Case:



Sample Input:



L: 2 -> 4 -> 6 -> 8 -> 10



ptr: Pointer of the node containing value 4.



Sample Output:



6



Explanation:



There are 5 nodes in L hence median M will be the value of 3rd node, which is 6.



Notes:

Expected solution: Linear time complexity with constant extra space.



Maximum time allowed in interview: 20 Minutes.



Due to some HackerRank limitations currently we are providing code-stubs only in C, C++, C++ 14, C#, Java 7, Java 8, JavaScript, Python 3 and Swift.



For other languages simply write your solution (no need to read input and write output) assuming that you are given input arguments mentioned in the input format. Your solution will be checked manually. Do not worry about input, output and test cases. Just submit it.

int find_median(LinkedListNode* ptr) 
{
	vector<int> values;

	LinkedListNode *runner = ptr;
	do {
	   values.push_back(runner->val);
	   runner = runner->next;
	} while(runner != ptr);
	sort(values.begin(), values.end());
	int len = values.size();
	if (len % 2) {
		return (values[len/2]);
	} else {
		long long int sum = (long long int) values[len/2-1] + (long long int) values[len/2];
		return (sum / 2);
	}
}

*/

#include <bits/stdc++.h>

using namespace std;
class LinkedListNode {
public:
	int val;
	LinkedListNode *next;

	LinkedListNode(int node_value) {
		val = node_value;
		next = NULL;
	}
};

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode *head, LinkedListNode *tail, int val) {
	if (head == NULL) {
		head = new LinkedListNode(val);
		tail = head;
	}
	else {
		LinkedListNode *node = new LinkedListNode(val);
		tail->next = node;
		tail = tail->next;
	}
	return tail;
}

/*
 * Complete the function below.
 */
 /*
 For your reference:
 LinkedListNode {
	 int val;
	 LinkedListNode *next;
 };
 */
int find_median(LinkedListNode* ptr) {

}

int main()
{
	ostream &fout = cout;

	int res;
	int ptr_size = 0;

	LinkedListNode* ptr = NULL;
	LinkedListNode* ptr_tail = NULL;

	cin >> ptr_size;

	for (int i = 0; i < ptr_size; i++) {
		int ptr_item;
		cin >> ptr_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		ptr_tail = _insert_node_into_singlylinkedlist(ptr, ptr_tail, ptr_item);

		if (i == 0) {
			ptr = ptr_tail;
		}
	}

	//----added manually----
	ptr_tail->next = ptr;															// Till now it was linear, now join tail to head and make it circular. 
	// Now we have got circular linked list but ptr will be the first element, but we need to give arbitrary node. 
	// Value of arbitrary_shift will be [0, ptr_size). 
	int arbitrary_shift;
	scanf("%d", &arbitrary_shift);
	while (arbitrary_shift--)
	{
		ptr = ptr->next;
	}
	//--------

	res = find_median(ptr);
	fout << res << endl;


	return 0;
}
