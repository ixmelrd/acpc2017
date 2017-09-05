#include<iostream>
#include<vector>
using namespace std;

vector<bool> ans(100005,false);//seen
int n,k;
int a[100005]={};

void dfs(int i,int t){
  if(t>=k)return;
  ans[i]=true;
  if(a[i-1])dfs(a[i-1],t+1);
}

int main(){
  cin>>n>>k;
  vector<bool> t(n+1,true);//bottom
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(a[i]==0)ans[i+1]=true;
    else t[a[i]]=false;
  }
  for(int i=1;i<=n;i++)if(t[i])dfs(i,0);
  int sum=0;
  for(int i=1;i<=n;i++)if(ans[i])sum++;
  cout<<sum<<endl;
}
