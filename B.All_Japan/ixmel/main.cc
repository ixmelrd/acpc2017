#include<iostream>
#include<vector>
#define rep(i,a) for(int i=0;i<a;i++) 
using namespace std;
typedef long long ll;
const ll inf=1e8;
int main(){
	int n,d;
	cin>>n>>d;
	vector<ll>t(n+2,inf),f(n+2,1);
	rep(i,n)cin>>t[i+1]>>f[i+1];
	t[0]=0;
	ll out=0,l=0;
	bool h=true;
	rep(i,n+1)if(f[i+1]+f[i]-2<=t[i+1]-t[i])if(d<=i-l)h=false;
	else while(l!=i+1)out+=t[i]+f[i]-1-t[l++];
	else if(abs(f[i+1]-f[i])>t[i+1]-t[i])h=false;

	if(!h)out=-1;
	cout<<out<<endl;
}
