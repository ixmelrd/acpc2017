#include<iostream>

int ary[1000][1000+1];
using namespace std;
#define rep(i,a) for(int i = 0 ; i < a ; i ++)
#define M (int)1e9;

int main(void){
  int n,m,d;
  cin>>n>>m;
  int in;
  rep(i,n)rep(j,n+1)ary[i][j] = 0;

  for(int i = 0 ; i < 3 * n - 1 ; i ++){
    cout<<"lst "<<i%n<<endl;
    cin>>d;
    for(int j = 0 ; j < d ; j ++){
      cin>>in;
      if(in == -1)continue;
      if(ary[i][in]==0)ary[i][n] ++;
      if(ary[in][i]==0)ary[in][n] ++;
      ary[i][in] = 1;
      ary[in][i] = 1;
    }
    /*cout<<"ret "<<i<<endl;

    rep(k,n){
      rep(l,n+1){
        cout<<ary[k][l]<<" ";
      }
      cout<<endl;
      }//*/
  }

  int ret = 0;
  for(int i = 0 ; i < n ; i ++){
    for(int j = 0 ; j < n ; j ++){
      if(ary[i][j]){      
        ret += ary[j][n]-1;
      }
    }
  }
  cout<<"ans "<<ret<<endl;
//*/
}
