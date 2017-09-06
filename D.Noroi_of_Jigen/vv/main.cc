#include <iostream>
#include <limits>
#include <queue>
#include <tuple>
#include <vector>
#define loop(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) loop(i, 0, n)
template<typename A, typename B> bool cmin(A &a, const B &b) { return a > b ? (a = b, true) : false; }
template<typename T> std::istream &operator>>(std::istream &is, std::vector<T> &v) {
  for (T &x : v) is >> x;
  return is;
}
using namespace std;

using Weight = int;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(const int s = 0, const int d = 0, const Weight w = 0) : src(s), dst(d), weight(w) {}
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

template<int inf = std::numeric_limits<Weight>::max() / 8> std::vector<Weight> dijkstra(const Graph &g, const int src) {
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
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  --s, --t;
  vector<int> d(n);
  cin >> d;
  Graph g(n);
  while (m--) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g.addArc(a, b, d[b]);
  }
  loop(i, 1, n) g.addArc(i, i - 1, 0);
  cout << dijkstra(g, s)[t] << endl;
}
