/*
	快速排序(Quick Sort)使用分治法策略。
它的基本思想是：选择一个基准数，通过一趟排序将要排序的数据分割成独立的两部分；其中一部分的所有数据都比另外一部分的所有数据都要小。然后，再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，以此达到整个数据变成有序序列。

快速排序流程：
(1) 从数列中挑出一个基准值。
(2) 将所有比基准值小的摆放在基准前面，所有比基准值大的摆在基准的后面(相同的数可以到任一边)；在这个分区退出之后，该基准就处于数列的中间位置。
(3) 递归地把"基准值前面的子数列"和"基准值后面的子数列"进行排序。

 

*/
#include<iostream>
using namespace std;

/*
	快速排序：

	参数说明：
		a--待排序的数组
		l--数组的左边界
		r--数组的右边界
*/
void quickSort(int* a, int l, int r)
{
	if (l < r)
	{
		int i, j, x;
		i = l;
		j = r;
		x = a[i];		//x作为基准
		while (i < j)	//直到 i=j时，终止循环
		{
			while (i<j && a[j]>x)
				j--;	//从右向左找第一个小于x的数
			if (i < j)
				a[i++] = a[j];	//用a[j]替换a[i]，同时i向后移一位
			while (i < j && a[i] < x)
				i++;	//从左向右找第一个大于x的数
			if (i < j)
				a[j--] = a[i];	//用a[i]替换a[j],同时j向前移一位
		}
		a[i] = x;		//循环终止处的节点值为基准值，左边小于基准，右边大于基准
		quickSort(a, l, i - 1);		//递归调用
		quickSort(a, i + 1, r);		//递归调用
	}
}

int main()
{
	int i;
	int a[] = { 30,40,60,10,20,50 };
	int ilen = (sizeof(a) / sizeof(a[0]));

	cout << "before sort:";
	for (i = 0; i < ilen; i++)
		cout << a[i] << " ";
	cout << endl;

	quickSort(a, 0, ilen - 1);

	cout << "after sort:";
	for (i = 0; i < ilen; i++)
		cout << a[i] << " ";
	cout << endl;

	system("pause");
	return 0;

}