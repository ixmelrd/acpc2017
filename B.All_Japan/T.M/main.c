#include<stdio.h>
#include<stdlib.h>
int main(){
  int n,f=0,a,b=0,t,d,s=0,i;
  scanf("%d",&n);
  for(i=0;n--;i++){
    scanf("%d %d",&a,&t);
    d=abs(f-a);
    if(d>t-b)goto END;
    if(f+a<=t-b){
      s+=i*f;
      i=0;
    }
    else s+=i*d;
    f=a;
    b=t;//printf("%d %d\n",s,i+1);
  }
  printf("%d\n",s+(i*f));
  return 0;
 END:;
  printf("-1\n");
  return 0;
}
