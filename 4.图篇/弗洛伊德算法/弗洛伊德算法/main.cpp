#include<iostream>
#include<stdlib.h>
using namespace std;

#define MAX 10
#define INF 65535

typedef struct graph
{
	char vexs[MAX];
	int vexnum;		//顶点数
	int edgnum;		//边数
	int matrix[MAX][MAX];		//邻接矩阵
}Graph;

int pathmatrix[MAX][MAX];	//记录对应点的最小路径的前驱点，例如p(1,3) = 2 说明顶点1到顶点3的最小路径要经过2 
int shortPath[MAX][MAX];	//记录顶点间的最小路径值

void short_path_floyd(Graph G, int P[MAX][MAX], int D[MAX][MAX])
{
	int v, w, k;
	for (v = 0; v < G.vexnum; v++)
	{
		//初始化floyd算法的两个矩阵
		for (w = 0; w < G.vexnum; w++)
		{
			D[v][w] = G.matrix[v][w];
			P[v][w] = w;
		}
	}

	//这是弗洛伊德算法的核心部分
	//k为中间点
	for (k = 0; k < G.vexnum; k++)
	{
		//v为起点
		for (v = 0; v < G.vexnum; v++)
		{
			//w1为终点
			for (w = 0; w < G.vexnum; w++)
			{
				if (D[v][w]>(D[v][k] + D[k][w]))
				{
					D[v][w] = D[v][k] + D[k][w];	//更新最小路径
					P[v][w] = P[v][k];		//更新最小路径中间顶点
				}
			}
		}
	}

	cout << endl << "初始化的D矩阵" << endl;
	for (v = 0; v < G.vexnum; v++)
	{
		for (w = 0; w < G.vexnum; w++)
		{
			cout << D[v][w];
		}
		cout << endl;
	}

	cout << endl << "初始化的P矩阵" << endl;
	for (v = 0; v < G.vexnum; v++)
	{
		for (w = 0; w < G.vexnum; w++)
		{
			cout << P[v][w];
		}
		cout << endl;
	}

	v = 0;
	w = 3;
	//求0到3的最小路径
	cout << endl << v << "->" << w << "的最小路径为：" << D[v][w] << endl;
	k = P[v][w];
	cout << "path:" << v;	//打印起点
	while (k != w)
	{
		cout << "->" << k;	//打印中间点
		k = P[k][w];
	}
	cout << "->" << w << endl;
}

int main()
{
	Graph G;
	int i = 0, j = 0, e = 0;
	cout << "请输入顶点数和边数 ：" << endl;
	cin >> G.vexnum >> G.edgnum;
	cout << "请输入顶点：" << endl;
	for (int k = 0; k < G.vexnum; k++)
	{
		cin >> G.vexs[k];
	}
	for (int i = 0; i < G.vexnum; i++)		//初始化权值为无穷大
	{
		for (int j = 0; j < G.vexnum; j++)
		{
			G.matrix[i][j] = INF;
		}
	}
	cout << "请输入边：" << endl;			//无向图，邻接矩阵对称
	for (int k = 0; k<G.edgnum; k++)
	{
		cin >> i >> j >> e;
		G.matrix[i][j] = e;
		G.matrix[j][i] = e;
	}

	short_path_floyd(G, pathmatrix, shortPath);

	return 0;
}