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
	vector<vector<edge> >hozon;
	vi level,iter;//[MAX];
	MF(int size){
		n=size;
		hozon=vector<vector<edge> >(n);
	}
	void add_edge(int from, int to, int cap){
		edge q={to,cap,int(hozon[to].size()),1};
		hozon[from].push_back(q);
		q={from,0,int(hozon[from].size()-1),0};
		hozon[to].push_back(q);
	}
	void bfs(int s){
		level=vi(n,-1);
		queue<int>q;
		level[s]=0;
		q.push(s);
		while(!q.empty()){
			int v=q.front();q.pop();
			for(int i=0;i<G[v].size();i++){
				edge &e=G[v][i];
				if(e.cap>0&&level[e.to]<0){
					level[e.to]=level[v]+1;
					q.push(e.to);
				}
			}
		}
	}
	int dfs(int v,int t, int f) {
		if(v==t)return f;
		for(int &i=iter[v];i<G[v].size();i++){
			edge &e=G[v][i];
			if(level[v]>=level[e.to]||e.cap<=0) continue;
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
		G=hozon;
		int flow=0;
		while(1){
			bfs(s);
			if(level[t]<0)return flow;
			iter=vi(n);
			int f;
			while((f=dfs(s,t,inf))>0)flow+=f;
			if(flow>=10010)return inf;
		}
	}//4 4 0 1 3 0 2 4 1 3 1 2 3 5
	int solve(){
		int flow=mf(0,n-1);
		rep(i,n)rep(j,hozon[i].size()){
			edge e=hozon[i][j];
			if(e.no==1&&e.cap==1){
				hozon[i][j].cap=0;
				flow=min(flow,mf(0,n-1));
				hozon[i][j].cap=1;
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










