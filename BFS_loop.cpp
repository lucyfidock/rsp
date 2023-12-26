#include <iostream>

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

void BFS(Graph *g, int s) {
    //mark all vertices as not visited
    for (int i = 0; i < g->nVertex; i++) {
        g->visited[i] = false;
    }

    list<int> queue;

    //mark s as visited and add to queue
    g->visited[s] = true;
    queue.push_back(s);

    while (!queue.empty()) {

        //dequeue vertex and print 
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        //get all adjacent vertices of s, if it has not been visited, mark as visited and add to queue 
        for (auto adj : g->adjacencyList[s]) {
            if (!g->visited[adj]) {
                g->visited[adj] = true;
                queue.push_back(adj);
            }
        }

        //could also do this way instead of auto 
        //iterator type for template class list<int>
        //list<int>::iterator i;

        //for (i = g->adjacencyList[s].begin(); i != g->adjacencyList[s].end(); i++) {
        //    if (!g->visited[*i]) {
        //        g->visited[*i] = true;
        //        queue.push_back(*i);
        //}
    
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

    cout << "\n BFS: " << endl;

    BFS(&adjListGraph, 1);
}

