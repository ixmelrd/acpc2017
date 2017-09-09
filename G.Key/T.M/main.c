#include<stdio.h>
#include<stdlib.h>
int s[100010],m;
int MAX(int a,int b){return a<b?b:a;}
int MIN(int a,int b){return a<b?a:b;}
void in(int *d,int a){
  int i;
  for(i=4;i&&d[i-1]<a;i--)d[i]=d[i-1];  
  d[i]=a;
  d[5]+=a;
}
void f(int *a,int *b,int n){//printf("f\n");
  int i;
  for(i=0;i<4;i++){
    if(a[i]==n){
      a[i]=0;
      a[5]-=n;
      in(b,m-n);
      return ;
    }
  }
}    
int main(){
  int n,i,j[3],k,l,o,max[2],ans=1e9,sum[2],a[2][6],b[2][6],c=0,t,d[2][6]={};
  scanf("%d %d",&n,&m);
  for(i=0;i<n;i++)scanf("%d",&s[i]);
  for(i=0;i<n;i++){
    if(m%2==0&&s[i]==m/2)c++;
    else if(s[i]<=m/2)in(d[0],s[i]);
    else              in(d[1],m-s[i]);
  }
  /*for(i=0;i<2;i++){
    for(k=0;k<6;k++)printf("%d ",d[i][k]);
    printf("\n");
    }printf("%d\n",c);//*/
  if(c>3){
    printf("%d\n",(d[0][5]+d[1][5]+c*m/2)/2);
    return 0;
  }
  for(l=0;l<=c;l++){
    for(k=0;k<2;k++){
      for(i=0;i<6;i++)a[k][i]=d[k][i];
    }
    for(i=0;i<l;i++)in(a[0],m/2);
    for(;   i<c;i++)in(a[1],m/2);

    for(i=t=0;i<2;i++){
      t+=a[i][0]>a[i][5]?a[i][5]:(a[i][5]+a[i][0])/2;
      max[i]=MAX(0,a[i][0]-a[i][5]);
    }
    ans=MIN(ans,t+abs(max[0]-max[1])/2+max[0]+max[1]);//*/
   
    /*for(i=0;i<2;i++){
      for(k=0;k<6;k++)printf("%d ",d[i][k]);
      printf("\n");
      }printf("\n");//*/
    
    for(j[0]=0;j[0]<n;j[0]++){
      if(m%2==0&&s[j[0]]==m/2)continue;
      for(j[1]=j[0]+1;j[1]<n+1;j[1]++){
	if(m%2==0&&s[j[1]]==m/2)continue;
	for(j[2]=j[1]+1;j[2]<n+2;j[2]++){
	  if(m%2==0&&s[j[2]]==m/2)continue;

	  for(k=0;k<2;k++){
	    for(o=0;o<6;o++)b[k][o]=a[k][o];
	  }
	  
	  for(k=0;k<3;k++){
	    if(j[k]>=n)continue;//printf("%d:\n",s[j[k]]);
	    if(s[j[k]]<m/2)f(b[0],b[1],s[j[k]]);
	    else           f(b[1],b[0],m-s[j[k]]);
	  }
	  for(o=t=0;o<2;o++){
	    //for(k=0;k<6;k++)printf("%d ",b[o][k]);printf("\n");
	    
	    for(i=max[o]=0;i<4;i++)max[o]=MAX(max[o],b[o][i]);
	    sum[o]=b[o][5]-max[o];
	    t+=max[o]>sum[o]?sum[o]:(sum[o]+max[o])/2;
	    max[o]=MAX(0,max[o]-sum[o]);
	    //printf("%d %d ",max[o],sum[o]);
	  }//printf("\n");
	  if((max[0]+sum[0])%2-(max[1]+sum[1])%2)continue;
	  ans=MIN(ans,t+abs(max[0]-max[1])/2+max[0]+max[1]);//*/
	}
      }
    }//*/
  }
  printf("%d\n",ans);//*/
  return 0;
}
