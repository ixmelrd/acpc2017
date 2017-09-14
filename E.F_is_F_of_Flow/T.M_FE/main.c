#include<stdio.h>
int MIN(int a,int b){return a<b?a:b;}
int ta[5010],to[100010],nt[100010],co[100010],F[5010];
int MF(int s,int t,int e,int min){
  if(s==t||min==0)return min;
  int i,r;
  F[s]=1;
  for(i=ta[s];i+1;i=nt[i]){
    if(F[to[i]])continue;
    r=MF(to[i],t,e,MIN(min,co[i]));
    co[i]-=r;
    co[(i+e)%(2*e)]+=r;
    if(r)return r;
  }
  return 0;
}
int maxf(int s,int t,int v,int e,int *a,int *b,int *c){
  int i,f,r;
  for(i=0;i<v;i++)ta[i]=-1;
  for(i=0;i<e;i++){
    nt[i  ]=ta[to[i+e]=a[i]];
    nt[i+e]=ta[to[i  ]=b[i]];
    co[ta[a[i]]=i  ]=co[ta[b[i]]=i+e]=c[i];
  }
  for(f=0;r=MF(s,t,e,1000000000);f+=r){
    if(f>10000)return -1;
    for(i=0;i<v;i++)F[i]=0;
  }
  return f;
}
int main(){
  int n,m,a[5010],b[5010],c[5010],i,q[5010],v[5010],vr=1,t,ans,r=0,u[5010]={2};
  scanf("%d %d",&n,&m);
  for(i=0;i<m;i++)scanf("%d %d %d",&a[i],&b[i],&c[i]);
  ans=maxf(0,n-1,n,m,a,b,c);
  if(ans==-1){
    printf("-1\n");
    return 0;
  }
  q[r++]=0;
  while(vr){
    for(t=vr=0;r-t;t++){
      for(i=ta[q[t]];i+1;i=nt[i]){
	if(u[to[i]]==2)continue;
	if(co[i]==0)u[to[v[vr++]=i]]=1;
	else u[q[r++]=to[i]]=2;
      }
    }
    for(i=0;i<vr;i++){
      if(u[to[v[i]]]-2&&c[v[i]%m]==1){
	ans--;
	goto END;
      }
    } 
    for(i=r=0;i<vr;i++){
      if(u[to[v[i]]]==1)u[q[r++]=to[v[i]]]=2;
    }
  }
 END:;
  printf("%d\n",ans>10000?-1:ans);
  return 0;
}
