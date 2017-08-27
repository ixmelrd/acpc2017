#include <iostream>
#include <utility>
#include "./testlib.h"
#include "./constraints.hpp"
#include <sys/types.h>
#include <unistd.h>
#include <cassert>
#include <set>

using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)

using PR = pair<int,int>;
using TPL = tuple<int,int,int>;

void output(int V, int E, const vector<TPL> &edges, const string &prefix, int suffix){
    assert(static_cast<int>(edges.size()) == E);
    char name[100];
    sprintf(name, "%s_%02d.in", prefix.c_str(), suffix);
    ofstream ofs(name);
    ofs << V << ' ' << E << endl;
    for (int i = 0; i < E; ++i) {
        int a, b, c;
        tie(a, b, c) = edges[i];
        ofs << a << ' ' << b << ' ' << c << '\n';
    }
    ofs.close();
}

vector<PR> createTree(int V){
    vector<PR> edges;
    for(int i = 1; i < V; i++){
        int par = rnd.next(0, i - 1);
        edges.emplace_back(i, par);
    }
    return edges;
}

vector<PR> createStar(int V){
    int c = rnd.next(0, V - 1);
    vector<PR> edges;
    for(int i = 0; i < V; i++){
        if(i == c) continue;
        edges.emplace_back(c,i);
    }
    return edges;
}

vector<PR> addEdgesToTree(int V, int E){
    vector<PR> edges = createTree(V);
    for(auto &e : edges){
        if(e.first > e.second) swap(e.first, e.second);
    }
    set<PR> used(edges.begin(), edges.end());
    assert(E <= static_cast<int>(V * (V - 1) / 2));
    while(static_cast<int>(edges.size()) != E){
        int a = rnd.next(0, V - 1);
        int b = rnd.next(0, V - 1);
        if(a == b) continue;
        if(a > b) swap(a,b);
        if(used.count(make_pair(a,b))) continue;
        edges.emplace_back(a,b);
        used.emplace(a,b);
    }
    shuffle(edges.begin(), edges.end());
    return edges;
}

//一直線のグラフを作る
vector<PR> createPathGraph(int V){
    vector<PR> edges;
    rep(i,V - 1){
        edges.emplace_back(i, i + 1);
    }
    return edges;
}

vector<TPL> random_c(const vector<PR> &edges, int max_c){
    int E = edges.size();
    vector<TPL> res(E);
    rep(i,E){
        int a, b;
        tie(a, b) = edges[i];
        int c = rnd.next(1, max_c);
        if(rnd.next(1, 3) == 1) c = 1; // 30%の確率で容量1になる
        res[i] = make_tuple(a, b, c);
    }
    return res;
}

vector<TPL> max_c(const vector<PR> &edges, int max_c){
    int E = edges.size();
    vector<TPL> res(E);
    rep(i,E){
        int a, b;
        tie(a, b) = edges[i];
        int c = max_c;
        if(rnd.next(1, 3) == 1) c = 1; // 30%の確率で容量1になる
        res[i] = make_tuple(a, b, c);
    }
    return res;
}


int main(){
    // 乱数のシードを設定
    // pidを足すことで、1秒以上間を置かずに起動したときに同じシードになってしまうのを防ぐ
    rnd.setSeed(time(0)+getpid());

    // 手計算できるぐらい小さいケース
    for(int i = 0; i < 10; i++){
        int V = rnd.next(MIN_V, 5);
        int E = rnd.next(V - 1, V * (V - 1) / 2);
        int C = 5;
        vector<TPL> g = random_c(addEdgesToTree(V, E), C);
        output(V, E, g, "random_small", i);
    }

    // 乱数ケース (連結)
    for(int i = 0; i < 10; ++i){
        int V = rnd.next(MIN_V, MAX_V);
        int E = rnd.next(V - 1, min(MAX_E, V * (V + 1) / 2));
        int C = rnd.next(MIN_C, MAX_C);
        vector<TPL> g = random_c(addEdgesToTree(V,E), C);
        output(V, E, g, "50_random", i);
    }

    // 木
    for(int i = 0; i < 4; i++){
        int V = rnd.next(MIN_V, MAX_V);
        int E = rnd.next(V - 1, min(MAX_E, V * (V + 1) / 2));
        int C = rnd.next(MIN_C, MAX_C);
        vector<TPL> g = random_c(addEdgesToTree(V, E), C);
        output(V, E, g, "tree", i);
    }

    // スター
    for(int i = 0; i < 4; i++){
        int V = rnd.next(MIN_V, MAX_V);
        vector<TPL> g = random_c(createStar(V), MAX_C);
        output(V, V - 1, g, "star", i);
    }

    //一直線のグラフ
    {
        int V = MAX_V;
        vector<TPL> g = random_c(createPathGraph(V), MAX_C);
        output(V, V - 1, g, "StraightGraph", 0);
    }

    //最大コストの辺ばかり (いらない)
    {
        int V = MAX_V;
        int E = MAX_E;
        vector<TPL> g = max_c(addEdgesToTree(V,E), MAX_C);
        output(V, E, g, "maximum_cost", 0);

    }
}
