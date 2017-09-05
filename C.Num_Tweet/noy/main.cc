#include<iostream>
#include<vector>
#include<queue>
#include<map>
#define range(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
using namespace std;

vector<int> graph[100005];
vector<int> leef, loot;

int bfs(int n, int start, int k){
    bool used[100005] = {0};
    queue<pair<int, int>> q;

    q.push(make_pair(start, k));
    used[start] = 1;

    int res = 0;
    while(not q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        //cout << "ur " << cur.first << endl;
        res++;
        //cout << "to " << cur.first << endl;
        for(auto to : graph[cur.first]){
            if(not used[to] && cur.second - 1 >= 0){
                used[to] = true;
                q.push(make_pair(to, cur.second - 1));
            }
        }
    }
    for(auto i : loot){
        //cout << "loot " << i << ' ' << used[i] << endl;
        if(not used[i]) res++;
    }
    if(used[0]) res--;
    return res - 1;
}

int main(){
    int n, k;
    cin >> n >> k;

    map<int,bool> m;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        m[a] = true;
        if(a == 0) loot.emplace_back(i + 1);
        graph[a].emplace_back(i + 1);
        graph[i + 1].emplace_back(a);
    }

    for(int i = 1; i <= n; i++){
        if(not m.count(i)){
            leef.emplace_back(i);
        }
    }


    for(auto i : leef){
        //cout << i << endl;
        graph[i].emplace_back(n + 1);
        graph[n + 1].emplace_back(i);
    }

    cout << bfs(n, n + 1, k) << endl;
}
