#include<stdio.h>
int M=1e9+7;
int mbk(long long a,int n,int m){return n?(mbk((a*a)%m,n/2,m)*(n%2?a:1))%m:1;}
int inv(int a,int m){return mbk((long long)a,m-2,m);}
int aCb(int a,int b,int m){
  long long s=1,i;
  if(b>a-b)b=a-b;
  for(i=0;i<b;i++)s=(((s*(a-i))%m)*inv(i+1,m))%m;  
  return (int)s;
}
int k(int i,int n){return (i<0?n-(-i%n):i)%n;}
int g(int i,int n){
  if(k(i,n+1)==n)return 0;
  return k(i,2*n+2)<n?1:-1;
}
int f(int n,int m){
  long long s=0,i;
  for(i=0;i<=m;i++)s=(s+aCb(m,i,M)*g(2*i-m,n)+M)%M;
  return (int)s;
}
int main(){
  int n,m;
  scanf("%d %d",&n,&m);
  int i,d[100010]={1,1};
  for(i=2;i<=m;i++)d[i]=(d[i-1]+d[i-2])%M;
  for(i=0;i<=m;i++){
    if(d[i]-f(4,i))printf("%3d %d\n",i,f(4,i));
  }
  //printf("%d\n",(f(n,m)-f(n-1,m))%M);
  return 0;
}
