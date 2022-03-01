#include "DynamicQueue.h"
#include <iostream>
#include <stdlib.h>

//-------------------------------------------------------------------------------
// constructors
//-------------------------------------------------------------------------------
/********************************************************************************
default constructor
********************************************************************************/
DynamicQueue::DynamicQueue() {
	front = nullptr;
	rear = nullptr;
	size = 0;
	
}

//---------------------------------------------------------------
// methods (inserts and deletes)
//---------------------------------------------------------------
bool DynamicQueue::empty() {
	return (front == nullptr);
}

void DynamicQueue::insert(char x) {
	DynamicNode* p = new DynamicNode;
	p->info =x;
	p->next = nullptr;

	if (empty()) {
		front = p;
	}
	else {
		rear->next = p;
	}

	rear = p;
	if(size != QUEUE_SIZE){
	size++;
	}
}

int DynamicQueue::remove() {
	if (empty()) {
		std::cout << "queue underflow";
		exit(1);
	}

	DynamicNode* p = front;
	int temp = p->info;
	front = p->next;
	delete p;
	if (front == nullptr)
		rear = nullptr;

	return temp;
}

void DynamicQueue::insertOrMove(char x) {

	

	if (empty()) {
		insert(x);
		std::cout << "Inserting " << x << " to rear. ";
		return;
	}
	if (front == rear && front->info == x) {
		return;
	}

	
	DynamicNode* q = front;
	DynamicNode* p = front->next;

		if (q->info == x) {
			front = front->next;
			delete q;
			insert(x);
			std::cout << "Moving " << x << " to rear. ";

			return;
		}
	
	while (p != nullptr) {

		// exception
		if (p->info == x) {//IN QUEUE
			if (p->info == rear->info) {
				//rear = q;

				std::cout << x << " is already rear. ";
				return;
			}
			q->next = p->next;
			delete p;
			insert(x);
			std::cout << "Moving " << x << " to rear. ";

			return;
		}

		p = p->next;
		q = q->next; // exception
	}
				//NOT IN QUEUE
				//If the queue is NOT full
			if (size != QUEUE_SIZE) {
				//insert new node with key ‘a’ in rear of queue.
				insert(x);
				std::cout << "Inserting " << x << " to rear. ";
				return;
			}
			else{//Else   
					//queue is full -- that is, it contains QUEUESIZE elements
				if (size = QUEUE_SIZE) {
				//remove front element of the queue; then, insert new node with key ‘a’ in rear.
					p = front;
					front = front->next;
					delete p;
					insert(x);
					std::cout << "Q is full removing front. Inserting " << x << " to rear. ";

				}
					
			}
}


void DynamicQueue::print(int index) {
	DynamicNode* p;
	if (empty()) {
		std::cout << "Empty Queue" << std::endl;
		return;
	}
	std::cout << "Q" << index << ": ";
	for (p = front; p != nullptr; p = p->next) {
		std::cout << p->info;
		if (p->next != nullptr) {
			std::cout << "->";

		}
	}
	std::cout << std::endl;
}