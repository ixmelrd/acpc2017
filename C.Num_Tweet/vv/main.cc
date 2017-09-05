// clang-format off
#include <bits/stdc++.h>
#define int long long
#define main signed main()
#define loop(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) loop(i, 0, n)
#define forever for (;;)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prec(n) fixed << setprecision(n)
template<typename A> using V = std::vector<A>;
template<typename A> using F = std::function<A>;
template<typename A, typename B> using P = std::pair<A, B>;
using pii = P<int, int>;
using vi = V<int>;
using vd = V<double>;
using vs = V<std::string>;
using vpii = V<pii>;
using vvi = V<vi>;
using vvpii = V<vpii>;
constexpr int INF = sizeof(int) == sizeof(long long) ? 1000000000000000000LL : 1000000000;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979;
template<typename A, typename B> bool cmin(A &a, const B &b) { return a > b ? (a = b, true) : false; }
template<typename A, typename B> bool cmax(A &a, const B &b) { return a < b ? (a = b, true) : false; }
constexpr bool odd(const int n) { return n & 1; }
constexpr bool even(const int n) { return ~n & 1; }
template<typename T> std::istream &operator>>(std::istream &is, std::vector<T> &v) { for (T &x : v) is >> x; return is; }
template<typename A, typename B> std::istream &operator>>(std::istream &is, std::pair<A, B> &p) { is >> p.first; is >> p.second; return is; }
using namespace std;
// clang-format on

using Weight = int;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(const int s = 0, const int d = 0, const Weight w = 0) : src(s), dst(d), weight(w) {}
};

using Edges = std::vector<Edge>;
using Array = std::vector<Weight>;
using Matrix = std::vector<Array>;

class Graph {
  std::vector<Edges> g;
  using iterator = std::vector<Edges>::iterator;
  using const_iterator = std::vector<Edges>::const_iterator;

public:
  Graph(const int size = 0) : g(size) {}
  size_t size() const { return g.size(); }
  const Edges &operator[](const int i) const { return g[i]; }
  void addArc(const int src, const int dst, const Weight w = 1) { g[src].emplace_back(src, dst, w); }
  void addEdge(const int node1, const int node2, const Weight w = 1) {
    addArc(node1, node2, w);
    addArc(node2, node1, w);
  }
  iterator begin() { return g.begin(); }
  const_iterator begin() const { return g.begin(); }
  iterator end() { return g.end(); }
  const_iterator end() const { return g.end(); }
};

std::vector<int> tsort(const Graph &g) {
  int n = g.size(), k = 0;
  std::vector<int> ord(n), in(n);
  for (auto &es : g) {
    for (auto &e : es) in[e.dst]++;
  }
  std::queue<int> q;
  rep(i, n) if (in[i] == 0) q.push(i);
  while (q.size()) {
    int v = q.front();
    q.pop();
    ord[k++] = v;
    for (auto &e : g[v])
      if (--in[e.dst] == 0) q.push(e.dst);
  }
  return *std::max_element(in.begin(), in.end()) == 0 ? ord : std::vector<int>();
}

main {
  int n, k;
  cin >> n >> k;
  Graph g(n);
  rep(i, n) {
    int a;
    cin >> a;
    if (a > 0) g.addArc(i, a - 1);
  }
  vector<int> in(n), out(n);
  for (auto &es : g) {
    for (auto &e : es) in[e.dst]++, out[e.src]++;
  }
  vector<int> dp(n);
  rep(i, n) if (in[i] == 0) dp[i] = k;

  vector<int> topo = tsort(g);
  for (auto &i : topo) {
    if (g[i].size()) cmax(dp[g[i][0].dst], dp[i] - 1);
  }
  rep(i, n) if (out[i] == 0) dp[i] = 1;
  cout << count_if(all(dp), [](int x) { return x > 0; }) << endl;
}
