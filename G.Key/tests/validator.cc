#include "./testlib.h"
#include "./constraints.hpp"
#include <cassert>
#include <string>
#include <vector>
#include <set>

int main(){
	registerValidation();
	int n = inf.readInt(MIN_N, MAX_N);
	inf.readSpace();
	int m = inf.readInt(MIN_M, MAX_M);
	inf.readEoln();

    for(int i = 0; i < n; i++){
		if(i)inf.readSpace();
		int t = inf.readInt(0,m-1);
	}
	inf.readEoln();
	inf.readEof();
}
