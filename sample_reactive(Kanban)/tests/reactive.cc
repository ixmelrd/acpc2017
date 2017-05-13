#include<stdio.h>
#include<string.h>
#include"reactive.hpp"
#include<time.h>
//#define DEBUG
#define MAX_BUF 1000000
#define MAX_NUM 100000000

typedef unsigned int u32;
typedef int i32;
struct Random {
    u32 seed;
    Random(u32 s = 0) {
        if (s) seed = s;
        else seed = (u32)time(0) + getpid() + 99191919;
#ifdef DEBUG
        ofstream fs("seed.txt");
        fs << seed << endl;
        fs.close();
#endif
        for(int i = 0; i < 100; ++i) next();
    }
    u32 next() {
        static u32 x = 123456789, y = 362436069, z = 521288629, w = seed;
        u32 t = x ^ (x << 11);
        x = y; y = z; z = w; w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
        return w;
    }
    i32 next(i32 l, i32 r) { return l + next() % (r - l + 1); }
    i32 next(int r) { return next() % r; }
    double nextDouble() { return next() * 0.00000000023283064365386962890625; }
    double nextDouble(double r) { return next() * 0.00000000023283064365386962890625 * r; }
};
Random rnd;

char buf[1000010];
int V,E;
int A[100010],B[100010];
int ta[100010],to[100010],nt[100010],di[100010];
//末尾の改行全消し
void rm_ln(char *s){
  int l=strlen(s);
  while(s[l-1]=='\n'||s[l-1]=='\r')l--;
  s[l]=0;
}
//テストケースからの入力だからエラー処理しない
void twoint(char *s,int *a,int *b){
  int i,n=0;
  rm_ln(s);
  for(i=0;s[i]-' ';i++)n=n*10+s[i]-'0';
  *a=n;
  n=0;
  for(i++;s[i];i++)n=n*10+s[i]-'0';
  *b=n;
}
//クエリが正しいものか判定
int chack_format(char *s,char *q,int *n){
  int i,l,m;
  l=strlen(s);
  if(l<5)return 1;
  for(i=0;i<l;i++){   
    if(s[i]==' '&&i!=3)return 2;
  }
  if(strncmp(s,"edg",3)&&
     strncmp(s,"lst",3)&&
     strncmp(s,"ans",3))return 3;
  for(i=4;i<l;i++){
    if(s[i]<'0'||'9'<s[i])return 4;
  }
  if(l>12)return 5;
  sscanf(s+4,"%d",&m);
  if(m>MAX_NUM)return 5;
  for(i=0;i<3;i++)q[i]=s[i];
  q[4]=0;
  *n=m;
  return 0;
}
int answer_edg_query(int n,char *a,char *b){
  if(n>=E)return 1;
  sprintf(a,"%d",A[n]);
  sprintf(b,"%d",B[n]);
  //?へ変換
  //if(rnd.next(0,4))sprintf(a,"-1");
  //if(rnd.next(0,4))sprintf(a,"-1");
  return 0;
}
int answer_lst_query(int n,char *s){
  int i;
  if(n>=V)return 1;
  sprintf(s,"%d",di[n]);
  //?へ変換
  //if(rnd.next(0,4))sprintf(s,"?");

  int l = 0;
  int arr[1010];

  for(i=ta[n];i+1;i=nt[i]){
      arr[l++] = rnd.next(0,4) ? -1 : to[i];
  }
  for(i=1;i<l;++i){
      int j = rnd.next(0,i-1);
      std::swap(arr[i], arr[j]);
  }

  
  for(i=0;i<l;++i){
      char num[100];
      sprintf(num, " %d", arr[i]);
      strcat(s, num);
  }
  return 0;
}
int main(int argc,char **argv){
  int i,ANS_A,ANS_B,count,MAX_Q,errorcode,num;
  char query[5];
  reactive_start(argv[1]);
  fgets(buf,MAX_BUF,stdin);
  twoint(buf,&V,&E);
  for(i=0;i<E;i++){
    fgets(buf,MAX_BUF,stdin);
    twoint(buf,&A[i],&B[i]);
  }//読み込み完了
  //隣接リストを作っていく
  for(i=0;i<V;i++)ta[i]=-1;
  for(i=0;i<E;i++){
    di[A[i]]++;
    di[B[i]]++;
    nt[i]=ta[A[i]];
    to[i]=B[i];
    ta[A[i]]=i;
    nt[i+E]=ta[B[i]];
    to[i+E]=A[i];
    ta[B[i]]=i+E;
  }
  for(i=0;i<V;i++)ANS_A+=di[i]*(di[i]-1);
  for(i=0;i<E;i++)ANS_B+=di[A[i]]+di[B[i]]-2;
  if(ANS_A!=ANS_B){
    printf("ERROR input FILE\n");
    fflush(stdout);
    reactive_end();
    return 0;
  }
#ifdef DEBUG
  printf("answer of this case is %d\n",ANS_A);
#endif
  //Nをクライアントへ出力
#ifdef DEBUG
  printf("serever writes:[%d %d]\n",V,E);
#endif
  sprintf(buf,"%d %d\n",V,E);
  reactive_write(buf);
  //クライアントからクエリ受け取り
  count=0;
  MAX_Q=3*V;
  while(1){//printf("%d\n",count);
    count++;
#ifdef DEBUG
    printf("query number %d\n",count);
#endif
    strcpy(buf,reactive_read(MAX_BUF).c_str());
    rm_ln(buf);
#ifdef DEBUG
    printf("server read:[%s]\n",buf);
#endif
    //クエリ回数チェック
    if(count>MAX_Q+1){
      printf("WA:too many query\n");
      fflush(stdout);
      reactive_end();
      return 0;
    }
    
    if(errorcode=chack_format(buf,query,&num)){
#ifdef DEBUG
      printf("querys format error\nerrorcode %d\n",errorcode);
      printf("1:query is too small\n");
      printf("2:query has invalid space\n");
      printf("3:query is not \"edg\",\"lst\",\"ans\"\n");
      printf("4:invalid number(not too big)\n");
      printf("5:too long number\n");
#endif
      sprintf(buf,"-1\n");
	reactive_write(buf);//*/
      /*reactive_end();
	return 0;//*/
    }
    else if(strncmp(query,"edg",3)==0){
      char res_a[20],res_b[20];
      if(answer_edg_query(num,res_a,res_b)){
#ifdef DEBUG
	printf("num over E(==%d)\n",E);
#endif
	sprintf(buf,"-1\n");
	reactive_write(buf);
      }
      else{
#ifdef DEBUG
	printf("server writes:[%s %s] for edg %d query\n",res_a,res_b,num);
#endif
	sprintf(buf,"%s %s\n",res_a,res_b);
	reactive_write(buf);
      }
    }
    else if(strncmp(query,"lst",3)==0){
      char res[1000010];
      if(answer_lst_query(num,res)){
#ifdef DEBUG
	printf("num over V(==%d)\n",V);
#endif
	sprintf(buf,"-1\n");
	reactive_write(buf);
      }
      else{
#ifdef DEBUG
	printf("server writes:%s for lst %d query\n",res,num);
#endif
	sprintf(buf,"%s\n",res);
	reactive_write(buf);
      }
    }
    else if(strncmp(query,"ans",3)==0){
      if(num==ANS_A)printf("AC\n");
      else          printf("Wrong Answer\n");
      fflush(stdout);
      reactive_end();
      return 0;
    }
    else{//ないと思う
#ifdef DEBUG
      printf("ERROR query\n");
#endif
      sprintf(buf,"-1\n");
      reactive_write(buf);
    }
  }
  return 0;
}
      
