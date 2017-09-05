#include<iostream>
#include<vector>
#include<queue>
#define range(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
using namespace std;

vector<int> graph[100005];
vector<int> leef;

void dfs(int n, int cur, vector<bool> &used){
    bool f = false;
    for(auto to : graph[cur]){
        if(used[to]) continue;
        used[to] = true;
        dfs(n, to, used);
        f = true;
    }
    if(not f) leef.emplace_back(cur);
}

int bfs(int n, int start, int k){
    bool used[100005] = {0};
    queue<pair<int, int>> q;

    q.push(make_pair(start, k));
    used[start] = 1;

    int res = 0;
    while(not q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        //cout << "ur " << cur.first << endl;
        if(cur.second == 0) continue;
        for(auto to : graph[cur.first]){
            if(not used[to]){
                res++;
                used[to] = true;
                q.push(make_pair(to, cur.second - 1));
            }
        }
    }
    return res;
}

int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        graph[a].emplace_back(i + 1);
        graph[i + 1].emplace_back(a);
    }
    vector<bool> used(n + 1, 0);
    dfs(n, 0, used);

    for(auto i : leef){
        //cout << i << endl;
        graph[i].emplace_back(n + 1);
        graph[n + 1].emplace_back(i);
    }

    cout << bfs(n, n + 1, k) << endl;
}
