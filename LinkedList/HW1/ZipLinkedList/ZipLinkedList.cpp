/*Zip Given Linked List From Ends

Problem Statement :
Given an integer singly linked list L of size n, zip it from its two ends.

What does zipping mean ?
Given a singly linked list L : L1->L2->…->Ln - 1->Ln->NULL, rearrange the nodes in the list so that the new formed linked list is :
L1->Ln->L2->Ln - 1->L3->Ln - 2 …

You have to do it in - place i.e.in the same linked list given in input, using only constant extra space.

(Looking at the sample test case will make it more clear.)

Input / Output Format For The Function :

Input Format :
There is only one argument in input, denoting integer singly linked list L.

Output Format :
Return zipped linked list resL.

Input / Output Format For The Custom Input :

Input Format :
The first line of input should contain an integer n, denoting size of input linked list L.In next n lines, ith line should contain an integer Li, denoting value in ith node of L.
If n = 6 and L: 1 -> 2 -> 3 -> 4 -> 5 -> 6->NULL, then input should be :

6
1
2
3
4
5
6

Output Format :
There will be n lines, where ith line contains value of ith node of resL.Here, resL is the resultant linked list returned by the solution function.
For input n = 6 and L: 1 -> 2 -> 3 -> 4 -> 5 -> 6->NULL, output will be :

1
6
2
5
3
4

Constraints:

0 <= n <= 100000
- 2 * 10 ^ 9 <= value stored in any node <= 2 * 10 ^ 9

Sample Test Case :

Sample Input :
1 -> 2 -> 3 -> 4 -> 5 -> 6->NULL

Sample Output :
1 -> 6 -> 2 -> 5 -> 3 -> 4->NULL

(Other modification to try yourself for practice: zip two separate lists and unzip them back into original lists.
i.e.unzip(zip(L1, L2)) should return L1 and L2.)
*/

#include <iostream>
#include <deque>

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

//To print the linked list
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
//Complexity: Space = O(n), Time = O(n)
LinkedListNode* zip_given_linked_list_using_deque(LinkedListNode* head) 
{
	if (head == NULL)
		return head;

	std::deque<LinkedListNode*> dq;

	LinkedListNode* temp = head;

	while (temp != NULL)
	{
		dq.push_back(temp);
		temp = temp->next;
	}

	LinkedListNode* zipList = dq.front();
	dq.pop_front();
	
	temp = NULL;
	LinkedListNode* curr = zipList;
	static int count = 1;

	while (dq.size() != 0)
	{
		if (count % 2 != 0)
		{
			temp = dq.back();
			dq.pop_back();
		}
		else
		{
			temp = dq.front();
			dq.pop_front();
		}
		count++;
		curr->next = temp;
		curr = temp;
		temp = NULL;
	}
	curr->next = NULL;
	printList(zipList);
	return zipList;
}

LinkedListNode* Reverse(LinkedListNode* head)
{
	if (head == NULL)
		return head;

	LinkedListNode* curr = head;
	LinkedListNode* prev = NULL;
	LinkedListNode* Next = NULL;

	while (curr != NULL)
	{
		Next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = Next;
	}

	return prev;
}

LinkedListNode* MergeLinkedLists(LinkedListNode* l1, LinkedListNode* l2)
{
	LinkedListNode* mergedList = l1;
	LinkedListNode* t1 = l1;
	LinkedListNode* t2 = l2;

	while (l1 && l2)
	{
		t1 = l1->next;
		t2 = l2->next;
		l1->next = l2;
		l2->next = t1;
		l1 = t1;
		l2 = t2;
	}
	return mergedList;
}

//Complexity: Space = O(1), Time = O(n)
LinkedListNode* zip_given_linked_list(LinkedListNode* head)
{
	if (head == NULL)
		return head;

	LinkedListNode* slow = head;
	LinkedListNode* fast = head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	LinkedListNode* revList = Reverse(slow->next);

	if (slow)
		slow->next = NULL;

	LinkedListNode* zipList = MergeLinkedLists(head, revList);

	printList(zipList);
	return zipList;
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
	
	//LinkedListNode* res = zip_given_linked_list_using_deque(head);
	LinkedListNode* res = zip_given_linked_list(head);
		
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




