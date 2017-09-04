#include "./constraints.hpp"
#include "./testlib.h"
#include <cassert>

int main() {
  registerValidation();
  int n = inf.readInt(MIN_N, MAX_N);

  inf.readEoln();

  char ptrn[100];
  sprintf(ptrn,"[ox]{%d}",n);
  
  inf.token(ptrn);
  
  inf.readEoln();
  inf.readEof();
}
