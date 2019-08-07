#include<iostream>
#include<stdlib.h>
#include"MyQueue.h"
#include"Customer.h"
using namespace std;



int main(void)
{
	MyQueue*p = new MyQueue(4);
	Customer c1("zhang", 20);
	Customer c2("lisi", 30);
	Customer c3("wangwu", 20);
	
	p->EnQueue(c1);
	p->EnQueue(c2);
	p->EnQueue(c3);

	p->QueueTraverse();
	Customer c4("", 0);
	p->DeQueue(c4);
	c4.printfInfo();
	p->QueueTraverse();
/*	MyQueue *p = new MyQueue(4);
	p->EnQueue(10);
	p->EnQueue(12);
	p->EnQueue(16);
	p->EnQueue(18);
	//p->EnQueue(20);
	p->QueueTraverse();

	int e = 0;
	p->DeQueue(e);
	cout << endl;
	cout << e << endl;

	p->DeQueue(e);
	cout << endl;
	cout << e << endl;

	cout << endl;
	p->QueueTraverse();

	p->ClearQueue();

	p->EnQueue(20);
	p->EnQueue(30);
	p->QueueTraverse();

*/
	delete p;
	system("pause");
	return 0;
}