#include <stdio.h>
#include "Bytecode.h"
#include "Incf.h"


char FSR[0x1000];

void incf(Bytecode *code){
	
	if(code->operand2 == 1){
		if(code->operand3 == 0){
			FSR[code->operand1]++;
		}else{
			FSR[code->operand1 + (FSR[BSR]<<8)]++;
		}
		
	}else{
		if(code->operand3 == 0){
			FSR[WREG] = FSR[code->operand1] + 1;
		}else{
			FSR[WREG] = FSR[code->operand1 + (FSR[BSR]<<8)] + 1;
		}

	}
}