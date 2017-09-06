#include <iostream>
#include <vector>
#define loop(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) loop(i, 0, n)
const long long INF = 1000000000000000000LL;
using namespace std;

int main() {
  int n, d;
  cin >> n >> d;
  vector<long long> t(n + 2), f(n + 2, 1);
  rep(i, n) cin >> t[i + 1] >> f[i + 1];
  rep(i, f.size()) f[i]--;
  t[n + 1] = INF;
  long long sumTime = 0LL, person = 0LL;
  rep(i, n + 1) {
    long long diffT = t[i + 1] - t[i], diffF = abs(f[i + 1] - f[i]);
    if (f[i + 1] + f[i] <= diffT) {
      sumTime += person * f[i];
      person = 1LL;
      continue;
    }
    if (diffF <= diffT && person < d) {
      sumTime += person * diffT;
      person++;
      continue;
    }
    goto IMPOSSIBLE;
  }
  cout << sumTime << endl;
  return 0;
IMPOSSIBLE:
  cout << -1 << endl;
}
