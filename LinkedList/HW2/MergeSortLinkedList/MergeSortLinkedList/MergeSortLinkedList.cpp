/*
Merge Sort A Linked List



Problem Statement:



You are given a singly linked list. You have to sort the linked list using merge sort algorithm in ascending order.



Input/Output Format For The Function:



Input Format:



The function contains a single argument, the head node of the linked list head.



Output Format:



Return the head of the sorted linked list.



Input/Output Format For The Custom Input:



Input Format:



First line contains integer n, the number of integers. The next n lines contains an integer each.



If linked list is 1->2->4->3 then input should be:



4

1

2

4

3



Output Format:



The function should return the head of the sorted linked list. The inbuilt print function will print each integer of the linked list starting from head in a new line.



For above input, output will be



1

2

3

4



You should have correctly returned the head, in this case the node containing data as 1, after sorting the linked list.



Constraints:



1 <= n <= 10^5
-10^9 <= value of each node of linked list <= 10^9


Sample Test Cases:



Sample Test Case 1:



Sample Input 1:



4

0

1

10

7



Sample Output 1:



0

1

7

10



Explanation 1:



We see that the linked list is sorted in increasing order as 0<1<7<10.



Sample Test Case 2:



Sample Input 2:



3

1

2

3



Sample Output 2:



1

2

3



Explanation 2:



We see that the input is already sorted and so is the output linked list. It is correctly sorted in increasing order as 1<2<3.

class Result {


	public static SinglyLinkedListNode merge_sort(SinglyLinkedListNode head) {
		if (head == null) {
			return null;
		}
		if (head.next == null) {
			return head;
		}

		SinglyLinkedListNode mid = findMid(head);
		SinglyLinkedListNode right = mid.next;
		mid.next = null;
		SinglyLinkedListNode leftSorted = merge_sort(head);
		SinglyLinkedListNode rightSorted = merge_sort(right);

		SinglyLinkedListNode merged = merge(leftSorted, rightSorted);
		//print(merged);
		return merged;
	}

	static SinglyLinkedListNode findMid (SinglyLinkedListNode head) {
		SinglyLinkedListNode slow = head;
		SinglyLinkedListNode fast = head;

		while (fast!= null && fast.next != null && fast.next.next != null) {
			slow = slow.next;
			fast = fast.next.next;
		}

		return slow;
	}

	static SinglyLinkedListNode merge (SinglyLinkedListNode left, SinglyLinkedListNode right) {
	   if (left == null) {
		   return right;
	   }
		if (right == null) {
			return left;
		}

		SinglyLinkedListNode result = null;
		if (left.data <= right.data) {
			result = left;
			left.next = merge(left.next, right);
		} else {
			result = right;
			right.next = merge(right.next, left);
		}

		return result;
	}

	static void print(SinglyLinkedListNode node) {
		SinglyLinkedListNode curr = node;
		System.out.println("list: ");
		while (curr != null) {
			System.out.print(curr.data + "->");
			curr = curr.next;
		}
		System.out.println("-//");
	}

}

*/

#include <bits/stdc++.h>


using namespace std;


string ltrim(const string &);
string rtrim(const string &);

class SinglyLinkedListNode {
public:
	int data;
	SinglyLinkedListNode *next;

	SinglyLinkedListNode(int node_data) {
		this->data = node_data;
		this->next = nullptr;
	}
};


class SinglyLinkedList {
public:
	SinglyLinkedListNode *head;
	SinglyLinkedListNode *tail;

	SinglyLinkedList() {
		this->head = nullptr;
		this->tail = nullptr;
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
LinkedListNode* mergeSortList(LinkedListNode* pList) {


}

int main()
{
	ostream &fout = cout;

	SinglyLinkedList* head = new SinglyLinkedList();

	string head_count_temp;
	getline(cin, head_count_temp);

	int head_count = stoi(ltrim(rtrim(head_count_temp)));

	for (int i = 0; i < head_count; i++) {
		string head_item_temp;
		getline(cin, head_item_temp);

		int head_item = stoi(ltrim(rtrim(head_item_temp)));

		head->insert_node(head_item);
	}

	SinglyLinkedListNode* result = merge_sort(head->head);

	print_singly_linked_list(result, "\n", fout);
	fout << "\n";

	return 0;
}


string ltrim(const string &str) {
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
	);

	return s;
}

string rtrim(const string &str) {
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end()
	);

	return s;
}


