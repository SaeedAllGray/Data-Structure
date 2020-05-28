//  ArrayLinkedList.cpp
//  Array Linked List
//
//  Created by Saeed All Gharaee @SaeedAG
//  Copyright © 2019-2020 Saeed. All rights reserved.


#include <iostream>
#include <stdlib.h>
using namespace std;

const int Null = -1;
const int Empty = -2;
const int Max = 100;

template <class type>
class ListIterator;
template <class type>
class ArrayLikedList
{
	friend class ListIterator<type>;
public:
	ArrayLikedList()
	{
		for(int i=1;i<Max;i++)
			link[i]=data[i]=Empty;
		start = 0;
	}
	void Insert(type newData);
	void Delete(type stuffData);
	void Reverse();
	bool IsEmpty();
	bool IsFull();
	void print();
	
	
private:
	type data[Max];
	int link[Max];
	int start;

	int FindEmptySlot();
};
template <class type>
int ArrayLikedList<type>::FindEmptySlot()
{
	for(int i=1;i<Max-1;i++)
	{
		if(data[i]==Empty)
			return i;
	}	
	return 0;
}
template <class type>
void ArrayLikedList<type>::Insert(type newData)
{
	if(IsFull())
		return;
	int emptySlot = FindEmptySlot();
	data[emptySlot] = newData;
	if(!start)
	{
		link[emptySlot] = Null;
		start = emptySlot;
		return;
	}
	int current = start, previous = 0;
	while (link[current]!=Empty && data[current] < newData) 
	{
		previous = current;
		current = link[current];
	}
	if(!previous)
	{
		link[emptySlot] = start;
		start = emptySlot;
	}

	else 
	{
		link[previous] = emptySlot;
		link[emptySlot] = current;
	}
}

template <class type>
void ArrayLikedList<type>::Delete(type stuffData)
{
	int current = start, previous = 0;
	while (link[current]!=Empty && data[current] != stuffData) 
	{
		previous = current;
		current = link[current];
	}
	if(link[current]==Empty)
	{
		cout<<"Doesn't Exist.\n";
		return;
	}
	if(!previous)
	{
		start = link[current];
	}
	else 
	{
		link[previous] = link[current];
	}
	current = Empty;
	data[current] = Empty;
}
template <class type>
void ArrayLikedList<type>::Reverse()
{
//	ArrayLikedList<type> reversedList;
	int previous, current, next;
//	reversedList.start = start;
	next = start;
	current = Null;
	while (next != Null)
	{
		previous = current;
		current = next;
		next = link[next];
		link[current] = previous;
	}
	start = current;
//	return reversedList;
}
template <class type>
bool ArrayLikedList<type>::IsEmpty()
{
	if(!start || start == Null)
		return true;
	return false;
}
template <class type>
bool ArrayLikedList<type>::IsFull()
{
	if(FindEmptySlot())
		return false;
	return true;
}
template <class type>
void ArrayLikedList<type>::print()
{
//	for(int current = start;link[current]!=Empty;current = link[current])
//	{
//		cout<<data[current]<<": ["<<link[current]<<"]"<<endl;
//		current = link[current];
//	}
	int current = start;
	cout<<"start: ["<<start<<"]"<<endl;
	while (link[current]!=Empty) 
	{
		cout<<data[current]<<": ["<<link[current]<<"]"<<endl;
		current = link[current];
	}
}
template <class type>
class ListIterator
{
	friend class ArrayLikedList<type>;
public:
	ListIterator(const ArrayLikedList<type> &all):current(all.start),list(all){}
	bool NotNull();
	bool NextNotNull();
	type Next();
	type First();
	
private:
	ArrayLikedList<type> list;
	int current;
};
template <class type>
bool ListIterator<type>::NotNull()
{
	return current != Null;
}
template <class type>
bool ListIterator<type>::NextNotNull()
{
	return current != Null && list.link[current] != Null;
}
template <class type>
type ListIterator<type>::First()
{
	if(list.start != Null)
		return list.data[list.start];
	return Null;
}
template <class type>
type ListIterator<type>::Next()
{
	if(NextNotNull())
	{
		current = list.link[current];
		return list.data[current];
	}
	return Null;
}
int main() 
{
	ArrayLikedList<int> all;


	ListIterator<int> li(all);
	all.Insert(2);


	all.Insert(8);
	all.Insert(0);
	all.Reverse();
	all.print();

//	cout<<all.IsFull();
	
	
	return 0;
}