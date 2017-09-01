#include "./constraints.hpp"
#include "./testlib.h"
#include <cassert>

int main() {
  registerValidation();
  int N = inf.readInt(MIN_N, MAX_N);
  inf.readSpace();
  int M = inf.readInt(MIN_M, MAX_M);
  inf.readSpace();
  int s = inf.readInt(1, N);
  inf.readSpace();
  int d = inf.readInt(1, N);
  assert(s != d);
  inf.readEoln();
  for (int i = 0; i < N; i++) {
    if (i) inf.readSpace();
    inf.readInt(MIN_d, MAX_d);
  }
  inf.readEoln();
  for (int i = 0; i < M; i++) {
    int a = inf.readInt(1, N);
    inf.readSpace();
    int b = inf.readInt(1, N);
    inf.readEoln();
    assert(a < b);
  }
  inf.readEof();
}
