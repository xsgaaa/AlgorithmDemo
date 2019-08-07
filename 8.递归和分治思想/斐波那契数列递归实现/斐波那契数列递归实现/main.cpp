#include<iostream>
/*
	斐波那契数列---递归实现:

	F(n)=F(n-1)+F(n-2)   n>1
	=1				 n=1
	=0               n=0
*/

int Fib(int n)
{
	if (n < 2)
		return n == 0 ? 0 : 1;
	else
		return Fib(n - 1) + Fib(n - 2);
}


using namespace std;
int main()
{
	int a[40];

	a[0] = 0;
	a[1] = 1;
	cout << a[0] << " " << a[1] << " ";
	for (int i = 2; i < 40; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}