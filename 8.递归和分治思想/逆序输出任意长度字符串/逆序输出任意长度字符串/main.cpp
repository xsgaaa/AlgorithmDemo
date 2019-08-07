#include<iostream>
using namespace std;

/*
	逆序输出任意长度的字符串--递归

	注意是任意长度，否则可以用栈

*/

void print()
{
	char a;
	cin >> a;
	if (a != '#')
		print();
	if (a != '#')
		cout << a;
}

int main()
{
	print();
	system("pause");
	return 0;
}