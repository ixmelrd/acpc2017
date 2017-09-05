#include<iostream>
#include<vector>
#define rep(i,a) for(int i=0;i<a;i++) 
using namespace std;
const long long INF = 1e8;

struct Data{
    long long t, f;
};

int main(){
    long long n, d;
    cin >> n >> d;

    vector<Data> v(n + 2);
    v[0] = Data{0, 1};
    rep(i,n){
        cin >> v[i + 1].t >> v[i + 1].f;
    }
    v[n + 1] = Data{INF, 1};

    long long w = 0, ans = 0;
    for(int i = 1; i <= n + 1; i++){
        long long time = v[i].t - v[i - 1].t;
        //cout << "TIme  " <<  time << endl; cout << " i " << i <<  ' ' << w << endl;
        if(v[i - 1].f + v[i].f - 2 <= time){
            //cout << "V " << v[i - 1].f << ' ' << w << endl;
            ans += w * (v[i - 1].f - 1);
            w = 1;
        }else if(abs(v[i].f - v[i - 1].f) <= time && w < d){
            ans += w * abs(v[i].f - v[i - 1].f);
            w++;
        }else{
            cout << -1 << endl;
            return 0;
        }
        //cout << ans << endl;
    }
    cout << ans << endl;
}
