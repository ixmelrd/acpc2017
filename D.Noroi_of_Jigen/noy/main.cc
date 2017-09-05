#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define range(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) range(i,0,a)
using namespace std;

const int INF = 1e9;

class Edge{
    public:
        int to, cost;
        Edge(int to, int cost) : to(to) ,cost(cost) {}
};

class Node{
    public:
        int dis;
        bool isUsed;
        Node(){
            this->dis = INF;
            this->isUsed = 0;
        }
};

typedef vector<vector<Edge>> AdjList;

int dijkstra(AdjList g, int start, int goal, int n){
    vector<Node> node(n);
    priority_queue<int, vector<pair<int, int>>, greater<pair<int, int>>> q;

    q.push(make_pair(0, start));
    node[start].dis = 0;

    pair<int, int> u;
    while(not q.empty()){
        u = q.top(); q.pop();
        int current = u.second;
        node[current].isUsed = 1;

        rep(i,g[current].size()){
            int next = g[current][i].to;
            if(node[next].isUsed == 0){
                if(node[next].dis > node[current].dis + g[current][i].cost){
                    node[next].dis = node[current].dis + g[current][i].cost;
                    q.push(make_pair(node[next].dis, next));
                }
            }
        }
    }
    return node[goal].dis;
}

int main(){
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    int d[100005];
    rep(i,n) cin >> d[i];

    AdjList g(n);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].emplace_back(Edge{b,d[b]});
    }
    range(i,1,n){
        g[i].emplace_back(Edge{i - 1, 0});
    }
    cout << dijkstra(g, s - 1, t - 1, n) << endl;
}
