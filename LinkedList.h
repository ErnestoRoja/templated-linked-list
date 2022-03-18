#pragma once
#include <iostream>
#include "leaker.h"
#include <vector>
#include <exception>
using namespace std;
template <class T>

class LinkedList
{
public:
	struct Node
	{
		T data;
		Node* next = nullptr;
		Node* prev = nullptr;
	};
	// Part 1
	LinkedList();
	~LinkedList();
	void AddHead(const T& data);
	void AddTail(const T& data);
	void AddNodesHead(const T* data, unsigned int count);
	void AddNodesTail(const T* data, unsigned int count);
	unsigned int NodeCount() const;
	void PrintForward() const;
	void PrintReverse() const;
	// Part 2
	Node* Head(); 
	const Node* Head() const; 
	Node* Tail(); 
	const Node* Tail() const; 
	Node* GetNode(unsigned int index);
	const Node* GetNode(unsigned int index) const;
	T& operator[](unsigned int index);
	const T& operator[](unsigned int index) const;
	Node* Find(const T& data);
	const Node* Find(const T& data) const;
	void FindAll(vector<Node*>& outData, const T& value) const;
	LinkedList(const LinkedList<T>& list);
	LinkedList<T>& operator=(const LinkedList<T>& rhs);
	// Part 3
	void InsertAfter(Node* node, const T& data);
	void InsertBefore(Node* node, const T& data);
	void InsertAt(const T& data, unsigned int index);
	bool operator==(const LinkedList<T>& rhs);
	//Part 4
	bool RemoveHead();
	bool RemoveTail();
	bool RemoveAt(unsigned int index);
	unsigned int Remove(const T& data);
	void Clear();
	void PrintForwardRecursive(const Node* node) const;
	void PrintReverseRecursive(const Node* node) const;

private:
	unsigned int count = 0;
	Node* head = nullptr;
	Node* tail = nullptr;
	Node* currentNode = nullptr;
};

// Part 1

template <class T>
LinkedList<T>::LinkedList() 
{
	count = 0;
	head = nullptr;
	tail = nullptr;
}

template <class T>
void LinkedList<T>::AddHead(const T& data)
{
	Node* currentNode = new Node;
	currentNode->data = data;
	currentNode->next = nullptr;
	currentNode->prev = nullptr;
	if (head == nullptr)
	{
		head = currentNode;
		tail = currentNode;
	}
	else
	{
		currentNode->next = head;
		head->prev = currentNode;
		head = currentNode;
	}
	count++;
}

template <class T>
void LinkedList<T>::AddTail(const T& data)
{
	Node* currentNode = new Node;
	currentNode->data = data;
	currentNode->next = nullptr;
	currentNode->prev = nullptr;
	if (tail == nullptr)
	{
		head = currentNode;
	}
	else
	{
		tail->next = currentNode;
		currentNode->prev = tail;
	}
	tail = currentNode;
	count++;
}

template <class T>
void LinkedList<T>::AddNodesHead(const T* data, unsigned int count)
{
	for (unsigned int i = count; i > 0; i--)
	{
		AddHead(data[i - 1]);
	}
}

template <class T>
void LinkedList<T>::AddNodesTail(const T* data, unsigned int count)
{
	for (unsigned int i = 0; i < count; i++)
	{
		AddTail(data[i]);
	}
}

template <class T>
unsigned int LinkedList<T>::NodeCount() const
{
	return count;
}

template <class T>
void LinkedList<T>::PrintForward() const
{
	Node* currentNode = head;
	while (currentNode != nullptr)
	{
		cout << currentNode->data << endl;
		currentNode = currentNode->next;
	}
}

template <class T>
void LinkedList<T>::PrintReverse() const
{
	Node* currentNode = tail;
	while (currentNode != nullptr)
	{
		cout << currentNode->data << endl;
		currentNode = currentNode->prev;
	}
}

template <class T>
LinkedList<T>::~LinkedList()
{
	currentNode = head;
	while (currentNode != nullptr)
	{
		Node* tempNode = currentNode->next;
		delete currentNode;
		currentNode = tempNode;
	}
}

