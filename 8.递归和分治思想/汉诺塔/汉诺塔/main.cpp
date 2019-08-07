#include<iostream>
using namespace std;

/*
	汉诺塔问题---递归解决

*/

//将n个盘子从 x 借助 y 移动到 z
void move(int n,char x,char y,char z)
{
	if (1 == n)
		cout << x << "--->" << z << endl;
	else
	{
		move(n - 1, x, z, y);			//把n-1个盘子从x借助z移动到y上
		cout << x << "--->" << z << endl;	//把第n个盘子从x移动到z上
		move(n - 1, y, x, z);				//把n-1个从y借助x移动到z上
	}

}

int main()
{
	int n;
	cout << "请输入汉诺塔的层数：" << endl;
	cin >> n;
	cout << "移动的步骤如下：" << endl;
	move(n, 'X', 'Y', 'Z');

	system("pause");
	return 0;
}