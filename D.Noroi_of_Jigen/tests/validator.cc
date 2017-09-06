#include "./constraints.hpp"
#include "./testlib.h"
#include <cassert>
#include <iostream>
#include <numeric>
#include <queue>
#include <tuple>
#define loop(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) loop(i, 0, n)
template<typename A, typename B> bool cmin(A &a, const B &b) { return a > b ? (a = b, true) : false; }
using namespace std;

using Weight = int;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(const int s, const int d, const Weight w) : src(s), dst(d), weight(w) {}
};

using Edges = std::vector<Edge>;
class Graph {
  std::vector<Edges> g;

public:
  Graph(const int size = 0) : g(size) {}
  size_t size() const { return g.size(); }
  const Edges &operator[](const int i) const { return g[i]; }
  void addArc(const int src, const int dst, const Weight w) { g[src].emplace_back(src, dst, w); }
  void addEdge(const int node1, const int node2, const Weight w) {
    addArc(node1, node2, w);
    addArc(node2, node1, w);
  }
};

template<int inf> std::vector<Weight> dijkstra(const Graph &g, const int src) {
  using state = std::pair<Weight, int>;
  std::priority_queue<state, std::vector<state>, std::greater<state>> q;
  std::vector<Weight> dist(g.size(), inf);
  dist[src] = 0;
  q.emplace(0, src);
  while (q.size()) {
    Weight d;
    int v;
    std::tie(d, v) = q.top();
    q.pop();
    if (dist[v] < d) continue;
    for (auto &e : g[v]) {
      if (cmin(dist[e.dst], dist[v] + e.weight)) q.emplace(dist[e.dst], e.dst);
    }
  }
  return dist;
}

int main() {
  registerValidation();
  int N = inf.readInt(MIN_N, MAX_N);
  inf.readSpace();
  int M = inf.readInt(MIN_M, MAX_M);
  inf.readSpace();
  int s = inf.readInt(1, N);
  inf.readSpace();
  int t = inf.readInt(1, N);
  inf.readEoln();
  vector<int> d(N);
  rep(i, N) {
    d[i] = inf.readInt(MIN_d, MAX_d);
    if (i < N - 1) {
      inf.readSpace();
    } else {
      inf.readEoln();
    }
  }
  vector<int> a(M), b(M);
  rep(i, M) {
    a[i] = inf.readInt(1, N);
    inf.readSpace();
    b[i] = inf.readInt(1, N);
    inf.readEoln();
  }
  inf.readEof();

  if (s == t) {
    cout << "Expected: s != t; Got s = " << s << ", t = " << t << ";" << endl;
    return 1;
  }
  rep(i, M) {
    if (a[i] >= b[i]) {
      cout << "Expected: a_" << i + 1 << " < b_" << i + 1 << "; Got a_" << i + 1 << " = " << a[i] << ", b_" << i + 1 << " = " << b[i] << ";" << endl;
      return 1;
    }
  }
  Graph g(N);
  loop(i, 1, N) g.addArc(i, i - 1, 0);
  rep(i, M) g.addArc(a[i] - 1, b[i] - 1, d[b[i] - 1]);
  constexpr int INF = MAX_d * MAX_N;
  bool isReachable = dijkstra<INF>(g, s - 1)[t - 1] != INF;
  if (!isReachable) {
    cout << "Expected: isReachable; Got s = " << s << ", t = " << t << ";" << endl;
    return 1;
  }
}
