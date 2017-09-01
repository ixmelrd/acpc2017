#include"./testlib.h"
#include"./constraints.hpp"
#include<cassert>

int main(){
	registerValidation();
	int N_CNT=inf.readInt(MIN_N,MAX_N);
	inf.readSpace();
	int D_CNT=inf.readInt(MIN_D,MAX_D);
	inf.readEoln();
	int pret=1;
	for(int i=0; i<N_CNT;i++){
		pret=inf.readInt(pret+1,MAX_T);
		inf.readSpace();
		inf.readInt(MIN_F,MAX_F);
		inf.readEoln();
	}
	inf.readEoln();
	inf.readEof();

	
}
