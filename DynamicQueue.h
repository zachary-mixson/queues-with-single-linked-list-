#ifndef DYNAMICQUEUE_H
#define DYNAMICQUEUE_H

struct DynamicNode{ // node is the same as in the dynamic list code 
  char info;
  DynamicNode *next;
};

class DynamicQueue {
public:
	//---------------------------------------------------------------
	// constructors
	//---------------------------------------------------------------
	DynamicQueue();

	//---------------------------------------------------------------
	// methods (inserts and deletes)
	//---------------------------------------------------------------
	bool empty();
	void insert(char x);
	int remove();
	void insertOrMove(char x);
	void print(int index);

private:
	DynamicNode* front;
	DynamicNode* rear;
	int size;
	const int QUEUE_SIZE = 4;
};
#endif

