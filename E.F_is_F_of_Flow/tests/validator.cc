#include "./testlib.h"
#include "./constraints.hpp"
#include <cassert>
#include <algorithm>
#include <queue>
#include <iostream>

bool graph[5000][5000];

bool isLinking(int V){
    bool used[5000] = {0};
    std::queue<int> q;

    used[0] = 1;
    q.push(0);

    int u;
    while(!q.empty()){
        u = q.front(); q.pop();
        for(int v = 0; v < V; v++){
            if(graph[u][v] && not used[v]){
                used[v] = true;
                q.push(v);
            }
        }
    }

    for(int i = 0; i < V; i++){
        if(not used[i]) return false;
    }
    return true;
}

int main(){
    registerValidation();
    int V = inf.readInt(MIN_V, MAX_V);
    inf.readSpace();
    int E = inf.readInt(MIN_E, std::min(MAX_E, V * (V + 1) / 2));
    inf.readEoln();

    for(int i = 0; i < E; i++){
        int e = inf.readInt(0, V - 1);
        inf.readSpace();
        int t = inf.readInt(0, V - 1);
        inf.readSpace();
        inf.readInt(MIN_C, MAX_C);
        inf.readEoln();

        assert(graph[e][t] == 0); //多重辺の検出
        assert(graph[t][e] == 0);
        graph[e][t] = graph[t][e] = 1;
    }
    for(int i = 0; i < V; i++){ //自己ループ検出
        assert(graph[i][i] == 0);
    }
    assert(isLinking(V));
    inf.readEof();
}
