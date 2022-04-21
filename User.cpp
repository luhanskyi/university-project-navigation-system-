#include "User.h"
using namespace std;

void User::Dialog()
{
	//ImportFromFile();

	while (true) {

		char input;
		cout << endl;
		cout << "User Menu:" << endl;
		cout << "\t 1.Navigation starten" << endl;
		cout << "\t x.Beenden" << endl;

		cin >> input;
		switch (input) {
		case'1': {

			Graphs g;
			string from, to;
			cout << "From:"; cin >> from;
			cout << "To:"; cin >> to;

			auto graph = g.read_graph("input.txt");
			auto path = g.find_path(graph, from, to);

			for (auto path_node_index : path)
			{
				std::cout << "ID:" << graph.nodes[path_node_index].id << " " << graph.nodes[path_node_index].name << " "
					<< graph.nodes[path_node_index].weight << " " << "km " << endl;
			}

			std::cout << std::endl;

		} break;
		case'2': {

		} break;

		case'x': {

			return;
		} break;

		}
	}


}
