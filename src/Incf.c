#include <stdio.h>
#include "Bytecode.h"
#include "Incf.h"
#include "CException.h"


char unsigned FSR[0x1000];

void incf(Bytecode *code){
	if(code->operand1 >= 0 && code->operand1 <= 255){
		if(code->operand2 >= -5 && code->operand2 <= 1){
			if(code->operand3 >= -5 && code->operand3 <= 1){
				if(code->operand3 == ACCESS || code->operand3 == -1 || code->operand3 == 0){
					if(code->operand2 == 1 || code->operand2 == F ||code->operand3 == -1){
						if(code->operand1 < 0x80){
							FSR[code->operand1] = FSR[code->operand1] + 1;
							if(FSR[code->operand1] <= -1){
								FSR[STATUS] == FSR[STATUS] | 0b00010000;
							}else if(FSR[code->operand1] >= 0x81){
								FSR[STATUS] == FSR[STATUS] | 0b00001000;
							}else if(FSR[code->operand1] == 0){
								FSR[STATUS] == FSR[STATUS] | 0b0000100;
							}
						}else{
							FSR[code->operand1 + (0x0F00)] = FSR[code->operand1 + (0x0F00)] + 1;
							if(FSR[code->operand1 + (0x0F00)] <= -1){
								FSR[STATUS] == FSR[STATUS] | 0b00010000;
							}else if(FSR[code->operand1 + (0x0F00)] >= 0x81){
								FSR[STATUS] == FSR[STATUS] | 0b00001000;
							}else if(FSR[code->operand1 + (0x0F00)] == 0){
								FSR[STATUS] == FSR[STATUS] | 0b0000100;
							}
						}
					}
					else{
						if(code->operand1 < 0x80){
							FSR[WREG] = FSR[code->operand1] + 1;
							if(FSR[WREG] <= -1){
								FSR[STATUS] == FSR[STATUS] | 0b00010000;
							}else if(FSR[WREG] >= 0x81){
								FSR[STATUS] == FSR[STATUS] | 0b00001000;
							}else if(FSR[WREG] == 0){
								FSR[STATUS] == FSR[STATUS] | 0b0000100;
							}
						}else{
							FSR[WREG + (0x0F00)] = FSR[code->operand1 + (0x0F00)] + 1;
							if(FSR[WREG + (0x0F00)] <= -1){
								FSR[STATUS] == FSR[STATUS] | 0b00010000;
							}else if(FSR[WREG + (0x0F00)] >= 0x81){
								FSR[STATUS] == FSR[STATUS] | 0b00001000;
							}else if(FSR[WREG + (0x0F00)] == 0){
								FSR[STATUS] == FSR[STATUS] | 0b0000100;
							}
						}
					}
				}else if(code->operand3 == BANKED || code->operand3 == -4 || code->operand3 == 1){
					if(FSR[BSR] <= 15){
						if(code->operand2 == 1 || code->operand2 == F ||code->operand3 == -1){
							FSR[code->operand1 + (FSR[BSR]<<8)] = FSR[code->operand1 + (FSR[BSR]<<8)] + 1;
								if(FSR[code->operand1 + (FSR[BSR]<<8)] <= -1){
									FSR[STATUS] == FSR[STATUS] | 0b00010000;
								}else if(FSR[code->operand1 + (FSR[BSR]<<8)] > 0xFF){
									FSR[STATUS] == FSR[STATUS] | 0b00001000;
								}else if(FSR[code->operand1 + (FSR[BSR]<<8)] == 0){
									FSR[STATUS] == FSR[STATUS] | 0b0000100;
								}
						}else{
							FSR[WREG] = FSR[code->operand1 + (FSR[BSR]<<8)] + 1;
							if(FSR[WREG] <= -1){
								FSR[STATUS] == FSR[STATUS] | 0b00010000;
							}else if(FSR[WREG] >= 0x81){
								FSR[STATUS] == FSR[STATUS] | 0b00001000;
							}else if(FSR[WREG] == 0){
								FSR[STATUS] == FSR[STATUS] | 0b0000100;
							}
						}
					}
					else
						Throw(ERROR_BSR);
				}else if(code->operand2 == -1 && code->operand3 == -1){
					code->operand2 = F;
					code->operand3 = ACCESS;
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
	