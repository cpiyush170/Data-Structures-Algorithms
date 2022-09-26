#include <iostream>
#include <list>
using namespace std;

// Adjacency list representation of graph using array of lists ---> O(n) time complexity
class Graph{

    int V; // no. of vertices in graph
    // Array of lists
    list<int> *l;
public:
// constructor
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }
// adding a bi-directional edge
// l[0] = 1
// l[1] = 0
    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

// printing adjacency list
    void printAdjList(){

        for(int i = 0; i < V; i++){
            cout <<"Vertex "<<i<<" -> ";
            for(int nbr : l[i]){
                cout<<nbr<<",";
            }
            cout << endl;
        }
    }
};
int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 2);

    g.printAdjList();
}
