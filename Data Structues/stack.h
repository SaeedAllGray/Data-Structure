//  stack.h
//  stack
//
//  Created by Saeed All Gharaee @SaeedAG
//  Copyright © 2019-2020 Saeed. All rights reserved.
#include <iostream>
#include<vector>

using namespace std;
template <class type>
class Stack1
{
public:
	
	Stack1():top(-1){}
	
	type Pop();
	void Push(type pushThis);
	void Print();
	bool IsEmpty(){return top==-1;}
//	void Graphic();
	
	type GetTop(){ return top; }
private:
	type top;
//	int maxSize=100;
	vector<type> stack;
};
template <class type>
void Stack1<type>::Print()
{
	for (int i=0;i<=top;i++) 
	{
		i==0?cout<<" _\n":NULL;
		cout<<'|'<<stack[i]<<"|"<<"\n";
	}
	cout<<'\n';
}
template <class type>
type Stack1<type>::Pop()
{
	type stuffData = stack[stack.size()-1];
	stack.pop_back();
	top--;
	return stuffData;
}
template <class type>
void Stack1<type>::Push(type pushThis)
{
	stack.push_back(pushThis);
	top++;
}
