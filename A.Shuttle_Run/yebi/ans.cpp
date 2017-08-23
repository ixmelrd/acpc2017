#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n;i++)
int main(){
	string s; cin>>s;
	bool Isreach=true;
	bool past=true;
	int cnt=0;
	rep(i,s.size()){
		if(s[i]=='o'){
			past=true;
			cnt++;
		}else if(past==false){
			Isreach=false;
			break;
		}else{
			past=false;
		}
	}
	if(Isreach)return puts("-1")*0;
	cout<<cnt<<endl;
}
