#include<iostream>
#include<cstdio>
#include<string>
using namespace std;



/*
	哈夫曼树---带权路径长度最短的树


*/

#define N 10		//带编码字符的个数，即树中叶子节点的最大个数
#define M (2*N-1)	//树中总的结点数目

class HTNode		//树中结点的结构
{
public:
	unsigned int weight;
	unsigned int parent, lchild, rchild;
};

class HTCode		//哈夫曼树的结构
{
public:
	char data;		//待编码的字符
	int weight;		//字符的权值
	char code[N];	//字符的编码
};

void Init(HTCode hc[], int *n)
{
	//初始化，读入待编码字符的个数n，从键盘输入n个字符和n个权值
	cout << "请输入个数n：";
	cin >> *n;

	cout << "请输入n个字符：";
	for (int i = 1; i <= *n; i++)
	{
		cin >> hc[i].data;
	}

	cout << "请输入n个权值：";
	for (int i = 1; i <= *n; i++)
	{
		cin >> hc[i].weight;
	}
}

void Select(HTNode ht[], int k, int *s1, int *s2)
{
	//ht[1...k]中选择parent为0，并且weight最小的两个结点，其序号由指针变量s1，s2指示
	int i;
	for (i = 1; i <= k&&ht[i].parent != 0; i++)
	{
		; ;
	}
	*s1 = i;		//跳出上一步循环时找到第一个 ht[i].parent=0
	for (i = 1; i <= k; i++)
	{
		if (ht[i].parent == 0 && ht[i].weight < ht[*s1].weight)
			*s1 = i;			//ht[*s1].weight的权值最小
	}
	for (i = 1; i <= k; i++)
	{
		if (ht[i].parent == 0 && i != *s1)
			break;
	}
	*s2 = i;		//跳出上一步循环时找到第一个 ht[i].parent=0
	for (i = 1; i <= k; i++)
	{
		if (ht[i].parent == 0 && i != *s1&&ht[i].weight < ht[*s2].weight)
			*s2 = i;		//ht[*s2].weight的权值最小
	}
}

void HuffmanCoding(HTNode ht[],HTCode hc[],int n)
{
	//构造Huffman树ht，并求出n个字符的编码
	char cd[N];
	int i, m, c, f, s1, s2, start;
	m = 2 * n - 1;					//总的结点数目
	for (i = 1; i <= m; i++)		//遍历所有结点
	{
		if (i <= n)
			ht[i].weight = hc[i].weight;	//将叶子节点都进行赋值
		else
			ht[i].weight = 0;				//非叶子节点初始情况下均赋值为0
		ht[i].parent = ht[i].lchild = ht[i].rchild = 0;		//其余参数均赋值为0
	}
	for (i = n + 1; i <= m; i++)			//对非叶子节点进行操作
	{
		Select(ht, i - 1, &s1, &s2);		//选取最小的两个节点的编号,组成上一级节点
		ht[s1].parent = i;					
		ht[s2].parent = i;
		ht[i].lchild = s1;
		ht[i].rchild = s2;
		ht[i].weight = ht[s1].weight + ht[s2].weight;
	}

	cd[n - 1] = '\0';

	for (i = 1; i <= n; i++)		//遍历叶子节点
	{
		start = n - 1;
		for (c = i, f = ht[i].parent; f; c = f, f = ht[f].parent)		//获取每个叶子节点的编码
		{
			if (ht[f].lchild == c)
				cd[--start] = '0';
			else
				cd[--start] = '1';
			strcpy(hc[i].code, &cd[start]);		//将编码拷贝到结构体中的编码区
		}
	}
}

int main()
{
	int n;
	HTNode ht[M + 1];
	HTCode hc[N + 1];
	Init(hc, &n);
	HuffmanCoding(ht, hc, n);
	for (int i = 1; i <= n; i++)
	{
		cout << hc[i].data << "-----" << hc[i].code << endl;
	}
	return 0;
}