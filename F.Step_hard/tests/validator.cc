#include "./testlib.h"
#include "./constraints.hpp"
#include <cassert>

int main(){
    registerValidation();
    inf.readInt(MIN_N, MAX_N);
    inf.readSpace();
    inf.readInt(MIN_M, MAX_M);
    inf.readEoln();
    inf.readEof();
}
