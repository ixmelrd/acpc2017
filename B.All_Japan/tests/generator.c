#include<stdio.h>
#include "./testlib.h"
#include "./constraints.hpp"
#include <sys/types.h>
#include <unistd.h>
int MAX(int a,int b){return a<b?b:a;}
int MIN(int a,int b){return a<b?a:b;}
int t[100010],F[100010];
void out(int n,int d,char *name){
  FILE *f;
  int i;
  f=fopen(name,"w");
  fprintf(f,"%d %d\n",n,d);
  for(i=0;i<n;i++)fprintf(f,"%d %d\n",t[i],F[i]);
  fclose(f);
}
void makeS(int n){
  int i,a=30/n*2,b=20/n,d;
  t[0]=rnd.next(MIN_T,MIN(MAX_T,a));
  F[0]=rnd.next(MAX(t[0]-b,MIN_F),MIN(t[0]+b,MAX_F));
  for(i=1;i<n;i++){
    t[i]=rnd.next(t[i-1]+1,MIN(t[i-1]+a,MAX_T-n+i+1));
    d=t[i]-t[i-1];
    F[i]=rnd.next(MAX(MIN_F,F[i-1]-d-b),MIN(MAX_F,F[i-1]+d+b));
  }
}
void makeE(int n){
  int i,a=MAX_T/n*2,b=MAX_F/n,d;
  t[0]=rnd.next(MIN_T,MIN(MAX_T,a));
  F[0]=rnd.next(MAX(t[0]-b,MIN_F),MIN(t[0]+b,MAX_F));
  for(i=1;i<n;i++){
    t[i]=rnd.next(t[i-1]+1,MIN(t[i-1]+a,MAX_T-n+i+1));
    d=t[i]-t[i-1];
    F[i]=rnd.next(MAX(MIN_F,F[i-1]-d-b),MIN(MAX_F,F[i-1]+d+b*2));
  }
}
void makeR(int n){
  int i,a=MAX_T/n*2,d;
  t[0]=rnd.next(MIN_T,MIN(MAX_T,a));
  F[0]=rnd.next(MIN_F,MAX_F);
  for(i=1;i<n;i++){
    t[i]=rnd.next(t[i-1]+1,MIN(t[i-1]+a,MAX_T-n+i+1));
    F[i]=rnd.next(MIN_F,MAX_F);
  }
}
void makeY(int n){
  int i,a=MAX_T/n*2,b=MAX_F/n,d;
  t[0]=rnd.next(MIN_T,MIN(MAX_T,a));
  F[0]=rnd.next(MIN_F,t[0]+1);
  for(i=1;i<n;i++){
    t[i]=rnd.next(t[i-1]+1,MIN(t[i-1]+a,MAX_T-n+i+1));
    d=t[i]-t[i-1];
    F[i]=rnd.next(MAX(MIN_F,F[i-1]-d),MIN(MAX_F,F[i-1]+d));
  }
}
int main(){
  int n,d,i;
  char s[100];
  rnd.setSeed(time(0)+getpid());

  for(i=0;i<10;i++){
    n=rnd.next(MIN_N,10);
    d=rnd.next(MIN_D,MAX_D);
    sprintf(s,"50_small_N_%02d.in",i);
    makeS(n);
    out(n,d,s);
  }
  
  for(i=0;i<10;i++){
    n=rnd.next(MIN_N,MAX_N);
    d=rnd.next(MIN_D,MAX_D);
    sprintf(s,"51_large_%02d.in",i);//printf("%d\n",n);
    makeE(n);
    out(n,d,s);
  }
  
  for(i=0;i<5;i++){
    n=MIN_N;
    d=MIN_D;
    sprintf(s,"52_MIN_%02d.in",i);
    makeR(n);
    out(n,d,s);
  }
  
  for(i=0;i<10;i++){
    n=MAX_N;
    d=MAX_D;
    sprintf(s,"53_MAX_%02d.in",i);
    makeE(n);
    out(n,d,s);
  }
  
  for(i=0;i<10;i++){
    n=rnd.next(MIN_N,MAX_N);
    d=rnd.next(MIN_D,10);
    sprintf(s,"54_small_D_%02d.in",i);
    makeE(n);
    out(n,d,s);
  }
  
  for(i=0;i<10;i++){
    n=rnd.next(MIN_N,MAX_N);
    d=rnd.next(MIN_D,MAX_D);
    sprintf(s,"55_parfect_random_%02d.in",i);
    makeR(n);
    out(n,d,s);
  }
  
  for(i=0;i<10;i++){
    n=rnd.next(MIN_N,MAX_N);
    d=MAX_D;
    sprintf(s,"56_Not_-1_%02d.in",i);
    makeY(n);
    out(n,d,s);
  }//*/

  return 0;
}

  
