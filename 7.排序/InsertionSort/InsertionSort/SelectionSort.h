#pragma once
#include<iostream>
using namespace std;

template<typename T>
void selectionSort(T arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		//寻找[i,n)区间里的最小值
		int minIndex = i;		//初始化最小值为i
		for (int j = i + 1; j < n; j++)		//找到区间最小值的索引
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		swap(arr[i], arr[minIndex]);	//swap函数在std命名空间中，是标准C++11函数
	}
}