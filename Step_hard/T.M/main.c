#include<stdio.h>
int e[100010],M=1e9+7;
long long d[100010]={1};
int mbk(long long a,int n,int m){return n?(mbk((a*a)%m,n/2,m)*(n%2?a:1))%m:1;}
int inv(int a,int m){return mbk((long long)a,m-2,m);}
int aCb(int a,int b,int m){return ((d[a]*e[b])%m*e[a-b])%m;}
int k(int i,int n){return (i<0?n-(-i%n):i)%n;}
int g(int i,int n){return k(i,n+1)-n?k(i,2*n+2)<n?1:-1:0;}
int f(int n,int m){
  long long s=0,i;
  for(i=0;i<=m;i++)s=(s+aCb(m,i,M)*g(2*i-m,n)+M)%M;
  return (int)s;
}
int main(){
  int n,m,i,j;
  scanf("%d %d",&n,&m);
  for(i=1;i<=m;i++)d[i]=(d[i-1]*i)%M;
  for(i=0;i<=m;i++)e[i]=inv(d[i],M);
  printf("%d\n",(f(n,m)-f(n-1,m)+M)%M);
  return 0;
}
