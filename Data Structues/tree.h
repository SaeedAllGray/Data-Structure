
//  tree.h
//  Tree
//
//  Created by Saeed All Gharaee @SaeedAG
//  Copyright © 2019-2020 Saeed. All rights reserved.

#include <iostream>
#include "stack.h"
using namespace std;

template <class type>
class Tree;
template <class type>
class TreeNode
{
	friend class Tree<type>;
public:
	TreeNode<type>(){}
	
	
protected:
	type data;
	TreeNode<type> *left ,*right;
};
template <class type>
class Tree
{
	friend class TreeNode<type>;
public:
	Tree() { root = NULL; }
	TreeNode<type>* Copy(TreeNode<type>* root);
	
	void PREorderDriver() {RecursivePREorder(root);}
	void INorderDriver() {RecursiveINorder(root);}
	void POSTorderDriver() {RecursivePOSTorder(root);}
	
	void NonRecursiveINorder();
	
private:
	TreeNode<type> *root;
	
	void RecursivePREorder(TreeNode<type> *curRoot);
	void RecursiveINorder(TreeNode<type> *curRoot);
	void RecursivePOSTorder(TreeNode<type> *curRoot);
};
template <class type>
void Tree<type>::RecursivePREorder(TreeNode<type> *curRoot)
{
	if(curRoot)
	{
		cout<<curRoot->data;
		RecursivePREorder(curRoot->left);
		RecursivePREorder(curRoot->right);
	}
}
template <class type>
TreeNode<type>* Tree<type>::Copy(TreeNode<type>* root)
{
	TreeNode<type>* root2;
	if(root)
	{
		root2 = new TreeNode<type>;
		root2->data = root->data;
		root2->left = Copy(root->left);
		root2->right = Copy(root->right);
		return root2;
	}
	else 
		return NULL;
}
template <class type>
void Tree<type>::RecursiveINorder(TreeNode<type> *curRoot)
{
	if(curRoot)
	{
		RecursiveINorder(curRoot->left);
		cout<<curRoot->data;
		RecursiveINorder(curRoot->right);
	}
}
template <class type>
void Tree<type>::RecursivePOSTorder(TreeNode<type> *curRoot)
{
	if(curRoot)
	{
		RecursivePOSTorder(curRoot->left);
		RecursivePOSTorder(curRoot->right);
		cout<<curRoot->data;
	}
}
template <class type>
void Tree<type>::NonRecursiveINorder()
{
	TreeNode<type>* curRoot = root;
	Stack1<TreeNode<type>*> stack;
	while (true) 
	{
		while (curRoot) 
		{
			stack.Push(curRoot);
			curRoot = curRoot->left;
		}
		if(!stack.IsEmpty())
		{
			curRoot = *stack.pop();
			cout<<curRoot->data<<endl;
			curRoot = curRoot->right;
			stack.Push(curRoot);
		}
		else break;
	}
}