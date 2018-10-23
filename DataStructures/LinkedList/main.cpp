#include "LinkedList.h"

using namespace std;

LinkedList* head;		//empty list

int main()
{
	head = NULL;
	int n;
	cout << "========Operations on a Linked List========" << endl;
	cout << "How many nodes to create for a Linked List ?" << endl;
	cin >> n;
	for (int i=0; i < n; i++)
	{
		int nVal;
		cout << "Enter node data: ";
		cin >> nVal;
		LinkedList::InsertAtBeginning(nVal, &head);
	}

	LinkedList::Print(&head);
	cout << endl;
	system("pause");
	return 1;
}