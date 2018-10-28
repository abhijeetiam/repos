#pragma once
#include <iostream>

using namespace std;

class BSTNode
{
public:
	BSTNode();
	~BSTNode();

	enum Operations
	{
		INSERT = 1,
		SEARCH,
		DELETE,
		PRINT,
		UNIVAL,
		EXIT = 10
	};

	enum TraversalType
	{
		INORDER,
		PREORDER,
		POSTORDER
	};

	enum NodeType
	{
		LEAF,
		SINGLE_PARENT,
		DOUBLE_PARENT
	};

	static BSTNode* Create(int data);
	static BSTNode* Insert(BSTNode* root, int data);		//Should return BSTNode* since we need Create a node and link it to existing tree
	static BSTNode* Delete(BSTNode* root, int data);		//Should return BSTNode* since we need Delete a node and link it to existing tree
	static bool Search(BSTNode* root, int data);			//Return bool if element exists in a tree
	static void Print(BSTNode* root, BSTNode::TraversalType);
	static BSTNode::NodeType CheckNodeType(BSTNode* root);			//Return type of node LEAF, SINGLE_PARENT, DOUBLE_PARENT
	static int findSingleValueTrees(BSTNode* root);
	static int IsSubTree(BSTNode* root);
		
private:
	int data_;
	BSTNode* left_;
	BSTNode* right_;
};

