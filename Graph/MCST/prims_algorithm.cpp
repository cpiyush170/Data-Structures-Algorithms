#include <bits/stdc++.h>
#define I INT_MAX
using namespace std;

int cost[8][8] = {
    {I, I, I, I, I, I, I, I},
    {I, I, 25, I, I, I, 5, I},
    {I, 25, I, 12, I, I, I, 10},
    {I, I, 12, I, 8, I, I, I},
    {I, I, I, 8, I, 16, I, 14},
    {I, I, I, I, 16, I, 20, 18},
    {I, 5, I, I, I, 20, I, I},
    {I, I, 10, I, 14, 18, I, I}
};
int near[8] = {I, I, I, I, I, I, I, I};

int res[2][6];

int main() {
    int n = 7, u, v, min = I;
    // finding the minimum cost edge
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(cost[i][j] < min){
                min = cost[i][j];
                u = i, v = j; // storing edges for use
            }
        }
    }
// putting the recorded edges in resultant matrix
    res[0][0] = u;
    res[1][0] = v;
// marking the minimum edges as 0 (as they are included);
    near[u] = 0; near[v] = 0;

// finding out all other vertices that are nearer to
// elements included in resultant matrix, we will do
// updating near array from cost matrix

    for(int i = 1; i <= n; i++){
        if(near[i] != 0){
        if(cost[i][u] < cost[i][v]){
            near[i] = u;
        }
        else{
            near[i] = v;
        }
        }
    }
// reapeating steps
    int k;
    for(int i = 1; i < n - 1; i++){

        min = I;
        for(int j = 1; j <= n; j++){
            if(near[j] != 0 && cost[j][near[j]] < min){
                min = cost[j][near[j]];
                k = j;
            }
        }
// adding minimum edges in res matrix
        res[0][i] = k;
        res[1][i] = near[k];
// marking them zero
    near[k] = 0;

// again updating near array

for(int j = 1; j <= n; j++){
    if(near[j] != 0 && cost[j][k] < cost[j][near[j]]){
        near[j] = k;
    }
}
}

// printing res
    for(int i = 0; i < n - 1; i++){
        cout << "(" << res[0][i] << "," << res[1][i] <<")"<< endl;
    }
}
