#include<iostream>
#include<string>
using namespace std;
/*
	KMP算法----模式匹配
*/
void getNext(string t, int *next)
{
	next[0] = -1;
	int i = 0, j = -1;
	while (i < t.length())
	{
		if (j == -1 || t[i] == t[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];
	}
}


int Kmp(string str1, string str2,int *next)		//KMP算法的主体
{
	int i = 0;
	int j = 0;
	while (i < (int)str1.length() && j <(int) str2.length())	//在结束前轮流循环
	{
		if (-1==j || str1[i] == str2[j])	//判断值是否相等
		{
			i++;
			j++;		//序号加1，判断后一位是否相等
		}
		else
			j = next[j];		//回到之前的j位置与现在的i进行比较
	}
	if (j == str2.length())		//整个子串全部比较完，说明完全匹配
		return (i - j);			//返回子串在主串中首字母出现的位置
	else
		return -1;
}



int main()
{
	string s;
	string t;
	cout << "请输入主串：" << endl;
	cin >> s;
	cout << "请输入子串：" << endl;
	cin >> t;

	int *next = new int[t.length()];	//定义next数组

	getNext(t, next);					//获取next数组的元素

	int result = Kmp(s, t,next);		//运行KMP算法
	if (-1 == result)					//返回结果判断
		cout << "匹配失败！" << endl;
	else
		cout << "子串在主串中的位置为：" << result << endl;

	system("pause");
	return 0;
}
