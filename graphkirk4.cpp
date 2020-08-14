#include <iostream>
#include <map>
#include <vector>
#include <string>
class undirectedgraph
{
public:
	undirectedgraph() { };
	~undirectedgraph() { };
	struct mazenode
	{
		mazenode() : x(0), y(0), vertex(0) { };
		~mazenode() { };
		int x;
		int y;
		int vertex;
		bool visited;
	};
	void connectnodes(int node1, int node2, int cost = 1);
	template<size_t r, size_t c>
	void mazetograph(mazenode(&mas)[r][c], std::string(&grid)[r][c]);
	void buildgraph(std::map<int, std::vector<std::pair<int, int>>> myNodes);
	std::map<int, std::vector<std::pair<int, int>>> myNodes;
	std::map<int, bool> treevisited;
	template<size_t r, size_t c>
	void bfsgogoprint(int go, mazenode(&mas)[r][c]);
	void bfsgogoprint(int go,int finish);
	std::vector<int> p;
private:
	//std::map<int, std::vector<std::pair<int, int>>> myNodes;
};
int main()
{
	static const size_t r = 10, c = 30;
	//std::string grid[r][c]{
	//	{"?","?","?","?","?","?","?","?","?","?","?","?"},//минимальный пример
	//	{"#",".",".",".",".",".","?","?","?","?","?","#"},
	//	{"#",".","#","#","#","#","#","#","#","#","#","#"},
	//	{"#",".",".",".",".",".",".",".",".","?",".","#"},
	//	{"#",".","#","#","#","#","#","#",".","?",".","#"},
	//	{"#",".","#",".",".",".","#","#",".","?",".","#"},
	//	{"#",".",".",".","#",".",".",".",".",".",".","#"},
	//	{"#","#","#","#","#","#","#","#","#","#","#","#"},
	//};


	std::string grid[10][30]{
	{"?","?","?","?","?","?","?","?","?","?","?","?","?","?","?","?","?","?","?","?","?","?","?","?","?","?","?","?","?","?"}, // матрица смежности
	{"#",".",".",".",".",".",".",".",".",".",".",".",".",".",".","?","?","?","?","?","?","?","?","?","?","?","?","?","?","?"},
	{"#",".","#","#","#","#","#","#","#","#","#","#","#","#","#","?","?","?","?","?","?","?","?","?","?","?","?","?","?","?"},
	{"#",".",".",".",".",".","T",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".","?","?","?","?"},
	{"#",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".","#",".","#",".",".","#"},
	{"#",".","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#",".","#",".",".","#"},
	{"#",".",".",".",".",".","#","#",".",".",".",".",".",".","#","#",".",".",".",".",".",".","#",".",".",".",".","#","#","#"},
	{"#",".",".",".","#","#","#","#",".",".","#","#",".",".","#","#",".",".","#","#",".",".","#",".",".","#",".",".",".","#"},
	{"#",".",".",".",".",".",".",".",".",".","#","#",".",".",".",".",".",".","#","#",".",".",".",".",".","#",".","C",".","#"},
	{"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"} };

	using undrctgrph_t = undirectedgraph;
	undrctgrph_t::mazenode graph[r][c];
	undrctgrph_t p;
	std::cout << "Hello World!\n";
	p.mazetograph(graph, grid);
}

void undirectedgraph::connectnodes(int node1, int node2, int cost)
{
	using nv_t = std::vector<std::pair<int, int>>;
	nv_t nvt;
	using nvpar_t = std::pair<int, int>;
	nvpar_t t;
	t.first = node2;
	t.second = 1;
	myNodes[node1].push_back(t);
	myNodes.emplace(node1, node2);
}

