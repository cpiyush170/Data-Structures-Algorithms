#include <iostream>
#include <vector>

using namespace std;
int main() {
   
   int v, e;
   cin >> v >> e;

   // 2d matrix for adjacency matrix
   int g[v+1][v+1];

   for(int i = 1; i <= v; i++){
       for(int j = 1; j <= v; j++) g[i][j] = 0;
}

    for(int i = 0; i < e; i++){
        int x, y;
        cin >> x >> y;
        g[x][y] = 1;
        g[y][x] = 1;
    }

    for(int i = 1; i <= v; i++){
        cout<<i<<"--> ";
        for(int j = 1; j <= v; j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
}
