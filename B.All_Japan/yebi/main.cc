#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0; i<n;i++)
using namespace std;
signed main(){
    int n,d; cin>>n>>d;
    typedef pair<int,int>pii;
    vector<pii>v;
    rep(i,n){
        pii hoge; cin>>hoge.first>>hoge.second;
        v.push_back(hoge);
    }
    int ans=0;
    pii now=pii(0,1);
    int cnt=0;
    rep(i,n){
        if(i==0&&v[i].second-1>v[i].first)return puts("-1")*0;
        if(!i){cnt++;now=v[i]; continue;}
        if(v[i].first-now.first<abs(now.second-v[i].second))return puts("-1")*0;
        if(cnt==d&&v[i].first-now.first<now.second+v[i].second-2)return puts("-1")*0;
        if(now==v[i]){cnt++;now=v[i];continue;}
        if(now.second+v[i].second-2<=v[i].first-now.first){
            ans+=(cnt*(now.second-1));
            cnt=1;
            now=v[i];
            continue;
        }else if(v[i].second-now.second>=abs(v[i].second-now.second)){
            ans+=abs(now.second-v[i].second)*cnt;
            cnt++;
            now=v[i];
        }
    }
    ans+=(v[n-1].second-1)*cnt;
    cout<<ans<<endl;
}

