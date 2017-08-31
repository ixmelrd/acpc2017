#include<stdio.h>
int main(){
  char s[100010];
  int i;
  scanf("%*d %s",s);
  for(i=1;s[i];i++){
    if(s[i-1]=='x'&&s[i]=='x')break;
  }
  printf("%d\n",i);
  return 0;
}
