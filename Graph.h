#pragma once
#include <iostream>
#include <array>
#include <queue>
#include <map>
#include <stack>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const int INF = numeric_limits<int>::max();

class Graphs {
public:

struct Edge {
	int weight;
	int indexTo;
};

struct Node {
	int id;
	vector <Edge> edges;

	int prevIndex;
	int weight;
	bool visited;
	string name;

	void setName(string name) {
		this->name = name;
	}
};

struct Graph {

	vector <Node> nodes;

	void clear()
	{
		nodes.clear();
	}
	void clear_edges()
	{
		for (auto& node : nodes)
		{
			node.edges.clear();
		}
	}
	void init_start_values() {
		for (auto& node : nodes) {
			node.weight = INF;
			node.visited = false;
			node.prevIndex = INF;
		}
	}

};

bool read_nodes(istream& istream, int nodes_count, Graph& graph_out)
{
	graph_out.nodes.clear();
	string name;

	for (int i = 0; i < nodes_count; i++)
	{
		decltype(Node::id) id;
		istream >> id >> name;
		graph_out.nodes.push_back({ id });
		graph_out.nodes[i].setName(name);

	}

	return true;
}

bool read_edges(istream& istream, int edges_count, Graph& graph_out)
{
	graph_out.clear_edges();

	for (int i = 0; i < edges_count; i++)
	{
		int start_id, end_id;
		int weight;

		istream >> start_id >> end_id;
		istream >> weight;

		auto& nodes_ref = graph_out.nodes;  //vector tmp

		// iter start,end bestimmen
		auto start_iter = find_if(nodes_ref.begin(), nodes_ref.end(), [start_id](const auto& node) { return node.id == start_id; });
		auto end_iter = find_if(nodes_ref.begin(), nodes_ref.end(), [end_id](const auto& node) { return node.id == end_id; });

		
		int index = (end_iter - nodes_ref.begin());            //index bestimmen 3-0 = 3
		(*start_iter).edges.push_back(Edge{ weight, index });  //Edge speichern
	}

	return true;
}

Graph read_graph(const string& file_path)
{
	Graph graph;
	ifstream fin(file_path);
	if (fin)
	{
		int node_count;
		int edge_count;

		fin >> node_count >> edge_count;

		if (read_nodes(fin, node_count, graph))
		{
			read_edges(fin, edge_count, graph);
		}
	}
	return graph;
}

vector<int> convert_to_path(Graph& graph, int start_index, int end_index)
{
	vector<int> result;
	stack<int> tmp_path;
	int current_node = end_index;  // wir beginnen am ende
	while (current_node != INF)
	{
		tmp_path.push(current_node);                            //current -> stack
		current_node = graph.nodes[current_node].prevIndex;     // den Weg wiederherstellen current -> prev
	}
	while (!tmp_path.empty())                                   // while not empty -> stack -> vector
	{ 
		result.push_back(tmp_path.top());
		tmp_path.pop();
	}
	return result;
}

std::vector<int> find_path(Graph& graph, string start, string end)
{
	int start_index = 0;
	int end_index = 0;

	for (int i = 0; i < graph.nodes.size();i++) {
		if (graph.nodes[i].name == start)
			start_index == i;
		if (graph.nodes[i].name == end)
			end_index = i;
	}

	graph.init_start_values();                  //wir füllen alles mit INF, false
	multimap<int, int> min_weigth_map;
	graph.nodes[start_index].weight = 0;
	min_weigth_map.insert({ 0, start_index });  // start index waehlen, weight -> 0
	while (!min_weigth_map.empty())             // weil nicht empty
	{
		auto current = *(min_weigth_map.begin()); // die Erste Node bekommen
		int current_weight = current.first;       // 1. Element -> current weight
		int current_index = current.second;       // 2. Element -> current id
		min_weigth_map.erase(min_weigth_map.begin()); // pop()
		if (graph.nodes[current_index].visited)
		{
			continue;
		}

		graph.nodes[current_index].visited = true;  // current Node als besucht markieren und besuchen alle seine Nachbarn

		for (int i = 0; i < graph.nodes[current_index].edges.size(); i++)  // weil es gibt Edges
		{
			int index_to = graph.nodes[current_index].edges[i].indexTo;      //wohin zeigt diese Edge von current Node
			int edged_weight = graph.nodes[current_index].edges[i].weight;   //welche Gewicht hat Edge von current Node
			if (!graph.nodes[index_to].visited)                              //when Zielort noch nicht besucht
			{
				if (current_weight + edged_weight < graph.nodes[index_to].weight)  //Abstand berechnen von current Node bis Zielort
				{                                                                   // when Abstand kleiner -> speichern
					graph.nodes[index_to].weight = current_weight + edged_weight;
					graph.nodes[index_to].prevIndex = current_index;
					min_weigth_map.insert({ graph.nodes[index_to].weight, index_to });  //z.B. London ist gespeichert (1700,5) push()
				}
			}
		}

	}

	return convert_to_path(graph, start_index, end_index);
}


};


