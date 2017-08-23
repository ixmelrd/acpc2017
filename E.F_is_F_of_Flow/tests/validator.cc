#include "./testlib.h"
#include "./constraints.hpp"
#include <cassert>
#include <algorithm>

bool graph[5000][5000];

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
    for(int i = 0; i < V; i++){ //事故ループ検出
        assert(graph[i][i] == 0);
    }

    inf.readEof();
}
