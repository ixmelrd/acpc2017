#include<stdio.h>
#include<stdlib.h>
int main(){
  int n,d,s=0,i,j,l,a[100010],t[100010];
  scanf("%d %d",&n,&l);
  for(i=0;i<n;i++)scanf("%d %d",&a[i+1],&t[i+1]);
  for(i=j=0;j++<n;i++){
    if(i>=l)goto END;
    d=abs(a[j-1]-a[j]);
    if(d>t[j]-t[j-1])goto END;
    if(a[j-1]+a[j]<=t[j]-t[j-1]){
      s+=i*a[j-1];
      i=0;
    }
    else s+=i*d;
  }
  printf("%d\n",s+(i*a[j-1]));
  return 0;
 END:;
  printf("-1\n");
  return 0;
}
