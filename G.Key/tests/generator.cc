#include <iostream>
#include <utility>
#include "./testlib.h"
#include "./constraints.hpp"
#include <sys/types.h>
#include <unistd.h>
#include <cassert>
#include <set>

using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)

void output(int N, int M, const vector<int> &a, const string &prefix, int suffix){
    assert(N == static_cast<int>(a.size()));
    char name[100];
    sprintf(name, "%s_%02d.in", prefix.c_str(), suffix);
    ofstream ofs(name);
    ofs << N << ' ' << M << endl;
    for(int i = 0; i < N; i++){
        ofs << a[i] << (i == N - 1 ? '\n' : ' ');
    }
    ofs.close();
}

vector<int> create(int N, int M){
    vector<int> res(N);
    rep(i,N){
        res[i] = rnd.next(0, M - 1);
    }
    return res;
}

int main(){
    // 乱数のシードを設定
    // pidを足すことで、1秒以上間を置かずに起動したときに同じシードになってしまうのを防ぐ
    rnd.setSeed(time(0)+getpid());

    //小さいケース
    for(int i = 0; i < 10; i++){
        int N = rnd.next(MIN_N, MIN_N + 10);
        int M = rnd.next(MIN_M, MIN_N + 10);
        vector<int> v = create(N, M);
        output(N, M, v, "50_random_small", i);
    }

    //大きいケース
    for(int i = 0; i < 10; i++){
        int N = rnd.next(MAX_N - 5, MAX_N);
        int M = rnd.next(MAX_N - 5, MAX_M);
        vector<int> v = create(N, M);
        output(N, M, v, "51_random_large", i);
    }

    //ランダム
    for(int i = 0; i < 10; i++){
        int N = rnd.next(MIN_N, MAX_N);
        int M = rnd.next(MIN_M, MAX_M);
        vector<int> v = create(N, M);
        output(N, M, v, "52_random", i);
    }

    //最大ケース
    for(int i = 0; i < 10; i++){
        int N = MAX_N;
        int M = MAX_M;
        vector<int> v = create(N, M);
        output(N, M, v, "61_maximum", i);
    }

    //最小ケース
    for(int i = 0; i < 3; i++){
        int N = MIN_N;
        int M = MIN_M;
        vector<int> v = create(N, M);
        output(N, M, v, "60_minimum", i);
    }

	//奇数が並ぶケース
    for(int i = 0; i < 1000; i++){
        int N = MAX_N;
		int M = 1;
		while(M % 2 || M < 2) M = rnd.next(MIN_M, MAX_M);
		vector<int> v;
		for(int j = 0; j < N; j++){
			v.push_back(M / 2);
		}
        output(N, M, v, "50_odd_number", i);
    }
}
