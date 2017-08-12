#include<iostream>
#include<vector>
#define rep(i,a) for(int i=0;i<a;i++) 
using namespace std;
typedef long long ll;
const ll inf=1e8;
int main(){
	int n,d;
	cin>>n>>d;
	vector<ll>t(n+1,inf),f(n+1,1);
	rep(i,n)cin>>t[i]>>f[i];
	ll out=0,l=0;
	rep(i,n)if(f[i+1]+f[i]-2<=t[i+1]-t[i])if(d<=i-l){
		cout<<-1<<endl;
		return 0;
	}else while(l!=i+1)out+=t[i]+f[i]-1-t[l++];
	cout<<out<<endl;
}