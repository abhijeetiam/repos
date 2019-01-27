#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
	head_ = NULL;
	curr_ = NULL;
	mLength_ = 0;
}

LinkedList::~LinkedList()
{
}

void LinkedList::InsertAtBeginning(const int data)
{
	Node* temp = new Node();
	temp->data_ = data;
	temp->next_ = head_;
	head_ = temp;
}

void LinkedList::InsertAtEnd(const int data)
{
	Node* temp = new Node();
	temp->data_ = data;
	temp->next_ = NULL;

	//if linked list does not exist or first node
	if (head_ == NULL)
		head_ = temp;
	else   //if linked list exists we traverse the curr_ ptr to the end
	{
		curr_ = head_;
		while (curr_->next_ != NULL)
			curr_ = curr_->next_;
		curr_->next_ = temp;
	}
}

int LinkedList::GetLength()
{
	if (head_ == NULL)
		mLength_ = 0;
	else
	{
		mLength_ = 0;
		curr_ = head_;
		while (curr_ != NULL)
		{
			mLength_++;
			curr_ = curr_->next_;
		}
	}
	return mLength_;
}

void LinkedList::InsertAtPosition(const int data, const int position)
{
	cout << "Position = " << position << ", Length = " << mLength_ << endl;

	if (head_ == NULL & position != 0)
		cout << "Cannot insert a new node at position " << position << endl;
	else
	{
		if (head_ == NULL && position == 0)
			InsertAtBeginning(data);
		else if (position == mLength_)
			InsertAtEnd(data);
		else
		{
			curr_ = prev_ = head_;
			for (int i = 0; i < position-1; i++)
				prev_ = prev_->next_;
			
			curr_ = prev_->next_;

			Node* temp = new Node();
			temp->data_ = data;
			temp->next_ = curr_;
			prev_->next_ = temp;
		}
	}
}

void LinkedList::Delete(const int position)
{
	if (head_ == NULL)
	{
		cout << "Cannot delete nodes from empty linked list at position " << position << endl;
		return;
	}

	if (position == 1)
	{
		cout << "Deleting 1st node" << endl;
		curr_ = head_;
		head_ = head_->next_;
		delete curr_;
	}
	else if (position == mLength_)
	{
		cout << "Deleting last node" << endl;
		curr_ = head_;

		while (curr_->next_->next_ != NULL)
			curr_ = curr_->next_;

		Node* last = curr_->next_;
		delete last;

		curr_->next_ = NULL;
	}
	else
	{
		cout << "Deleting node : " << position << endl;

		curr_ = prev_ = head_;
		for (int i = 1; i < position - 1; i++)
			prev_ = prev_->next_;

		curr_ = prev_->next_->next_;

		delete prev_->next_;
		prev_->next_ = curr_;
	}
}

bool LinkedList::Search(const int data)
{
	bool bfound = false;
	if (head_ == NULL)
	{
		cout << "Cannot search an empty linked list" << endl;
		return bfound;
	}

	curr_ = head_;

	while (curr_ != NULL)
	{
		if (curr_->data_ == data)
		{
			bfound = true;
			break;
		}
		curr_ = curr_->next_;
	}
	
	return bfound;
}

void LinkedList::Update(const int position, const int data)
{
	if (head_ == NULL)
	{
		cout << "Cannot update an empty linked list" << endl;
		return;
	}

	curr_ = head_;

	for (int i = 1; i < position; i++)
		curr_ = curr_->next_;

	curr_->data_ = data;
}

//Used stack data structure for reversing when popping. Hence Space = O(n), Time = O(n)
void LinkedList::Reverse()
{
	std::stack<Node*> rev;

	if (head_ == NULL)
	{
		cout << "Cannot reverse an empty linked list" << endl;
		return;
	}

	curr_ = head_;

	while (curr_ != NULL)
	{
		rev.push(curr_);
		curr_ = curr_->next_;
	}

	head_ = rev.top();		//IMPORTANT: Make sure you set head_ properly to the first node popped out
	curr_ = head_;
	rev.pop();
	
	while (!rev.empty())
	{
		Node* temp = rev.top();
		curr_->next_ = temp;
		curr_ = temp;
		rev.pop();			//Top returns you the elements in the stack while pop will remove it. Both have to work in tandem
	}

	curr_->next_ = NULL;	//IMPORTANT: Make sure you set last nodes next_ pointer point to NULL or infinite loop
}

//Used set data structure for ordering. Hence Space = O(n), Time = O(n)
void LinkedList::Sort()
{
	std::set<Node*> temp;
	std::set<Node*>::iterator iter;

	if (head_ == NULL)
	{
		cout << "Cannot reverse an empty linked list" << endl;
		return;
	}

	curr_ = head_;

	while (curr_ != NULL)
	{
		temp.insert(curr_);
		curr_ = curr_->next_;
	}

	iter = temp.begin();		//IMPORTANT: Make sure you set head_ is properly to the first node in the set and erase it
	head_ = *iter;
	curr_ = head_;
	temp.erase(iter);

	for(iter = temp.begin(); iter != temp.end(); ++iter)	//Since we erased it we are looping from the 2nd elements in the set
	{
		curr_->next_ = *iter;
		curr_ = *iter;
	}
	curr_->next_ = NULL;	//IMPORTANT: Make sure you set last nodes next_ pointer point to NULL or infinite loop
}

void LinkedList::Print()
{
	const Node* temp = head_;
	while (temp != NULL)
	{
		cout << temp->data_ << "->";
		temp = temp->next_;
	}
	cout << endl;
}
