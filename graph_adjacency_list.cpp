// used https://www.programiz.com/dsa/graph-adjacency-list to help understanding of how to code this

#include <iostream>
//library in C++ for lists
#include <list>

class Graph {
    public:
    int nVertex;
    std::list<int> *adjacencyList;
    Graph(int _nVertex) {
        nVertex = _nVertex;
        adjacencyList = new std::list<int> [_nVertex];
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

int main() {
    Graph adjListGraph = Graph(6);

    adjListGraph.addEdge(1,3);
    adjListGraph.addEdge(0,1);
    adjListGraph.addEdge(5,4);
    adjListGraph.addEdge(2,4);
    adjListGraph.addEdge(2,3);
    

    adjListGraph.print();
}


