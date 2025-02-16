#include <iostream>
#include <string>
#include <stdexcept>
#include "HybridList.h"
using namespace std;

HybridList::HybridList() {}

HybridList::HybridList(int blockSize) {
	if (blockSize <= 0)
		throw out_of_range("Invalid block size " + to_string(blockSize));
	this->blockSize = blockSize;
}

HybridList::HybridList(const HybridList& h)
{
    if(h.block_size() <= 0)
        throw out_of_range("Invalid block size " + to_string(blockSize));
    this->blockSize = h.block_size();
    if(h.capacity() <= 0)
        throw out_of_range("Invalid size " + to_string(size());
    numElements = h.capacity();
    for(int i = 0; i < numElements; i++)
    {
        push_back(h.at(i));
    }
}

HybridList::~HybridList() {
	clear();
}

int HybridList::size() const {
	return numElements;
}

int HybridList::capacity() const {
	return numBlocks * blockSize;
}

int HybridList::block_size() const {
	return blockSize;
}

HybridListNode* HybridList::front() const {
	return head;
}

HybridListNode* HybridList::back() const {
	return tail;
}

HybridList& operator=(const HybridList& h)
{
   clear();
   for(int i = 0; i < h.size(); i++)
       push_back(h.at(i));
}

double& HybridList::at(int index) const {
	HybridListNode* curNode = head;
	int elementsSearched = 0;

	if (index < 0 || index >= numElements)
		throw out_of_range("Invalid index " + to_string(index));

	// Iterate through all blocks to identify block containing the index
	while (curNode != nullptr) {
		if (index < elementsSearched + curNode->size()) {
			// Element is in this block so just return the correct element from
			// this block
			return curNode->at(index - elementsSearched);
		}
		// Element is not in this block so add the number of elements in the
		// block to the number of elements searched
		elementsSearched += curNode->size();
		curNode = curNode->next;
	}

	// Iterator went beyond last block so something went horribly wrong
	abort();
}

void HybridList::push_back(double value) {
	if (numBlocks == 0) {
		// Hybrid list is empty so creating a new node that will be both the head
		// and tail and append the element to it
		HybridListNode* newTail = new HybridListNode(blockSize);
		newTail->push_back(value);
		tail = newTail;
		head = newTail;
		numBlocks = 1;
	}
	else if (tail->size() == blockSize) {
		// Tail node is full so create a new tail node and copy the back half of
		// the old tail node to the new tail node
		HybridListNode* newTail = new HybridListNode(blockSize);

		// Copy just under half of elements from old tail to new tail
		for (int i = blockSize / 2 + 1; i < blockSize; i++)
			newTail->push_back(tail->at(i));
		tail->resize(blockSize / 2 + 1);
		//cout << tail->size() << endl;
		// Append new item to new tail
		newTail->push_back(value);
		tail->next = newTail;
		//cout << newTail->size() << endl;
		//cout << "Tail: " << tail << endl;
		//cout << "New tail: " << newTail << endl;
		tail = newTail;
		numBlocks++;
	}
	else
		tail->push_back(value);	// Tail isn't full so just append to tail
	
	numElements++;
}

void HybridList::pop_back()
{
    if(numElements <= 0)
        throw out_of_range("Hybrid List Empty");
    tail.pop_back();
    if(tail.size() = 0)
    {
        HybridListNode currNode = head;
        while(currNode->next !=tail)
            currNode = currNode->next;
        tail = currNode;
    }
}

void HybridList::insert(int index, double value)
{   
    int nodeIndex;
    //check to see if there is only 1 block
    if(numBlocks == 0)
        nodeIndex = index;
    //assigns nodeIndex for the index within the proper block
    else
        nodeIndex = index / numBlocks;
    //assigns localIndex to the proper index for the Bounded Array we want to address

    int localIndex = index % numBlocks;
    HybridListNode currNode = head;
    for(int i = 0; i = nodeIndex; i++)
    {
        currNode = currNode->Next;
    }
    if(currNode.size() == blockSize)
    {
        if(currNode == tail)
        {
            push_back(currNode.at(blockSize));
            currNode[localIndex] = value;
        }    
        else
        {
            insert(index + (blockSize - localindex), currentNode[blockSize]);
            for(int i = 0; i < blockSize - localIndex; i++)
            {
                currNode[blockSize - i] = *currNode[localIndex + 1];
            }
            currNode[localIndex] = value;
        }
    }
}

void erase(int index)
{
    int nodeIndex;
    //check to see if there is only 1 block
    if(numBlocks == 0)
        nodeIndex = index;
    //assigns nodeIndex for the index within the proper block
    else
        nodeIndex = index / numBlocks;
    //assigns localIndex to the proper index for the Bounded Array we want to address

    int localIndex = index % numBlocks;
    HybridListNode currNode = head;
    for(int i = 0; i = nodeIndex; i++)
    {
        currNode = currNode->Next;
    }
    currNode.erase(localIndex);
}

void HybridList::clear() {
	HybridListNode* curNode = head, * nextNode = nullptr;
	// Iterate through each node starting from the head and delete it
	while (curNode != nullptr) {
		nextNode = curNode->next;
		delete curNode;
		curNode = nextNode;
	}
	head = tail = nullptr;
	numElements = numBlocks = 0;
}


