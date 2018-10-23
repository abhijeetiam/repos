#include "BSTNode.h"

BSTNode::BSTNode()
{
}

BSTNode::~BSTNode()
{
}

BSTNode* BSTNode::Create(int data)
{
	BSTNode* node = new BSTNode();
	node->data_ = data;
	node->left_ = NULL;
	node->right_ = NULL;
	return node;
}

BSTNode* BSTNode::Insert(BSTNode* root, int data)
{
	if (root == NULL)
	{
		//This print will always hit since root->left_ or root_right_ will be NULL for newly to be created nodes
		//cout << "Root is NULL and data to be added = " << data << endl;		
		root = BSTNode::Create(data);
		return root;
	}
	else if (data <= root->data_)			//Takes care of duplicates
		root->left_ = BSTNode::Insert(root->left_, data);
	else
		root->right_ = BSTNode::Insert(root->right_, data);

	return root;
}

bool BSTNode::Search(BSTNode* root, int data)
{
	if (root == NULL)
	{
		//cout << "Element " << data << " not present in the tree" << endl;
		return false;
	}

	if (data == root->data_)		//Node to be searched found
		return true;

	if (data < root->data_)
		Search(root->left_, data);
	else
		Search(root->right_, data);
}

BSTNode* BSTNode::Delete(BSTNode* root, int data)
{
	if (root == NULL)
		return false;
	else
	{
		if (data < root->data_)
			root->left_ = Delete(root->left_, data);
		else if (data > root->data_)
			root->right_ = Delete(root->right_, data);
		else if (data == root->data_)		//Node to be deleted found
		{
			BSTNode::NodeType nodeType = BSTNode::CheckNodeType(root);

			if(nodeType == LEAF)
				root = NULL;
			else if (nodeType == SINGLE_PARENT)
			{
				if (root->left_ != NULL)
				{
					root->data_ = root->left_->data_;
					root->left_ = NULL;
				}
				else
				{
					root->data_ = root->right_->data_;
					root->right_ = NULL;
				}
			}
			else if (nodeType == DOUBLE_PARENT)			//Which child node to replace by in case of 2 children ???
			{
				if (root->left_->data_ < root->right_->data_)
				{
					root->data_ = root->left_->data_;
					root->left_ = NULL;
				}
				else
				{
					root->data_ = root->right_->data_;
					root->right_ = NULL;
				}
			}
		}
	}
	return root;
}

BSTNode::NodeType BSTNode::CheckNodeType(BSTNode* root)
{
	if (root->left_ == NULL && root->right_ == NULL)
		return BSTNode::NodeType::LEAF;
	else if (root->left_ != NULL && root->right_ != NULL)
		return BSTNode::NodeType::DOUBLE_PARENT;
	else
		return BSTNode::NodeType::SINGLE_PARENT;
}

void BSTNode::Print(BSTNode* root, BSTNode::TraversalType type)
{
	if (root == NULL)
		return;

	switch (type)
	{
		case INORDER:			//Left -> Root -> Right
		{
			Print(root->left_, type);
			cout << root->data_ << " -> ";
			Print(root->right_, type);
			break;
		}
		case PREORDER:			//Root -> Left -> Right
		{
			cout << root->data_ << " -> ";
			Print(root->left_, type);
			Print(root->right_, type);
			break;
		}
		case POSTORDER:			//Left -> Right -> Root
		{
			Print(root->left_, type);
			Print(root->right_, type);
			cout << root->data_ << " -> ";
			break;
		}
		default:
		{
			cout << " Invalid Traversal type" << endl;
			break;
		}
	}
}

int BSTNode::findSingleValueTrees(BSTNode* root)
{
	int nUnivalSubtrees = 0;

	if(root == NULL)
	{ }
		
	nUnivalSubtrees += findSingleValueTrees(root->left_);
	nUnivalSubtrees += findSingleValueTrees(root->right_);

	return nUnivalSubtrees;
}

int BSTNode::IsSubTree(BSTNode* root)
{
	if (root == NULL)
		return 0;
	if ((root->left_ == NULL) && (root->right_ == NULL))
		return 1;
	else if ((root->left_ != NULL) && (root->right_ == NULL) && (root->left_->data_ == root->data_))
		return 2;
	else if ((root->right_ != NULL) && (root->left_ == NULL) && (root->right_->data_ == root->data_))
		return 2;
	else if (root->left_->data_ == root->right_->data_ == root->data_)
		return 3;
	else return 0;
}