#pragma once



template <typename T>
void insertionSort(T arr[], int n)
{
	for (int i = 1; i < n; i++)		//不考虑第0个元素，将其视为已排好
	{
		T e = arr[i];							//将当前元素保存
		int j;									//保存元素e应该插入的位置
		for (j = i; j > 0 && arr[j - 1] > e; j--)	//循环结束后，j的值就是应该插入的位置
			arr[j] = arr[j - 1];
		arr[j] = e;
	}
}

template <typename T>
void insertionSort(T arr[], int l, int r)
{
	for (int i = l + 1; i <= r; i++)
	{
		T e = arr[i];
		int j;
		for (j = i; j > l&&arr[j - 1] > e; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = e;
	}
	return;
}