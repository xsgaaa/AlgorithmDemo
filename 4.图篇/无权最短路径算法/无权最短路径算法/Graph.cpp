#include"Graph.h"

void Graph::unweightShortestPathAdv(int src)
{
	queue<int> que;
	for (int i = 0; i < vertex_num; i++)
	{
		nodeArr[i].dist = INFINITY;
	}
	nodeArr[src].dist = 0;
	que.push(src);

	while (!que.empty())
	{
		int top = que.front();
		que.pop();


		for (list<Node>::iterator it = graph_list[top].begin(); it != graph_list[top].end(); ++it)
		{
			if (nodeArr[(*it).vertex].dist == INFINITY)
			{
				nodeArr[(*it).vertex].dist = nodeArr[top].dist + 1;
				nodeArr[(*it).vertex].path = top;

				que.push((*it).vertex);
			}
		}
	}
}

void Graph::unweightShortestPath(int src)
{
	for (int i = 0; i < vertex_num; i++)
	{
		nodeArr[i].known = false;
		nodeArr[i].dist = INFINITY;
		nodeArr[i].path = 0;
	}

	nodeArr[src].dist = 0;

	for (int currentDist = 0; currentDist < vertex_num; ++currentDist)
	{
		for (int i = 0; i < vertex_num; ++i)
		{
			if ((!nodeArr[i].known) && (nodeArr[i].dist == currentDist))
			{
				nodeArr[i].known = true;

				for (list<Node>::iterator it = graph_list[i].begin(); it != graph_list[i].end(); ++it)
				{
					if (nodeArr[(*it).vertex].dist == INFINITY)
					{
						nodeArr[(*it).vertex].dist = currentDist + 1;
						nodeArr[(*it).vertex].path = i;
					}
				}
			}
		}
	}
}

void Graph::printShortestPath()
{
	cout << "¶¥µã\t" << "known\t" << "dist\t" << "path" << endl;
	for (int i = 0; i < vertex_num; i++)
	{
		if (nodeArr[i].known)
		{
			cout << i << "\t" << nodeArr[i].known << "\t" << nodeArr[i].dist << "\t" << nodeArr[i].path << endl;
		}
	}

}

void Graph::print()
{
	cout << "*************************************************************" << endl;
	for (int i = 0; i < vertex_num; i++)
	{
		if (graph_list[i].begin() != graph_list[i].end())
		{
			cout << i << "-->";
			for (list<Node>::iterator it = graph_list[i].begin(); it != graph_list[i].end(); ++it)
			{
				cout << (*it).vertex << "(±ßºÅ£º" << (*it).edge_num << "£¬È¨ÖØ£º" << (*it).weight << ")-->";
			}
			cout << "NULL" << endl;
		}
	}
	cout << "**************************************************************" << endl;
}


vector<int> Graph::get_graph_value(char* graph[], int columns)
{
	vector<int> v;
	char buff[20];
	int i = 0, j = 0, val;
	memset(buff, 0, 20);

	while ((graph[columns][i] != '\n') && (graph[columns][i] != '\0'))
	{
		if (graph[columns][i] != ',')
		{
			buff[j] = graph[columns][i];
			j++;
		}
		else
		{
			j = 0;
			val = atoi(buff);
			v.push_back(val);
			memset(buff, 0, 20);
		}
		i++;
	}
	val = atoi(buff);
	v.push_back(val);

	return v;
}

void Graph::addEdge(char* graph[], int columns)
{
	Node node;
	vector<int> v = get_graph_value(graph, columns);
	node.edge_num = v[0];
	node.src = v[1];
	node.vertex = v[2];
	node.weight = v[3];

	if (node.vertex > vertex_num)
	{
		vertex_num = node.vertex;
	}

	for (list<Node>::iterator it = graph_list[node.src].begin(); it != graph_list[node.src].end(); ++it)
	{
		if ((*it).vertex == node.vertex)
		{
			if ((*it).weight > node.weight)
			{
				(*it).weight = node.weight;
			}
			return;
		}
	}
	graph_list[node.src].push_back(node);
}

Graph::Graph(char* graph[], int edgenum) :nodeArr(MAX_VERTEX_NUM)
{
	edge_num = edgenum;
	vertex_num = 0;
	graph_list = new list<Node>[MAX_VERTEX_NUM + 1];

	for (int i = 0; i < edgenum; i++)
	{
		addEdge(graph, i);
	}
	vertex_num++;
}

Graph::~Graph()
{
	delete[] graph_list;
}
