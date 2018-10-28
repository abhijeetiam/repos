#include "Graphs.h"

Graphs::Graphs()
{
}

Graphs::~Graphs()
{
}

void Graphs::CreateGraph(const int src, const int dest, const int weight)
{
	EdgeInfo.startVertex = src;
	EdgeInfo.endVertex = dest;
	EdgeInfo.weight = weight;

	//cout << "========BEFORE===========" << endl;
	//PrintGraphMap();

	EdgeList edgeList;

	iter_ = edgeMap_.find(src);
	if (iter_ != edgeMap_.end())
		edgeList = edgeMap_[src];
	
	edgeList.push_back(EdgeInfo);
	edgeMap_[src] = edgeList;

	//cout << "========AFTER===========" << endl;
	//PrintGraphMap();
}

void Graphs::PrintGraphMap()
{
	EdgeList edgeList;
	for (auto& mapElem : edgeMap_)
	{
		edgeList = mapElem.second;
		for (auto& edge : edgeList)
		{
			cout << edge.startVertex << " --> " << edge.endVertex << " with weight: " << edge.weight << endl;
		}
	}
}

void Graphs::DFS()
{
	std::set<int> seen;		//keep track of visited nodes

	for (auto& mapElem : edgeMap_)		//going through global map
	{
		if (seen.count(mapElem.first) == 0)		//checking if first node is visited or not
		{
			std::list<int> component;				//will have component graphs
			Graphs::Explore(mapElem.first, seen, component);	//getting to all possible neighbors of node from edgeList
			Graphs::PrintList(component);			//printing components
		}
	}
}

void Graphs::Explore(int vertex, std::set<int>& seen, std::list<int>& component)
{
	seen.insert(vertex);
	component.push_back(vertex);

	EdgeList edgeList = edgeMap_[vertex];		//getting all neighbors for the the vertex and going through each of them
	for (auto& edge : edgeList)
	{
		if (seen.count(edge.endVertex) == 0)
		{
			Graphs::Explore(edge.endVertex, seen, component);	//Recursively adding all neighbors to the seen and component list
		}
	}
}

void Graphs::PrintList(std::list<int>& list)
{
	for (auto& elem : list)
		cout << elem << " ";
	cout << endl;
}

void Graphs::BFS(const int start, const int end)
{
	std::set<int> seen;		//keep track of visited nodes
	std::queue<int> q;		//Queing nodes
	std::vector<int> dist;	//tracking distance from start to end node

	q.push(start);			//starting with first node and adding to seen list
	seen.insert(start);

	while (!q.empty())		//process first node while queue is not empty
	{
		int curr = q.front();
		q.pop();

		cout << curr << " ";

		EdgeList edgeList = edgeMap_[curr];
		for (auto& edge : edgeList)			//getting all neighbors for the the vertex and going through each of them
		{
			if (seen.count(edge.endVertex) == 0)
			{
				seen.insert(edge.endVertex);
				q.push(edge.endVertex);
			}
		}
	}
	cout << endl;
}