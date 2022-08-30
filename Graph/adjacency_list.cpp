#include <iostream>
#include <vector>
using namespace std;
/* Adjacency list representation of graph */

int main() {
    int v, e; // taking input of vertices and edges
    cin >> v >> e;

    vector<int> g[v+1]; // array for adjacency list

    for(int i = 0; i < e; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for(int i = 1; i <= v; i++){
        cout<<i<<"--> ";
        for(int j = 0; j < g[i].size(); j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
}
