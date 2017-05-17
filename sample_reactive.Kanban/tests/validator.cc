#include "./testlib.h"
#include "./constraints.hpp"
#include <cassert>
#include <map>
using namespace std;
typedef pair<int,int> pii;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)

int main(){
    registerValidation();

    int V = inf.readInt(MIN_V, MAX_V);
    inf.readSpace();
    int E = inf.readInt(MIN_E, V*(V-1)/2);
    inf.readEoln();

    map<pii,bool> mp;

    rep(i,E){
        int a = inf.readInt(0,V-1);
        inf.readSpace();

        int b = inf.readInt(0,V-1);
        inf.readEoln();
        
        assert( a!=b ); //自己ループ検知    

        if(a>b)swap(a,b);
        assert( mp.count( pii(a,b) )==0 );  //多重辺検知

        mp[pii(a,b)] = true;
    }
    inf.readEof();
}
