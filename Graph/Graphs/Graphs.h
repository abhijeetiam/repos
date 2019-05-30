#pragma once

#include <iostream>
#include <map>
#include <list>
#include <set>
#include <queue> 

using namespace std;

struct Edge {
	int startVertex;
	int endVertex;
	int weight;				//Needed only for weighted graphs
};

typedef std::list<struct Edge> EdgeList;
typedef std::map<int, EdgeList> GraphMap;

class Graphs
{
	public:
		Graphs();
		~Graphs();

		void CreateGraph(const int src, const int dest, const int weight);
		void PrintGraphMap();
		void DFS();
		void BFS(const int start, const int end);
		void Explore(int, std::set<int>&, std::list<int>&);
		void PrintList(std::list<int>&);

		enum Operations
		{
			CREATE = 1,
			PRINT,
			PRINT_DFS,			//Uses stack LIFO
			PRINT_BFS,			//Uses queue FIFO
			EXIT = 10
		};

	private:

		struct Edge EdgeInfo;
		GraphMap edgeMap_;
		GraphMap::iterator iter_;
};

