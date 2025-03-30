#include "RedBlackTree.h"
#include <algorithm>

RedBlackTree::~RedBlackTree() {
    deleteTree(root);
}

void RedBlackTree::deleteTree(RBTNode* node) {
    // Recursively remove all nodes in the BST (used by the destructor). 
    // By doing this recursively, we start removing nodes from the bottom
    // of the tree (leaf nodes), which is most efficiently because it does
    // not require replacing any nodes.

    if (node == nullptr)
        return;

    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

void RedBlackTree::insert(RBTNode* node)
{
	BSTInsert(node);
	node->red = true;
	RBTreeBalance(node);
}

void BSTInsert(Node* node)
{
	if(root == nullptr)
		root-> = node;
	else
	{
		Node* currentNode = root;
		while(currentNode != nullptr)
		{
			if(node->key < currentNode->key)
				if(current->left == nullptr)
				{
					currentNode->left = node;
					currentNode = nullptr;
				}
				else
					currentNode = currentNode->left;
			else
			{
				if(currentNode->right == nullptr)
				{
					currentNode->right = node;
					currentNode = nullptr;
				}
				else
					currentNode = currentNode->right;
			}
		}
	}
}

void RBTreeBalance(Node* node)
{
	if(node->parent == nullptr)
	{
		node->red = false;
		return;
	}
	if(node->parent->red == false)
		return;
	Node* parent = node->parent;
	Node* grandparent = RBTreeGetGrandparent(node);
	Node* uncle = RBTreeGetUncle(node);
	Node* tempParent = nullptr;
	Node* tempGrandParent = nullptr;
	Node* temp
	if(uncle != nullptr && uncle->red == true)
	{
		parent->red = uncle->red = false;
		grandparent->red = true;
		RBTreeBalance(grandparent);
		return;
	}
	if(node == parent->right && parent == grandparent->left)
	{
		//Rotate Left
		node = parent;
		parent = node->parent;
	}
	else if(node == parent->left && parent == grandparent->right)
	{
		//Rotate Right
		node = parent;
		parent = node->parent;
	}
	parent->red = true;
	if(node == parent->left)
		//Rotate Right
	else
		//Rotate Left
}

Node* RBTreeGetGrandparent(Node* node)
{
	if(node-> parent == nullptr)
		return nullptr;
	return node->parent->parent;
}

Node* RBTreeGetUncle(Node* node)
{
	Node* grandparent = nullptr;
	if(node->parent !- nullptr)
		grandparent = node->parent->parent;
	if(grandparent == nullptr)
		return nullptr;
	if(grandparent->left == node->parent)
		return grandparent->right;
	else
		return grandparent->left;
}

int main()
{
	RedBlackTree a;
	RBTNode* aRoot = new RBTNode(22);
	a.insert(aRoot);
	a.insert(new RBTNode(11));
	a.insert(new RBTNode(33));
	a.insert(new RBTNode(55));
	a.insert(new RBTNode(44));
	std::cout << aRoot->key << std::endl;
	std::cout << aRoot->left->key << " " << aRoot->right-
		>key << std::endl;
	std::cout << aRoot->right->left->key << " " << aRoot-
		>right->right->key << std::endl;
}
