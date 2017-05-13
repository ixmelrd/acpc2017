#include<stdio.h>
int main(){
  int n,m,a,c,i,j;
  char s[1000010];
  scanf("%d %d%*c",&n,&m);
  for(i=a=0;i<n;i++){
    printf("lst %d\n",i);
    fflush(stdout);
    fgets(s,100000,stdin);
    for(j=c=0;s[j];j++){
      if(s[j]==' ')c++;
    }
    a+=c*(c-1);
  }
  printf("ans %d\n",a);
  return 0;
}
