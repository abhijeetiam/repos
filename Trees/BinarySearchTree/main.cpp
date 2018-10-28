#include "BSTNode.h"

BSTNode* root;

int main()
{
	int n;
	root = NULL;		//creating an empty tree with root --> NULL

	while (true)
	{
		cout << "============================TREE MENU=============================" << endl;
		cout << "1: INSERT elements" << endl;
		cout << "2: SEARCH elements" << endl;
		cout << "3: DELETE elements" << endl;
		cout << "4: PRINT elements" << endl;
		//A unival tree(which stands for “universal value”) is a tree where all nodes have the same value.
		cout << "5: UNIVAL [Given a binary tree, we need to count the number of unival subtrees (all nodes that have the same value) elements]" << endl;
		cout << "10: EXIT " << endl;
		cout << "==================================================================" << endl;
		cout << "Enter your choice : ";

		cin >> n;

		switch (n)
		{
		case BSTNode::INSERT:
		{
			cout << "Insert the number of elements to be added into the binary search tree - BST: ";
			cin >> n;

			cout << "Insert the elements to be added into the binary search tree - BST: " << endl;

			while (n != 0)
			{
				int data;
				cin >> data;
				root = BSTNode::Insert(root, data);
				//BSTNode::Print(root);
				n--;
			}

			break;
		}

		case BSTNode::SEARCH:
		{
			cout << "Enter the element to be searched in the binary search tree - BST: " << endl;
			cin >> n;
			if (BSTNode::Search(root, n))
				cout << "Element " << n << " is present in the tree" << endl;
			else
				cout << "Element " << n << " is not present in the tree" << endl;

			break;
		}

		case BSTNode::DELETE:
		{
			cout << "Enter the element to be deleted from the binary search tree - BST: " << endl;
			cin >> n;

			if (BSTNode::Search(root, n))
			{
				root = BSTNode::Delete(root, n);
				cout << "Printing INORDER Traversal post deletion " << endl;
				BSTNode::Print(root, BSTNode::TraversalType::INORDER);
				cout << endl;
			}
			else
				cout << "Element " << n << " is not present in the tree" << endl;

			break;
		}

		case BSTNode::PRINT:
		{
			cout << "Printing INORDER Traversal: " << endl;
			BSTNode::Print(root, BSTNode::TraversalType::INORDER);
			cout << endl;

			cout << "Printing PREORDER Traversal: " << endl;
			BSTNode::Print(root, BSTNode::TraversalType::PREORDER);
			cout << endl;

			cout << "Printing POSTORDER Traversal: " << endl;
			BSTNode::Print(root, BSTNode::TraversalType::POSTORDER);
			cout << endl;

			break;
		}

		case BSTNode::UNIVAL:	//User Post-Order traversal Bottom->Top so that we can count
		{
			cout << "Number of unival subtrees = " << BSTNode::findSingleValueTrees(root) << endl;
			break;
		}

		case BSTNode::EXIT:
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

   	system("pause");
	return 1;
}