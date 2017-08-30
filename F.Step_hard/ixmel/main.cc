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
#define M 1000100
vector<ll> fact;
void init(){
	fact=vector<ll>(M);
	fact[0]=fact[1]=1;
	loop(i,2,M)fact[i]=fact[i-1]*i%MOD;
}
// nCr
ll nCr(ll n,ll r){
	if(n<r)return 1;
	ll out=fact[n]*powmod(fact[r]*fact[n-r]%MOD,MOD-2)%MOD;
	return out;
}
int main(){
	;
}