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
    assert(M + 1 == static_cast<int>(a.size()));
    char name[100];
    sprintf(name, "%s_%02d.in", prefix.c_str(), suffix);
    ofstream ofs(name);
    ofs << N << ' ' << M << endl;
    for(int i = 0; i < M + 1; i++){
        ofs << a[i] << endl;
    }
    ofs.close();
}

vector<int> create(int N, int M){
    vector<int> res(N);
    rep(i,N){
        res[i] = rnd.next(0, M);
    }
    return res;
}

int main(){
    // 乱数のシードを設定
    // pidを足すことで、1秒以上間を置かずに起動したときに同じシードになってしまうのを防ぐ
    rnd.setSeed(time(0)+getpid());

    //小さいケース
    for(int i = 0; i < 10; i++){
        int N = rnd.next(MIN_N, 4);
        int M = rnd.next(MIN_M, 4);
        vector<int> v = create(N, M);
        output(N, M, v, "50_random_small", i);
    }

    //大きいケース
    for(int i = 0; i < 10; i++){
        int N = rnd.next(12, MAX_N);
        int M = rnd.next(12, MAX_M);
        vector<int> v = create(N, M);
        output(N, M, v, "50_random_large", i);
    }

    //ランダム
    for(int i = 0; i < 10; i++){
        int N = rnd.next(MIN_N, MAX_N);
        int M = rnd.next(MIN_M, MAX_M);
        vector<int> v = create(N, M);
        output(N, M, v, "50_random", i);
    }

    //最大ケース
    for(int i = 0; i < 3; i++){
        int N = MAX_N;
        int M = MAX_M;
        vector<int> v = create(N, M);
        output(N, M, v, "60_maximum", i);
    }

    //最小ケース
    for(int i = 0; i < 3; i++){
        int N = MIN_N;
        int M = MIN_M;
        vector<int> v = create(N, M);
        output(N, M, v, "60_minimum", i);
    }
}
