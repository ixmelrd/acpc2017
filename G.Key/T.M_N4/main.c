#include<stdio.h>
#include<stdlib.h>
int n,m,sum[2],max[2],c=0,d[100010]={};
int MAX(int a,int b){return a<b?b:a;}
int MIN(int a,int b){return a<b?a:b;}
int p(int a,int b,int c,int d){//max sum max sum
  if(a<0||b<0||c<0||d<0)return 1e9;
  int s=0;
  b-=a;
  d-=c;
  s+=a>b?b:(a+b)/2;
  a=MAX(0,a-b);
  s+=c>d?d:(c+d)/2;
  c=MAX(0,c-d);
  return s+abs(a-c)/2+a+c;
}
int f(int i,int n){
  sum[i]+=n;
  max[i]=MAX(max[i],n);
}
int g(int i,int j,int k,int l){
  int t,o,ans=1e9;
  sum[0]=sum[1]=max[0]=max[1]=0;
  for(o=0;o<n;o++){
    if(m%2==0&&d[o]==m/2)continue;
    if((d[o]<(m+1)/2)==(o==i||o==j||o==k))f(1,m-d[o]);
    else                                  f(0,  d[o]);
  }
  for(o=0;o<l;o++)f(0,m/2);
  for(   ;o<c;o++)f(1,m/2);
  //printf("%d %d %d %d %d %d %d\n",d[i],d[j],d[k],max[0],sum[0],max[1],sum[1]);
  if(sum[0]%2-sum[1]%2)return 1e9;
  if(sum[0]%2){
    ans=MIN(ans,p(max[0]-1,sum[0]-1,max[1]  ,sum[1]+1)+1);
    ans=MIN(ans,p(max[0]  ,sum[0]+1,max[1]-1,sum[1]-1)+1);
  }
  else ans=p(max[0],sum[0],max[1],sum[1]);
  return ans;
}
int main(){
  int i,j,k,l,ans=1e9;
  scanf("%d %d",&n,&m);
  for(i=0;i<n;i++){
    scanf("%d",&d[i]);
    if(m%2==0&&d[i]==m/2)c++;
  }
  if(n==2){
    if(d[0]==d[1])ans=MIN(d[0],m-d[0]);
    printf("%d\n",ans-1e9?ans:-1);
    return 0;
  }  
  for(l=0;l<=c;l++){
    ans=MIN(ans,g(n,n,n,l));//printf("%d\n",ans);
    for(i=0;i<n;i++){
      ans=MIN(ans,g(i,n,n,l));//printf("%d\n",ans);
      for(j=i+1;j<n;j++){
	ans=MIN(ans,g(i,j,n,l));//printf("%d\n",ans);
	for(k=j+1;k<n;k++){ans=MIN(ans,g(i,j,k,l));}//printf("%d\n",ans);}
      }
    }
  }
  printf("%d\n",ans-1e9?ans:-1);
  return 0;
}
	  
