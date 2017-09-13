#include <iostream>
#include <utility>
#include "./testlib.h"
#include "./constraints.hpp"
#include <sys/types.h>
#include <unistd.h>
#include <cassert>
#define TEST_CASE 10
#define rangemax 100000
#define rangemin 1
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
// oが出る確率が90%  xが出る確率が10%に設定
void output(string s,int length,const string &name){
    ofstream ofs(name);
    ofs << length << endl;
    rep(i,s.size()){
        ofs << s[i];
    }
    ofs << endl;
    ofs.close();
}
int main(){
    rnd.setSeed(time(0)+getpid());
    /*小さいテストケースを作成*/
    rep(case_num,5){
        char file_name[100];
        sprintf(file_name,"50-small-%02d.in",case_num);
        int length=rnd.next(MIN_N,20);
        string s;
        rep(i,length){
            int num=rnd.next(1,100);
            if(num%10)s.push_back('o');
            else s.push_back('x');
        }
        output(s,length,file_name);
    }
    rnd.setSeed(time(0)+getpid());
    /*大きめ*/
    rep(case_num,5){
        
        rnd.setSeed(time(0)+getpid());
        char file_name[100];
        sprintf(file_name,"50-large-%02d.in",case_num);
        int length=rnd.next(MAX_N-1000,MAX_N);
        string s;
        rep(i,length){
            int num=rnd.next(rangemin,rangemax);
            if(num%10)s.push_back('o');
            else s.push_back('x');
        }
        output(s,length,file_name);
    }
    rnd.setSeed(time(0)+getpid());
    /*最大テストケースを作成*/
    rep(case_num,TEST_CASE){
        char file_name[100];
        sprintf(file_name,"50-MAX-%02d.in",case_num);
        int length=MAX_N;
        string s;
        rep(i,length){
            int num=rnd.next(rangemin,rangemax);
            if(num%10)s.push_back('o');
            else s.push_back('x');
        }
        output(s,length,file_name);
    }
    /*xの出現確率を50％*/
    rnd.setSeed(time(0)+getpid());
    rep(case_num,TEST_CASE){
        char file_name[100];
        sprintf(file_name,"60-even-%02d.in",case_num);
        int length=rnd.next(MIN_N,MAX_N);
        string s;
        rep(i,length){
            int num=rnd.next(rangemin,rangemax);
            if(num%2)s.push_back('o');
            else s.push_back('x');
        }
        output(s,length,file_name);
    }
    /*xが連続して2つでない*/
    rep(case_num,5){
        char file_name[100];
        sprintf(file_name,"50-NotFailed-%02d.in",case_num);
        int length=rnd.next(MIN_N,20);
        string s;
        rep(i,length){
            int num=rnd.next(1,100);
            if(num%10||s.back()=='x')s.push_back('o');
            else s.push_back('x');
        }
        output(s,length,file_name);
    }
    rnd.setSeed(time(0)+getpid());
    /*ランダムテストケース*/
    rep(case_num,TEST_CASE){
        char file_name[100];
        sprintf(file_name,"60-random-%02d.in",case_num);
        int length=rnd.next(MIN_N,MAX_N);
        string s;
        rep(i,length){
            int num=rnd.next(rangemin,rangemax);
            if(num%10)s.push_back('o');
            else s.push_back('x');
        }
        output(s,length,file_name);
    }
    /*corner*/
    rep(case_num,TEST_CASE){
        char file_name[100];
        sprintf(file_name,"60-corner-%02d.in",case_num);
        int length=MAX_N;
        string s;
        rep(i,length){
            int num=rnd.next(rangemin,rangemax);
            if(i<=length-3)s.push_back('o');
            else s.push_back('x');
        }
        output(s,length,file_name);
    }
}
