#include <iostream>
#include<map>
#include<queue>
#include <list>
using namespace std;

template<typename T>
class Graph{
 // we are using hashmap to represent adjacency list
// hashmap with key of type T, and value is list of type T
    map<T, list<T>> l;
public:

    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfs(T src){
// we need two data structures for implementing
// bfs: visited array and queue
    map<T, bool> visited;
    queue<T> q;
    // add source node to queue
    q.push(src);
    // mark it visited
    visited[src] = true;

    // now keep popping element from queue until
// it doesn't gets empty
    while(!q.empty())
    {
// keep node in temp variable
        T node = q.front();
// print it 
        cout << node << " ";
// pop it
        q.pop();
// now explore all the neighbours of that node
// put them in queue and mark visited
    for(auto nbr : l[node]){
// if not visited, push it into queue and mark visited
        if(!visited[nbr]){
        q.push(nbr);
        visited[nbr] = true;
        }
    }

    }

    }
};
int main() {
    Graph<int> g;

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    g.bfs(1);
}
