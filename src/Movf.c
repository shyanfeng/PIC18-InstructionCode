#include <stdio.h>
#include "Bytecode.h"
#include "Movf.h"
#include "CException.h"

char unsigned FSR[0x1000];

void movf(Bytecode *code){
	if(code->operand1 <= 0 || code->operand1 >= 255){
		Throw(ERROR_RANGE);
	}else{
		if(code->operand2 == -1 && code->operand3 == -1){
			Throw(ERROR_OPERAND2andOPERAND3);
		}else if((code->operand2 == 0 || code->operand2 == 1) && code->operand3 == -1){
			Throw(ERROR_OPERAND3);
		}else if((code->operand3 == 0 || code->operand3 == 1) && code->operand2 == -1){
			Throw(ERROR_OPERAND2);
		}else if(FSR[BSR] > 15){
			Throw(ERROR_BSR);
		}else{
			if(code->operand2 == 0){
				if(code->operand3 == 0){
					FSR[WREG] = FSR[code->operand1];
				}else{
					FSR[WREG] = FSR[code->operand1 + (FSR[BSR]<<8)];
				}
			}else{
				if(code->operand3 == 0){
					FSR[code->operand1] = FSR[code->operand1];
				}else{
					FSR[code->operand1] = FSR[code->operand1 + (FSR[BSR]<<8)];
				}
			}
		}
	}
}