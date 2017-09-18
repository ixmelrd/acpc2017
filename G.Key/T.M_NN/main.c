#include<stdio.h>
#include<stdlib.h>
int s[100010],m;
int MAX(int a,int b){return a<b?b:a;}
int MIN(int a,int b){return a<b?a:b;}
int f(int a,int b,int c,int d){//max,sum,max,sum
  if(a<0||b<0||c<0||d<0)return 1e9;
  if(b%2-d%2)return 1e9;
  if(b%2)return MIN(f(a-1,b-1,c,d+1),f(a,b+1,c-1,d-1))+1;
  int s=0;
  b-=a;
  d-=c;
  s+=(a>b?b:(a+b)/2);
  a=MAX(0,a-b);
  s+=(c>d?d:(c+d)/2);
  c=MAX(0,c-d);
  return s+abs(a-c)/2+a+c;
}
int main(){
  int n,m,i,j,max[2],sum[2],d[110],min=1e9;
  scanf("%d %d",&n,&m);
  if(n>20)return 0;
  for(i=0;i<n;i++)scanf("%d",&d[i]);
  if(n==2){
    printf("%d\n",d[0]-d[1]?-1:MIN(d[0],m-d[0]));
    return 0;
  }
  for(i=0;i<(1<<n);i++){
    sum[0]=sum[1]=max[0]=max[1]=0;
    for(j=0;j<n;j++){
      if(i&(1<<j)){
      	sum[1]+=m-d[j];
	if(max[1]<m-d[j])max[1]=m-d[j];
      }
      else{
	sum[0]+=d[j];
	if(max[0]<d[j])max[0]=d[j];
      }
    }
    min=MIN(min,f(max[0],sum[0],max[1],sum[1]));
    //printf("%d %d %d %d %d\n",min,max[0],sum[0],max[1],sum[1]);
  }
  printf("%d\n",min-1e9?min:-1);
  return 0;
}
