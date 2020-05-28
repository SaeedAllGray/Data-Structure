#include <iostream>
#include <string>
#include "stack.h"

using namespace std;
enum Priority {power=4 ,mult=3, devision=3, sum=2, sub=2};

string PostfixToInfix(Stack1 &stack,string postfix){
	for(int i=0;i<postfix.size();i++)
	{
		if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/' || postfix[i]=='^')
		stack.Push
	}
}


class PreInPost
{
public:
	PreInPost(string a):preInPost(a){}
	string PostfixToInfix(Stack1 &stack,string postfix);
//	string InfixToPostfix(string infix);
	char OperatorDetector();
private:
	string preInPost;
};

string PreInPost::PostfixToInfix(Stack1 &stack,string postfix)
{
	for(int i=0;i<postfix.size();i++)
	{
		if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/' || postfix[i]=='^')
		{
			char operatorr=OperatorDetector(postfix[i]);
		}
		else 
			stack.Push(postfix[i])
	}
}
char PreInPost::OperatorDetector(char operatorr)
{
	switch (operatorr) 
	{
		case '+':
			return '+';
		
	}
}
int main()
{

}