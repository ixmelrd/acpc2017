#include <bits/stdc++.h>
#include "./testlib.h"
#include "./constraints.hpp"
#include <sys/types.h>
#include <unistd.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)

//aとbをファイルストリームに出力するためのsample
void output(int V, int E, const vector<pair<int,int>> &es, char *name){
    ofstream ofs(name);
    ofs << V << ' ' << E << endl;
    for(auto &e : es){
        int a,b;
        tie(a,b) = e;
        ofs << a << ' ' << b << endl;
    }
    ofs.close();
}

int main(){
    rnd.setSeed(time(0)+getpid());

    // sample
    {
        int V = 4;
        int E = 3;
        vector<pair<int,int>> es = { {1,0}, {1,2}, {1,3} };
        
        char file_name[100];
        sprintf(file_name, "00_sample_%02d.in", 0);
        output(V,E,es,file_name);
    }

    // dence
    rep(i,5){
        int V = MAX_V;
        int E = rnd.next(MIN_E-50, MAX_E);

        vector<pair<int,int>> es;
        rep(i,V)rep(j,i){
            int a = i, b = j;
            if(rnd.next(0,1)) swap(a,b);
            es.emplace_back(a,b);
        }
        for(int i = 1; i < (int)es.size(); ++i){
            int j = rnd.next(0, i-1);
            swap(es[i], es[j]);
        }
        es.resize(E);

        char file_name[100];
        sprintf(file_name, "10_dence_%02d.in", i);
        output(V,E,es,file_name);
    }

    // sparce
    rep(i,5){
        int V = rnd.next(20, MAX_V);
        int E = V*(V-1)/2 * 0.2;

        vector<pair<int,int>> es;
        rep(i,V)rep(j,i){
            int a = i, b = j;
            if(rnd.next(0,1)) swap(a,b);
            es.emplace_back(a,b);
        }
        for(int i = 1; i < (int)es.size(); ++i){
            int j = rnd.next(0, i-1);
            swap(es[i], es[j]);
        }
        es.resize(E);

        char file_name[100];
        sprintf(file_name, "10_sparce_%02d.in", i);
        output(V,E,es,file_name);
    }

    rep(case_num,15){   //ランダムケース
        int V = rnd.next(MIN_V,MAX_V);
        int E = rnd.next(MIN_E,V*(V-1)/2);

        vector<pair<int,int>> es;
        rep(i,V)rep(j,i){
            int a = i, b = j;
            if(rnd.next(0,1)) swap(a,b);
            es.emplace_back(a,b);
        }
        for(int i = 1; i < (int)es.size(); ++i){
            int j = rnd.next(0, i-1);
            swap(es[i], es[j]);
        }
        es.resize(E);
        char file_name[100];
        sprintf(file_name, "50_large_%02d.in", case_num);
        output(V,E,es,file_name);
    }

    rep(case_num, 15){   //ランダムケース
        int V = rnd.next(MIN_V,MAX_V);
        int E = rnd.next(MIN_E,V*(V-1)/2);

        vector<pair<int,int>> es;
        rep(i,V)rep(j,i){
            int a = i, b = j;
            if(rnd.next(0,1)) swap(a,b);
            es.emplace_back(a,b);
        }
        for(int i = 1; i < (int)es.size(); ++i){
            int j = rnd.next(0, i-1);
            swap(es[i], es[j]);
        }
        es.resize(E);
        char file_name[100];
        sprintf(file_name, "50_small_%02d.in", case_num);
        output(V,E,es,file_name);
    }
}
