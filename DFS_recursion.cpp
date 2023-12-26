#include <iostream>
#include <list>

using namespace std;

//graph class from adjacency list code
class Graph {
    public:
    int nVertex;
    std::list<int> *adjacencyList;
    bool *visited;
    Graph(int _nVertex) {
        nVertex = _nVertex;
        adjacencyList = new std::list<int> [_nVertex];
        visited = new bool[nVertex];
    }
    void addEdge(int start, int end) {
        if ((start < 0 || start >= nVertex) || (end < 0 || end >= nVertex)) {
            return;
        }
        //add edge that is undirected
        adjacencyList[start].push_back(end);
        adjacencyList[end].push_back(start);
    }
    void print() {
        for (int i = 0; i < nVertex; i++) {
            std::cout << "\n Vertex " << i << ": ";
            //to iterate through the list
            for (auto value : adjacencyList[i]) {
                std::cout << value << " ";
            }
        }
    }
};

void DFS(Graph *g, int v) {
    if (v >= g->nVertex || v < 0) {
        return;
    }

    g->visited[v] = true;

    cout << v << " ";

    //iterator type for template class list<int>
    list<int>::iterator i;

    for (i = g->adjacencyList[v].begin(); i != g->adjacencyList[v].end(); i++) {
        if (!g->visited[*i]) {
            DFS(g, *i);
        }
    }
}

int main() {
    //setting up graph
    Graph adjListGraph = Graph(6);

    adjListGraph.addEdge(1,3);
    adjListGraph.addEdge(0,1);
    adjListGraph.addEdge(5,4);
    adjListGraph.addEdge(2,4);
    adjListGraph.addEdge(2,3);
    
    adjListGraph.print();

    cout << "\n DFS: " << endl;

    DFS(&adjListGraph, 0);
}

