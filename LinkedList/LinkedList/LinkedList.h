#pragma once
#include <iostream>
#include <stack>
#include <set>

struct Node
{
	int data_;
	Node* next_;
};

class LinkedList
{
private:
	Node* head_;
	Node* curr_;
	Node* prev_;
	Node* Next;
	int mLength_;
	
public:
	
	LinkedList();
	~LinkedList();

	enum Operations
	{
		INSERT_BEGIN = 1,
		INSERT_END,
		INSERT_POS,
		DELETE_POS,
		SEARCH,
		UPDATE,
		REVERSE,
		REVERSE_STACK,
		SORT,
		LENGTH,
		PRINT,
		EXIT = 12
	};
	
	void InsertAtBeginning(const int data);
	void InsertAtEnd(const int data);
	void InsertAtPosition(const int data, const int position);
	void Delete(const int position);
	bool Search(const int data);
	void Update(const int position, const int data);
	void Reverse();
	void ReverseUsingStack();
	void Sort();
	int GetLength();
	void Print();
};