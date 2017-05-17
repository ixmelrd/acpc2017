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
#include<cstdio>
#include<sstream>
#include<iomanip>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef pair<int,pii> pip;
typedef vector<pip>vip;
const double PI=acos(-1);
const double EPS=1e-8;
const int inf=1e8;
vector<string> split(string s){
	stringstream ss(s);//ss<<s;
	vector<string> vec;
	for(int i=0;!ss.eof();i++){
		string t;ss>>t;
		vec.pb(t);
	}
	return vec;
}
int main(){
	int n;
	cin>>n;
	int out=0;
	string s;
	getline(cin,s);
	rep(i,n){
		cout<<"lst "<<i<<endl;
		getline(cin,s);
		int co=split(s).size()-1;
		out+=co*(co-1);
	}
	cout<<"ans "<<out<<endl;
}





