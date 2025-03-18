#include "AVLTree.h"
#include <algorithm>

AVLTree::~AVLTree() {
    deleteTree(root);
}

void AVLTree::deleteTree(Node* node) {
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

void AVLTree::insert(Node* node)
{
	if(root == nullptr)
	{
		root = node;
		node->parent = nullptr;
			return;
	}

	Node* cur = root;
	while(cur != nullptr)
	{
		if(node->key < cur->key)
		{
			if(cur->left == nullptr)
			{
				cur->left = node;
				node->parent = cur;
				cur = nullptr;
			}
			else
			{
				cur = cur->left;
			}
		}
		else
		{
			if(cur->right == nullptr)
			{
				cur->right = node;
				node->parent = cur;
				cur = nullptr;
			}
			else
				cur = cur->right;
		}
	}

	//node = node->parent;
	//while(node != null)
	//{
		//AVLTreeRebalance(tree, node);
	//}
}
