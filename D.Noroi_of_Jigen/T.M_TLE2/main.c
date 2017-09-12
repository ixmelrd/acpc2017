#include<stdio.h>
int MIN(int a,int b){return a<b?a:b;}
int main(){
  int n,m,s,t,i,j,a,b,c[100010],d[100010],min[100010];
  scanf("%d %d %d %d",&n,&m,&s,&t);
  for(i=0;i<n;i++)scanf("%d",&c[i]);
  for(i=0;i<n;i++)min[i+1]=1e9;
  for(i=1;i<=n;i++)d[i]=i<t?1e9:0;
  for(i=0;i<m;i++){
    scanf("%d %d",&a,&b);
    min[b]=MIN(min[b],a);
  }
  for(i=n;i;i--){
    for(j=min[i];j<i;j++)d[j]=MIN(d[j],d[i]+c[i-1]);
  }
  printf("%d\n",d[s]);
  return 0;
}
    
