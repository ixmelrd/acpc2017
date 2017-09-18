#include<stdio.h>
#include "./testlib.h"
#include "./constraints.hpp"
#include <sys/types.h>
#include <unistd.h>
int MIN(int a,int b){return a<b?a:b;}
int a[100010],b[100010],c[100010];
void swap(int *a,int *b){
  int t=*a;
  *a=*b;
  *b=t;
}
void out(int v,int e,char *s){
  int i,r[100010];
  FILE *f;
  f=fopen(s,"w");
  fprintf(f,"%d %d\n",v,e);
  for(i=0;i<e;i++)r[i]=i;
  for(i=0;i<e;i++)swap(&r[i],&r[rnd.next(0,e-1)]);
  for(i=0;i<e;i++){
    if(rnd.next(0,1))swap(&a[r[i]],&b[r[i]]);
    fprintf(f,"%d %d %d\n",a[r[i]],b[r[i]],c[r[i]]);
  }
  fclose(f);
}
void makeG(int v,int e){
  int ta[10010],nt[10010];
  int i,j,r[300010],n=0;
  if(v<500){//printf("a\n");
    for(i=n=0;i<v-1;i++){
      a[i]=rnd.next(0,i);
      b[i]=i+1;
      c[i]=rnd.next(MIN_C,MAX_C);
      if(rnd.next(0,1))c[i]=1;
      for(j=0;j<i+1;j++){
	if(j==a[i])continue;
	r[n++]=(i+1)*1000+j;
      }
    }//printf("%d %d ",v,n);
    for(i=0;i<n;i++)swap(&r[i],&r[rnd.next(0,n-1)]);
    for(i=v-1;i<e;i++){
      a[i]=r[i-v+1]%1000;
      b[i]=r[i-v+1]/1000;
      c[i]=rnd.next(MIN_C,MAX_C);
      if(rnd.next(0,1))c[i]=1;
    }//printf("%d\n",e-v+1);
    return;
  }
  for(i=0;i<v;i++)ta[i]=-1;
  for(i=0;i<v-1;i++){
    a[i]=rnd.next(0,i);
    b[i]=i+1;
    c[i]=rnd.next(MIN_C,MAX_C);
    if(rnd.next(0,1))c[i]=1;
    nt[i]=ta[a[i]];
    ta[a[i]]=i;
  }
  for(;i<e;i++){//printf("%d\n",i);
    a[i]=rnd.next(0,v-2);
    b[i]=rnd.next(a[i]+1,v-1);
    c[i]=rnd.next(MIN_C,MAX_C);
    if(rnd.next(0,2))c[i]=1;
    for(j=ta[a[i]];j+1;j=nt[j]){
      if(b[j]==b[i])break;
    }
    if(j+1)i--;
    else{
      nt[i]=ta[a[i]];
      ta[a[i]]=i;
    }
  }
  return;
}
void makeP(int v){
  int i,r[10010];
  for(i=0;i<v;i++)r[i]=i;
  for(i=0;i<v;i++)swap(&r[i],&r[rnd.next(0,v-2)]);
  for(i=0;i<v-1;i++){
    a[i]=r[i];
    b[i]=r[i+1];
    c[i]=rnd.next(MIN_C,MAX_C);
    //if(rnd.next(0,1))c[i]=1;
  }
}
void makeC(int v){
  int i,r[100010];
  for(i=0;i<v;i++)r[i]=i+1;
  for(i=0;i<v;i++)swap(&r[i],&r[rnd.next(0,v-1)]);
  for(i=0;i<v-2;i++){
    a[i]=r[i];
    b[i]=r[i+1];
    c[i]=v;
  }
  for(i=0;i<v-1;i++){
    a[i+v-2]=r[i];
    b[i+v-2]=r[v-1];
    c[i+v-2]=1;
  }
}
void challenge00(){
  int v,e;
  char s[100];
  v=MAX_V/2+2;
  e=v*2-4;
  sprintf(s,"60_challenge_00.in");
  makeC(v-1);
  a[e-1]=0;
  b[e-1]=a[0];
  c[e-1]=MAX_C;
  out(v,e,s);
}
void challenge01(){
  int v,e;
  char s[100];
  v=MAX_V/2+2;
  e=v*2-4;
  sprintf(s,"60_challenge_01.in");
  makeC(v-1);
  a[e-1]=0;
  b[e-1]=a[0];
  c[e-1]=200;
  out(v,e,s);
}
void challenge02(){
  int v,e;
  char s[100];
  v=MAX_V/2+1;
  e=v*2-4;
  sprintf(s,"60_challenge_02.in");
  makeC(v-1);
  a[e]=0;
  b[e]=a[0];
  c[e]=MAX_C;
  a[e-1]=b[v];
  b[e-1]=v;
  c[e-1]=200;
  out(v+1,e+1,s);
}
void challenge03(){
  int v,e,i;
  char s[100];
  v=MAX_V/2+2;
  e=MAX_E/2;
  sprintf(s,"60_challenge_03.in");
  for(i=0;i<e;i++){
    a[i]=0;
    b[i]=i+1;
    c[i]=1;
    a[i+e]=i+1;
    b[i+e]=v-1;
    c[i+e]=1;
  }
  out(v,e*2,s);
}
int main(){
  int v,e,i,j;
  char s[100];
  rnd.setSeed(time(0)+getpid());
  
  for(i=0;i<10;i++){
    v=rnd.next(MIN_V,10);
    e=rnd.next(v-1,MIN(v*(v-1)/2,3*v));
    sprintf(s,"50_random_small_%02d.in",i);
    makeG(v,e);
    out(v,e,s);
  }
  
  for(i=0;i<10;i++){
    v=rnd.next(MIN_V,MAX_V);
    e=rnd.next(v-1,MIN(v*(v-1)/2,MAX_E));
    sprintf(s,"51_random_large_%02d.in",i);
    makeG(v,e);
    out(v,e,s);
  }
  
  for(i=0;i<3;i++){
    v=MIN_V;
    e=MIN_E;
    sprintf(s,"52_MIN_%02d.in",i);
    makeG(v,e);
    out(v,e,s);
  }
  
  for(i=0;i<5;i++){
    v=MAX_V;
    e=MAX_E;
    sprintf(s,"53_MAX_%02d.in",i);
    makeG(v,e);
    out(v,e,s);
  }
  
  for(i=0;i<10;i++){
    v=rnd.next(MIN_V,MAX_V);
    e=v-1;
    sprintf(s,"54_Tree_%02d.in",i);
    makeG(v,e);
    out(v,e,s);
    }//*/

  for(i=0;i<5;i++){
    v=rnd.next(MIN_V,100);
    e=v*(v-1)/2;
    sprintf(s,"55_Complete_graph_%02d.in",i);
    makeG(v,e);
    out(v,e,s);
  }
  
  for(i=0;i<10;i++){
    v=rnd.next(MIN_V,100);
    e=rnd.next(v-1,MIN(MAX_E,v*(v-1)/2));
    sprintf(s,"56_large_E_%02d.in",i);
    makeG(v,e);
    out(v,e,s);
  }
  
  for(i=0;i<5;i++){
    v=rnd.next(MIN_V,MAX_V);
    e=v-1;
    sprintf(s,"57_pass_%02d.in",i);
    makeP(v);
    out(v,e,s);
  }

  for(i=0;i<10;i++){
    v=rnd.next(MIN_V,MAX_V);
    e=rnd.next(v-1,MIN(MAX_E,v*(v-1)/2));
    sprintf(s,"58_small_cost_%02d.in",i);
    makeG(v,e);
    for(j=0;j<e;j++)c[j]=(c[j]-1)%100+1;
    out(v,e,s);
  }

  for(i=0;i<10;i++){
    v=rnd.next(MIN_V,MAX_V);
    e=rnd.next(v-1,MIN(MAX_E,v*(v-1)/2));
    sprintf(s,"59_All_cost_1_%02d.in",i);
    makeG(v,e);
    for(j=0;j<e;j++)c[j]=1;
    out(v,e,s);
  }
  
  challenge00();
  challenge01();
  challenge02();
  challenge03();
  //*/
  return 0;
}
