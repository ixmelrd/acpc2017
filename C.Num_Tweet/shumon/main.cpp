#include<iostream>
#include<iomanip>
#include<queue>
#include<string>
#include<stack>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<cassert>
#include<ctime>
#include<algorithm>
#include<utility>
#include<map>
#include<set>
#include<vector>
#include<functional>

using namespace std;

typedef  long long           ll;
typedef  unsigned            ui;
typedef  unsigned long long  ull;
typedef  pair<int,int>       i_i;
typedef  pair<ll,int>        ll_i;
typedef  pair<ll,ll>         ll_ll;
typedef  pair<double,int>    d_i;
typedef  pair<double,double> d_d;

//#define DEBUG
#ifdef DEBUG
#define dprintf      printf
#define dout(x)      cout<<#x" = "<<(x)<<endl
#define darray(x,n)  {int i;rep(i,n)cout<<#x"["<<i<<"] = "<<*((x)+i)<<endl;}
#define dloop(i,s,g) for(int (i)=(s);(i)<(g);(i)++)
#define drep(i,n)    for(int (i)=0;(i)<(n);(i)++)
#define dstop()      scanf("%*c")
#else
#define dprintf      (1)?0:printf
#define dout(x)
#define darray(x,n)
#define dloop(i,s,g) if(int i=0){}else
#define drep(i,n)    if(int i=0){}else
#define dstop()
#endif

#define F    first
#define S    second
#define pb   push_back
#define mp   make_pair

#define loop(i,s,g) for((i)=(s);(i)<(g);(i)++)
#define rep(i,n)    for((i)=0;(i)<(n);(i)++)
#define all(x)      (x.begin(),x.end())
#define in(T,...) T __VA_ARGS__; impl(__VA_ARGS__)
#define array(T,id,n) T id[(n)]; for(int i=0;i<(n);i++)cin>>id[i]
#define putv(n)     cout<<(n)<<endl

//#define int long long;
#ifndef int
#define INF (0x7fffffff)
#else
#define INF (0x7fffffffffffffff)
#endif

void impl(){};
template <typename T,typename... TS >
void impl(T &head,TS &... tail)
{
  cin>>head;
  impl(tail ...);
}

queue<i_i> q;
int a[112345]; // リプライ数
int v[112345]; // ツイート木
int w[112345]; // 葉のツイート番号
int ans[112345];
int n,k;

i_i dfs(i_i now);

signed main(void)
{
  cin>>n>>k;
  int i;
  int temp;
  int sum=0;
  
  rep(i,n+1)
    a[i]=1;

  rep(i,n)
    {
      cin>>temp;
      v[i+1]=temp;
      a[temp]++;
      if(!temp)
	ans[i+1]++;
    }

  int j=0;

  rep(i,n+1)
    if(a[i]==1)
      q.push(make_pair(1,i));

  darray(v,n);
  darray(a,n+1);
  i_i zero=make_pair(0,0);
  i_i t;
  while(!q.empty())
    {
      dprintf("\n\n------------\n\n");
      t=dfs(q.front());
      q.pop();
      if(t!=zero)q.push(t);
      //dout(w[i]);
    }

  rep(i,n+1)sum+=ans[i]!=0;
  darray(ans,n+1);
  putv(sum);
  return 0;
}
/*
0  : 1,2
1  : 
2  : 3
3  : 4
4  : 5,7
5  : 6
6  : 
7  : 

N=7 , K=3
0-+-1
  |
  +-2---3---4-+-5---6
              |
              +-7

 */
i_i dfs(i_i now)
{
  /*
  dout(depth);
  dout(now);
  dout(v[now]);
  dprintf("\n");
  */
  if(ans[now.S])
    return make_pair(0,0);
  ans[now.S]++;
  if(now.F==k)
    return make_pair(0,0);
  if(v[now.S]==0)
    return make_pair(0,0);
  return make_pair(now.F+1,v[now.S]);
}
