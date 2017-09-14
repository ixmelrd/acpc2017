#include<stdio.h>
int MIN(int a,int b){return a<b?a:b;}
int ta[5010],to[100010],nt[100010],co[100010],F[5010];
int MF(int s,int t,int e,int min,int n){//printf("%d %d\n",s,t);
  if(s==t||min==0)return min;
  int i,r;
  F[s]=1;
  for(i=ta[s];i+1;i=nt[i]){
    if(F[to[i]]||i%e==n)continue;
    r=MF(to[i],t,e,MIN(min,co[i]),n);
    co[i]-=r;
    co[(i+e)%(2*e)]+=r;
    if(r)return r;
  }
  return 0;
}
//呼び出す方
//sからtへの最大流を求める　ノード数v辺の数e　aからbへキャパcのフローが流れる
int maxf(int s,int t,int v,int e,int n){//printf("%d\n",n);
  int i,f,r;
  for(i=0;i<v;i++)F[i]=0;
  for(f=0;r=MF(s,t,e,1e9,n);f+=r){
    if(f>10010)return -1;
    for(i=0;i<v;i++)F[i]=0;
  }
  return f;
}
int main(){
  int n,m,a,b,c[5010],i,j,r=0;
  scanf("%d %d",&n,&m);
  for(i=0;i<n;i++)ta[i]=-1;
  for(i=0;i<m;i++){
    scanf("%d %d %d",&a,&b,&c[i]);
    nt[i  ]=ta[to[i+m]=a];
    nt[i+m]=ta[to[i  ]=b];
    co[ta[a]=i  ]=co[ta[b]=i+m]=c[i];
  }   
  r=maxf(0,n-1,n,m,-1);
  if(r==-1){
    printf("-1\n");
    return 0;
  }//printf("%d\n",r);
  for(i=0;i<m;i++){
    for(j=0;j<m;j++)co[j]=co[j+m]=c[j];
    if(c[i]==1)r=MIN(r,maxf(0,n-1,n,m,i));//printf("%d\n",r);
  }
  printf("%d\n",r>10000?-1:r);
  return 0;
}
