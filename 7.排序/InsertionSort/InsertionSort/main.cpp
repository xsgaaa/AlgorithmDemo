#include<algorithm>
#include<iostream>
#include"SortTestHelper.h"
#include"SelectionSort.h"
using namespace std;

template <typename T>
void insertionSort(T arr[], int n)
{
	for (int i = 1; i < n; i++)		//不考虑第0个元素，将其视为已排好
	{
		//寻找元素arr[i]合适的插入位置
		/*for (int j = i; j > 0; j--)
		{
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
			else
				break;
		}*/

		T e = arr[i];							//将当前元素保存
		int j;									//保存元素e应该插入的位置
		for (j = i; j > 0 && arr[j-1] > e; j--)	//循环结束后，j的值就是应该插入的位置
			arr[j] = arr[j - 1];
		arr[j] = e;

		//for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
		//	swap(arr[j], arr[j - 1]);
	}
}

int main()
{
	int n = 10000;
	int *arr = SortTestHelper::generateNearlyOrderedArray(n, 10);
	int *arr2 = SortTestHelper::copyIntArray(arr, n);

	SortTestHelper::testSort("Insertion Sort", insertionSort, arr, n);
	SortTestHelper::testSort("Selection Sort", selectionSort, arr2, n);


	delete[]arr;
	delete[]arr2;
	system("pause");
	return 0;
}