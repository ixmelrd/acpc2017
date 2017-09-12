#include<iostream>
#include<vector>
#include<algorithm>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
using namespace std;
const int inf = 1e9;
typedef vector<int> vi;
typedef long long ll;
#define MOD 1000000007
// a^b mod MOD
ll powmod(ll a,ll b){
	ll out=1;
	ll p=a%MOD;
	while(b){
		if(b&1)out=out*p%MOD;
		p=p*p%MOD;
		b>>=1;
	}
	return out;
}
#define M 200100
vector<ll> fact;
void init(){
	fact=vector<ll>(M);
	fact[0]=fact[1]=1;
	loop(i,2,M)fact[i]=fact[i-1]*i%MOD;
}
// nCr
ll nCr(ll n,ll r){
	if(n<r)return 0;
	ll out=fact[n]*powmod(fact[r]*fact[n-r]%MOD,MOD-2)%MOD;
	return out;
}
ll solve(ll n,ll m){
	if(n==1)return 0;
	vi cnt(m+1);
	rep(i,n)if((m+i)%2==0&&m-i>=0){
		//up+down=m
		//up-down=i
		// -> up=(m+i)/2 down=(m-i)/2
		ll up=(m+i)/2,down=(m-i)/2;
		ll N[2]={n,1};
		int t=up,q=1;
		cnt[t]-=1;
		while(t>=0){
			if(q)cnt[t]+=1;
			else cnt[t]-=1;
			q^=1;
			t-=N[q];
		}
		t=up,q=1;
		while(t<=m){
			if(q)cnt[t]+=1;
			else cnt[t]-=1;
			q^=1;
			t+=N[q^1];
		}
	}
	ll out=0;
	rep(i,m+1)(out+=cnt[i]*nCr(m,i)+MOD)%=MOD;
	return out;
}
int main(){
	init();
	ll n,m;
	cin>>n>>m;
//	cout<<solve(n,m)<<endl;
	cout<<(solve(n,m)-solve(n-1,m)+MOD)%MOD<<endl;
}