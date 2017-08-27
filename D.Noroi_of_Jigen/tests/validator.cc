#include "./constraints.hpp"
#include "./testlib.h"
#include <cassert>

int main() {
  registerValidation();
  int N = inf.readInt(MIN_N, MAX_N);
  inf.readSpace();
  int M = inf.readInt(MIN_M, MAX_M);
  inf.readEoln();
  for (int i = 0; i < N; i++) {
    if (i) inf.readSpace();
    inf.readInt(MIN_d, MAX_d);
  }
  inf.readEoln();
  for (int i = 0; i < M; i++) {
    inf.readInt(MIN_N, N);
    inf.readSpace();
    inf.readInt(MIN_N, N);
    inf.readEoln();
  }
  inf.readEof();
}
