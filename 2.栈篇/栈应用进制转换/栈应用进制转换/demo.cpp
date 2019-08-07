#include<iostream>
#include<stdlib.h>
#include"MyStack.h"
using namespace std;

//*************************************************************//
/*
	栈应用--进制转换

	描述：输入任意的十进制正整数N，分别输出该整数N的二进制、八进制、十六进制的数

	公式：N=（N div d) *d +N mod d  (div表示整除，mod表示求余)
	目的：通过实例灵活掌握栈机制的使用技巧
*/
//*************************************************************//
/*
#define BITARY 2
#define OCTONARY 8
#define HSXADECIMAL 16
*/


int main(void)
{
	system("color 2E");
	char num[] = { "0123456789ABCDEF" };
	MyStack<int> *pStack = new MyStack<int>(30);
	int N = 0,flag;
	cout << "请输入要转换的数：" << endl;
	cin >> N;
	cout << "请输入要转换的进制(2、8、16）：" << endl;
	cin >> flag;
	int mod = 0;
	while (N!=0)
	{
		mod = N % flag;
		pStack->push(mod);
		N = N / flag;
	}

	//pStack->stackTraverse(false);
	/*for (int i = pStack->stackLength() - 1; i >= 0; i--)
	{
		num[pStack[i]]
	}*/
	int elem = 0;
	while (!pStack->stackEmpty())
	{
		pStack->pop(elem);
		cout<<num[elem];
	}
	cout << endl;
	delete pStack;
	pStack = NULL;

	system("pause");
	return 0;
}