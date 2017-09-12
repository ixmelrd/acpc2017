#include<iostream>
#include<vector>
using namespace std;

int main(){
  int n,k;
  cin>>n>>k;
  vector<bool> b(n+1,true);//bottom
  int a[100005]={};
  for(int i=1;i<=n;i++){
    cin>>a[i];
    if(a[i])b[a[i]]=false;
  }
  vector<int> rank(100005,100000);
  for(int i=1;i<=n;i++)
    if(b[i]){
      rank[i]=1;
      int j=i;
      while(a[j]!=0){
	if(rank[j]+1>=rank[a[j]])break;
	rank[a[j]]=rank[j]+1;
	j=a[j];
      }
    }

  int ans=0;
  for(int i=1;i<=n;i++)if(a[i]==0 || rank[i]<=k)ans++;
  cout<<ans<<endl;
}
