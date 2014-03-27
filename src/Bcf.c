#include <stdio.h>
#include "Bytecode.h"
#include "Bcf.h"
#include "CException.h"


char unsigned FSR[0x1000];

void bcf(Bytecode *code){
	if(code->operand1 >= 0 && code->operand1 <= 255){
		if(code->operand2 >= 0 && code->operand2 <= 7){
			if(code->operand3 >= -5 && code->operand3 <= 1 && code->operand3 != -2 && code->operand3 != -3){
				if(code->operand3 == ACCESS || code->operand3 == -1 || code->operand3 == 0){
					if(code->operand1 < 0x80){
						if(code->operand2 == 0){
							FSR[code->operand1] = FSR[code->operand1]&0b11111110;
						}else if(code->operand2 == 1){
							FSR[code->operand1] = FSR[code->operand1]&0b11111101;
						}else if(code->operand2 == 2){
							FSR[code->operand1] = FSR[code->operand1]&0b11111011;
						}else if(code->operand2 == 3){
							FSR[code->operand1] = FSR[code->operand1]&0b11110111;
						}else if(code->operand2 == 4){
							FSR[code->operand1] = FSR[code->operand1]&0b11101111;
						}else if(code->operand2 == 5){
							FSR[code->operand1] = FSR[code->operand1]&0b11011111;
						}else if(code->operand2 == 6){
							FSR[code->operand1] = FSR[code->operand1]&0b10111111;
						}else if(code->operand2 == 7){
							FSR[code->operand1] = FSR[code->operand1]&0b01111111;
						}else{
							FSR[code->operand1] = FSR[code->operand1]&0b11111111;
						}
					}else{
						if(code->operand2 == 0){
							FSR[code->operand1 + (0x0F00)] = FSR[code->operand1 + (0x0F00)]&0b11111110;
						}else if(code->operand2 == 1){
							FSR[code->operand1 + (0x0F00)] = FSR[code->operand1 + (0x0F00)]&0b11111101;
						}else if(code->operand2 == 2){
							FSR[code->operand1 + (0x0F00)] = FSR[code->operand1 + (0x0F00)]&0b11111011;
						}else if(code->operand2 == 3){
							FSR[code->operand1 + (0x0F00)] = FSR[code->operand1 + (0x0F00)]&0b11110111;
						}else if(code->operand2 == 4){
							FSR[code->operand1 + (0x0F00)] = FSR[code->operand1 + (0x0F00)]&0b11101111;
						}else if(code->operand2 == 5){
							FSR[code->operand1 + (0x0F00)] = FSR[code->operand1 + (0x0F00)]&0b11011111;
						}else if(code->operand2 == 6){
							FSR[code->operand1 + (0x0F00)] = FSR[code->operand1 + (0x0F00)]&0b10111111;
						}else if(code->operand2 == 7){
							FSR[code->operand1 + (0x0F00)] = FSR[code->operand1 + (0x0F00)]&0b01111111;
						}else{
							FSR[code->operand1 + (0x0F00)] = FSR[code->operand1 + (0x0F00)]&0b11111111;
						}
					}
				}
				else{
					if(FSR[BSR] <= 15){
						if(code->operand2 == 0){
							FSR[code->operand1 + (FSR[BSR]<<8)] = FSR[code->operand1 + (FSR[BSR]<<8)]&0b11111110;
						}else if(code->operand2 == 1){
							FSR[code->operand1 + (FSR[BSR]<<8)] = FSR[code->operand1 + (FSR[BSR]<<8)]&0b11111101;
						}else if(code->operand2 == 2){
							FSR[code->operand1 + (FSR[BSR]<<8)] = FSR[code->operand1 + (FSR[BSR]<<8)]&0b11111011;
						}else if(code->operand2 == 3){
							FSR[code->operand1 + (FSR[BSR]<<8)] = FSR[code->operand1 + (FSR[BSR]<<8)]&0b11110111;
						}else if(code->operand2 == 4){
							FSR[code->operand1 + (FSR[BSR]<<8)] = FSR[code->operand1 + (FSR[BSR]<<8)]&0b11101111;
						}else if(code->operand2 == 5){
							FSR[code->operand1 + (FSR[BSR]<<8)] = FSR[code->operand1 + (FSR[BSR]<<8)]&0b11011111;
						}else if(code->operand2 == 6){
							FSR[code->operand1 + (FSR[BSR]<<8)] = FSR[code->operand1 + (FSR[BSR]<<8)]&0b10111111;
						}else if(code->operand2 == 7){
							FSR[code->operand1 + (FSR[BSR]<<8)] = FSR[code->operand1 + (FSR[BSR]<<8)]&0b01111111;
						}else{
							FSR[code->operand1 + (FSR[BSR]<<8)] = FSR[code->operand1 + (FSR[BSR]<<8)]&0b11111111;
						}
					}else
						Throw(ERROR_BSR);
				}
			}
			else
				Throw(ERROR_OPERAND3);
		}
		else
			Throw(ERROR_OPERAND2);
	}
	else
		Throw(ERROR_RANGE);
}