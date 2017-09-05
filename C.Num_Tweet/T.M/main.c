#include<stdio.h>
int MAX(int a,int b){return a<b?b:a;}
int main(){
  int i,n,k,d[100010],a[100010]={};
  int c[100010]={};
  scanf("%d %d",&n,&k);
  for(i=0;i<n;i++){
    scanf("%d",&d[i+1]);
    a[d[i+1]]=1;
  }
  for(i=n;i;i--){
    if(a[i]==0)c[i]=k;
    c[d[i]]=MAX(c[d[i]],c[i]-1);
  }
  for(i=k=0;i<n;i++){
    if(c[i+1])k++;
    if(c[i+1]==0&&d[i+1]==0)k++;
  }
  printf("%d\n",k);
  return 0;
}
