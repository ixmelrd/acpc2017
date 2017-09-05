#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<cstdio>
#include<sstream>
#include<iomanip>
#include<assert.h>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
typedef int Def;
typedef pair<Def,Def> pii;
typedef vector<Def> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<Def,pii> pip;
typedef vector<pip>vip;
//#define mt make_tuple
//typedef tuple<double,int,double> tp;
//typedef vector<tp> vt;
template<typename A,typename B>bool cmin(A &a,const B &b){return a>b?(a=b,true):false;}
template<typename A,typename B>bool cmax(A &a,const B &b){return a<b?(a=b,true):false;}
const double PI=acos(-1);
const double EPS=1e-7;
Def inf = sizeof(Def) == sizeof(long long) ? 2e18 : 1e9;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
struct edge{int to,cap,rev,no;};//ikisaki youryou gyakuhen
class MF{//max flow
	public:
	int n;
	vector<vector<edge> >G;//[MAX];
	vector<bool>used;//[MAX];
	MF(int size){
		n=size;
		G=vector<vector<edge> >(n);
	}
	void add_edge(int from, int to, int cap){
		edge q={to,cap,int(G[to].size()),1};
		G[from].push_back(q);
		q={from,0,int(G[from].size()-1),0};
		G[to].push_back(q);
	}
	int dfs(int v,int t, int f) {
		if(v==t)return f;
		used[v]=1;
		for(int i=0;i<G[v].size();i++){
			edge &e=G[v][i];
			if(used[e.to]||e.cap<=0) continue;
			int d =dfs(e.to,t,min(f,e.cap));
			if(d>0){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
		return 0;
	}
	int mf(int s,int t) {//from s to t,ford_fulkerson
		int flow=0,f;
		while(1){
			used=vector<bool>(n,false);
			f=dfs(s,t,inf);
			if(f==0)return flow;
			flow+=f;
			if(flow>=10010)return -1;
		}
	}
	int from,to;
	bool DFS(int a){
		if(a==to)return true;
		used[a]=true;
		rep(i,G[a].size()){
			edge e=G[a][i];
			if(a==from&&e.to==to)continue;
			if(used[e.to])continue;
			if(e.cap&&G[e.to][e.rev].cap&&DFS(e.to))return true;
		}
		return false;
	}
	int solve(){
		int flow=mf(0,n-1);
		if(flow==-1)return -1;
		rep(i,n)rep(j,G[i].size()){
			edge e=G[i][j];
			if(e.no==1&&e.cap==0&&G[e.to][e.rev].cap==1){
//				cout<<i<<" "<<e.to<<endl;
				used=vector<bool>(n);
				from=e.to,to=i;
				if(!DFS(e.to))return flow-1;
			}
		}
		return flow<=10000?flow:-1;
	}
};
int main(){
	int n,m;
	cin>>n>>m;
	MF mf(n);
	rep(i,m){
		int a,b,c;
		cin>>a>>b>>c;
		mf.add_edge(a,b,c);
		mf.add_edge(b,a,c);
	}
	cout<<mf.solve()<<endl;
}










