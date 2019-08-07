/*
模式匹配之BF(Brute Force)暴力算法
*/
# include<iostream>
# include<string>

using namespace std;

int patternMatch_BF(string s, string t);
int main()
{
	string s;
	string t;

	cout << "请输入主串:";
	cin >> s;
	cout << "请输入子串:";
	cin >> t;

	int result = patternMatch_BF(s, t);
	if (result == -1)
		cout << endl << "匹配失败" << endl;
	else cout << endl << "子串在主串中的位置为:" << result << endl;
	return 0;
}

int patternMatch_BF(string s, string t)//返回子串t在串s第一次出现的位置(从1开始)，若t不是s的子串
									   //返回-1
{
	int i = 1, j = 1;
	while (i <= s.length() && j <= t.length())//两个串都没扫描完
	{
		if (s[i - 1] == t[j - 1])	//该位置上字符相等，就比较下一个字符
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 2;			
			//否则，i为上次扫描位置的下一位置
			//这个值是这样来的,i=i-(j-1)+1
			//
			j = 1;					//j从1开始
		}

	}
	if (j > t.length())
		return (i - t.length());
	return -1;
}
























//bool BruteForce(string str1, string str2)
//{
//	int i = 0,j = 1;
//	while (true)
//	{
//		if (str1[i] == str2[0])
//		{
//			for (j = 1; j <(int)str2.length(); j++)
//			{
//				if (str1[j + i] == str2[j])
//				{
//
//				}
//				else
//					break;	
//			}
//			if (j == str2.length())
//				return true;
//		}
//		i++;
//		if (i == str1.length() - 1)
//			return false;
//
//	}
//}
//
//int main()
//{
//	string str1 = "I love FishC.com!";
//	string str2 = "FishC";
//
//	bool flag=BruteForce(str1, str2);
//	if (flag)
//		cout << "匹配成功"<<endl;
//	else
//		cout << "匹配失败"<<endl;
//
//	system("pause");
//	return 0;
//}
