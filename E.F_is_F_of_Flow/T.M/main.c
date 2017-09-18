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
//呼び出す方
//sからtへの最大流を求める　ノード数v辺の数e　aからbへキャパcのフローが流れる
int maxf(int s,int t,int v,int e,int *a,int *b,int *c){
  int i,f,r;
  for(i=0;i<v;i++)ta[i]=-1;
  for(i=0;i<e;i++){
    nt[i  ]=ta[to[i+e]=a[i]];
    nt[i+e]=ta[to[i  ]=b[i]];
    co[ta[a[i]]=i  ]=c[i];
    co[ta[b[i]]=i+e]=c[i];
  }
  for(f=0;r=MF(s,t,e,1000000000);f+=r){
    if(f>10000)return -1;
    for(i=0;i<v;i++)F[i]=0;
  }
  return f;
}
int u[5010];
int f(int s,int t){//printf("s %d t %d\n",s,t);
  int i;
  if(s==t)return 1;
  u[s]=1;
  for(i=ta[s];i+1;i=nt[i]){
    if(co[i]==0||u[to[i]])continue;
    if(f(to[i],t))return 1;
  }
  return 0;
}
int main(){
  int n,m,a[5010],b[5010],c[5010],i,j,r=0;
  scanf("%d %d",&n,&m);
  for(i=0;i<m;i++)scanf("%d %d %d",&a[i],&b[i],&c[i]);
  r=maxf(0,n-1,n,m,a,b,c);
  if(r==-1){
    printf("-1\n");
    return 0;
  }
  for(i=0;i<m*2;i++){//printf("%d %d %d\n",to[i<m?(i+m):(i-m)],to[i],co[i]);
    if(c[i%m]-1)continue;//printf("%d %d\n",i,co[i]);
    if(co[i])continue;//printf("%d %d\n\n",i,to[i]);
    for(j=0;j<n;j++)u[j]=0;
    //if(i/m==0&&f(a[i],b[i])==0||i/m&&f(b[i%m],a[i%m])==0)break;
    if(f(to[i<m?(i+m):(i-m)],to[i])==0)break;
  }
  //printf("%d %d\n",i,r);
  if(i<m*2)r--;
  printf("%d\n",r>10000?-1:r);
  return 0;
}
