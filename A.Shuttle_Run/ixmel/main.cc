#include<iostream>
#include<string>
#define rep(i,a) for(int i=0;i<a;i++)
using namespace std;
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	rep(i,s.size()-1)if(s[i]=='x'&&s[i+1]=='x'){
		cout<<i<<endl;
		return 0;
	}
	cout<<-1<<endl;
}