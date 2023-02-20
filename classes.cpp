#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "classes.h"

using namespace std;

//Queue Methods-------------------------------------------------------------------------------------------------

Queue::Queue(){
	front = NULL;
	s = 0;
}

Queue::~Queue()
{
	delete[] front;
}

void Queue::push(unsigned int np, unsigned int size) {
	if (s == 0) {
		front = new Node(np, size);
		s++;
	}
	else
	{
		Node *temp = front;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new Node(np, size);
		s++;
		cout << temp->next->parent->getnum();
	}
	cout << "th parent entered the queue"<< endl;
}

Node * Queue::pop(unsigned int n) {
	if (s == 1) {
		Node *temp;
		temp = front;
		front = front->next;
		s--;
		return temp;
	}

	else
	{
		Node *temp, *prev;
		unsigned int counter=1;
		temp = front->next;
		prev = front;

		if (n == 1) {
			temp = front;
			front = front->next;
			s--;
			return temp;
		}
		else {

			while (counter < n - 1)
			{
				temp = temp->next;
				prev = prev->next;
				counter++;
			}
		}

		if (prev->next->next != NULL)
			prev->next = prev->next->next;
		else
			prev->next = NULL;

		s--;
		return temp;
	}
}
int Queue::queueEmpty()
{
	return s;
}
int Queue::returnNode(unsigned int teach)
{
	int counter = 1;
	Node *temp = front;
	while (temp != NULL) {
		if (temp->parent->getArray(teach) == 1) {
			return counter ;
		}
		counter++;
		temp = temp->next;
	}
	return 0;
}
void Queue::push2(Node * p)
{
	int i = rand() % 4;
	if (s == 0) {
		front = p;
		front->next = NULL;
		s++;
	}
	else
	{
		Node *temp = front;
		temp = front;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = p;
		temp->next->next = NULL;
		s++;
	}
	/*for (int i = 0; i < 10; i++) {
		cout << p->parent->getArray(i) << " ";
	}*/

	if (i > 1) {
		cout << p->parent->getnum();
		cout << "th parent returns to the queue" << endl;
	}
	else {
		cout << "THIS IS MY POSITION GO BACK!" << endl;
		cout << p->parent->getnum();
		cout << "th parent returns to the queue" << endl;
	}
}
Node* Queue::getnode()
{
	return front;
}
int Queue::returnNode2(unsigned int teach)
{
	int counter = 1;
	Node *temp = front;
	while (temp != NULL) {
		if (temp->parent->getparentarray(teach) == 0) {
			return counter;
		}
		counter++;
		temp = temp->next;
	}
	return 0;
}
//Node methods---------------------------------------------------------------------------------------------------

Node::Node(unsigned int np,  unsigned int size, Node * n) :  next(n)
{
	parent = new Parent(np, size);
}

Node::~Node()
{
	delete[] parent;
}

//Parent methods---------------------------------------------------------------------------------------------------

Parent::Parent(unsigned int n,unsigned int size) : num(n)
{
	teachersArray = new int[size];
	arraysize = size;
	for (int i = 0; i < size; i++) {
		teachersArray[i] = rand() % 2;
		cout << teachersArray[i]<< " ";
	}
	cout << endl;
}

Parent::~Parent()
{
		delete[] teachersArray;

}

void Parent::setArray(unsigned int cell, unsigned int n)
{
	
	teachersArray[cell] = n;
}

int Parent::getArray(unsigned int cell)
{
	return teachersArray[cell];
}

int Parent::getparentarray(unsigned int t)
{
	int i, s = 0;
	for (i = 0; i < t; i++) {
		if (getArray(i) == 1)
			s++;
	}
	if (s > 0)
		return 1; //hasnt seen them all
	else
		return 0; //seen all of them
}

int Parent::getnum()
{
	return num;
}


//Teacher methods----------------------------------------------------------------------------
Teacher::Teacher(){
	busy = 0;
	num = 0;
	pnode = NULL;
}

Teacher::~Teacher()
{
	delete[] pnode;
}

void Teacher::setnum(int n){
	num = n;
}

int Teacher::getnum()
{
	return num;
}

void Teacher::setbusy(int n)
{
	busy = n;
}

int Teacher::getbusy()
{
	return busy;
}

void Teacher::setparent(Node * parent)
{
	pnode = parent;
}

Node * Teacher::getparent()
{
	return pnode;
}

int Teacher::getparentarray(unsigned int t)
{
		int i, s = 0;
		for (i = 0; i < t; i++) {
			if (pnode->parent->getArray(i) == 1)
				s++;
		}
		if (s > 0)
			return 1; //hasnt seen them all
		else
			return 0; //seen all of them
	
}

void Teacher::deletepnode()
{
	pnode->~Node();
}
