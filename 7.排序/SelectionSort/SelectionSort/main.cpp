#include<iostream>
#include<algorithm>
#include<string>
#include"Student.h"
#include"SortTestHelper.h"
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

int main()
{
	int n = 1000;
	int *arr=SortTestHelper::generateRandomArray(n,0,n);
	//selectionSort(arr, n);
	//SortTestHelper::printArray(arr, n);

	SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);

	delete[] arr;



	//int a[10] = { 10,9,8,7,6,5,4,3,2,1 };
	//selectionSort(a, 10);
	//for (int i = 0; i < 10; i++)
	//{
	//	cout << a[i] << " ";
	//}
	//cout << endl;

	//float b[4] = { 4.4,3.3,2.2,1.1};
	//selectionSort(b, 4);
	//for (int i = 0; i < 4; i++)
	//{
	//	cout << b[i] << " ";
	//}
	//cout << endl;

	//string c[4] = { "D","C","B","A" };
	//selectionSort(c, 4);
	//for (int i = 0; i < 4; i++)
	//{
	//	cout << c[i] << " ";
	//}
	//cout << endl;

	//Student d[4] = { {"D",90},{"C",100},{"B",95},{"A",95} };
	//selectionSort(d, 4);
	//for (int i = 0; i < 4; i++)
	//{
	//	cout << d[i];
	//}
	//cout << endl;


	system("pause");
	return 0;
}