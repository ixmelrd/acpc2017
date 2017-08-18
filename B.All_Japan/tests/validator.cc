#include"./testlib.h"
#include"./constraints.hpp"
#include<cassert>

int main(){
	registerValidation();
	int N_CNT=inf.readint(MIN_N,MAX_N);
	int D_CNT=inf.readint(MIN_D,MAX_D);
	int pret=1;
	for(int i=0; i<N_CNT;i++){
		pret=inf.readint(pret+1,MAX_T);
		inf.readSpace();
		inf.readint(MIN_F,MAX_F);
	}
	inf.readEoln();
	inf.readEof();

	
}
