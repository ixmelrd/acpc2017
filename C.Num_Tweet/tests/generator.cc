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

void case_51_N_small() {
  rep(num, 10) {
    int N = rnd.next(MIN_N, 20);
    int K = rnd.next(MIN_K, MAX_N);
    vector<int> A(N);
    rep(i, N) A[i] = rnd.next(MIN_A, i);
    output(N, K, A, "51_Nsmall", num);
  }
}

void case_60_corner() { // larger N
  rep(num, 10) {
    int N = rnd.next(MAX_N / 2, MAX_N);
    int K = rnd.next(MIN_K, MAX_K);
    vector<int> A(N);
    rep(i, N) A[i] = rnd.next(MIN_A, i);
    output(N, K, A, "60_corner", num);
  }
}

void case_61_corner() { // stack overflow attack (anti dfs)
  int N = MAX_N, K = MAX_K;
  vector<int> A(N);
  rep(i, N) A[i] = i;
  output(N, K, A, "61_corner");
}

void case_62_corner() { // single node
  int N = 1, K = MIN_K;
  vector<int> A(N);
  A[0] = 0;
  output(N, K, A, "62_corner");
}

int main() {
  rnd.setSeed(time(0) + getpid());
  case_50_random();
  case_51_N_small();
  case_60_corner();
  case_61_corner();
  case_62_corner();
}
