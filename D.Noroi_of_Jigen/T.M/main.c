#include<stdio.h>
int R=1,C=1,H[2000010],N[2000010];
int hyouka(int a,int b){
  if(C<b)return 1;
  if(C<a||b==0)return 0;
  return N[H[a]]<N[H[b]]?1:0;
}
void hin(int a){
  int i=C++;
  for(N[H[0]=R]=a;hyouka(0,i/2);i/=2)H[i]=H[i/2];
  H[i]=R++;
}
int hout(){
  int rt=H[1],i,j=2,k=H[--C];
  for(i=1;hyouka(i,C);i=j)H[i]=H[j=i*2+1-hyouka(i*2,i*2+1)];
  H[j/2]=k;
  return rt;
}
int CO[100010],id[2000010];
void dijk(int v,int e,int *fr,int *to,int *co,int mi){
  int i,ta[100010],nt[200010],f[100010]={0};
  for(i=0;i<v;i++)ta[i+1]=-1;
  for(i=0;i<v;i++)CO[i+1]=1000000000;
  for(i=CO[mi]=0;i<e;i++){
    nt[i]=ta[fr[i]];
    ta[fr[i]]=i;
  }
  while(f[mi]-1){
    f[mi]=1;
    for(i=ta[mi];i+1;i=nt[i]){
      if(CO[to[i]]>CO[mi]+co[i])hin(CO[id[R]=to[i]]=CO[mi]+co[i]);
    }
    while(f[mi]&&C-1)mi=id[hout()];
  }
}
int MIN(int a,int b){return a<b?a:b;}
int main(){
  int n,m,s,t,a[200010],b[200010],c[200010],d[100010],i,j,k;
  scanf("%d %d %d %d",&n,&m,&s,&t);
  for(i=0;i<n;i++)scanf("%d",&d[i]);
  for(i=0;i<m;i++){
    scanf("%d %d",&j,&k);
    a[i]=j;
    b[i]=k;
    c[i]=d[k-1];
  }
  for(j=1;j<n;j++){
    a[m+j-1]=j+1;
    b[m+j-1]=j;
    c[m+j-1]=0;
  }
  dijk(n,m+n-1,a,b,c,s);
  printf("%d\n",CO[t]);
}
    
