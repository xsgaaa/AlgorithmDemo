#include<iostream>
#include<list>
#include<queue>
using namespace std;

/*
	在图论中，拓扑排序（Topological Sorting）是一个有向无环图（DAG, Directed Acyclic Graph）
	的所有顶点的线性序列。且该序列必须满足下面两个条件：
		(1)每个顶点出现且只出现一次。
		(2)若存在一条从顶点 A 到顶点 B 的路径，那么在序列中顶点 A 出现在顶点 B 的前面。
	有向无环图（DAG）才有拓扑排序，非DAG图没有拓扑排序一说。
*/





/*********************类声明*******************/
class Graph
{
public:
	Graph(int V);		//构造函数
	~Graph();			//析构函数
	void addEdge(int v, int w);	//添加边
	bool topological_sort();	//拓扑排序
private:
	int V;				//顶点个数
	list<int> *adj;		//邻接表
	queue<int>q;		//维护一个入度为0的顶点的集合
	int *indegree;		//数组，记录每个顶点的入度
};

/**********************成员函数实现********************/
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];		//分配内存

	indegree = new int[V];		//入度全部初始化为0
	for (int i = 0; i < V; i++)
	{
		indegree[i] = 0;
	}
}

Graph::~Graph()
{
	delete[]adj;
	delete[]indegree;
}

void Graph::addEdge(int v, int w)		//v->w
{
	adj[v].push_back(w);				//将w加入到邻接表中
	++indegree[w];						//w的入度加1
}

bool Graph::topological_sort()
{
	for (int i = 0; i < V; i++)
	{
		if (indegree[i] == 0)
			q.push(i);		//将所有入度为0的顶点入队
	}

	int count = 0;			//计数，记录当前已经输出的顶点数

	while (!q.empty())		//入度为0的队列不为空
	{
		int v = q.front();	//取出队头取出元素
		q.pop();			//弹出元素
		cout << v << " ";
		++count;

		list<int>::iterator beg = adj[v].begin();	//定义迭代器
		for (; beg != adj[v].end(); ++beg)			//当迭代器不到末尾的时候，每次循环后移一位
		{
			if (!(--indegree[*beg]))				//若入度为0，则入栈
				q.push(*beg);
		}
	}

	if (count < V)
	{
		return false;		//没有输出全部顶点，有向图中有回路
	}
	else
		return true;		//拓扑排序成功
}

int main()
{
	Graph g(6);			//创建图
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);

	g.topological_sort();
	return 0;
}