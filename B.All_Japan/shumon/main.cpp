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
#define dstop()      scanf("")
#endif

#define F    first
#define S    second
#define pb   push_back
#define mp   make_pair

#define loop(i,s,g) for(int (i)=(s);(i)<(g);(i)++)
#define rep(i,n)    for((i)=0;(i)<(n);(i)++)
#define all(x)      (x.begin(),x.end())
#define in(T,...) T __VA_ARGS__; impl(__VA_ARGS__)
#define array(T,id,n) T id[n]; rep(i,n)cin>>id[i]
#define putv(n)     cout<<(n)<<endl

//#define int long long;
#ifndef int
#define INF (0x7fffffff)
#else
#define INF (0x7fffffffffffffff)
#endif
#define LINF (0x7fffffffffffffff)

typedef  long long           ll;
typedef  unsigned            ui;
typedef  unsigned long long  ull;
typedef  pair<int,int>       i_i;
typedef  pair<ll,int>        ll_i;
typedef  pair<ll,ll>         ll_ll;
typedef  pair<double,int>    d_i;
typedef  pair<double,double> d_d;

void impl(){};
template <typename T,typename... TS >
void impl(T &head,TS &... tail)
{
  cin>>head;
  impl(tail ...);
}

signed main(void)
{
  in(int,n,d);
  dout(n);
  dout(d);
  vector<ll_i> tf(n+1);
  i_i now=make_pair(0,0);
  ll sum=0;
  ll a=0;
  ll ds;
  ll i;

  rep(i,n)
    cin>>tf[i].F>>tf[i].S,tf[i].S--;
  tf[n]=make_pair(LINF,0);
  ll f,nf;

  rep(i,n+1)
    {
      f=tf[i].S;
      nf=now.S;
      ds=tf[i].F-now.F;

      dout(i);
      dout(tf[i].F);
      dout(f);
      dout(f-nf);
      dout(ds);
      dout(a);
      dout(sum);
      dprintf("\n");      

      if(abs(f-nf)>ds)
	{
	  dprintf("abs(f-nf)>ds\n");
	  sum=-1;
	  break;
	}
      else if(f+nf<=ds)
	{
	  sum+=a*nf;
	  a=1;
	}
      else if(a<d)
	{
	  sum+=a*ds;
	  a++;
	}
      else
	{
	  dprintf("else\n");
	  sum=-1;
	  break;
	}
      now=tf[i];
    }
  dout(n);
  dout(d);
  putv(sum);
  return 0;
}
