#include<iostream>
#include<algorithm>
#include"SortTestHelper.h"
#include"MergeSort.h"

using namespace std;

//自底向上的归并排序，没有用到数组的取元素操作，可作用于链表的排序
template<typename T>
void mergeSortBU(T arr[], int n)
{
	for (int sz = 1; sz <= n; sz += sz)
	{
		for (int i = 0; i +sz< n; i += 2 * sz)
		{
			//对arr[i...i + sz - 1]和arr[i + sz...i + sz + sz - 1]进行归并
			__merge(arr, i, i + sz - 1, min(i + sz + sz - 1,n-1));
		}
	}
}

int main()
{
	

	system("pause");
	return 0;
}