#include<stdio.h>
#include<stdlib.h>
int main(){
  long long n,s=0,i,j,l,a[100010],t[100010];
  a[t[0]=0]=1;
  scanf("%lld %lld",&n,&l);
  for(i=0;i<n;i++)scanf("%lld %lld",&t[i+1],&a[i+1]);
  for(i=j=0;j++<n;i++){
    if(i>=l)goto END;
    if(abs(a[j-1]-a[j])>t[j]-t[j-1])goto END;
    if(a[j-1]+a[j]-2<=t[j]-t[j-1]){
      s+=i*(a[j-1]-1);
      i=0;
    }
    else s+=i*(t[j]-t[j-1]);//printf("%lld\n",s);
  }
  printf("%lld\n",s+(i*(a[j-1]-1)));
  return 0;
 END:;
  printf("-1\n");
  return 0;
}
