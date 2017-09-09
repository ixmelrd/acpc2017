#include<iostream>
#include<vector>
#include<queue>
#define rep(i,a) for(int i=0;i<a;i++) 
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
class DIJ{
	public:
	struct edge{
		int to,cost;
	};
	vector<vector<edge> >G;
	int n;
	vi d;//distance
	DIJ(int size){
		n=size;
		G=vector<vector<edge> >(n);
	}
	void add_edge(int a,int b,int c){
		edge e={b,c},ee={a,c};
		G[a].pb(e);
//		G[b].pb(ee);
	}
	void dij(int s){
		d=vi(n,1e9);
		d[s]=0;
		priority_queue<pii>q;
		q.push(pii(0,s));
		while(!q.empty()){
			pii p=q.top();
			q.pop();
			int pos=p.second,cost=-p.first;
			if(cost>d[pos])continue;
			rep(i,G[pos].size()){
				edge e=G[pos][i];
				int to=e.to;
				int nowcost=cost+e.cost;
				if(nowcost<d[to]){
					d[to]=nowcost;
					q.push(pii(-d[to],to));
				}
			}
		}
	}
};
int main(){
	int n,k;
	cin>>n>>k;
	DIJ dij(n+1);
	vi cnt(n);
	rep(i,n){
		int a;
		cin>>a;
		if(a){
			dij.add_edge(i,a-1,1);
			cnt[a-1]++;
		}else dij.add_edge(n,i,1);
	}
	rep(i,n)if(!cnt[i])dij.add_edge(n,i,1);
	dij.dij(n);
	int out=0;
	rep(i,n)if(dij.d[i]<=k)out++;
	cout<<out<<endl;
}










