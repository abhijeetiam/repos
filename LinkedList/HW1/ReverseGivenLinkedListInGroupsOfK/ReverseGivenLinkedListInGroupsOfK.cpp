/* Reverse Given Linked List In Groups Of k

Problem Statement :
Given an integer singly linked list L, of size n, and an integer k, you have to reverse every k nodes of the linked list.

There are two cases possible :

1) When n % k = 0: There will be n / k  groups of size k.So, you have to reverse n / k  groups of size k.
2) When n % k != 0: Considering first(floor(n / k) * k) nodes, there will be floor(n / k) groups of size k and one group made of last few nodes of size n % k.
So, you have to reverse floor(n / k) groups of size k and one group of size n % k.

(Looking at sample test cases will make it more clear.)

Input / Output Format For The Function :

Input Format :
There are two arguments in input.First is an integer singly linked list L and second is an integer k.

Output Format :
Return resultant linked list resL, after reversing L in groups of k, as asked in problem statement.

Input / Output Format For The Custom Input :

Input Format :
The first line of input should contain an integer n, denoting size of input linked list L.In next n lines, ith line should contain an integer Li, denoting value in ith node of L.In the next line, there should be an integer k, denoting the size of group as explained in problem statement section.
If n = 6, L: 1 -> 2 -> 3 -> 4 -> 5 -> 6->NULL and k = 3, then input should be :

6
1
2
3
4
5
6
3

Output Format :
There will be n lines, where ith line contains value of ith node of resL.Here, resL is the resultant linked list returned by the solution function.
For input n = 6, L: 1 -> 2 -> 3 -> 4 -> 5 -> 6->NULL and k = 3, output will be :

3
2
1
6
5
4

Constraints:

1 <= n <= 100000
- 2 * 10 ^ 9 <= value stored in any node <= 2 * 10 ^ 9
1 <= k <= n
Solve it with constant extra space.


Sample Test Case :

Sample Test Case 1 :

Sample Input 1 :
list : 1 -> 2 -> 3 -> 4 -> 5 -> 6->NULL
k : 3

Sample Output 1 :
3 -> 2 -> 1 -> 6 -> 5 -> 4->NULL

Explanation 1:
n = 6, k = 3 hence n % k = 0. So there are n / k = 6 / 3 = 2 groups of size k = 3.
Groups to be reversed are(1 -> 2 -> 3) and (4 -> 5 -> 6).


Sample Test Case 2:

Sample Input 2 :
list : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8->NULL
k : 3

Sample Output 2 :
3 -> 2 -> 1 -> 6 -> 5 -> 4 -> 8 -> 7->NULL

Explanation 2:
n = 8, k = 3 hence n % k != 0, so there are floor(n / k) = floor(8 / 3) = 2 groups of size k = 3 and one group of size n % k = 8 % 3 = 2.
Groups to be reversed are(1 -> 2 -> 3), (4 -> 5 -> 6) and (7 -> 8).

Notes:

Suggested time in interview : 40 minutes.
The “Suggested Time” is the time expected to complete this question during a real - life interview, not now in homework i.e.
For the first attempt of a given homework problem, the focus should be to understand what the problem is asking, what approach you are using, coding it,
as well as identifying any gaps that you can discuss during a TA session.Take your time, but limit yourself to 2 one hour sessions for most problems.
*/

#include <iostream>
#include <stack>

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

//To get length of a linked list
int GetLength(LinkedListNode* head)
{
	int len = 0;

	if (head == NULL)
		len = 0;
	else
	{
		LinkedListNode* temp = head;
		while (temp != NULL)
		{
			temp = temp->next;
			len++;
		}
	}
	return len;
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

//To reverse a linked list using a stack data structure
//Complexity: Time = O(n), Space = O(n)
LinkedListNode* ReverseUsingStack(LinkedListNode* head)
{
	std::stack<LinkedListNode*> rev;

	if (head == NULL)
	{
		//cout << "Cannot reverse an empty linked list" << endl;
		return head;
	}

	LinkedListNode* curr = head;

	while (curr != NULL)
	{
		rev.push(curr);
		curr = curr->next;
	}

	head = rev.top();		//IMPORTANT: Make sure you set head properly to the first node popped out
	curr = head;
	rev.pop();

	while (!rev.empty())
	{
		LinkedListNode* temp = rev.top();
		curr->next = temp;
		curr = temp;
		rev.pop();			//Top returns you the elements in the stack while pop will remove it. Both have to work in tandem
	}

	curr->next = NULL;	//IMPORTANT: Make sure you set last nodes next_ pointer point to NULL or infinite loop
	return head;
}

//To reverse a linked list
//Complexity: Time = O(n), Space = O(1)
LinkedListNode* Reverse(LinkedListNode* head)
{
	if (head == NULL)
	{
		//cout << "Cannot reverse an empty linked list" << endl;
		return head;
	}

	LinkedListNode* curr = head;
	LinkedListNode* prev = NULL;
	LinkedListNode*	Next = NULL;

	while (curr != NULL)
	{
		Next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = Next;
	}

	head = prev;
	return head;
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
LinkedListNode* reverse_linked_list_in_groups_of_k(LinkedListNode* head, int k)
{
	int len = GetLength(head);

	cout << "Linked list length = " << len << endl;

	int groups = 0;
	if (len % k == 0)
		groups = len / k;
	else
	{
		groups = floor(len / k);
		groups++;
	}

	cout << "Number of groups = " << groups << endl;

	 LinkedListNode* finalRevGroupsHead = NULL;
	 LinkedListNode* finalRevGroupsTail = NULL;

	for (int i = 0; i < groups; i++)	//Looping through the number of groups
	{
		LinkedListNode* temp = head;
		LinkedListNode* curr = head;

		int nodes = 0;
		if (len % k == 0)				//Regular case wherein all groups have same number of nodes k
			nodes = k - 1;
		else
		{
			if (i == (groups - 1))		//Irregular case where running the last group with < k nodes
				nodes = (len % k);		//Number of nodes is the last group is the remainder value of mod %
			else
				nodes = k - 1;			//Irregular case where running the initial groups with == k nodes
		}

		for (int j = 0; ((j < nodes) && (temp->next)); j++)	//Looping through the nodes per group
		{
			temp = temp->next;			//getting to the last node of the group
		}

		curr = temp->next;				//marking the 1st node of the next group
		temp->next = NULL;				//marking the group to NULL to end the linked list so we can reverse it

		//LinkedListNode* revHead = ReverseUsingStack(head);
		LinkedListNode* revHead = Reverse(head);
		head = curr;

		if (i == 0)
		{
			finalRevGroupsHead = revHead;
			finalRevGroupsTail = revHead;
		}
		else
		{
			while (finalRevGroupsTail->next)
				finalRevGroupsTail = finalRevGroupsTail->next;

			finalRevGroupsTail->next = revHead;
		}

		cout << "Reverse Group" << i+1 << ": ";
		printList(revHead);
		cout << "Complete Reverse" << i + 1 << ": ";
		printList(finalRevGroupsHead);
		cout << "Tail Reverse" << i + 1 << ": ";
		printList(finalRevGroupsTail);
	}
	return finalRevGroupsHead;
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

	LinkedListNode* res = reverse_linked_list_in_groups_of_k(head, k);

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