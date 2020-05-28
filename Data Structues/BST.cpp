//  BST.cpp
//  Binary Search Tree
//
//  Created by Saeed All Gharaee @SaeedAG
//  Copyright © 2019-2020 Saeed. All rights reserved.

#include <iostream>

using namespace std;
template<class type>
class BSTNode;
template<class type>
class BSTTree;
template<class type>
class Element
{
	friend class BSTNode<type>;
	friend class BSTTree<type>;
public:
	Element<type>(){}
	Element<type>(type keyInput):key(keyInput){}
private
	type key;
};
template<class type>
class BSTNode
{
	friend class BSTTree<type>;
	friend class Element<type>;
public:
	BSTNode<type>():left(NULL),right(NULL){}
private:
	Element<type> data;
	BSTNode<type> *right, *left;
};

template<class type>
class BSTTree
{
	friend class BSTNode<type>;
	friend class Element<type>;
public:
	BSTTree<type>(){ root = NULL; }
	bool Insert(Element<type> newData);
	
	void INorderDriver() {RecursiveINorder(root);}
private:
	BSTNode<type>* root;
	
	void RecursiveINorder(BSTNode<type> *curRoot);

};
template<class type>
bool BSTTree<type>::Insert(Element<type> newData)
{
	BSTNode<type> *current,*previous;
	BSTNode<type> *current,*previous;
	current = root;
	previous = NULL;
	while (current) 
	{
		previous = current;
		if(current->data.key == newData.key)
			return false;
		if(current->data.key > newData.key)
			current = current->left;
		else 
			current = current->right;
	}
	current = new BSTNode<type>;
	current->data = newData;
	current->left = current->right = NULL;
	if(!root) 
	{
		root = current;
		return true;
	}
	if(newData.key < previous->data.key)
		previous->left = current;
	else
		previous->right = current;
	return true;
}
template <class type>
void BSTTree<type>::RecursiveINorder(BSTNode<type> *curRoot)
{
	if(curRoot)
	{
		RecursiveINorder(curRoot->left);
		cout<<curRoot->data.key;
		RecursiveINorder(curRoot->right);
	}
}
int main() 
{
	Element<int> e(3);
	Element<int> e3(8);
	Element<int> eo3(1);
	BSTTree<int> bst;
	bst.Insert(e);
	bst.Insert(e3);
//	bst.Insert(eo3);
	bst.INorderDriver();

	
}