#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0; i<n;i++)
using namespace std;
typedef pair<int,int> pii;
void call(){puts("-1");}
signed main(){
    int n,d; cin>>n>>d;
    vector<int>t(n);
    vector<int>r(n);
    rep(i,n)cin>>t[i]>>r[i];
    pii now=pii(0,0);
    int cnt=0,ans=0;
    for(int i=0; i<n;i++){
        
        if(cnt==d+1){call();;return 0;}
        if(!i&&t[0]<r[0]-1){call();return 0;}
        else if(!i){now=pii(t[i],r[i]);cnt++; continue;}
        if(t[i]-now.first<abs(r[i]-now.second)){call();return 0;}
        if(now.second+r[i]-2<=t[i]-now.first){
            ans+=cnt*(now.second-1);
            cnt=1;
            now=pii(t[i],r[i]);
            continue;
        }
        
        if(now.second==r[i]){ans+=cnt*(t[i]-now.first);cnt++;now=pii(t[i],r[i]); continue;}
        if(abs(now.second-r[i])<=t[i]-now.first){
            ans+=cnt*abs(t[i]-now.first);
            cnt++;
            now=pii(t[i],r[i]);
            continue;
        }
    }
    if(cnt>d){call();return 0;}
    ans+=cnt*(now.second-1);
    cout<<ans<<endl; return 0;
}
