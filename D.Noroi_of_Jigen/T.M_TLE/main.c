#include<stdio.h>
int R=1,C=1,H[2000010],N[2000010];
//評価関数（いまはMIN）
int hyouka(int a,int b){
  if(C<b)return 1;
  if(C<a||b==0)return 0;
  return N[H[a]]<N[H[b]]?1:0;
}
//挿入関数
void hin(int a){
  int i=C++;
  for(N[H[0]=R]=a;hyouka(0,i/2);i/=2)H[i]=H[i/2];
  H[i]=R++;
}
//取り出す関数
int hout(){
  int rt=H[1],i,j=2,k=H[--C];
  for(i=1;hyouka(i,C);i=j)H[i]=H[j=i*2+1-hyouka(i*2,i*2+1)];
  H[j/2]=k;
  return rt;
}
int MIN(int a,int b){return a<b?a:b;}
int main(){
  int n,m,s,t,a,b[100010],c[100010],d[100010],i;
  scanf("%d %d %d %d",&n,&m,&s,&t);
  for(i=0;i<n;i++)scanf("%d",&c[i]);
  for(i=0;i<m;i++){
    scanf("%d %d",&a,&b[R]);
    hin(a);
  }
  for(i=0;i<n;i++)d[i+1]=i<s?0:1e9;
  //for(i=0;i<n;i++)printf("%d ",d[i+1]);printf("\n");
  while(C-1){
    a=hout();//printf("%d %d\n",N[a],b[a]);
    for(i=N[a];i<b[a];i++)d[i+1]=MIN(d[i+1],d[N[a]]+c[b[a]-1]);
    //for(i=0;i<n;i++)printf("%d ",d[i+1]);
  }//printf("\n");
  printf("%d\n",d[t]);
  return 0;
}
    
