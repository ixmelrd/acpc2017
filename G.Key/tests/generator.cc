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

void output(int N, int M, const vector<string> &a, const string &prefix, int suffix){
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

string createT(int N, int M, vector<string> v){
    string res;
    rep(i,N){
        res += v[static_cast<int>(rnd.next(0,M - 1))][i];
    }
    return res;
}

vector<string> createString(int N, int M){
    vector<string> res;
    set<char> s[16]; //同じ文字が含まれるのを防ぐ
    rep(i,M){
        string tmp;
        rep(j,N){
            char add;
            while(true){
                add = static_cast<char>('a' + static_cast<int>(rnd.next(0,25)));
                if(not s[j].count(add)) break;
            }
            s[j].insert(add);
            tmp += add;
        }
        res.push_back(tmp);
    }
    res.push_back(createT(N, M, res));
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
        vector<string> v = createString(N, M);
        output(N, M, v, "50_random_small", i);
    }

    //大きいケース
    for(int i = 0; i < 10; i++){
        int N = rnd.next(12, MAX_N);
        int M = rnd.next(12, MAX_M);
        vector<string> v = createString(N, M);
        output(N, M, v, "50_random_large", i);
    }

    //ランダム
    for(int i = 0; i < 10; i++){
        int N = rnd.next(MIN_N, MAX_N);
        int M = rnd.next(MIN_M, MAX_M);
        vector<string> v = createString(N, M);
        output(N, M, v, "50_random", i);
    }

    //最大ケース
    for(int i = 0; i < 3; i++){
        int N = MAX_N;
        int M = MAX_M;
        vector<string> v = createString(N, M);
        output(N, M, v, "60_maximum", i);
    }

    //最小ケース
    for(int i = 0; i < 3; i++){
        int N = MIN_N;
        int M = MIN_M;
        vector<string> v = createString(N, M);
        output(N, M, v, "60_minimum", i);
    }
}
