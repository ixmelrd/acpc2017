#include<iostream>
#include<vector>
#include<queue>
#include<map>
#define range(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
using namespace std;

vector<int> graph[100005];
vector<int> leef, loot;

void dfs(int cur, int k, bool used[100005]){
    used[cur] = true;
    for(auto to : graph[cur]){
        if(not used[to] && k - 1 >= 0){
            dfs(to, k - 1, used);
        }
    }
}

int main(){
    int n, k;
    cin >> n >> k;

    map<int,bool> m;
    bool used[100005] = {0};
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        m[a] = true;
        if(a == 0) used[i + 1] = true;
        graph[i + 1].emplace_back(a);
    }

    for(int i = 1; i <= n; i++){
        if(not m.count(i)){
            //cout << "leef " << i << endl;
            leef.emplace_back(i);
        }
    }

    for(auto i : leef){
        dfs(i, k - 1, used);
    }

    int sum = 0;
    range(i,1,n + 1){
        if(used[i]) sum++;
    }


    cout << sum << endl;
}
