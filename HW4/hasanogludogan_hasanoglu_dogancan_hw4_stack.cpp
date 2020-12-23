#include<iostream>
#include "hasanogludogan_hasanoglu_dogancan_hw4_stack.h"

using namespace std;

DynamicStack::DynamicStack()    // constructor
{
	top=NULL;

}

DynamicStack::~DynamicStack()      // destructor
{
	StackNode * ptr= top;
	while(top!=NULL)
	{
		StackNode * temp;
		temp=top->next;
		delete top;
		top=temp;
	}
}
void DynamicStack::push(int x, int y)  //push function
{
	
	StackNode * newnode= new StackNode(x,y,top);
	top=newnode;
}

void DynamicStack::pop(int & x, int & y)   // pop function
{
	if(!isEmpty())
	{
		StackNode * temp;
		x=(*top).cellx;
		y=(*top).celly;
		temp = (*top).next;
		delete top;
		top = temp;
	}


}
bool DynamicStack::isEmpty()   // check if it is empty
{
	if (top == NULL)
		return true;
	else
		return false;
}