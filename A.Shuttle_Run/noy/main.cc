#include<iostream>
#include<string>
#define rep(i,a) for(int i=0;i<a;i++)
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;

    cout << (s.find("xx") == string::npos ? n : s.find("xx") + 1) << endl;

}
