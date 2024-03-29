#include <iostream>
#include <utility>
#include "./testlib.h"
#include "./constraints.hpp"
#include <sys/types.h>
#include <unistd.h>
#include <cassert>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)

typedef pair<int,int> pii;

void output(int N, int M, int s, int t, const vector<int> &d, const vector<pii> &v, const string &prefix, int suffix){
    char name[100];
    sprintf(name, "%s_%02d.in", prefix.c_str(), suffix);
    ofstream ofs(name);
    ofs << N << ' ' << M << ' ' << s << ' ' << t << endl;
    for (int i = 0; i < N; ++i) {
        ofs << d[i] << (i + 1 == N ? '\n' : ' ');
    }
    for(int i = 0; i < M; ++i){
      ofs << v[i].first << ' ' << v[i].second << endl;
    }
    ofs.close();
}

//「次元の呪い」
vector<int> gen_d(int N) {
    vector<int> d(N);
    for (int i = 0; i < N; ++i) {
        d[i] = rnd.next(MIN_d, MAX_d);
    }
    return d;
}


//魔法の移動元と移動先を生成
vector<pii> gen_v(int N, int M) {
  vector<pii> v;
  v.reserve(M);
  set<pii> used;
  while((int)v.size() != M){
    int a = rnd.next(1, N);
    int b = rnd.next(1, N);
    if (a == b) continue;
    if (a > b) swap(a, b);
    if (used.count(pii(a, b))) continue;
    v.emplace_back(pii(a, b));
    used.emplace(pii(a, b));
  }
  return v;
}

int main(){
    // 乱数のシードを設定
    // pidを足すことで、1秒以上間を置かずに起動したときに同じシードになってしまうのを防ぐ
    rnd.setSeed(time(0)+getpid());

    // 乱数ケース
    for(int i = 0; i < 10; ++i){
        int N = rnd.next(MIN_N, MAX_N);
        int M = rnd.next((long long)MIN_M, min((long long)N*(N-1)/2,(long long)MAX_M));
        vector<int> d = gen_d(N);
	vector<pii> v = gen_v(N, M);
	sort(v.begin(), v.end());
	int s = 0, t = 0;
	while(s == t){
	  s = rnd.next(1, N);
	  int max_b = s;
	  for(int j = 0; j < M; j++)
	    if(v[j].first < max_b) max_b = v[j].second;
	  t = rnd.next(1, max_b);
	}
        shuffle(v.begin(), v.end());   
        output(N, M, s, t, d, v, "50_random", i);
    }

    //　N 最大ケース
    for(int i = 0; i < 5; ++i){
      int N = MAX_N;
      int M = rnd.next((long long)MIN_M, min((long long)N*(N-1)/2,(long long)MAX_M));
      vector<int> d = gen_d(N);
      vector<pii> v = gen_v(N, M);

      sort(v.begin(), v.end());
      int s = 0, t = 0;
      while(s == t){
	s = rnd.next(1, N);
	int max_b = s;
	for(int j = 0; j < M; j++)
	  if(v[j].first < max_b) max_b = v[j].second;
	t = rnd.next(1, max_b);
      }
      shuffle(v.begin(), v.end());
      output(N, M, s, t, d, v, "60_NMAX_random", i);
    }

    //  M 最大ケース
    for(int i = 0; i < 5; ++i){
      int N = rnd.next(MIN_N, (int)sqrt(MAX_N*2));
      int M = (long long)N*(N-1)/2;
      vector<int> d = gen_d(N);
      vector<pii> v;
      for(int j = 1; j < N; j++) for(int k = j+1; k <= N; k++) v.emplace_back(pii(j,k));
      int s = 0, t = 0;
      while(s == t){
	s = rnd.next(1, N);
	t = rnd.next(1, N);
      }
      shuffle(v.begin(), v.end());
      output(N, M, s, t, d, v, "60_MMAX_random", i);
    }


    //  N M 最大ケース
    for(int i = 0; i < 1; ++i){
      int N = sqrt(MAX_N*2);
      int M = (long long)N*(N-1)/2;
      vector<int> d = gen_d(N);
      vector<pii> v;
      for(int j = 1; j < N; j++) for(int k = j+1; k <= N; k++) v.emplace_back(pii(j,k));
      int s = 0, t = 0;
      while(s == t){
        s = rnd.next(1, N);
        t = rnd.next(1, N);
      }
      shuffle(v.begin(), v.end());
      output(N, M, s, t, d, v, "60_NMMAX", i);
    }


    //　N 最大 s=1 t=N 階段ケース 
    for(int i = 0; i < 1; ++i){
      int N = MAX_N;
      int M = N-1;
      vector<int> d = gen_d(N);
      vector<pii> v;
      for(int j = 1; j < N; j++) v.emplace_back(pii(j,j+1));
      int s = 1;
      int t = N;
      shuffle(v.begin(), v.end());
      output(N, M, s, t, d, v, "70_s1tN_NMAX", i);
    }


    // s > t 
    for(int i = 0; i < 5; ++i){
      int N = rnd.next(MIN_N, MAX_N);
      int M = rnd.next((long long)MIN_M, min((long long)N*(N-1)/2,(long long)MAX_M));
      vector<int> d = gen_d(N);
      vector<pii> v = gen_v(N, M);
      int s = rnd.next(2, N);
      int t = rnd.next(1, s-1);
      shuffle(v.begin(), v.end());
      output(N, M, s, t, d, v, "80_slarge_tsmall_random", i);
    }


    //　N 最大 s=1 t=N 1点からすべてに行けるケース
    for(int i = 0; i < 1; ++i){
      int N = MAX_N;
      int M = N-1;
      vector<int> d = gen_d(N);
      vector<pii> v;
      for(int j = 2; j <= N; j++) v.emplace_back(pii(1,j));
      int s = 1;
      int t = N;
      shuffle(v.begin(), v.end());
      output(N, M, s, t, d, v, "90_s1tN_all_NMAX", i);
    }


    // 小さいケース

    for(int i = 0; i < 10; ++i){
      int N = rnd.next(MIN_N, 10);
      int M = rnd.next((long long)MIN_M, min((long long)N*(N-1)/2,(long long)MAX_M));
      vector<int> d = gen_d(N);
      vector<pii> v = gen_v(N, M);
      sort(v.begin(), v.end());
      int s = 0, t = 0;
      while(s == t){
	s = rnd.next(1, N);
	int max_b = s;
	for(int j = 0; j < M; j++)
	  if(v[j].first < max_b) max_b = v[j].second;
	t = rnd.next(1, max_b);
      }
      shuffle(v.begin(), v.end());
      output(N, M, s, t, d, v, "40_small_random", i);
    }




}
