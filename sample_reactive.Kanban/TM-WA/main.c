#include<stdio.h>
int main(){
  int n,m,a,c,i,b,e[1000010][2],d[100010]={0};
  char s[1000010];
  scanf("%d %d%*c",&n,&m);
  for(i=a=0;i<m;i++){
    printf("edg %d\n",i);
    fflush(stdout);
    scanf("%d %d",&a,&b);
    d[a]++;
    d[b]++;
    e[i][0]=a;
    e[i][1]=b;
  }
  for(i=a=0;i<m;i++)a+=d[e[i][0]]+d[e[i][1]]-2;
  printf("ans %d\n",a);
  return 0;
}
