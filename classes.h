class Parent {
private:
	unsigned int num;
	int *teachersArray; // 1-> havent see 0-> saw
	unsigned int arraysize;
public:
	Parent(unsigned int n, unsigned int size);
	~Parent();
	void setArray(unsigned int cell, unsigned int n);
	int getArray(unsigned int cell);
	int getparentarray(unsigned int t);//0-> seen them all //1-> Not seen
	int getnum();
};

struct Node{
	Parent *parent;
	Node *next;
	///////////////////////////
	Node(unsigned int np,unsigned int size, Node *n = NULL);
	~Node();

};

class Queue {
private:
	Node *front;
	unsigned int s;
public:
	Queue();
	~Queue();
	void push(unsigned int np,unsigned int size);
	Node * pop(unsigned int n);
	int queueEmpty();
	int returnNode(unsigned int teach);
	void push2(Node *p);
	Node* getnode();
	int returnNode2(unsigned int teach);
};

class Teacher {
private:
	Node *pnode;
	int busy; //0-> free / 1->busy
	int num;
public:
	Teacher();
	~Teacher();
	void setnum(int n);
	int getnum();
	void setbusy(int n);
	int getbusy();
	void setparent(Node *parent);
	Node * getparent();
	int getparentarray(unsigned int t);
	void deletepnode();
};