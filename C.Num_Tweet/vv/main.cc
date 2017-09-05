// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define loop(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) loop(i, 0, n)
#define all(v) (v).begin(), (v).end()
template<typename A, typename B> bool cmax(A &a, const B &b) { return a < b ? (a = b, true) : false; }
using namespace std;

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
  const_iterator begin() const { return g.begin(); }
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

int main() {
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
