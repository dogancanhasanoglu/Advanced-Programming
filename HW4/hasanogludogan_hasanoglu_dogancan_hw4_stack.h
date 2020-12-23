#ifndef hasanogludogan_hasanoglu_dogancan_hw4_stack
#define hasanogludogan_hasanoglu_dogancan_hw4_stack

struct StackNode    // our struct to operate on
{
	 int cellx;
	 int celly;
	 StackNode *next;

	StackNode::StackNode()   // default constructor
	{}

	StackNode::StackNode(int x,int y,StackNode * nextnode)   // constructor
		: cellx(x), celly(y), next(nextnode)
	{}

};

class DynamicStack
{
private:

	StackNode *top;

public:
	DynamicStack();   // our functions here , which are defined in stack.cpp
	~DynamicStack();
	void push (int x,int y);
	void pop(int & x, int & y);
	bool isEmpty();

};


#endif