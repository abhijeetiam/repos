/*
Implement Queue Using Two Stacks



Problem Statement:



Implement a queue Q using exactly two stacks S1 and S2.



As an input, you will receive a singly linked list L containing integers values. Denote size of L as N.



When node value of L is negative, you should consider it as a dequeue operation, else consider it as an enqueue operation.



You have to return a singly linked list res of dequeued values.



In the case where there is nothing left to dequeue and still you see a dequeue operation, add -1.



Input/Output Format For The Function:



Input Format:



A singly linked list L of size N.



Output Format:



Return a singly linked list res of dequeued values.



Input/Output Format For The Custom Input:



Input Format:



The first line of input should contain an integer N, denoting size of L. In next N lines, ith line should contain an integer Li, denoting value in ith node of L.



If N = 7 and L: 1 -> -1 -> 2 -> -1 -> -1 -> 3 -> -1 -> NULL, then input should be:



7

1

-1

2

-1

-1

3

-1



Output Format:



Let’s denote total no. of dequeue operations as x. So, size of returned linkedlist res will be x.

There will be x lines, where ith line contains resi, denoting value in ith node of res.



For input N = 7 and L: 1 -> -1 -> 2 -> -1 -> -1 -> 3 -> -1 -> NULL, output will be:



1

2

-1

3



Constraints:

-1 <= value of node <= 2 * 10^9
1 <= N <= 10^5
There will be at least one dequeue operation.


Sample Test Case:



Sample Input:



1 -> -1 -> 2 -> -1 -> -1 -> 3 -> -1 -> NULL



Sample Output:



1 -> 2 -> -1 -> 3 -> NULL



Explanation:



L  -> ans



1   : NULL

-1 : 1 -> NULL

2  : 1 -> NULL

-1 : 1 -> 2 -> NULL

-1 : 1 -> 2 -> -1 -> NULL       (At this time queue is empty so add -1.)

3  : 1 -> 2 -> -1 -> NULL

-1 : 1 -> 2 -> -1 -> 3 -> NULL



Notes:

Maximum time allowed in interview: 20 Minutes.

int dequeue( stack<int> &S1, stack<int> &S2 ) {
	if( !S2.empty() ) {
		int x = S2.top();
		S2.pop();
		return x;
	}
	else if( !S1.empty() ) {
		while( !S1.empty() ) {
			S2.push( S1.top() );
			S1.pop();
		}
		return dequeue( S1, S2 );
	}
	else return -1;
}


//  int data; SinglyLinkedListNode* next;
SinglyLinkedListNode* implement_queue( SinglyLinkedListNode* op ) {
	SinglyLinkedListNode *head = NULL, *tail = NULL;
	stack<int> S1, S2;

	while( op ) {
		int x = op->data;
		if( x >= 0 ) S1.push( x );
		else {
			int y = dequeue( S1, S2 );
			SinglyLinkedListNode *node = new SinglyLinkedListNode( y );
			if( !head ) head = node;
			else tail->next = node;
			tail = node;
		}
		op = op->next;
	}

	return head;
}

*/

#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
public:
	int data;
	SinglyLinkedListNode *next;

	SinglyLinkedListNode(int node_data) {
		this->data = node_data;
		this->next = NULL;
	}
};

class SinglyLinkedList {
public:
	SinglyLinkedListNode *head;
	SinglyLinkedListNode *tail;

	SinglyLinkedList() {
		this->head = NULL;
		this->tail = NULL;
	}

	void insert_node(int node_data) {
		SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

		if (!this->head) {
			this->head = node;
		}
		else {
			this->tail->next = node;
		}

		this->tail = node;
	}
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ostream& fout) {
	while (node) {
		fout << node->data;

		node = node->next;

		if (node) {
			fout << sep;
		}
	}
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
	while (node) {
		SinglyLinkedListNode* temp = node;
		node = node->next;

		free(temp);
	}
}

/*
 * Complete the implement_queue function below.
 */

 /*
  * For your reference:
  *
  * SinglyLinkedListNode {
  *     int data;
  *     SinglyLinkedListNode* next;
  * };
  *
  */
SinglyLinkedListNode* implement_queue(SinglyLinkedListNode* operations) {
	/*
	 * Write your code here.
	 */

}

int main()
{
	ostream &fout = cout;

	SinglyLinkedList* operations = new SinglyLinkedList();

	int operations_count;
	cin >> operations_count;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int operations_itr = 0; operations_itr < operations_count; operations_itr++) {
		int operations_item;
		cin >> operations_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		operations->insert_node(operations_item);
	}

	SinglyLinkedListNode* res = implement_queue(operations->head);

	print_singly_linked_list(res, "\n", fout);
	fout << "\n";

	free_singly_linked_list(res);



	return 0;
}