#include "./constraints.hpp"
#include "./testlib.h"
#include <iomanip>
#include <sys/types.h>
#include <unistd.h>
using namespace std;

#define loop(i, a, n) for (int i = a; i < (n); i++)
#define rep(i, n) loop(i, 0, n)

void output(const int N, const int K, const vector<int> &A, const string &prefix, const int num = 0) {
  ostringstream os;
  os << prefix << '_' << setw(2) << setfill('0') << num << ".in";
  ofstream ofs(os.str());
  ofs << N << ' ' << K << '\n';
  for (auto &x : A) ofs << x << '\n';
  ofs.close();
}

void case_50_Nsmall_Ksmall() {
  rep(num, 10) {
    int N = rnd.next(MIN_N, 20);
    int K = rnd.next(MIN_K, 3);
    vector<int> A(N);
    rep(i, N) A[i] = rnd.next(MIN_A, i);
    output(N, K, A, "50_Nsmall_Ksmall", num);
  }
}

void case_51_Nsmall() {
  rep(num, 10) {
    int N = rnd.next(MIN_N, 20);
    int K = rnd.next(MIN_K, MAX_K);
    vector<int> A(N);
    rep(i, N) A[i] = rnd.next(MIN_A, i);
    output(N, K, A, "51_Nsmall", num);
  }
}

void case_52_Nlarge() {
  rep(num, 10) {
    int N = rnd.next(MAX_N / 2, MAX_N);
    int K = rnd.next(MIN_K, MAX_K);
    vector<int> A(N);
    rep(i, N) A[i] = rnd.next(MIN_A, i);
    output(N, K, A, "52_Nlarge", num);
  }
}

void case_53_Nlargest_Ksmall() {
  int N = MAX_N;
  rep(num, 10) {
    int K = rnd.next(MIN_K, 20);
    vector<int> A(N);
    rep(i, N) A[i] = rnd.next(MIN_A, i);
    output(N, K, A, "53_Nlargest_Ksmall", num);
  }
}

void case_54_Nlargest() {
  int N = MAX_N;
  rep(num, 10) {
    int K = rnd.next(MIN_K, MAX_K);
    vector<int> A(N);
    rep(i, N) A[i] = rnd.next(MIN_A, i);
    output(N, K, A, "54_Nlargest", num);
  }
}

void case_55_Nsmallest() {
  int N = MIN_N;
  rep(num, 10) {
    int K = rnd.next(MIN_K, MAX_K);
    vector<int> A(N);
    A[0] = 0;
    output(N, K, A, "55_Nsmallest", num);
  }
}

void case_59_random() {
  rep(num, 10) {
    int N = rnd.next(MIN_N, MAX_N);
    int K = rnd.next(MIN_K, MAX_K);
    vector<int> A(N);
    rep(i, N) A[i] = rnd.next(MIN_A, i);
    output(N, K, A, "59_random", num);
  }
}

void case_60_corner() { // stack overflow attack (anti dfs)
  rep(num, 10) {
    int N = num == 0 ? MAX_N : rnd.next(MAX_N - 100, MAX_N);
    int K = num == 0 ? MAX_K : rnd.next(MAX_K - 100, MAX_K);
    vector<int> A(N);
    rep(i, N) A[i] = i;
    output(N, K, A, "60_corner", num);
  }
}

void case_61_corner() { // single node trees
  rep(num, 10) {
    int N = num == 0 ? MAX_N : rnd.next(MAX_N - 100, MAX_N);
    int K = num == 0 ? MAX_K : rnd.next(MAX_K - 100, MAX_K);
    vector<int> A(N);
    rep(i, N) A[i] = 0;
    output(N, K, A, "61_corner", num);
  }
}

void case_62_corner() { // many large walks
  rep(num, 10) {
    int N = rnd.next(MAX_N - 100, MAX_N);
    int K = rnd.next(MAX_K - 100, MAX_K);
    vector<int> A(N);
    rep(i, N / 2) A[i] = i;
    loop(i, N / 2, N) A[i] = N / 2 - 1;
    output(N, K, A, "62_corner", num);
  }
}

void case_63_corner() { // replied by all others
  rep(num, 10) {
    int N = num == 0 ? MAX_N : rnd.next(MAX_N - 100, MAX_N);
    int K = num == 0 ? MIN_K : rnd.next(MIN_K, MIN_K + 10);
    vector<int> A(N);
    A[0] = 0;
    loop(i, 1, N) A[i] = 1;
    output(N, K, A, "63_corner", num);
  }
}

int main() {
  rnd.setSeed(time(0) + getpid());
  case_50_Nsmall_Ksmall();
  case_51_Nsmall();
  case_52_Nlarge();
  case_53_Nlargest_Ksmall();
  case_54_Nlargest();
  case_55_Nsmallest();
  case_59_random();
  case_60_corner();
  case_61_corner();
  case_62_corner();
  case_63_corner();
}
