#include "./constraints.hpp"
#include "./testlib.h"
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <tuple>
#define loop(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) loop(i, 0, n)
#define all(v) (v).begin(), (v).end()
using pii = std::pair<int, int>;
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

template<typename Monoid> constexpr typename Monoid::value_type powm(typename Monoid::value_type a, int b) {
  Monoid m;
  typename Monoid::value_type c = m.id();
  while (b) {
    if (b & 1) c = m(c, a);
    b >>= 1;
    a = m(a, a);
  }
  return c;
}

template<typename LSTTrait> class LazySegTree {
  using FoldMonoid = typename LSTTrait::FoldMonoid;
  using ActionMonoid = typename LSTTrait::ActionMonoid;
  using T = typename FoldMonoid::value_type;
  using Q = typename ActionMonoid::value_type;

  LSTTrait lstTrait; // apply :: (T, Q) -> T
  FoldMonoid foldM;
  ActionMonoid actionM;
  int size = 1;
  std::vector<T> tree; // 1-indexed
  std::vector<Q> lazy; // 1-indexed

  void flush(int i, int l, int r) {
    tree[i] = lstTrait.apply(tree[i], powm<ActionMonoid>(lazy[i], r - l));
    if (i < size) {
      lazy[i * 2] = actionM(lazy[i * 2], lazy[i]);
      lazy[i * 2 + 1] = actionM(lazy[i * 2 + 1], lazy[i]);
    }
    lazy[i] = actionM.id();
  }

public:
  LazySegTree(const int n = 0) {
    while (size < n) size *= 2;
    tree.assign(size * 2, foldM.id());
    lazy.assign(size * 2, actionM.id());
  }

  template<typename InputIterator> LazySegTree(InputIterator first, InputIterator last) {
    int n = std::distance(first, last);
    while (size < n) size *= 2;
    tree.resize(size * 2, foldM.id());
    lazy.resize(size * 2, actionM.id());
    std::copy(first, last, tree.begin() + size);
    for (int i = size - 1; i >= 1; i--) tree[i] = foldM(tree[i * 2], tree[i * 2 + 1]);
  }

  // [l, r)
  void act(int l, int r, const Q x) { act(l, r, x, 1, 0, size); }
  void act(const int l, const int r, const Q x, int i, int a, int b) {
    flush(i, a, b);
    if (b <= l || r <= a) return;
    if (l <= a && b <= r) {
      lazy[i] = actionM(lazy[i], x);
      flush(i, a, b);
      return;
    }
    act(l, r, x, i * 2, a, (a + b) / 2);
    act(l, r, x, i * 2 + 1, (a + b) / 2, b);
    tree[i] = foldM(tree[i * 2], tree[i * 2 + 1]);
  }

  // [l, r)
  T fold(int l, int r) { return fold(l, r, 1, 0, size); }
  T fold(int l, int r, int i, int a, int b) {
    flush(i, a, b);
    if (b <= l || r <= a) return foldM.id();
    if (l <= a && b <= r) return tree[i];
    T lhs = fold(l, r, i * 2, a, (a + b) / 2);
    T rhs = fold(l, r, i * 2 + 1, (a + b) / 2, b);
    tree[i] = foldM(tree[i * 2], tree[i * 2 + 1]);
    return foldM(lhs, rhs);
  }
};

template<typename T, T upperInf = std::numeric_limits<T>::max()> struct minMonoid {
  using value_type = T;
  constexpr value_type id() { return upperInf; }
  constexpr value_type operator()(const value_type &a, const value_type &b) { return a < b ? a : b; }
};

template<typename T> struct updateMonoid {
  using value_type = pair<bool, T>;
  constexpr value_type id() { return {false, T()}; }
  constexpr value_type operator()(const value_type &a, const value_type &b) { return b.first ? b : a; }
};

template<typename T, T upperInf = std::numeric_limits<T>::max()> struct RMQ_RUQ_Trait {
  using FoldMonoid = minMonoid<T, upperInf>;
  using ActionMonoid = updateMonoid<T>;
  typename FoldMonoid::value_type apply(typename FoldMonoid::value_type t, typename ActionMonoid::value_type q) { return q.first ? q.second : t; }
};

class RangeUnionFind {
  LazySegTree<RMQ_RUQ_Trait<int>> lst;

public:
  RangeUnionFind(const int n) {
    vector<int> ufInit(n);
    iota(all(ufInit), 0);
    lst = LazySegTree<RMQ_RUQ_Trait<int>>(all(ufInit));
  }

  int root(int x) {
    int a = lst.fold(x, x + 1);
    if (a == x) return x;
    int b = root(a);
    lst.act(x, x + 1, {true, b});
    return b;
  }

  bool same(const int a, const int b) { return root(a) == root(b); }

  void unite(int a, int b) { // unite [a, b)
    int r = root(a);
    if (a == b) return;
    lst.act(a, b, {true, r});
  }
};

bool isReachable(const int N, const int M, const int s, const int t, const vector<int> &a, const vector<int> &b) {
  if (t < s) return true;
  bool isReachableByDijkstra, isReachableByRangeUnionFind;
  {
    Graph g(N);
    loop(i, 1, N) g.addArc(i, i - 1, 0);
    rep(i, M) g.addArc(a[i] - 1, b[i] - 1, 0);
    constexpr int INF = 1;
    isReachableByDijkstra = dijkstra<INF>(g, s - 1)[t - 1] != INF;
  }
  {
    RangeUnionFind uf(N);
    rep(i, M) uf.unite(a[i] - 1, b[i]);
    isReachableByRangeUnionFind = uf.same(s - 1, t - 1);
  }
  if (isReachableByDijkstra != isReachableByRangeUnionFind) {
    cout << "The validator is something wrong. Please report it to vvataarne." << endl;
    return 1;
  }
  return isReachableByDijkstra;
}

int main() {
  registerValidation();
  int N = inf.readInt(MIN_N, MAX_N);
  inf.readSpace();
  int M = inf.readInt(MIN_M, static_cast<int>(min(static_cast<long long>(MAX_M), static_cast<long long>(N) * (static_cast<long long>(N) - 1LL) / 2LL)));
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
    cout << "Expected s != t; Got s = t = " << s << ";" << endl;
    return 1;
  }
  map<pii, int> edges;
  rep(i, M) {
    pii p(a[i], b[i]);
    if (edges.count(p)) {
      int j = edges[p];
      cout << "Expected noMultiEdges; Got (a_" << j + 1 << ", b_" << j + 1 << ") = (a_" << i + 1 << ", b_" << i + 1 << ") = (" << a[i] << ", " << b[i] << ");" << endl;
      return 1;
    }
    edges.emplace(p, i);
    if (a[i] >= b[i]) {
      cout << "Expected a_" << i + 1 << " < b_" << i + 1 << "; Got a_" << i + 1 << " = " << a[i] << ", b_" << i + 1 << " = " << b[i] << ";" << endl;
      return 1;
    }
  }
  if (!isReachable(N, M, s, t, a, b)) {
    cout << "Expected isReachable; Got s = " << s << ", t = " << t << ";" << endl;
    return 1;
  }
}
