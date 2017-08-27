#include "./constraints.hpp"
#include "./testlib.h"
#include <cassert>

int main() {
   registerValidation();
   int n = inf.readInt(MIN_N, MAX_N);
   inf.readSpace();
   int k = inf.readInt(MIN_K, MAX_K);
   inf.readEoln();

   for(int i = 0; i < n; i++){
       inf.readInt(MIN_A, i);
       inf.readEoln();
   }
   inf.readEof();
}
