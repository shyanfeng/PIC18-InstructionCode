#include <stdio.h>
#include "Bytecode.h"
#include "Clrf.h"
#include "CException.h"


char unsigned FSR[0x1000];

void clrf(Bytecode *code){
	
	if(code->operand1 <= 0 || code->operand1 >= 255){
		Throw(ERROR_RANGE);
	}else{
		if(code->operand3 == 0){
			FSR[code->operand1] = 0;
		}else{
			if(FSR[BSR] > 15){
				Throw(ERROR_BSR);
			}else{
			FSR[code->operand1 + (FSR[BSR]<<8)] = 0;
			}
		}
	}

}