/* Flatten a multilevel list so that all the nodes appear at a single-level
   Data structure of the linked list is as below:

   struct Node
   {
		int data;
		int Node* next;
		int Node* child;
	}

	HINT: Queue (since FIFO) all the child nodes while traversing the nodes
	and pop them out whenever you encounter a NULL while traversing.
*/
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// Macro to find number of elements in array 
#define SIZE(arr) (sizeof(arr)/sizeof(arr[0])) 

// A linked list node has data, next pointer and child pointer 
struct Node
{
	int data;
	Node* next;
	Node* child;
};

// A utility function to create a linked list with n nodes. The data 
// of nodes is taken from arr[].  All child pointers are set as NULL 
struct Node *createList(int *arr, int n)
{
	struct Node *head = NULL;
	struct Node *p = NULL;

	int i;
	for (i = 0; i < n; ++i) {
		if (head == NULL)
			head = p = (struct Node *)malloc(sizeof(*p));
		else {
			p->next = (struct Node *)malloc(sizeof(*p));
			p = p->next;
		}
		p->data = arr[i];
		p->next = p->child = NULL;
	}
	return head;
}

// A utility function to print all nodes of a linked list 
void printList(struct Node *head)
{
	while (head != NULL) {
		printf("%d->", head->data);
		head = head->next;
	}
	printf("\n");
}

// This function creates the input list.  The created list is same 
// as shown in the above figure 
struct Node *createList(void)
{
	int arr1[] = { 10, 5, 12, 7, 11 };
	int arr2[] = { 4, 20, 13 };
	int arr3[] = { 17, 6 };
	int arr4[] = { 9, 8 };
	int arr5[] = { 19, 15 };
	int arr6[] = { 2 };
	int arr7[] = { 16 };
	int arr8[] = { 3 };

	/* create 8 linked lists */
	struct Node *head1 = createList(arr1, SIZE(arr1));
	struct Node *head2 = createList(arr2, SIZE(arr2));
	struct Node *head3 = createList(arr3, SIZE(arr3));
	struct Node *head4 = createList(arr4, SIZE(arr4));
	struct Node *head5 = createList(arr5, SIZE(arr5));
	struct Node *head6 = createList(arr6, SIZE(arr6));
	struct Node *head7 = createList(arr7, SIZE(arr7));
	struct Node *head8 = createList(arr8, SIZE(arr8));


	/* modify child pointers to create the list shown above */
	head1->child = head2;
	head1->next->next->next->child = head3;
	head3->child = head4;
	head4->child = head5;
	head2->next->child = head6;
	head2->next->next->child = head7;
	head7->child = head8;


	/* Return head pointer of first linked list.  Note that all nodes are
	   reachable from head1 */
	return head1;
}

/* The main function that flattens a multilevel linked list 
   Time Complexity = O(n)
   Space Complexity = O(n)	//Because of use of a queue
*/
void flattenList(struct Node *head)
{
	if (head == NULL)
	{
		cout << "Cannot flatten an empty linked list" << endl;
		return;
	}
	
	cout << "Printing FLATTENED LIST using QUEUE" << endl;
	
	Node* curr = head;
	std::queue<Node*> flatQ;

	while (curr != NULL)
	{
		cout << curr->data << "->";

		if (curr->child)
			flatQ.push(curr->child);		//Queue which if FIFO First-In-First-Out
		
		if (curr->next == NULL)
		{
			if (!flatQ.empty())
			{
				Node* temp = flatQ.front();
				flatQ.pop();
				curr->next = temp;
			}
		}
		curr = curr->next;
	}
}

/* The main function that flattens a multilevel linked list
   Time Complexity = O(2n) ~ O(n)	//Since 2 while loops. One for tail and another for regular processing
   Space Complexity = O(1)
*/
void flattenListWithoutQueue(struct Node *head)
{
	if (head == NULL)
	{
		cout << "Cannot flatten an empty linked list" << endl;
		return;
	}

	cout << "Printing FLATTENED LIST using TAIL pointers" << endl;

	Node* tail;
	Node* curr;
	Node* temp_tail = NULL;
	curr = tail = head;
	
	while (tail->next != NULL)
		tail = tail->next;

	while (curr != NULL)
	{
		cout << curr->data << "->";

		if (curr->child)
		{
			tail->next = curr->child;
			temp_tail = curr->child;

			while (temp_tail->next != NULL)
				temp_tail = temp_tail->next;

			tail = temp_tail;
		}
		
		curr = curr->next;
	}
}


// A driver program to test above functions 
int main(void)
{
	struct Node *head = NULL;
	head = createList();
	//flattenList(head);
	flattenListWithoutQueue(head);
	cout << endl;
	//cout << "Printing flattened list : ";
	printList(head);
	system("pause");
	return 0;
}