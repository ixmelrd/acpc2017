#include<stdio.h>
int e[100010],M=1e9+7;
long long d[100010]={1};
int mbk(long long a,int n,int m){return n?(mbk((a*a)%m,n/2,m)*(n%2?a:1))%m:1;}
int inv(int a,int m){return mbk((long long)a,m-2,m);}
int aCb(int a,int b,int m){return ((d[a]*e[b])%m*e[a-b])%m;}
int g(int n,int m,int k){
  int a=(m-k)/2,i;//printf("%d %d\n",s,a);
  long long s=aCb(m,a,M);
  for(i=0;1;i++){
    a-=i%2?n:1;//printf("a %d\n",a);
    if(a<0)break;
    s=(s+aCb(m,a,M)*(i%2?1:-1)+M)%M;
  }//printf("%d\n",s);
  a=(m-k)/2;
  for(i=0;1;i++){
    a+=i%2?1:n;
    if(a>m)return s;
    s=(s+aCb(m,a,M)*(i%2?1:-1)+M)%M;
  }
  return  (int)s;
}
int f(int n,int m){
  int s=0,i;
  for(i=0;i<n;i++){
    if(m%2-i%2)continue;
    s=(s+g(n,m,i))%M;
  }
  return s;
}
int main(){
  int n,m,i,j;
  scanf("%d %d",&n,&m);
  for(i=1;i<=m;i++)d[i]=(d[i-1]*i)%M;
  for(i=0;i<=m;i++)e[i]=inv(d[i],M);
  printf("%d\n",(f(n,m)-f(n-1,m)+M)%M);
  /*for(i=0;i<n;i++){
    if(i%2==m%2)printf("%d\n",g(n,m,i));
    }//*/
  return 0;
}
