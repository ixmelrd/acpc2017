#include <algorithm>
#include <iostream>
#include <vector>
#define loop(i, a, n) for (int i = (a); i < (n); i++)
constexpr int INF = 1000000000;
template<typename A, typename B> bool cmin(A &a, const B &b) { return a > b ? (a = b, true) : false; }
using namespace std;

template<typename Monoid, typename InputIterator> typename Monoid::value_type fold(InputIterator first, InputIterator last) {
  Monoid m;
  auto acc = m.id();
  std::for_each(first, last, [&](auto &x) { acc = m(acc, x); });
  return acc;
}

template<typename T, T upperInf = std::numeric_limits<T>::max()> struct minMonoid {
  using value_type = T;
  constexpr value_type id() { return upperInf; }
  constexpr value_type operator()(const value_type &a, const value_type &b) { return a < b ? a : b; }
};

int main() {
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  --s, --t;
  vector<int> d(n);
  for (auto &x : d) cin >> x;
  vector<int> mostLeftFrom(n, INF);
  while (m--) {
    int a, b;
    cin >> a >> b;
    cmin(mostLeftFrom[--b], --a);
  }
  vector<int> dp(n, INF);
  dp[s] = 0;
  loop(i, s + 1, n) { // worst O(N)
    if (mostLeftFrom[i] != INF) {
      dp[i] = fold<minMonoid<int, INF>>(dp.begin() + mostLeftFrom[i], dp.begin() + i) + d[i]; // worst O(N)
    }
  }
  cout << fold<minMonoid<int, INF>>(dp.begin() + t, dp.end()) << endl;
}
