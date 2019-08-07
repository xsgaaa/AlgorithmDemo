#include<iostream>
#include"stdlib.h"
#include"MyStack.h"
#include"Coordinate.h"
using namespace std;

//*********************************************************************************/
/*
	栈 类模板
	要求：
		将普通栈改造成类模板栈，使其可以适用任何数据类型
	目的：灵活掌握栈机制，理解抽象数据类型在栈中的应用
*/
//*********************************************************************************/

int main(void)
{
	/*
		MyStack<Coordinate> *pStack = new MyStack<Coordinate>(5);
		pStack->push(Coordinate(1,2));		//底
		pStack->push(Coordinate(3,4));
	*/
	MyStack<char> *pStack = new MyStack<char>(5);
	pStack->push('h');		//底
	pStack->push('l');

	pStack->stackTraverse(true);

	pStack->stackTraverse(false);


	cout << pStack->stackLength() << endl;

	if (pStack->stackEmpty())
		cout << "栈为空" << endl;

	if (pStack->stackFull())
		cout << "栈为满"<<endl;

	delete pStack;
	pStack = NULL;

	system("pause");
	return 0;
}