// Part 2

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::Head()
{
	 return head;
}

 template <class T>
 const typename LinkedList<T>::Node* LinkedList<T>::Head() const
 {
	 return head;
 }

 template<class T>
 typename LinkedList<T>::Node* LinkedList<T>::Tail()
 {
	 return tail;
 }
 template<class T>
 const typename LinkedList<T>::Node* LinkedList<T>::Tail() const
 {
	 return tail;
 }

 template <class T>
 typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index)
 {
	 if (index >= count)
	 {
		 throw out_of_range("The index is out of range.");
	 }
	 else
	 {
		 unsigned int indexPos = 0;
		 Node* currentNode = head;
		 while (indexPos != index)
		 {
			 currentNode = currentNode->next;
			 indexPos++;
		 }
		 return currentNode;
	 }
 }

 template <class T>
 const typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) const
 {
	 if (index >= count)
	 {
		 throw out_of_range("The index is out of range.");
	 }
	 else
	 {
		 unsigned int indexPos = 0;
		 Node* currentNode = head;
		 while (indexPos != index)
		 {
			 currentNode = currentNode->next;
			 indexPos++;
		 }
		 return currentNode;
	 }
 }

 template <class T>
 T& LinkedList<T>::operator[](unsigned int index)
 {
	 return GetNode(index)->data;
 }

 template <class T>
 const T& LinkedList<T>::operator[](unsigned int index) const
 {
	 return GetNode(index)->data;
 }

 template <class T>
 typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data)
 {
	 Node* currentNode = head;
	 while (currentNode != nullptr)
	 {
		 if (currentNode->data == data)
		 {
			 return currentNode;
		 }
		 currentNode = currentNode->next;
	 }
	 return nullptr;
 }

 template <class T>
 const typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) const
 {
	 Node* currentNode = head;
	 while (currentNode != nullptr)
	 {
		 if (currentNode->data == data)
		 {
			 return currentNode;
		 }
		 currentNode = currentNode->next;
	 }
	 return nullptr;
 }

 template <class T>
 void LinkedList<T>::FindAll(vector<Node*>& outData, const T& value) const
 {
	 Node* currentNode = head;
	 unsigned int listSize = 1;
	 while (currentNode->next != nullptr)
	 {
		 listSize++;
		 currentNode = currentNode->next;
	 }
	 
	 Node* tempNode = head;
	 for (unsigned int i = 0; i < listSize; i++)
	 {
		 if (tempNode->data == value)
		 {
			 outData.push_back(tempNode);
		 }
		 tempNode = tempNode->next;
	 }
 }

 template <class T>
 LinkedList<T>::LinkedList(const LinkedList<T>& list)
 {
	for (unsigned int i = 0; i < list.count; i++) 
	{
		 AddTail(list.GetNode(i)->data);
	 }
 }

 template <class T>
 LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs)
 {
	 Node* currentNode = head;
	 while (currentNode->next != nullptr)
	 {
		 head = head->next;
		 delete currentNode;
		 currentNode = head;
	 }
	 delete currentNode;
	 head = nullptr;
	 tail = nullptr;
	 count = 0;

	 for (unsigned int i = 0; i < rhs.count; i++)
	 {
		 AddTail(rhs.GetNode(i)->data);
	 }
	 return *this;
 }

 // Part 3
 template <class T>
 void LinkedList<T>::InsertAfter(Node* node, const T& data)
 {
	 Node* currentNode = new Node;
	 currentNode->data = data;
	 node->next->prev = currentNode;
	 currentNode->next = node->next;
	 currentNode->prev = node;
	 node->next = currentNode;
	 count++;
 }

 template <class T>
 void LinkedList<T>::InsertBefore(Node* node, const T& data)
 {
	 Node* currentNode = new Node;
	 currentNode->data = data;
	 node->prev->next = currentNode;
	 currentNode->prev = node->prev;
	 currentNode->next = node;
	 node->prev = currentNode;
	 count++;
 }

 template <class T>
 void LinkedList<T>::InsertAt(const T& data, unsigned int index)
 {
	 if (index > count)
	 {
		 throw out_of_range("The index is out of range.");
	 }
	 else if (index == 0)
	 {
		 AddHead(data);
	 }
	 else if (index == count)
	 {
		 AddTail(data);
	 }
	 else
	 {
		 Node* currentNode = head;
		 for (unsigned int i = 0; i < index; i++)
		 {
			 currentNode = currentNode->next;
		 }
		 InsertBefore(currentNode, data);
	 }
 }

 template <class T>
 bool LinkedList<T>::operator==(const LinkedList<T>& rhs)
 {
	 if (count != rhs.count)
	 {
		 return false;
	 }
	 Node* currentNode = head;
	 for (unsigned int i = 0; i < count; i++)
	 {
		 if (currentNode->data != rhs.GetNode(i)->data)
		 {
			 return false;
		 }
		 currentNode = currentNode->next;
	 }
	 return true;
 }

 // Part 4

 template <class T>
 bool LinkedList<T>::RemoveHead()
 {
	if (head == nullptr)
	 {
		 return false;

	 }
	 else if (head->next == nullptr)
	 {
		 Node* currentNode = head;
		 delete currentNode;
		 head = nullptr;
		 tail = nullptr;
		 count--;
		 return true;
		 
	 }
	 else
	 {
		 Node* currentNode = head;
		 head->next->prev = nullptr;
		 head = head->next;
		 delete currentNode;
		 count--;
		 return true;
	 }
 }

 template <class T>
 bool LinkedList<T>::RemoveTail()
 {
	 if (tail == nullptr)
	 {
		 return false;
	 }
	 else if (tail->prev == nullptr)
	 {
		 Node* currentNode = tail;
		 delete currentNode;
		 head = nullptr;
		 tail = nullptr;
		 count--;
		 return true;
		 
	 }
	 else
	 {
		 Node* currentNode = tail;
		 tail->prev->next = nullptr;
		 tail = tail->prev;
		 delete currentNode;
		 count--;
		 return true;
	 }
 }

 template <class T>
 bool LinkedList<T>::RemoveAt(unsigned int index)
 {
	 if (index > count)
	 {
		 return false;
	 }
	 else
	 {
		 Node* currentNode = GetNode(index);
		 currentNode->prev->next = currentNode->next;
		 currentNode->next->prev = currentNode->prev;
		 delete currentNode;
		 count--;
		 return true;
	 }
 }

 template <class T>
 unsigned int LinkedList<T>::Remove(const T& data)
 {
	 unsigned int removalCount = 0;
	 unsigned int listIndex = 0;

	 Node* currentNode = head;
	 Node* tempNode = nullptr;
	 while (currentNode != nullptr)
	 {
		tempNode = currentNode->next;

		 if (currentNode->data == data)
		 {
			 RemoveAt(listIndex);
			 removalCount++;
		 }
		 else 
		 {
			 listIndex++;
		 }
		 currentNode = tempNode;
	 }
	 return removalCount;
 }

 template <class T>
 void LinkedList<T>::Clear()
 {
	 Node* currentNode = head;
	 while (currentNode->next != nullptr)
	 {
		 head = head->next;
		 delete currentNode;
		 currentNode = head;
	 }
	 delete currentNode;
	 head = nullptr;
	 tail = nullptr;
	 count = 0;
 }

 template <class T>
 void LinkedList<T>::PrintForwardRecursive(const Node* node) const
 {
	 if (node == nullptr)
	 {
		 return;
	 }
	 else
	 {
		 cout << node->data << endl;
		 PrintForwardRecursive(node->next);
	 }
 }

 template <class T>
 void LinkedList<T>::PrintReverseRecursive(const Node* node) const
 {
	 if (node == nullptr)
	 {
		 return;
	 }
	 else
	 {
		 cout << node->data << endl;
		 PrintReverseRecursive(node->prev);
	 }
 }

