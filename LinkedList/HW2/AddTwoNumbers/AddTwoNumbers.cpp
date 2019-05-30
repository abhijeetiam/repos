/*Add Two Numbers

Write a function which adds two numbers a and b, represented as linked lists of size lenA and lenB respectively, and returning the sum c in
form of a new linked list. Ignoring the allocation of a new linked list, try to use constant memory when solving it.
A number is represented by a linked list, with the head of the linked list being the least significant digit.
For example 125 is represented as 5->2->1, and 371 is represented as 1->7->3. Adding 5->2->1(125) and 1->7->3(371) should produce 6->9->4(496).

Input Format
There will be two arguments l_a and l_b, denoting linked lists representing numbers a and b respectively

Output Format
Return result denoting head node of resultant sum linked list.

Constraints
1 <= lenA, lenB <= 100000
Numbers represented by l_a and l_b will always be non - negative.
As digits of number can be[0 - 9], nodes of linked list l_a and l_b will always have number[0 - 9].
If a or b is 0, then corresponding linked list will contain only one node having value 0. For values greater than 0, there will not be any leading zeros.Same for expected output.If answer is 0, then there must be only one node having value 0 and if answer is greater than 0, then there must not be any leading zeros.

Sample Test Cases

Sample Test Case 1

Sample Input 1
l_a = 7->5->2
l_b = 2->0->3

Sample Output 1
result = 9->5->5

Explanation 1
As l_a = 7->5->2 means number 257 and l_b = 2->0->3 means number 302. Sum of 257 and 302 is 559 so, result will represent 9->5->5.


Sample Test Case 2

Sample Input 2
l_a = 5->8->3
l_b = 9->4->1

Sample Output 2
result = 4->3->5

Explanation 2
As l_a = 5->8->3 means number 385 and l_b = 9->4->1 means number 149. Sum of 385 and 149 is 534 so, result will represent 4->3->5.


bool check_if_zero(int sum, int carry_over, SinglyLinkedListNode* node)
{
	if (! node || sum != 0) {
		return true;
	}
	return false;
}

void add_val(
	SinglyLinkedListNode** l_prev, SinglyLinkedListNode** r_prev, SinglyLinkedListNode** prev,
	int val,
	int num_zeros)
{
	for (int i = 0; i < num_zeros; ++i) {
		SinglyLinkedListNode *p = nullptr;
		if (*l_prev) {
			p = *l_prev;
			*l_prev = (*l_prev)->next;
		} else if (*r_prev) {
			p = *r_prev;
			*r_prev = (*r_prev)->next;
		}
		p->data = val % 10;
		if (*prev) {
			(*prev)->next = p;
		}
		*prev = p;
	}
}

SinglyLinkedListNode* addTwoNumbers1(SinglyLinkedListNode* l_a, SinglyLinkedListNode* l_b) {
	if (! l_a && ! l_b) {
		return nullptr;
	}
	if (l_a && ! l_b) {
		return l_a;
	}
	if (! l_a && l_b) {
		return l_b;
	}

	SinglyLinkedListNode* l_next = l_a;
	SinglyLinkedListNode* r_next = l_b;
	SinglyLinkedListNode* l_prev = l_a;
	SinglyLinkedListNode* r_prev = l_b;
	SinglyLinkedListNode* prev = nullptr;

	int carry_over = 0;
	bool pending_0s = false;
	int num_pending_0s = 0;

	// do not delete unused nodes.
	while (l_next || r_next) {
		int l = (l_next) ? l_next->data : 0;
		int r = (r_next) ? r_next->data : 0;
		int sum = l + r + carry_over;

		bool should_store_sum = check_if_zero(sum, carry_over, prev);
		if (should_store_sum) {
			if (pending_0s) {
				pending_0s = false;
				add_val(&l_prev, &r_prev, &prev, 0, num_pending_0s);
				num_pending_0s = 0;
			}
			add_val(&l_prev, &r_prev, &prev, sum, 1);
		} else {
			pending_0s = true;
			num_pending_0s++;
		}

		carry_over = sum / 10;
		if (l_next) { l_next = l_next->next; }
		if (r_next) { r_next = r_next->next; }
	}

	// if both have ended, store the carry over
	if (carry_over > 0) {
		// store in rprev, this works since we start using rprev
		// if l_prev reaches null.
		prev->next = r_prev;
		r_prev->data = carry_over;
		r_prev->next = nullptr;
	} else {
		prev->next = nullptr;
	}

	return l_a;
}

SinglyLinkedListNode* addTwoNumbers(SinglyLinkedListNode* l_a, SinglyLinkedListNode* l_b) {
	if (! l_a && ! l_b) {
		return nullptr;
	}
	if (l_a && ! l_b) {
		return l_a;
	}
	if (! l_a && l_b) {
		return l_b;
	}

	SinglyLinkedListNode* l_next = l_a;
	SinglyLinkedListNode* r_next = l_b;
	SinglyLinkedListNode* r_prev = l_b;
	SinglyLinkedListNode* prev = nullptr;

	int carry_over = 0;
	// do not delete unused nodes.
	while (l_next || r_next) {
		int l = (l_next) ? l_next->data : 0;
		int r = (r_next) ? r_next->data : 0;
		int sum = l + r + carry_over;

		carry_over = sum / 10;
		SinglyLinkedListNode* node = nullptr;
		if (l_next) {
			node = l_next;
		} else {
			node = r_prev;
			r_prev = r_prev->next;
		}
		node->data = sum % 10;
		if (! prev) {
			prev = node;
		} else {
			prev->next = node;
			prev = node;
		}

		if (l_next) { l_next = l_next->next; }
		if (r_next) { r_next = r_next->next; }

		// if both have ended, store the carry over and break
		if (! l_next && ! r_next) {
			if (carry_over > 0) {
				// store in rprev, this works since we start using rprev
				// if l_prev reaches null.
				prev->next = r_prev;
				r_prev->data = carry_over;
				r_prev->next = nullptr;
			} else {
				prev->next = nullptr;
			}
			break;
		}
	}
	return l_a;
}

*/

