
/* Detect loop in a linked list 
Soution 1: Using Hashing: Store addresses of each node in a set and while 
		   traversing if a node repeat we will find a match in the set

Solution 2: Using Slow and Fast pointers. Also called Tortoise and Hare approach
			This is also know as Floyd's algorithm
*/

#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

/* Link list node */
struct Node
{
	int data;
	struct Node* next;
};

bool detectLoopHashing(Node*);
bool detectLoopSlowFastPtr(Node*);			//Also known as Floyd's Algorithm

void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node = new Node;

	/* put in the data  */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;

	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 10);

	/* Create a loop for testing */
	//head->next->next->next->next = head;

	//if (detectLoopHashing(head))
	if (detectLoopSlowFastPtr(head))
		cout << "Loop found" << endl;
	else
		cout << "No Loop" << endl;

	system("pause");
	return 0;
}

//Using Hashing: Store addresses of each node in a set and while 
//traversing if a node repeats we will find a match in the set
bool detectLoopHashing(Node* head)
{
	if (head == NULL)
	{
		cout << "Linked list empty. Cannot detect loop !!!" << endl;
		return false;
	}

	bool bLoop = false;
	std::unordered_set<Node*> hashSet;
	Node* curr = head;

	while (curr != NULL)
	{
		if (hashSet.find(curr) != hashSet.end())
		{
			cout << "CYCLE/LOOP detected in linked list" << endl;
			bLoop = true;
			break;
		}
		else
			hashSet.insert(curr);
		
		curr = curr->next;
	}

	return bLoop;
}

//Time Complexity = O(n)
bool detectLoopSlowFastPtr(Node* head)			//Also known as Floyd's Algorithm
{
	if (head == NULL)
	{
		cout << "Linked list empty. Cannot detect loop !!!" << endl;
		return false;
	}

	Node* slow;
	Node* fast;
	slow = fast = head;
	
	while (fast && fast->next)				//fast & fast->next are not equal to NULL
	{
		slow = slow->next;					//Slow and Fast pointers should be moved ahead first
		fast = fast->next->next;			//before checking to see if they match each other

		if (fast == slow)
			return true;
	}
	return false;
}