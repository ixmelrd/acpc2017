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
Def inf=sizeof(Def)==sizeof(long long)?2e18:1e9;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int main(){
	int n,m;
	cin>>n>>m;
	vi in(n);
	rep(i,n)cin>>in[i];
	if(n==2){
		if(in[0]==in[1])cout<<in[0]<<endl;
		else cout<<-1<<endl;
	}else{
//		vi posi,nega;
		vi t(n);
		int out=inf;
		rep(i,1<<n){
			rep(j,n)if(i&1<<j)t[j]=m-in[j];
			else t[j]=in[j];
			int sum_posi=0,max_posi=-1;
			int sum_nega=0,max_nega=-1;
			rep(j,n)if(i&1<<j){
				sum_nega+=t[j];
				max_nega=max(max_nega,t[j]);
			}else{
				sum_posi+=t[j];
				max_posi=max(max_posi,t[j]);
			}
			sum_posi-=max_posi;
			sum_nega-=max_nega;
			
			int posi=max((max_posi+sum_posi)%2,max_posi-sum_posi);
			int nega=max((max_nega+sum_nega)%2,max_nega-sum_nega);
			
			if(posi%2!=nega%2)continue;
			int cnt=(sum_posi+max_posi-posi)/2+
					(sum_nega+max_nega-nega)/2+
					min(posi,nega)*2+
					abs(posi-nega)/2*3;
			out=min(out,cnt);
//			rep(j,n)cout<<" "<<t[j];cout<<endl;
//			rep(j,n)cout<<" "<<(i>>j&1);cout<<endl;
//			cout<<cnt<<endl;
		}
		if(out==inf)cout<<-1<<endl;
		else cout<<out<<endl;
	}
}




