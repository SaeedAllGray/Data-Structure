#include <iostream>

using namespace std;
class DoubleLinkedList;
class DoubleNode
{
public:
	friend class DoubleLinkedList;
	DoubleNode(){};
	DoubleNode(int dataInput):data(dataInput){}
private:
	int data;
	DoubleNode *right, *left;
};
class DoubleLinkedList
{
public:
	DoubleLinkedList()
	{ 
		head = new DoubleNode(0);
		head->left = head->right = head;
	}
	void Insert(int newData);
	void Delete(int staffData);
	void print();
private:
	DoubleNode *head;
};
void DoubleLinkedList::Insert(int newData)
{
	DoubleNode* addThis, *current;
	addThis = new DoubleNode(newData);
	current = head->right;
	if(current == head)
	{
		head->right = head->left = addThis;
		addThis->left = addThis ->right = head;
		return;
	}
	while (current->data < addThis->data) 
	{
		current->left = current;
		current->right = current->right->right;
		current = current->right;
	}
	current->right->left = addThis;
	addThis->right = current->right;
	addThis->left = current;
	current->right = addThis;
	
}
void DoubleLinkedList::Delete(int staffData)
{
	DoubleNode *current;
	current = head;
	while(current->data != staffData)
	{
		current->left = current;
		current->right = current->right->right;
		current = current->right;
	}
	current->left->right = current->right;
	current->right->left = current->left;
	delete current;
}
void DoubleLinkedList::print()
{
	DoubleNode *current;
	current = head;
	while(current->right != head )
	{
		if(current==head)
		{
			cout<<"HEAD <--> ";
			current = current->right;
		}
		cout<<current->data<<" <--> ";
		current = current->right;
	}
}

int main() 
{
	DoubleLinkedList dl;

	dl.Insert(2);
//	dl.Insert(3);
	dl.print();	

}