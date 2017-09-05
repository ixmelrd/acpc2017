#include<iostream>
#include<vector>
#include<cmath> 
using namespace std;
int main(){
  int n,d;
  cin>>n>>d;
  int now=1;
  int bef=0;
  vector<int> ans(2000005,0);
  int el=0;
  vector<int> t(n),f(n);
  for(int i=0;i<n;i++)cin>>t[i]>>f[i];
  for(int i=0;i<n;i++){
    if(abs(now-f[i])>t[i]-bef){
      cout<<-1<<endl;
      return 0;
    }else if(now-1+f[i]-1<=t[i]-bef){
      ans[bef+now-1]-=el;
      el=0;
    }
    ans[t[i]]++;
    el++;
    now=f[i];
    bef=t[i];
    if(el==d){
      bef=bef+now-1;
      now=1;
    }
  }
  ans[t[n-1]+f[n-1]-1]-=el;
  for(int i=0;i<2000004;i++)ans[i+1]+=ans[i];
  long long sum=0;
  for(int i=0;i<2000004;i++)sum+=ans[i];
  cout<<sum<<endl;
}
