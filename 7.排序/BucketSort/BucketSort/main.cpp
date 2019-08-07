/*
	桶排序，有很多局限性：
	1.数组元素必须都是正整数
	2.数组元素不能太大，如果要排序的数为，那么我们就需要构造一个1001大小的数组

	时间复杂度：
	N个整数	范围从0到M-1
	时间复杂度为O（M+N)          
*/
#include<stdio.h>
#include<string.h>
#include<iostream>

using namespace std;

#define MAX 100

void bucketsort(int A[], int size, int max_num)		//size表示数组的大小，max_num表示数组中最大的数
{
	int count[MAX];			//创建一个新数组
	memset(count, 0, sizeof(count));			//将count指针所指向的区域都初始化为0
	for (int i = 0; i < size; i++)
	{
		++count[A[i]];			//统计原来数组中每个数的个数，原来每个数组的值作为新数组的下标
	}
	for (int j = 0; j <= max_num; j++)
	{
		while (count[j] > 0)
		{
			cout << j<<" ";
			count[j]--;
		}
	}
	cout << endl;
}

int main()
{
	int a[] = { 2,5,6,12,4,8,8,6,7,8,8,10,7,6,0,1 };
	bucketsort(a, sizeof(a) / sizeof(a[0]), 12);

	system("pause");
	return 0;
}