#include <stdio.h>
#include "Bytecode.h"
#include "Clrf.h"


char FSR[0x1000];

void clrf(Bytecode *code){
	
	if(code->operand2 == 0){
		FSR[code->operand1] = 0;
	}else{
		FSR[code->operand1 + (FSR[BSR]<<8)] = 0;
	}

}