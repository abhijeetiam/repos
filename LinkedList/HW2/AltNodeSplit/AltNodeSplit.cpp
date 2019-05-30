/*
Alternative Node Split


Problem Statement:


Given a linked list, split it into two such that every other node goes into the new list. For lists with odd number of nodes, first one should be longer. For example: an input list: {a, b, c, d, e, f, g} results in {a, c, e, g} and {b, d, f}.


Input format:

There is only one argument named head denoting the head of the input linked list.



Output format:

Return an array of linked list which contains two linked list.



Constraints:

0 <= number of nodes <= 100000
1 <= values stored in the nodes <= 1000000000
Input will be a singly linked list


Sample Test Case:



Sample Input:



1 -> 2 -> 3 -> 4 -> 5



Sample Output:



1 -> 3 -> 5

2 -> 4



Explanation:

Process is explained in the problem statement.

vector< LinkedListNode*> alternativeSplit( LinkedListNode *head ) {
	LinkedListNode *head1 = NULL, *tail1 = NULL;
	LinkedListNode *head2 = NULL, *tail2 = NULL;

	while( head ) {
		if( !head1 ) head1 = head;
		else tail1->next = head;
		tail1 = head;
		head = head->next;
		tail1->next = NULL;

		if( !head ) break;

		if( !head2 ) head2 = head;
		else tail2->next = head;
		tail2 = head;
		head = head->next;
		tail2->next = NULL;
	}

	return { head1, head2 };
}

*/

// #include <bits/stdc++.h>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cassert>
#include <unordered_set>

using namespace std;

struct LinkedListNode {
	int val;
	LinkedListNode *next;

	LinkedListNode(int _val) {
		val = _val;
		next = NULL;
	}
};

LinkedListNode* createLinkedList(int *inputArray, int inputSize) {
	LinkedListNode *head = NULL;
	LinkedListNode *tail = NULL;
	for (int i = 0; i < inputSize; i++) {
		LinkedListNode *currentNode = new LinkedListNode(inputArray[i]);
		if (head == NULL) {
			head = currentNode;
			tail = head;
		}
		else {
			tail->next = currentNode;
			tail = tail->next;
		}
	}
	return head;
}

LinkedListNode* readInput() {
	int n; cin >> n;
	int *ar;
	ar = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	return createLinkedList(ar, n);
}

/*
	Complete the function below
*/

vector<LinkedListNode*> alternativeSplit(LinkedListNode *head) {

}

void printList(LinkedListNode *head) {
	int id = 0;
	while (head) {
		if (id > 0) cout << " ";
		cout << head->val;
		head = head->next;
		id++;
	}
	cout << endl;
}

int getArraySize(vector<LinkedListNode*> array) {
	return array.size();
}

int main() {
	LinkedListNode *head = readInput();
	vector<LinkedListNode*> result = alternativeSplit(head);
	int outputArraySize = getArraySize(result);
	if (outputArraySize != 2) {
		cerr << "Output must be an array with 2 LinkedListNode" << endl;
		return 0;
	}
	printList(result[0]);
	printList(result[1]);
	return 0;
}
