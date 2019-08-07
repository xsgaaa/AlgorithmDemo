/*
	希尔排序：C++
*/
#include<iostream>
using namespace std;

/*
	希尔排序

	参数说明：
		a--待排序的数组
		n--数组的长度
*/
void shellSort1(int* a, int n)
{
	int i, j, gap;
	// gap为步长，每次减为原来的一半
	for (gap = n / 2; gap > 0; gap /= 2)
	{
		//共gap(0...gap-1)组，对每一组都执行直接插入排序
		for (i = 0; i < gap; i++)
		{
			for (j = i + gap; j < n; j += gap)
			{
				//如果a[j]<a[j-gap]，则寻找a[j]位置，并将其后面数据的位置都后移
				if (a[j] < a[j - gap])
				{
					int tmp = a[j];		//保留当前值a[j]的值
					int k = j - gap;	//获得其前面一个值的索引

					//将当前值与前面的每一个值作比较，循环终止a[k]<=tmp
					while (k >= 0 && a[k]>tmp)		
					{
						a[k + gap] = a[k];			//将值向后移动
						k -= gap;					//找其前面一个值
					}
					a[k + gap] = tmp;		//K的后面一个位置即为tmp的正确位置
				}
			}
		}
	}
}


/*
	对希尔排序中的单个组进行排序

	参数说明：
		a--待排序的数组
		n--数组总的长度
		i--组的起始位置
		gap--组的步长

*/
void groupSort(int* a, int n, int i, int gap)
{
	int j;
	for (j = i + gap; j < n; j += gap)
	{
		if (a[j] < a[j - gap])
		{
			int tmp = a[j];
			int k = j - gap;
			while (k >= 0 && a[k]>tmp)
			{
				a[k + gap] = a[k];
				k -= gap;
			}
			a[k + gap]=tmp;
		}
	}
}

/*
	希尔排序：
		参数说明：
		a--待排序的数组
		n--数组的长度
*/
void shellSort2(int* a, int n)
{
	int i, gap;
	for (gap = n / 2; gap > 0; gap /= 2)
	{
		for (i = 0; i < gap; i++)
			groupSort(a, n, i, gap);
	}
}

int  main()
{
	int i;
	int a[] = { 80,30,60,40,20,10,50,70 };
	int ilen = (sizeof(a) / sizeof(a[0]));

	cout << "before sort:";
	for (i = 0; i < ilen; i++)
		cout << a[i] << " ";
	cout << endl;

	//shellSort1(a, ilen);
	shellSort2(a, ilen);

	cout << "after sort:";
	for (i = 0; i < ilen; i++)
		cout << a[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}