void undirectedgraph::buildgraph(std::map<int, std::vector<std::pair<int, int>>> myNodes)
{
	std::map<int, std::vector<std::pair<int, int>>>::iterator it = undirectedgraph::myNodes.begin();
	std::cout << "graph{" << "\n";
	for (int i = 1; it != undirectedgraph::myNodes.end(); ++it, ++i) {
		std::cout << "node_" << i << "[label =" << i << "]" << "\n";
	}
	std::cout << "\n\n\n";
	std::map<int, std::vector<std::pair<int, int>>>::iterator itt = undirectedgraph::myNodes.begin();
	for (int i = 1; itt != undirectedgraph::myNodes.end(); ++itt, ++i) {
		//std::cout << i << " = ";
		for (const auto& pair : undirectedgraph::myNodes[i]) {
			//node_0 -- node_1
			std::cout << "\t" << "node_" << (itt->first) << "--" << " " << "node_" << pair.first << std::endl;
		}std::cout << " " << "\n";
	}
	std::cout << "}" << "\n";
}
void undirectedgraph::bfsgogoprint(int go,int finish)
{
	int i = myNodes.find(go)->first;
	//std::cout << myNodes.find(go)->second[0].first << std::endl;

	undirectedgraph::p.push_back(i);

	bool thisfail=false;

	std::vector<int>::iterator it = undirectedgraph::p.begin();
	if (i != finish) {
		i = myNodes.find(go)->second[0].first;

		for (; it != undirectedgraph::p.end(); ++it)
		{
			if (*it == i) thisfail = true;
			//std::cout << "fail" << std::endl;

		}
		if (thisfail) {
			std::cout << myNodes.find(go)->second[1].first << std::endl;
			bfsgogoprint(myNodes.find(go)->second[1].first,finish);
		}
		if(!thisfail) {
			std::cout << myNodes.find(go)->second[0].first << std::endl;
			bfsgogoprint(myNodes.find(go)->second[0].first,finish);
		}

		thisfail = false;
	}
}
template<size_t r, size_t c>
void undirectedgraph::bfsgogoprint(int start,mazenode(&graph)[r][c])
{
	////std::cout<< 
	//std::queue<int> q;
	//q.push(start);
	//int vertex[500],d[500];
	//for (size_t i = 0; i < 500; i++)
	//{
	//	vertex[i] = -1;
	//	d[i] = 0;
	//}
	//vertex[start] = 0;
	//int i = 0;
	//while (!q.empty())
	//{
	//	int temp = q.front();
	//	q.pop();
	//	while (vertex[temp] != -1 && graph[temp][i].vertex!=0) {
	//		q.push(vertex[temp]);
	//		d[i] = d[temp]+1;
	//		//std::cout << d[i] <<" "<< std::endl;
	//		std::cout << graph[temp][i].x<<" "<< graph[temp][i].y << std::endl;
	//		i++;
	//	}
	//}
}
template<size_t r, size_t c>
void undirectedgraph::mazetograph(mazenode(&graph)[r][c], std::string(&grid)[r][c])
{
	int l = 0;
	for (size_t i = 0; i < r; i++)
	{
		for (size_t y = 0; y < c; y++)
		{
			if (grid[i][y] == "?" || grid[i][y] == "#")
			{

			}
			if (grid[i][y] == ".")
			{
				l++;
				graph[i][y].x = i;
				graph[i][y].y = y;
				graph[i][y].vertex = l;
				graph[i][y].visited = false;
			}
			if (grid[i][y] == "T"|| grid[i][y] == "C")
			{
				l++;
				graph[i][y].x = i;
				graph[i][y].y = y;
				graph[i][y].vertex = l;
				graph[i][y].visited = false;
			}
		}
	}
	for (size_t i = 0; i < r; i++)
	{

		for (size_t y = 0; y < c; y++)
		{
			if (graph[i][y].vertex != 0 && graph[i + 1][y].vertex != 0) {

				undirectedgraph::connectnodes(graph[i][y].vertex, graph[i + 1][y].vertex);
			}
			if (graph[i][y].vertex != 0 && graph[i][y + 1].vertex != 0) {

				undirectedgraph::connectnodes(graph[i][y].vertex, graph[i][y + 1].vertex);
			}
			if (graph[i][y].vertex != 0 && graph[i - 1][y].vertex != 0) {

				undirectedgraph::connectnodes(graph[i][y].vertex, graph[i - 1][y].vertex);
			}
			if (graph[i][y].vertex != 0 && graph[i][y - 1].vertex != 0) {

				undirectedgraph::connectnodes(graph[i][y].vertex, graph[i][y - 1].vertex);
			}
			std::cout << "\t" << graph[i][y].vertex;
		}std::cout << " " << "\n";
	}

	std::cout << " " << "\n\n\n";

	std::map<int, std::vector<std::pair<int, int>>>::iterator it = undirectedgraph::myNodes.begin();

	for (int i = 1; it != undirectedgraph::myNodes.end(); ++it, ++i) {
		std::cout << i << " = ";
		for (const auto& pair : undirectedgraph::myNodes[i]) {
			std::cout << "\t" << (it->first) << " " << pair.first << std::endl;
		}std::cout << " " << "\n";
	}

	buildgraph(myNodes);

	int start,finish;
	std::cout << "Enter start: ";
	std::cin >> start;
	std::cout << "Enter finish: ";
	std::cin >> finish;
	bfsgogoprint(start,finish);

	
}
