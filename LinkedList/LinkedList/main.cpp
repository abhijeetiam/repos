#include "LinkedList.h"

using namespace std;

int main()
{
	int n;
	LinkedList list;

	while (true)
	{
		cout << endl;
		cout << "============================LINKED LIST MENU=============================" << endl;
		cout << "1: INSERT at Beginning" << endl;
		cout << "2: INSERT at End" << endl;
		cout << "3: INSERT at Position" << endl;
		cout << "4: DELETE" << endl;
		cout << "5: SEARCH" << endl;
		cout << "6: UPDATE" << endl;
		cout << "7: REVERSE" << endl;
		cout << "8: REVERSE_STACK" << endl;
		cout << "9: SORT" << endl;
		cout << "10: LENGTH" << endl;
		cout << "11: PRINT" << endl;
		cout << "12: EXIT " << endl;
		cout << "==================================================================" << endl;
		cout << "Enter your choice : ";

		cin >> n;
		
		switch (n)
		{
			case LinkedList::INSERT_BEGIN:
			{
				cout << "How many nodes to create for a Linked List in beginning ?" << endl;
				cin >> n;
				for (int i = 0; i < n; i++)
				{
					int data;
					cout << "Enter node data: ";
					cin >> data;
					list.InsertAtBeginning(data);
				}
				list.Print();
				break;
			}

			case LinkedList::INSERT_END:
			{
				cout << "How many nodes to create for a Linked List at end ?" << endl;
				cin >> n;
				for (int i = 0; i < n; i++)
				{
					int data;
					cout << "Enter node data: ";
					cin >> data;
					list.InsertAtEnd(data);
				}
				break;
			}

			case LinkedList::INSERT_POS:
			{
				int data, position = 0;
				cout << "After which node do you want to insert a node : ";
				cin >> position;
				cout << "Enter node data: ";
				cin >> data;
				list.InsertAtPosition(data, position);
				break;
			}

			case LinkedList::DELETE_POS:
			{
				int position = 0;;
				cout << "Which node do you want to delete : ";
				cin >> position;
				list.Delete(position);
				break;
			}

			case LinkedList::LENGTH:
			{
				cout << "Length of the linked list is : " << list.GetLength() << endl;
				break;
			}

			case LinkedList::SEARCH:
			{
				int data = 0;
				cout << "What data do you want to check in the linked list: ";
				cin >> data;
				if (list.Search(data))
					cout << "Data " << data << " EXISTS in the linked list" << endl;
				else
					cout << "Data " << data << " DOES NOT EXIST in the linked list" << endl;
				break;
			}

			case LinkedList::UPDATE:
			{
				int data, position = 0;
				cout << "Which node do you want to update : ";
				cin >> position;

				if (position > list.GetLength())
				{
					cout << "Node to be updated : " << position << " cannot be greater than the linked list's length : " << list.GetLength() << endl;
					break;
				}

				cout << "What data do you want to update it with: ";
				cin >> data;
				list.Update(position, data);
				break;
			}

			case LinkedList::REVERSE:
			{
				cout << "Reversing the linked list......" << endl;
				list.Reverse();
				break;
			}

			case LinkedList::REVERSE_STACK:
			{
				cout << "Reversing the linked list using Stack data structure......" << endl;
				list.ReverseUsingStack();
				break;
			}

			case LinkedList::SORT:
			{
				cout << "Sorting the linked list......" << endl;
				list.Sort();
				break;
			}
			 
			case LinkedList::PRINT:
			{
				cout << "Printing linked list..... " << endl;
				list.Print();
				cout << endl;
				break;
			}
			
			case LinkedList::EXIT:
			{
				cout << "Exiting ... !!!!" << endl;
				return 1;
			}

			default:
			{
				cout << "Invalid choice" << endl;
			}
		}
	}
	cout << endl;
	system("pause");
	return 1;
}