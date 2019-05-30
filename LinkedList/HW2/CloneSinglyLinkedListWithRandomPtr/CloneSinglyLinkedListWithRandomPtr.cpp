/*

Clone Singly Linked List With Random Pointer





Problem Statement:



Given a singly LinkedList list of n elements. The data stored in the nodes of the linked list are the continuous sequence of the integral natural numbers i.e. the head node stores the integer 1 , then the  next node stores the integer 2 , so on and so forth till the last node of the linked list stores the integer n. Now, apart the standard next pointer of the linked-list node; there is a special random pointer that may or may not exists on each node. This random pointer of a node can point to any node of the linked list including itself.

Your task is to clone the LinkedList List in an efficient manner both in terms of time and space.



Input Format:



First and only parameter of the function cloneLinkedList, that is to be implemented is the head node pointer of the given LinkedList list.



Output Format:



Return the head node of the newly cloned LinkedList in the cloneLinkedList function.



Then code written by us will traverse the returned linked list (starting from head node) and for each node, it will print one line containing three space separated integers 1) Data of the current node 2) If next node exists, then data of the next node, else -1 3) If random pointed node exists, then data of the random pointed node else -1.



Constraints:



1 <= n <= 100000



Sample Test Case:



Sample Input:





﻿Sample Output:



1 2 3

2 3 -1

3 4 4

4 5 -1

5 -1 -1



Explanation:



Here the newly cloned list will be same as the input linkedlist. Hence, traversing from the head to tail node, code written by us will print 1 (data of the node), then 2 (data of its next node) and then 3 (data of its random pointed node). Now, it will move on the next node and print 2 (data of the node), then 3 (data of its next node), -1 (because this node has no random pointing node). Then it will move to the next node and print in the same fashion.



Note:



You may modify the given input linked-list list for cloning purpose.

SinglyLinkedListNode* cloneLinkedList( SinglyLinkedListNode* head ) 
{
	SinglyLinkedListNode *p1 = head, *p2 = NULL;
	while( p1 ) {
		p2 = p1->next;
		p1->next = new SinglyLinkedListNode( p1->data );
		p1->next->next = p2;
		p1 = p2;
	}

	p1 = head;
	while( p1 ) {
		if( p1->randomPointer ) p1->next->randomPointer = p1->randomPointer->next;
		p1 = p1->next->next;
	}

	SinglyLinkedListNode *head2 = NULL, *tail2 = NULL;
	p1 = head;
	while( p1 ) {
		p2 = p1->next->next;
		if( !head2 )  head2 = tail2 = p1->next;
		else {
			tail2->next = p1->next;
			tail2 = tail2->next;
		}
		tail2->next = NULL;
		p1->next = p2;
		p1 = p2;
	}

	return head2;
}

*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

class SinglyLinkedListNode
{
public:
	int data;
	SinglyLinkedListNode *next;
	SinglyLinkedListNode *randomPointer;

	SinglyLinkedListNode(int node_data)
	{
		this->data = node_data;
		this->next = nullptr;
		this->randomPointer = nullptr;
	}

	void link_random_node(SinglyLinkedListNode *random_node)
	{
		this->randomPointer = random_node;
	}
};

class SinglyLinkedList
{
public:
	SinglyLinkedListNode *head;
	SinglyLinkedListNode *tail;

	SinglyLinkedList()
	{
		this->head = nullptr;
		this->tail = nullptr;
	}

	void insert_node(int node_data)
	{
		SinglyLinkedListNode *node = new SinglyLinkedListNode(node_data);

		if (!this->head)
		{
			this->head = node;
		}
		else
		{
			this->tail->next = node;
		}

		this->tail = node;
	}
};

void print_singly_linked_list_with_random_node(SinglyLinkedListNode *node, string sep);
bool cloneCheck(SinglyLinkedListNode *head, unordered_set<SinglyLinkedListNode *> originalNodes);


// ------------------------------ START ------------------------------

/*
 * @param head: pointer to the head node of the original linkedList
 * @returns the pointer to the newly cloned linkedList head node
 *  For your reference:
 *  class SinglyLinkedListNode
 *  {
 *      int data;
 *      SinglyLinkedListNode *next;
 *      SinglyLinkedListNode *randomPointer;
 *  }
 */
SinglyLinkedListNode *cloneLinkedList(SinglyLinkedListNode *list)
{
	return list;
}

// ------------------------------ STOP -------------------------------

int main()
{
	ostream &ferr = cerr;
	unordered_map<int, SinglyLinkedListNode *> mapper;
	unordered_set<SinglyLinkedListNode *> originalNodes;
	SinglyLinkedList *List = new SinglyLinkedList();

	string linkedList_count_temp;

	getline(cin, linkedList_count_temp);

	int linkedList_count = stoi(ltrim(rtrim(linkedList_count_temp)));

	for (int i = 1; i <= linkedList_count; i++)
	{
		List->insert_node(i);
		mapper[i] = List->tail;
		originalNodes.insert(List->tail);
	}

	for (int i = 1; i <= linkedList_count; i++)
	{
		string linkedList_item_temp;
		getline(cin, linkedList_item_temp);
		int linkedList_item = stoi(ltrim(rtrim(linkedList_item_temp)));
		if (linkedList_item != -1)
			mapper[i]->link_random_node(mapper[linkedList_item]);
	}

	SinglyLinkedListNode *clonedListHeadNode = cloneLinkedList(List->head);

	if (cloneCheck(clonedListHeadNode, originalNodes) == false)
	{
		ferr << "Instead of creating new node, you have used node from the input linked list.";
		ferr << "Any node from the input linked list must not be used in the cloned linked list";
	}
	else
	{
		string seperator = "\n";
		print_singly_linked_list_with_random_node(clonedListHeadNode, seperator);
	}

	return 0;
}

string ltrim(const string &str)
{
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

	return s;
}

string rtrim(const string &str)
{
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end());

	return s;
}

void print_singly_linked_list_with_random_node(SinglyLinkedListNode *node, string sep)
{
	ostream &fout = cout;
	ostream &ferr = cerr;
	unordered_set<SinglyLinkedListNode *> visited;
	string delimitter = " ";
	while (node)
	{
		visited.insert(node);
		if (node->next != nullptr and visited.find(node->next) != visited.end())
		{
			ferr << "The next pointer links in the cloned list are forming a loop";
			return;
		}
		fout << node->data << delimitter;

		if (node->next != nullptr)
		{
			fout << node->next->data << delimitter;
		}
		else
			fout << -1 << delimitter;

		if (node->randomPointer != nullptr)
		{
			fout << node->randomPointer->data;
		}
		else
		{
			fout << "-1";
		}

		node = node->next;

		if (node)
		{
			fout << sep;
		}
	}
}

bool cloneCheck(SinglyLinkedListNode *head, unordered_set<SinglyLinkedListNode *> originalNodes)
{
	SinglyLinkedListNode *tmp = head;
	while (tmp)
	{
		if (originalNodes.find(tmp) != originalNodes.end())
		{
			return false;
		}
		tmp = tmp->next;
	}
	return true;
}

