#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n;i++)
int main(){
	int n; cin>>n;
	string s; cin>>s;
	rep(i,s.size()-1){
		if(s[i]=='x'&&!(s[i]-s[i+1])){
			cout<<i+1<<endl;
			return 0;
		}
	}
	cout<<n<<endl;
}
