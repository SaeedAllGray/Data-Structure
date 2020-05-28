//  LinkedList.h
//  Linked List
//
//  Created by Saeed All Gharaee
//  Copyright © 2019-2020 Saeed. All rights reserved.
#include <iostream>

using namespace std;
class ListIterator;
class LinkedList;
////////////////////////////////
class Node
{
private:
	int data;
	Node* nextDataAddress;
public:
	Node();
	Node(int dataInput)
	{
		data=dataInput;
		nextDataAddress = NULL;
	}
	friend class LinkedList;
	friend class ListIterator;
};
///////////////////////////////////
class LinkedList
{
private:
	Node* startAddress;
	friend class ListIterator;
public:
	LinkedList() { startAddress=NULL; }
	void Insert(int newData);
	void Attach(int newData);
	void Delete(int stuffData);
	Node* Find(int data,bool returnItself);
	void Swap(int swapThis,int withThis);
	Node* GetLast();
	void Reverse();
	void Concat(LinkedList &B);
	void print();
	~LinkedList();
};
void LinkedList::Insert(int newData)
{
	Node *addThis, *current, *previous;
	addThis = new Node(newData);
	
	if(!startAddress)// empty list
	{
//		cout<<"1. added to empty list\n";
		startAddress = addThis;
		return;
	}
	current = startAddress;
	previous = NULL;
	
	while(current && current->data < addThis->data)
	{
		previous = current;
		current = current->nextDataAddress;
	}
	if(!previous)// add to first part of list
	{
//		cout<<"2. added to first of the list\n";
		addThis->nextDataAddress = startAddress;
		startAddress = addThis;
	}
	else // otherwise
	{
//		cout<<"3. added to any other part of the list\n";
		previous->nextDataAddress = addThis;
		addThis->nextDataAddress = current;
	}
}
void LinkedList::Reverse()
{
	Node *previous, *current, *next;
	next = startAddress;
	current = NULL;
	while (next) 
	{
		previous = current;
		current = next;
		next = next->nextDataAddress;
		current->nextDataAddress = previous;
	}
	startAddress = current;
}
Node* LinkedList::GetLast()
{
	Node *current;
	current= startAddress;
	if(!startAddress)
		return NULL;
	while (current && current->nextDataAddress) 
	{
		current = current->nextDataAddress;
	}
	return current;
}
void LinkedList::Attach(int newData)
{
	Node *last, *attachThis;
	attachThis = new Node(newData);
	last = GetLast();
	if(!startAddress)
	{
		startAddress = attachThis;
	}	
	else
	{
		last->nextDataAddress = attachThis;
	}
}
//Node* LinkedList::Find(int data,bool returnItself) 
//{
//	Node *current,*previous;
//	current=startAddress;
//	previous = NULL;
//	while(current && current->data!=data)
//	{
//		previous = current;
//		current = current->nextDataAddress;
//	}
//	if(!previous)
//	{
//		startAddress = startAddress->nextDataAddress;
//	}
//	else 
//	{
//		previous->nextDataAddress = current->nextDataAddress;
//	}
//	cout<< returnItself ? current->data : previous->data;
//	return returnItself ? current : previous;
//}
void LinkedList::Swap(int swapThis, int withThis)
{
	Node *current1,*current2,*previous1,*previous2;
	while(current1 && current2)
	{
//		if(current1->data==swapThis)
	}
}
void LinkedList::Delete(int stuffData)
{
	Node *current,*previous;
	current=startAddress;
	previous = NULL;
	while(current && current->data!=stuffData)
	{
		previous = current;
		current = current->nextDataAddress;
	}
	if(!current)//couldn't find
	{
//		cout<<"\ndoesn't exist\n";
		return;
	}
	if(!previous)//ommit from first of the list
	{
//		cout<<"\nommit from first of the list\n";
		startAddress = startAddress->nextDataAddress;
	}
	else // otherwise
	{
//		cout<<"\nommit from other part of the list\n";
		previous->nextDataAddress = current->nextDataAddress;
	}
	delete current;
}

void LinkedList::print()
{
	Node *current;
	current = startAddress;
	while(current)
	{
		cout<<current->data<<" --> ";
		current = current->nextDataAddress;
		current?NULL:cout<<"NULL\n";
	}
}
LinkedList::~LinkedList()
{
	Node *current;
	current = startAddress;

	while (current)
	{
		startAddress = current->nextDataAddress;
		delete current;
		current = startAddress;	
	}
}
/////////////////////////////////////////////////////////////
class ListIterator
{
private:
	const LinkedList &list;
	Node *current;
public:
	friend class LinkedList;
	ListIterator(const LinkedList &l):list(l),current(l.startAddress){}
	bool NotNull();
	bool NextNotNull();
	int First();
	int Next();
};
bool ListIterator::NotNull()
{
	return current != NULL;
}
bool ListIterator::NextNotNull()
{
	return current && current->nextDataAddress;
}
int ListIterator::First()
{
	if(list.startAddress)
		return list.startAddress->data;
	return NULL;
}
int ListIterator::Next()
{
	if(current && current->nextDataAddress)
	{
		current = current->nextDataAddress;
		return current->data;
	}
	return NULL;
}
int sum(LinkedList &l)
{
	ListIterator li(l);
	int result = 0;
	result = li.First();
	if(!li.NotNull())
		return 0;
	while (li.NextNotNull())
	{
		result +=li.Next();
	}
	return result;
}
void LinkedList::Concat(LinkedList &B)
{
	ListIterator LiB(B);
	if(LiB.NotNull()) 
	{
		this->Insert(LiB.First());
	}
	while (LiB.NextNotNull()) 
	{
		this->Insert(LiB.Next());
	}
	
}