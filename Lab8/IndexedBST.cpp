#include "IndexedBST.h"

Node* IndexedBST::search(double desiredKey) {
    Node* cur = root;
    while (cur != nullptr) {
        // Return the node if the key matches
        if (cur->key == desiredKey) {
            return cur;
        }

        // Navigate to the left if the search key is 
        // less than the node's key.
        else if (desiredKey < cur->key) {
            cur = cur->left;
        }

        // Navigate to the right if the search key is 
        // greater than the node's key.
        else {
            cur = cur->right;
        }
    }

    // The key was not found in the tree.
    return nullptr;
}
void IndexedBST::fixHeight(Node* node)
{
	if(node == nullptr)
		return;
	node->leftSize = nodeHeight(node);
	fixHeight(node->left);
	fixHeight(node->right);
}
void IndexedBST::insert(Node* node)
{
	if(root == nullptr)
		root = node;
	else
	{
		Node* currentNode = root;
		while(currentNode != nullptr)
		{
			if(node->key < currentNode->key)
			{
				if(currentNode->left == nullptr)
				{
					currentNode->left = node;
					fixHeight(root);
					currentNode = nullptr;
				}
				else
					currentNode = currentNode->left;
			}
			else
			{
				if(currentNode->right == nullptr)
				{
					currentNode->right = node;
					fixHeight(root);
					currentNode = nullptr;
				}
				else
				{
					currentNode = currentNode->right;
				}
			}
		}
	}
}
bool IndexedBST::remove(double key)
{
	Node* parent = nullptr;
	Node* currentNode = root;
	while(currentNode != nullptr)
	{
		if(currentNode->key == key)
		{
			if(currentNode->left == nullptr && currentNode->right == nullptr)
			{
				if(parent == nullptr)
					root == nullptr;
				else if(parent->left == currentNode)
					parent->left = nullptr;
				else
					parent->right = nullptr;
				fixHeight(root);
				return true;
			}
			else if(currentNode->right == nullptr)
			{
				if(parent == nullptr)
					root = currentNode->left;
				else if(parent->left == currentNode)
					parent->left = currentNode->left;
				else
					parent->right = currentNode->left;
				fixHeight(root);
				return true;
			}
			else
			{
				Node* successor = currentNode->right;
				while(successor->left != nullptr)
				{
					successor = successor->left;
				}

				currentNode->key = successor->key;
				Node* Parent = currentNode;

				currentNode = currentNode->right;
				key = successor->key;
			}
		}
		else if(currentNode->key < key)
		{
			parent = currentNode;
			currentNode = currentNode->right;
		}
		else
		{
			parent = currentNode;
			currentNode = currentNode->left;
		}
	}
	return false;
}
int IndexedBST::nodeHeight(Node* node)
{
	if(node == nullptr)
		return -1;
	return nodeHeight(node->left) + 1;
}
Node* IndexedBST::at(int index) {
    Node* cur = root;
    while (cur != nullptr) {
        if (index == cur->leftSize)
            return cur;     // Found
        else if (index < cur->leftSize)
            cur = cur->left;    // index is in left subtree
        else {
            // index is in right subtree
            index = index - cur->leftSize - 1;
            cur = cur->right;
        }
    }

    return nullptr;
}
