#pragma once
#include <iostream>

class LinkedList
{
private:
	int data;
	LinkedList* next;

public:
	LinkedList();
	~LinkedList();

	static void InsertAtBeginning(const int i, LinkedList** head);
	static void Print(LinkedList** head);
};

