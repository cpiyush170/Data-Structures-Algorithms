#include <iostream>
#include <list>
#include <map>
using namespace std;

class Graph{

    map<int, list<int>> l;
public:
    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

// it is a recursive function that will traverse graph
    void dfs_helper(int src, map<int, bool> &visited){

        cout << src <<" ";
        visited[src] = true;
// for every neighbour of source in list, recursively
// visit it, if it isn't visited and mark it true
        for(auto nbr : l[src]){
            if(!visited[nbr]){
                dfs_helper(nbr, visited);
            }
        }

    }
    void dfs(int src){
        map<int, bool> visited;
// mark all the nodes as not visited in the beginning
        for(auto pr : l){
            int node = pr.first;
            visited[node] = false;
        }
        dfs_helper(src, visited);
    }

};
int main() {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.addEdge(2, 3);
    g.addEdge(4, 5);

    g.dfs(3);
}
