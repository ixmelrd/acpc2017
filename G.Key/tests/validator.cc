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

    std::vector<std::string> in;
    for(int i = 0; i < m + 1; i++){
        std::string s = inf.readToken("[a-z]+");
        in.push_back(s);
        assert(s.size() == n);
        inf.readEoln();
    }
    for(int i = 0; i < n; i++){
		std::vector<int>h(26);
        for(int j = 0; j < m; j++){
			assert(h[in[j][i]]==0);
			h[in[j][i]]=1;
        }
    }

    inf.readEof();
}
