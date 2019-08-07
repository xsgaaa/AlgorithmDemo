/*	
	2019-3-27
	冒泡排序
		它是一种较简单的排序算法。它会遍历若
		干次要排序的数列，每次遍历时，它都会
		从前往后依次的比较相邻两个数的大小；
		如果前者比后者大，则交换它们的位置。
		这样，一次遍历之后，最大的元素就在数列
		的末尾！ 采用相同的方法再次遍历时，第二
		大的元素就被排列在最大元素之前。重复此操
		作，直到整个数列都有序为止！
*/
#include<iostream>
using namespace std;

/*
	参数说明：
		a--待排序的数组
		n--数组的长度
*/
void bubbleSort1(int* a, int n)
{
	int tmp, i, j;
	for (i = n - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			//将z[0...i]中最大的数据放在末尾
			if (a[j] > a[j + 1])
			{
				//交换a[j]和a[j+1]
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

/*
	冒泡排序(改进版)
*/
void  bubbleSort2(int* a, int n)
{
	int i, j, tmp;
	int flag;	//标记

	for (i = n - 1; i > 0; i--)
	{
		flag = 0;		//初始化为0
		for (j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;

				flag = 1;	//若发生交换，则标记记为1
			}
		}

		if (flag == 0)
			break;			//若没发生交换，则说明数列已有序
	}
}

int main()
{
	int i;
	int a[] = { 20,40,30,10,60,50 };
	int ilen = (sizeof(a) / sizeof(a[0]));

	cout << "before sort:";
	for (i = 0; i < ilen; i++)
		cout << a[i] << " ";
	cout << endl;

	//bubbleSort1(a, ilen);
	bubbleSort2(a, ilen);

	cout << "after sort:";
	for (i = 0; i < ilen; i++)
		cout << a[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}