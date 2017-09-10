#include<iostream>
#include<cassert>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    assert(n <= 20 && m <= 20);

    int dp[20][20][20] = {{{0}}};
    dp[1][m][1] = 1;

    for (int j = m; j >= 1; j--) {
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= n; k++) {
                if(i + 1 <= n) dp[i + 1][j - 1][max(k, i + 1)] += dp[i][j][k];
                if(i - 1 >= 0) dp[i - 1][j - 1][k] += dp[i][j][k];
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[i][0][n];
    }
    cout << ans << endl;
}
