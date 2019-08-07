#include<iostream>
using namespace std;

/*
	八皇后问题----递归解决

*/

int count1 = 0;		//count1表示总的可能性的数量，为避免冲突，末尾加了个1

bool notDanger(int row, int  j, int(*chess)[8])			//传入参数：行 列 行指针 ，判断是否有危险
{	
	//i，k：自增变量
	//flag：表示在不同方向上是否冲突的标志
	int i,k,flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0,flag5 = 0;

	//判断列方向
	for (i = 0; i < 8; i++)
	{
		if (*(*(chess + i) + j) != 0)		//从第一行到最后一行，轮流扫描
		{
			flag1 = 1;
			break;
		}
	}

	//判断左上方
	for (i = row, k = j; i >= 0 && k >=0; i--, k--)
	{
		if (*(*(chess + i) + k) != 0)		//行数和列数同步减1，表示斜45度方向
		{
			flag2 = 1;
			break;
		}
	}

	//判断右下方
	for (i = row, k = j; i <8 && k <8; i++, k++)
	{
		if (*(*(chess + i) + k) != 0)
		{
			flag3 = 1;
			break;
		}
	}

	//判断右上方
	for (i = row, k = j; i>=0&& k <8; i--, k++)
	{
		if (*(*(chess + i) + k) != 0)
		{
			flag4 = 1;
			break;
		}
	}

	//判断左下方
	for (i = row, k = j; i<8 && k >=0; i++, k--)
	{
		if (*(*(chess + i) + k) != 0)
		{
			flag5 = 1;
			break;
		}
	}
	if (flag1 || flag2 || flag3 || flag4 || flag5)
	{
		return false;
	}
	{	
		return true;		//当5个标志都为1，表示没有危险时，才返回
	}
}

void EightQueen(int row,int n,int (*chess)[8])			//函数主体，参数：行，列，行指针
{
	//参数row：表示起始行
	//参数n：表示列数
	//参数chess表示指向棋盘每一行的指针
	int chess2[8][8],i,j;	//定义一个临时的棋盘
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8;j++)
		{
			chess2[i][j] = chess[i][j];	//临时棋盘存储当前棋盘数据
		}
	}

	if (8 == row)						//递归结束条件
	{
		cout << "第" << (count1 + 1 )<< "种" << endl;
		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 8; j++)
			{
				cout<<*(*(chess2+i)+j)<<" ";	//输出棋局结果
			}
			cout << endl;
		}
		cout << endl;
		count1++;
	}
	else										//递归没有结束
	{
		//判断这个位置是否有危险，如果没有危险，继续往下
		for (j = 0; j < n; j++)
		{
			if (notDanger(row,j,chess))			//判断当前位置是否危险
			{
				for (i = 0; i < 8; i++)
				{
					*(*(chess2 + row) + i) = 0;		//将行上面的元素都置为0
				}
				*(*(chess2 + row) + j)=1;
				EightQueen(row + 1, n, chess2);		//继续在下一行寻找合适位置
			}
		}
	}
}


int main()
{
	int chess[8][8];				//定义棋盘

	for (int i = 0; i < 8; i++)		//初始化棋盘，0表示没有放任何东西
	{
		for (int j = 0; j < 8; j++)
		{
			chess[i][j] = 0;
		}
	}
	EightQueen(0,8,chess);			//调用函数，从第一行开始

	cout << "总共有" << count1 << "种解决方法！" << endl << endl;

	system("pause");
	return 0;
}