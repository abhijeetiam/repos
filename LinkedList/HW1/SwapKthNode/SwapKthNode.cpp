/*Swap kth Nodes In Given Linked List

Problem Statement :
Given an integer singly linked list L of size n, and an integer k, you have to swap kth(1 - indexed) node from the beginning, with kth node from the end.
Note that you have to swap the nodes themselves, not just the contents.

Input / Output Format For The Function :

Input Format :
There are two arguments in input.First is an integer singly linked list L and second is an integer k.

Output Format :
Return resultant linked list resL, after swapping kth nodes of L.

Input / Output Format For The Custom Input :

Input Format :
The first line of input should contain an integer n, denoting size of input linked list L.In next n lines, ith line should contain an integer Li, denoting value in ith node of L.In the next line, there should be an integer k, denoting the size of group as explained in problem statement section.
If n = 6, L: 1 -> 2 -> 3 -> 4 -> 7 -> 0->NULL and k = 2, then input should be :

6
1
2
3
4
7
0
2

Output Format :
There will be n lines, where ith line contains value of ith node of resL.Here, resL is the resultant linked list returned by the solution function.
For input n = 6, L: 1 -> 2 -> 3 -> 4 -> 7 -> 0->NULL and k = 2, output will be :

1
7
3
4
2
0

Constraints:

1 <= n <= 100000
- 2 * 10 ^ 9 <= value stored in any node <= 2 * 10 ^ 9
1 <= k <= n
Try to access linked list nodes minimum number of times.

Sample Test Case :

Sample Input :
list: 1 -> 2 -> 3 -> 4 -> 7 -> 0->NULL
k : 2

Sample Output :
1 -> 7 -> 3 -> 4 -> 2 -> 0->NULL

Notes :

Suggested time in interview : 30 minutes.
The “Suggested Time” is the time expected to complete this question during a real - life interview, not now in homework
i.e.For the first attempt of a given homework problem, the focus should be to understand what the problem is asking, what approach you are using, 
coding it, as well as identifying any gaps that you can discuss during a TA session.Take your time, but limit yourself to 2 one hour sessions for most problems.
*/

#include <iostream>

using namespace std;

class LinkedListNode {
public:
	int val;
	LinkedListNode* next;

	LinkedListNode(int node_value) {
		val = node_value;
		next = NULL;
	}
};

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode* head, LinkedListNode* tail, int val) {
	if (!head) {
		head = new LinkedListNode(val);
		tail = head;
	}
	else {
		LinkedListNode* node = new LinkedListNode(val);
		tail->next = node;
		tail = tail->next;
	}

	return tail;
}

void printList(LinkedListNode* head)
{
	LinkedListNode* temp = head;
	while (temp) {
		cout << temp->val;

		if (temp->next) {
			cout << "->";
		}

		temp = temp->next;
	}
	cout << endl;
}

/*
 * Complete the function below.
 */
 /*
 For your reference:
 LinkedListNode {
	 int val;
	 LinkedListNode* next;
 };
 */
LinkedListNode* swap_nodes(LinkedListNode* head, int k) {

	if (head == NULL)
		return head;
	
	LinkedListNode* front = head;
	LinkedListNode* back = head;

	int len = 0;
	while (back != NULL)
	{
		len++;
		back = back->next;
	}

	cout << "Linked list length = " << len << endl;

	back = head;

	printList(head);
	
	for (int i = 1; i < k - 1; i++)
		front = front->next;
	
	cout << "Front = " << endl;
	printList(front);

	cout << "Head = " << endl;
	printList(head);

	LinkedListNode* front_2 = front->next;
	LinkedListNode* front_3 = front->next;

	cout << "Front_2 = " << endl;
	printList(front_2);
	printList(head);

	cout << "Front_3 = " << endl;
	printList(front_3);
	printList(head);

	for (int i = 1; i < len - k; i++)
		back = back->next;

	cout << "Back = " << endl;
	printList(back);
	printList(head);

	LinkedListNode* back_2 = back->next;
	LinkedListNode* back_3 = back->next;

	cout << "Back_2 = " << endl;
	printList(back_2);
	printList(head);

	front->next = back_2;

	cout << "Front->next = " << endl;
	printList(front->next);
	printList(head);

	//cout << "Back->next = " << endl;
	//printList(back->next);
	//printList(head);

	back_2->next = front_2->next;
	
	cout << "Back_2->next = " << endl;
	//printList(back_2->next);
	//printList(head);

	back->next = front_3;
	
	cout << "Back->next = " << endl;
	//printList(back->next);
	//printList(head);

	front_3->next = back_3->next;
	
	cout << "Front_3->next = " << endl;
	//printList(front_3->next);
	//printList(head);

	back_3->next->next = NULL;
	
	cout << "Back_2->next = " << endl;
	//printList(back_2->next);
	//printList(head);

	return head;
}

int main()
{
	ostream &fout = cout;

	int head_size;
	cin >> head_size;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	LinkedListNode* head = NULL;
	LinkedListNode* head_tail = NULL;

	for (int head_i = 0; head_i < head_size; head_i++) {
		int head_item;
		cin >> head_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		head_tail = _insert_node_into_singlylinkedlist(head, head_tail, head_item);

		if (!head_i) {
			head = head_tail;
		}
	}

	int k;
	cin >> k;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	LinkedListNode* res = swap_nodes(head, k);

	while (res) {
		fout << res->val;

		if (res->next) {
			fout << "\n";
		}

		res = res->next;
	}

	fout << "\n";

	system("pause");
	return 0;
}