#include <string>
#include <iostream>
#include <algorithm>
#include <functional>

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

int GetLength(SinglyLinkedListNode* list)
{
	if (list == NULL)
		return 0;

	int count = 0;
	
	while (list != NULL)
	{
		count++;
		list = list->next;
	}
	return count;
}

/*void AddAndStoreTwoNumbers(SinglyLinkedListNode* n1, SinglyLinkedListNode* n2)
{
	int carry = 0;
	n2->data = (n2->data + n1->data) % 10;
	carry = (n2->data + n1->data) / 10;
	n1 = n1->next;
	n1 += carry;
	n2 = n2->next;
	//return n2;
}*/

/*
 * Complete the 'addTwoNumbers' function below.
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

SinglyLinkedListNode* addTwoNumbers(SinglyLinkedListNode* l_a, SinglyLinkedListNode* l_b)
{
	if (l_a && !l_b)
		return l_a;

	if (!l_a && l_b)
		return l_b;

	if (!l_a && !l_b)
		return NULL;

	int len_a = GetLength(l_a);
	int len_b = GetLength(l_b);

	SinglyLinkedListNode* head_a = l_a;
	SinglyLinkedListNode* head_b = l_b;

	SinglyLinkedListNode* l_carry = new SinglyLinkedListNode(0);
	int sum = 0;

	while (l_a && l_b)
	{
		sum = l_a->data + l_b->data + l_carry->data;
		l_b->data = sum % 10;
		l_carry->data = sum / 10;

		cout << "l_b->data = " << l_b->data << " , l_a->data = " << l_a->data <<
			", l_carry->data = " << l_carry->data << ", sum = " << sum << endl;
		
		if (l_a->next == NULL || l_b->next == NULL)
		{
			if (l_carry->data != 0)
				l_b->next = l_carry;

			if (len_a > len_b)
				l_b->next = l_a->next;
			
			return head_b;
		}
		l_a = l_a->next;
		l_b = l_b->next;
	}

	/*while (l_a && l_b)
	{
		sum = l_b->data + l_a->data;
		//cout << "sum = " << sum << endl;
		if (len_b >= len_a)
		{
			//AddAndStoreTwoNumbers(l_a, l_b);
			l_b->data = sum % 10;
			cout << "l_b->data = " << l_b->data << endl;
			l_carry->data =  sum / 10;
			cout << "carry = " << l_carry->data << endl;
			
			if ((l_b->next == NULL) && (l_carry->data > 0))
				l_b->next = l_carry;
			else
				l_b = l_b->next;

			if (l_b)
			{
				l_b->data += l_carry->data;
				cout << "l_a->data = " << l_a->data << endl;
			}
			l_a = l_a->next;
		}
		else
		{
			//AddAndStoreTwoNumbers(l_b, l_a);
			l_a->data = sum % 10;
			//cout << "l_a->data = " << l_a->data << endl;
			carry = sum / 10;
			//cout << "carry = " << carry << endl;
			l_b = l_b->next;
			if (l_b) l_b->data += carry;
			l_a = l_a->next;
		}
	}

	if (len_b >= len_a)
		return head_b;
	else
		return head_a;*/
}

int main()
{
	SinglyLinkedList* l_a = new SinglyLinkedList();

	string l_a_count_temp;
	getline(cin, l_a_count_temp);

	int l_a_count = stoi(ltrim(rtrim(l_a_count_temp)));

	for (int i = 0; i < l_a_count; i++) {
		string l_a_item_temp;
		getline(cin, l_a_item_temp);

		int l_a_item = stoi(ltrim(rtrim(l_a_item_temp)));

		l_a->insert_node(l_a_item);
	}
	
	SinglyLinkedList* l_b = new SinglyLinkedList();

	string l_b_count_temp;
	getline(cin, l_b_count_temp);

	int l_b_count = stoi(ltrim(rtrim(l_b_count_temp)));

	for (int i = 0; i < l_b_count; i++) {
		string l_b_item_temp;
		getline(cin, l_b_item_temp);


		int l_b_item = stoi(ltrim(rtrim(l_b_item_temp)));

		l_b->insert_node(l_b_item);
	}

	ostream &fout = cout;

	SinglyLinkedListNode* result = addTwoNumbers(l_a->head, l_b->head);

	print_singly_linked_list(result, "\n", fout);
	fout << "\n";

	system("pause");
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


