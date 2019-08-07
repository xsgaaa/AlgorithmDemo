/*
	»ùÊýÅÅÐò£ºC++
*/

#include<iostream>
using namespace std;


int getMax(int a[], int n)
{
	int i, max;
	max = a[0];
	for (i = 1; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	return max;
}

void countSort(int a[], int n, int exp)
{
	int output[n];
	int i, buckets[10] = { 0 };

	for (i = 0; i < n; i++)
		buckets[(a[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		buckets[i] += buckets[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[buckets[(a[i] / exp) % 10] - 1] = a[i];
		buckets[(a[i] / exp) % 10]--;
	}
	for (i = 0; i < n; i++)
		a[i] = output[i];
}


void radixSort(int a[], int n)
{
	int exp;
	int max = getMax(a, n);

	for (exp = 1; max / exp>0; exp *= 10)
		countSort(a, n, exp);
}