#include<iostream>
#include"stdlib.h"
#include"MyStack.h"
using namespace std;

/***************************************************************/
/*
	栈应用--括号匹配

	描述：任意输入一组括号，可以判断括号是否匹配

	字符串示例：[()]	[()()]	[()[()()]]	[[()]

	目的：通过灵活掌握栈机制的使用技巧
*/
/***************************************************************/

int main(void)
{
	MyStack<char> *pStack = new MyStack<char>(30);

	MyStack<char> *pNeedStack = new MyStack<char>(30);

	char str[] = "[[()]]";

	char currentNeed = 0;

	for (int i = 0; i<strlen(str); i++)
	{
		if (str[i] != currentNeed)
		{
			pStack->push(str[i]);
			switch (str[i])
			{
			case '[':
				if (currentNeed != 0)
				{
					pNeedStack->push(currentNeed);
				}
				currentNeed = ']';
					break;
			case '(':
				if (currentNeed != 0)
				{
					pNeedStack->push(currentNeed);
				}
				currentNeed = ')';
				break;
			default:
				cout << "字符串括号不匹配" << endl;
				system("pause");
				return 0;

			}
		}
		else
		{
			char elem;
			pStack->pop(elem);
			if (!pNeedStack->pop(currentNeed))
			{
				currentNeed = 0;
			}
		}
	}
	if (pStack->stackEmpty())
	{
		cout << "字符串括号匹配" << endl;
	}
	else
	{
		cout << "字符串括号不匹配" << endl;
	}

	delete pStack;
	pStack = NULL;

	delete pNeedStack;
	pNeedStack = NULL;

	system("pause");
	return 0;
}