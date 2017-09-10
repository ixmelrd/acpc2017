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
ll solve2(ll n,ll m,ll a,ll b){
	ll out;
	if(a<=n&&b<=m)out=(nCr(n+m,n)-nCr(n+m,m-b)-solve2(n-a,m+a,b,2*a+b)+MOD)%MOD;
	else if(a<=n)out=(nCr(n+m,n)-nCr(n+m,n-a)+MOD)%MOD;
	else if(b<=m)out=(nCr(n+m,n)-nCr(n+m,m-b)+MOD)%MOD;		
	else out=nCr(n+m,n);

	cout<<n<<" "<<m<<" "<<a<<" "<<b<<" "<<out<<endl;
	return out;
}
ll solve(ll n,ll m){
	if(n==1)return 0;
	
	ll out=0;
	rep(i,n)if((m+i)%2==0&&m-i>=0){
		ll up=(m+i)/2,down=(m-i)/2;
		//up+down=m
		//up-down=i
		// -> up=(m+i)/2 down=(m-i)/2
		(out+=solve2(up,down,n,1))%=MOD;
	}
	return out;
}
int main(){
	init();
	ll n,m;
	cin>>n>>m;
	cout<<solve(n,m)<<endl;
//	cout<<(solve(n,m)-solve(n-1,m)+MOD)%MOD<<endl;
}