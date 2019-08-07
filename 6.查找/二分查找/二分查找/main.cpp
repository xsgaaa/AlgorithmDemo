#include<iostream>
using namespace std;
/*
	顺序查找
	顺序查找--优化
	折半查找/插值查找
	斐波那契查找---基于黄金分割
*/
int F[10] = { 0,1,1,2,3,5,8,13,21,34 };
//顺序查找---每次循环，两次判断
int Sequential_Search(int *a, int n, int key)
{
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == key)
			return i;
	}
	return 0;
}

//顺序查找---每次循环，一次判断
int Sequential_Search(int *a, int n, int key)
{
	int i;
	a[0] = key;		//设置a[0]为关键字值，我们称之为哨兵
	i = n;			//循环从数组尾部开始
	while (a[i] != key)
	{
		i--;
	}
	return i;		//返回0则说明查找失败

}

//折半查找
int Binary_Search(int *a, int n, int key)
{
	int low, high, mid;
	low = 1;		//定义最底下标为记录首位
	high = n;		//定义最高下标为记录末位
	while (low <= high)
	{
		mid = (low + high) / 2;		//折半
		//mid=low+(high-low)*(key-a[low])/(a[high]-a[low]);		//插值法
		if (key < a[mid])
			high = mid - 1;
		else if (key > a[mid])
			low = mid + 1;
		else
			return mid;
	}
	return 0;
}


//斐波那契查找
int Fibonacci_Search(int *a, int n, int key)
{
	int low, high, mid, i, k;
	low = 1;		//最低位为首位
	high = n;		//最高位为末位
	k = 0;
	while (n > F[k] - 1)	//计算n位于数列的位置
		k++;
	for (i = n; i < F[k] - 1; i++)		//将不满的数值补全
		a[i] = a[n];					// n=<i<F[k]-1的数值全部补为a[n]

	while (low <= high)
	{
		mid = low + F[k - 1] - 1;		//F[k-1]-1=<n
		if (key < a[mid])
		{
			high = mid - 1;				//最高下标调整到分隔下标mid-1处
			k = k - 1;					//将近是折半
		}
		else if (key>a[mid])
		{
			low = mid + 1;
			k = k - 2;					//将近是折半
		}
		else
		{
			if (mid <= n)
				return mid;
			else						//大于n处的值均被赋值为n处的值
				return n;
		}
	}
	return 0;
}




//测试折半查找
int main()
{
	int a[11] = { 0,3,12,24,37,45,53,61,78,90,98 };
	int key = 0;
	cout << "输入要查找的数字：" << endl;
	cin >> key;
	int tmp = Binary_Search(a, 10, key);
	if (0 == tmp)
	{
		cout<<"查找不到所求得数据"
	}
	else
	{
		cout << "查询数字的索引为：" << tmp << endl;
	}
	return 0;
}