#include "Graphs.h"

int main()
{
	int n;
	Graphs* graph = new Graphs();
	
	while (true)
	{
		cout << "============================TREE MENU=============================" << endl;
		cout << "1: CREATE graph" << endl;
		cout << "2: PRINT elements" << endl;
		cout << "3: DFS elements" << endl;
		cout << "4: BFS elements" << endl;
		cout << "10: EXIT " << endl;
		cout << "==================================================================" << endl;
		cout << "Enter your choice : ";

		cin >> n;

		switch (n)
		{
			case Graphs::CREATE:
			{

				cout << "Creating graph..." << endl;

				graph->CreateGraph(0, 1, 0);
				graph->CreateGraph(1, 2, 0);
				graph->CreateGraph(2, 0, 0);
				graph->CreateGraph(2, 1, 0);
				graph->CreateGraph(2, 3, 0);
				graph->CreateGraph(3, 2, 0);
				graph->CreateGraph(3, 4, 0);
				graph->CreateGraph(4, 3, 0);
				graph->CreateGraph(4, 5, 0);
				//graph->CreateGraph(4, 5, 0);
				//graph->CreateGraph(5, 4, 0);
				break;
			}

			case Graphs::PRINT:
			{
				cout << "Printing graph..." << endl;

				graph->PrintGraphMap();
				break;
			}

			case Graphs::EXIT:
			{
				cout << "Exiting ... !!!!" << endl;
				return 1;
			}

			case Graphs::PRINT_DFS:
			{
				cout << "Printing DFS Traversal of the graph" << endl;

				graph->DFS();
				break;
			}

			case Graphs::PRINT_BFS:
			{
				cout << "Printing BFS Traversal of the graph" << endl;

				graph->BFS(0,5);
				break;
			}

			default:
			{
				cout << "Invalid choice" << endl;
			}
		}

	}
	system("pause");
	return 1;
};