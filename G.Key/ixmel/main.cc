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
#define it vector<int>::iterator
bool next_combination(it first1,it last1,it first2,it last2){
	if((first1==last1)||(first2==last2))return false;
	it m1=last1,m2=last2;
	m2--;
	while(--m1!=first1&&!(*m1<*m2));
	bool result=(m1==first1)&&!(*first1<*m2);
	if(!result){
		while(first2!=m2&&!(*m1<*first2))first2++;
		first1=m1;
		iter_swap(first1,first2);
		first1++;first2++;
	}
	if((first1!=last1)&&(first2!=last2)){
		m1=last1;m2=first2;
		while((m1!=first1)&&(m2!=last2))iter_swap(--m1,m2++);
		reverse(first1,m1);
		reverse(first1,last1);
		reverse(m2,last2);
		reverse(first2,last2);
	}
	return !result;
}
bool next_combination(it first,it middle,it last){
  return next_combination (first , middle , middle , last );
}
/*
n=5,r=3;
a=0 1 1 2 3
011 012 013 023 112 113 123
*/
//combination (begin,begin+r,end)
int n,m;
vi po,ne;
int calc(int sum_posi,int max_posi,int sum_nega,int max_nega){
	int posi=max((max_posi+sum_posi)%2,max_posi-sum_posi);
	int nega=max((max_nega+sum_nega)%2,max_nega-sum_nega);
	
	if(posi%2!=nega%2)return inf;
	int cnt=(sum_posi+max_posi-posi)/2+
			(sum_nega+max_nega-nega)/2+
			min(posi,nega)*2+
			abs(posi-nega)/2*3;
	return cnt;
}
int solve(){
	sort(all(po));
	sort(all(ne));
	int sum_po=0,max_po=-1;
	int sum_ne=0,max_ne=-1;
	rep(i,po.size()){
//		cout<<" "<<po[i];
		sum_po-=po[i];
		max_po=max(max_po,-po[i]);
	}
//	cout<<endl;
	rep(i,ne.size()){
//		cout<<" "<<ne[i];
		sum_ne-=ne[i];
		max_ne=max(max_ne,-ne[i]);
	}
//	cout<<endl;
//	cout<<endl;
	int out=inf;
	rep(k,4){
		if(k<=po.size()){
			vi w(po.size());
			rep(i,po.size())w[i]=i;
			do{
				int sum_posi=sum_po,max_posi=0;
				int sum_nega=sum_ne,max_nega=max_ne;
				rep(j,k){
					sum_posi+=po[w[j]];
					sum_nega+=m+po[w[j]];
					max_nega=max(max_nega,m+po[w[j]]);
				}
				rep(j,min((int)po.size(),4)){
					bool h=true;
					rep(l,k)if(j==w[l])h=false;
					if(h){
						max_posi=-po[j];
						break;
					}
				}
				sum_posi-=max_posi;
				sum_nega-=max_nega;
//				cout<<k<<endl;
//				rep(j,po.size())cout<<" "<<w[j];cout<<endl;
//				cout<<sum_posi<<" "<<max_posi<<endl;
//				cout<<sum_nega<<" "<<max_nega<<endl;
//				cout<<endl;
				out=min(out,calc(sum_posi,max_posi,sum_nega,max_nega));
			}while(next_combination(w.begin(),w.begin()+k,w.end()));
		}
		if(k<=ne.size()){
			vi w(ne.size());
			rep(i,ne.size())w[i]=i;
			do{
				int sum_posi=sum_po,max_posi=max_po;
				int sum_nega=sum_ne,max_nega=0;
				rep(j,k){
					sum_posi+=m+ne[w[j]];
					sum_nega+=ne[w[j]];
					max_posi=max(max_posi,m+ne[w[j]]);
				}
				rep(j,min((int)ne.size(),4)){
					bool h=true;
					rep(l,k)if(j==w[l])h=false;
					if(h){
						max_nega=-ne[j];
						break;
					}
				}
				sum_posi-=max_posi;
				sum_nega-=max_nega;

//				cout<<k<<endl;
//				rep(j,ne.size())cout<<" "<<w[j];cout<<endl;
//				cout<<sum_posi<<" "<<max_posi<<endl;
//				cout<<sum_nega<<" "<<max_nega<<endl;
//				cout<<endl;
				
				out=min(out,calc(sum_posi,max_posi,sum_nega,max_nega));
			}while(next_combination(w.begin(),w.begin()+k,w.end()));
		}
	}
	return out;
}
int main(){
	cin>>n>>m;
	vi in(n);
	rep(i,n)cin>>in[i];
	if(n==2){
		if(in[0]==in[1])cout<<min(in[0],m-in[0])<<endl;
		else cout<<-1<<endl;
	}else{
		vi P,N;
		int co=0;//2*in[i]==m
		rep(i,n)if(2*in[i]==m)co++;
		else if(2*in[i]<m)P.pb(-in[i]);
		else N.pb(-m+in[i]);

		int out=inf;
		if(co>=4){
			po=P;ne=N;
			rep(j,co/2)po.pb(-m/2);
			rep(j,co-co/2)ne.pb(-m/2);
			out=min(out,solve());
		}else{
			rep(i,co+1){
				po=P;ne=N;
				rep(j,i)po.pb(-m/2);
				rep(j,co-i)ne.pb(-m/2);
//				rep(j,po.size())cout<<" "<<po[j];cout<<endl;
//				rep(j,ne.size())cout<<" "<<ne[j];cout<<endl;
				out=min(out,solve());
			}
		}
		if(out==inf)cout<<-1<<endl;
		else cout<<out<<endl;
	}
}




