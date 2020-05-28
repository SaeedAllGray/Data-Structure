//  stack.cpp
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
	
	void Pop();
	void Push(type pushThis);
	void Print();
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
void Stack1<type>::Pop()
{
	stack.pop_back();
	top--;
}
template <class type>
void Stack1<type>::Push(type pushThis)
{
	stack.push_back(pushThis);
	top++;
}
int main(){
	Stack1<char> s;
	s.Push('S');
	s.Push('T');
	s.Push('A');
	s.Push('C');
	s.Push('k');
//	s.Pop();
	s.Print();
//	s.Graphic();
	cout<<s.GetTop();
	
}