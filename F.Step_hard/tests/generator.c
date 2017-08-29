#include<stdio.h>
#include "./testlib.h"
#include "./constraints.hpp"
#include <sys/types.h>
#include <unistd.h>
void out(int n,int m,char *name){
  FILE *f;
  f=fopen(name,"w");
  fprintf(f,"%d %d\n",n,m);
  fclose(f);
}
int main(){
  int a,b,i;
  char s[100];
  rnd.setSeed(time(0)+getpid());

  for(i=0;i<15;i++){
    a=rnd.next(MIN_N,10);
    b=rnd.next(MIN_M,10);
    sprintf(s,"50_random_small_%02d.in",i);
    out(a,b,s);
  }
  
  for(i=0;i<15;i++){
    a=rnd.next(MIN_N,MAX_N);
    b=rnd.next(MIN_M,MAX_M);
    sprintf(s,"51_random_large_%02d.in",i);
    out(a,b,s);
  }
  
  a=MIN_N;
  b=MIN_M;
  sprintf(s,"52_MIN_00.in");
  out(a,b,s);

  a=MAX_N;
  b=MAX_M;
  sprintf(s,"53_MAX_00.in");
  out(a,b,s);

  for(i=0;i<5;i++){
    a=rnd.next(MIN_N,MAX_N);
    b=rnd.next(MIN_M,a-1);
    sprintf(s,"54_N_greater_M_%02d.in",i);
    out(a,b,s);
  }

  for(i=0;i<10;i++){
    a=rnd.next(MIN_N,10);
    b=rnd.next(100,MAX_M);
    sprintf(s,"55_large_answer_%02d.in",i);
    out(a,b,s);
  }
  for(i=0;i<10;i++){
    a=2;
    b=rnd.next(MIN_M,MAX_M);
    sprintf(s,"60_Challange_%02d.in",i);
    out(a,b,s);
  }
  return 0;
}
  
