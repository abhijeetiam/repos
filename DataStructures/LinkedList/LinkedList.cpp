#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
}

LinkedList::~LinkedList()
{
}

void LinkedList::InsertAtBeginning(const int data, LinkedList** head)
{
	LinkedList* temp = new LinkedList();
	temp->data = data;
	temp->next = *head;
	*head = temp;
}

void LinkedList::Print(LinkedList** head)
{
	const LinkedList* temp = *head;
	while (temp != NULL)
	{
		cout << temp->data << "->";
		temp = temp->next;
	}
}
