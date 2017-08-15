#include "./constraints.hpp"
#include "./testlib.h"
#include <sys/types.h>
#include <unistd.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

void output(const int N, const int K, const vector<int> &A, const string &prefix, const int num = 0) {
  ostringstream os;
  os << prefix << '_' << num << ".in";
  ofstream ofs(os.str());
  ofs << N << ' ' << K << '\n';
  for (auto &x : A) ofs << x << '\n';
  ofs.close();
}

void case_50_random() {
  rep(num, 10) {
    int N = rnd.next(MIN_N, MAX_N);
    int K = rnd.next(MIN_K, MAX_N);
    vector<int> A(N);
    rep(i, N) A[i] = rnd.next(MIN_A, i);
    output(N, K, A, "50_random", num);
  }
}

void case_60_random() { // larger N
  rep(num, 10) {
    int N = rnd.next(MAX_N / 2, MAX_N);
    int K = rnd.next(MIN_K, MAX_K);
    vector<int> A(N);
    rep(i, N) A[i] = rnd.next(MIN_A, i);
    output(N, K, A, "60_random", num);
  }
}

void case_70_corner() { // stack overflow attack (anti dfs)
  int N = MAX_N, K = MAX_K;
  vector<int> A(N);
  rep(i, N) A[i] = i;
  output(N, K, A, "70_corner");
}

void case_80_corner() { // single node
  int N = 1, K = MIN_K;
  vector<int> A(N);
  A[0] = 0;
  output(N, K, A, "80_corner");
}

int main() {
  rnd.setSeed(time(0) + getpid());
  case_50_random();
  case_60_random();
  case_70_corner();
  case_80_corner();
}
