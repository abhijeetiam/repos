/*
Find Intersection Of Two Singly Linked Lists



Problem Statement:



Given two singly linked lists L1 and L2 containing non-negative integers, you have to find the intersection of given linked lists if any.



Intersection of two linked lists is the first common node (first node with the same address).



Input/Output Format For The Function:



Input Format:



There are two arguments L1 and L2 denoting pointers to head of the linked lists.



Output Format:



If given linked lists L1 and L2 intersects, then return the value in the first node where intersection begins, else return -1. Let’s denote this returned value as res.



Input/Output Format For The Custom Input:



Input Format:



The first line of input should contain a number M1, denoting the size of linked list L1. In next M1 lines, ith line should contain a number L1i, denoting an integer value in ith node of L1.

In next line, there should be an integer M2, denoting the size of L2(no. of nodes before its intersection with L1). In next M2 lines, ith line should contain an integer L2i, denoting an integer value in ith node of L2.

In the next line, there should be a number x, denoting the index of node in L1, where L2 should intersect. (x should be in 0-based indexing convention.) i.e. M2th index node of L2 is xth index node of L1.



If

M1 = 7, L1: 1 -> 2 -> 3 -> 4 -> 7 -> 8 -> 9 and

M2 = 2, L2: 5 -> 6 -> 4 -> 7 -> 8 -> 9, and

x = 3, as L2 intersect L1 at 3rd index node of L1, (i.e. node with value 4), then input should be:



7

1

2

3

4

7

8

9

2

5

6

3



Output Format:



There will be one line, containing a number res, denoting the result returned by the solution function.



For input:

M1 = 7, L1: 1 -> 2 -> 3 -> 4 -> 7 -> 8 -> 9 and

M2 = 2, L2: 5 -> 6 -> 4 -> 7 -> 8 -> 9, and

x = 3, as L2 intersect L1 at 3rd index node of L1, (i.e. node with value 4), output will be:



4



Constraints:



0 <= value stored in nodes <= 10^9
You are not allowed to modify the given linked lists.
Let N1 denote total number of nodes in L1 and N2 denote total number of nodes in L2. Then 0 <= N1, N2 <= 10^5.


Sample Test Case:



Sample Input:



L1: 1 -> 2 -> 3 -> 4 -> 7 -> 8 -> 9

L2: 5 -> 6 -> 4 -> 7 -> 8 -> 9



Sample Output:



4



Explanation:



L1 and L2 intersects at node containing value 4.



Notes:

Expected solution: Linear time complexity, with constant extra space.



Maximum time allowed in interview: 20 Minutes.



Realize that when comparing two nodes, you should be comparing the addresses, and NOT values.



Due to some HackerRank limitations currently we are providing code-stubs only in C, C++, C++ 14, C#, Java 7, Java 8, JavaScript, Python 3 and Swift.



For other languages simply write your solution (no need to read input and write output) assuming that you are given input arguments mentioned in the input format. Your solution will be checked manually. Do not worry about input, output and testcases. Just submit it.

#define nil 0
int
getlen(LinkedListNode *list)
{
	int count = 0;
	for(; list != nil; list = list->next)
		count++;
	return count;
}

int find_intersection(LinkedListNode* l1, LinkedListNode* l2) {
	int c1 = getlen(l1);
	int c2 = getlen(l2);

	LinkedListNode *s = l1;
	LinkedListNode *l = l2;
	int d = c2-c1;
	if(d < 0) {
		d =  c1 - c2;
		s = l2;
		l = l1;
	}
	for(int i = 0; i < d; i++) {
		l = l->next;
	}
	while(s != nil && l != nil){
		if(s == l)
			return s->val;
		s = s->next;
		l = l->next;
	}
	return -1;
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
int find_intersection(LinkedListNode* l1, LinkedListNode* l2) {

}

int main()
{
	ostream &fout = cout;

	int res;
	int l1_size = 0;

	LinkedListNode* l1 = NULL;
	LinkedListNode* l1_tail = NULL;

	cin >> l1_size;

	for (int i = 0; i < l1_size; i++) {
		int l1_item;
		cin >> l1_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		l1_tail = _insert_node_into_singlylinkedlist(l1, l1_tail, l1_item);

		if (i == 0) {
			l1 = l1_tail;
		}
	}


	int l2_size = 0;

	LinkedListNode* l2 = NULL;
	LinkedListNode* l2_tail = NULL;

	cin >> l2_size;

	for (int i = 0; i < l2_size; i++) {
		int l2_item;
		cin >> l2_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		l2_tail = _insert_node_into_singlylinkedlist(l2, l2_tail, l2_item);

		if (i == 0) {
			l2 = l2_tail;
		}
	}

	//----added manually----
	int merge_at;
	cin >> merge_at;
	LinkedListNode* l1_temp = l1;
	for (int i = 0; i < merge_at; i++)
	{
		l1_temp = l1_temp->next;
	}
	if (l2_tail == NULL)
	{
		l2 = l1_temp;
	}
	else
	{
		l2_tail->next = l1_temp;
	}
	//--------

	res = find_intersection(l1, l2);
	fout << res << endl;


	return 0;
}