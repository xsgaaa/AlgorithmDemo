#include<iostream>
using namespace std;

#define MAX 7			//顶点数量
#define INF 65535		//代表无穷大
//邻接矩阵
typedef struct graph
{
	char vexs[MAX];		//顶点集合
	int vexnum;			//顶点数
	int edgnum;			//边数
	int matrix[MAX][MAX];		//邻接矩阵
}Graph,*pGraph;

////边的结构体
//typedef struct EdgeData
//{
//	char start;		//边的起点
//	char end;		//边的终点
//	int weight;		//边的权重
//}EData;


/*
* Dijkstra最短路径。
* 即，统计图(G)中"顶点vs"到其它各个顶点的最短路径。
*
* 参数说明：
*        G -- 图
*       vs -- 起始顶点(start vertex)。即计算"顶点vs"到其它顶点的最短路径。
*     prev -- 前驱顶点数组。即，prev[i]的值是"顶点vs"到"顶点i"的最短路径所经历的全部顶点中，位于"顶点i"之前的那个顶点。
*     dist -- 长度数组。即，dist[i]是"顶点vs"到"顶点i"的最短路径的长度。
*/
void dijkstra(Graph G, int vs, int prev[], int dist[])
{
	int i, j, k;
	int min;			//存放最小边
	int tmp;			//存放临时路径长度
	int flag[MAX];		//flag[i]=1 表示顶点vs到顶点i的最短路径已成功获取

	//初始化
	for (i = 0; i < G.vexnum; i++)
	{
		flag[i] = 0;	//顶点i的最短路径还没有获取到
		prev[i] = 0;	//顶点i的前驱节点为0
		dist[i] = G.matrix[vs][i];		//初始距离为起点到其余各点的距离
	}
	
	//对顶点vs自身进行初始化
	flag[vs] = 1;
	dist[vs] = 0;

	//遍历G.vexnum-1次；每次找出一个顶点的最短路径
	for (i = 1; i < G.vexnum; i++)
	{
		//寻找当前最小的路径；
		// 即，在未获取最短路径的顶点中，找到离vs最近的顶点(k)。
		min = INF;
		for (j = 0; j < G.vexnum; j++)
		{
			if (flag[j] == 0 && dist[j] < min)
			{
				min = dist[j];		//存放最短路径
				k = j;				//存放最短路径的节点
			}
		}


		//标记顶点k为已获取到的最短路径
		//k为没有被获取到的，最短路径
		flag[k] = 1;

		// 修正当前最短路径和前驱顶点
		// 即，当已经"顶点k的最短路径"之后，更新"未获取最短路径的顶点的最短路径和前驱顶点"。
		for (j = 0; j < G.vexnum; j++)
		{
			// 防止溢出，不会产生超过INF的数
			//如果G.matrix[k][j]为INF，结果为INF，如果小于INF，则结果min + G.matrix[k][j]
			tmp = (G.matrix[k][j] == INF ? INF : (min + G.matrix[k][j]));	
			if (flag[j] == 0 && (tmp<dist[j]))
			{
				dist[j] = tmp;		//更新路径长度
				prev[j] = k;		//j的前一个结点为k
			}
		}
	}

	// 打印dijkstra最短路径的结果
	cout << "dijkstra(" << G.vexs[vs] << "):" << endl;
	for (i = 0; i < G.vexnum; i++)
		cout << "shortest(" << G.vexs[vs] <<","<< G.vexs[i] << ")=" << dist[i] << endl;
}

int main()
{
	Graph G;
	int i = 0, j = 0,e=0,prev[MAX],dist[MAX];
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

	dijkstra(G, 3, prev, dist);

	return 0;
}