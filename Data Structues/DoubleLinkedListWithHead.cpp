#include <iostream>

using namespace std;
class DoubleLinkedList;
class DoubleNode
{
public:
	friend class DoubleLinkedList;
	DoubleNode();
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
		head = new DoubleNode;
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
	current = head;
	while (current->data > addThis->data) 
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
	while(current->left != head)
	{
		if(current==head)
			cout<<"HEAD";
		cout<<current->data<<" <--> ";
		current->left = current;
		current->right = current->right->right;
		current = current->right;
	
	}
}

int main(int argc, char *argv[]) 
{
	DoubleNode a;	

}