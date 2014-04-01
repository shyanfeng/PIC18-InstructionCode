#include <stdio.h>
#include "Bytecode.h"
#include "Negf.h"
#include "CException.h"

char unsigned FSR[0x1000];

void negf(Bytecode *code){
	if(code->operand1 >= 0 && code->operand1 <= 255){
		if(code->operand2 >= -5 && code->operand2 <= 1){
			if(code->operand3 >= -5 && code->operand3 <= 1){
				if(code->operand3 == -1){
					if(code->operand2 == ACCESS || code->operand2 == -1 || code->operand2 == 0){
						if(code->operand1 < 0x80){
							printf("aaa");
							FSR[code->operand1] = ~(FSR[code->operand1]) + 1;
							if(FSR[code->operand1] <= -1){								//Status Affect: N
								FSR[STATUS] == FSR[STATUS] | 0b00010000;
							}else if(FSR[code->operand1] >= 0x81){						//Status Affect: OV
								FSR[STATUS] == FSR[STATUS] | 0b00001000;
							}else if(FSR[code->operand1] == 0){							//Status Affect: Z
								FSR[STATUS] == FSR[STATUS] | 0b00000100;
							}else if(FSR[code->operand1] == 0x0F){						//Status Affect: DC
								FSR[STATUS] == FSR[STATUS] | 0b00000010;
							}else if(FSR[code->operand1] == 0xFF){						//Status Affect: C
								FSR[STATUS] == FSR[STATUS] | 0b00000001;
							}
						}
						else{
							FSR[code->operand1 + (0x0F00)] = ~(FSR[code->operand1 + (0x0F00)]) + 1;
							if(FSR[code->operand1 + (0x0F00)] <= -1){					//Status Affect: N
								FSR[STATUS] == FSR[STATUS] | 0b00010000;	
							}else if(FSR[code->operand1 + (0x0F00)] >= 0x81){			//Status Affect: OV
								FSR[STATUS] == FSR[STATUS] | 0b00001000;
							}else if(FSR[code->operand1 + (0x0F00)] == 0){				//Status Affect: Z
								FSR[STATUS] == FSR[STATUS] | 0b0000100;
							}else if(FSR[code->operand1] == 0x0F){						//Status Affect: DC
								FSR[STATUS] == FSR[STATUS] | 0b00000010;
							}else if(FSR[code->operand1] == 0xFF){						//Status Affect: C
								FSR[STATUS] == FSR[STATUS] | 0b00000001;
							}
						}
					}else{
						if(FSR[BSR] >= 0 && FSR[BSR] <= 15){
							FSR[code->operand1 + (FSR[BSR]<<8)] = ~(FSR[code->operand1 + (FSR[BSR]<<8)]) + 1;
							if(FSR[code->operand1 + (FSR[BSR]<<8)] <= -1){					//Status Affect: N
								FSR[STATUS] == FSR[STATUS] | 0b00010000;				
							}else if(FSR[code->operand1 + (FSR[BSR]<<8)] >= 0x81){		//Status Affect: OV
								FSR[STATUS] == FSR[STATUS] | 0b00001000;
							}else if(FSR[code->operand1 + (FSR[BSR]<<8)] == 0){			//Status Affect: Z
								FSR[STATUS] == FSR[STATUS] | 0b0000100;
							}else if(FSR[code->operand1 + (FSR[BSR]<<8)] == 0x0F){		//Status Affect: DC
								FSR[STATUS] == FSR[STATUS] | 0b00000010;
							}else if(FSR[code->operand1 + (FSR[BSR]<<8)] == 0xFF){		//Status Affect: C
								FSR[STATUS] == FSR[STATUS] | 0b00000001;
							}
						}
						else
							Throw(ERROR_BSR);
					}
				}
				if(code->operand2 == -1){
					if(code->operand3 == ACCESS || code->operand3 == -1 || code->operand3 == 0){
						if(code->operand1 < 0x80){
							FSR[code->operand1] = ~(FSR[code->operand1]) + 1;
							if(FSR[code->operand1] <= -1){								//Status Affect: N
								FSR[STATUS] == FSR[STATUS] | 0b00010000;
							}else if(FSR[code->operand1] >= 0x81){						//Status Affect: OV
								FSR[STATUS] == FSR[STATUS] | 0b00001000;
							}else if(FSR[code->operand1] == 0){							//Status Affect: Z
								FSR[STATUS] == FSR[STATUS] | 0b00000100;
							}else if(FSR[code->operand1] == 0x0F){						//Status Affect: DC
								FSR[STATUS] == FSR[STATUS] | 0b00000010;
							}else if(FSR[code->operand1] == 0xFF){						//Status Affect: C
								FSR[STATUS] == FSR[STATUS] | 0b00000001;
							}
						}
						else{
							FSR[code->operand1 + (0x0F00)] = ~(FSR[code->operand1 + (0x0F00)]) + 1;
							if(FSR[code->operand1 + (0x0F00)] <= -1){					//Status Affect: N
								FSR[STATUS] == FSR[STATUS] | 0b00010000;	
							}else if(FSR[code->operand1 + (0x0F00)] >= 0x81){			//Status Affect: OV
								FSR[STATUS] == FSR[STATUS] | 0b00001000;
							}else if(FSR[code->operand1 + (0x0F00)] == 0){				//Status Affect: Z
								FSR[STATUS] == FSR[STATUS] | 0b0000100;
							}else if(FSR[code->operand1] == 0x0F){						//Status Affect: DC
								FSR[STATUS] == FSR[STATUS] | 0b00000010;
							}else if(FSR[code->operand1] == 0xFF){						//Status Affect: C
								FSR[STATUS] == FSR[STATUS] | 0b00000001;
							}
						}
					}else{
						if(FSR[BSR] >= 0 && FSR[BSR] <= 15){
							FSR[code->operand1 + (FSR[BSR]<<8)] = ~(FSR[code->operand1 + (FSR[BSR]<<8)]) + 1;
							if(FSR[code->operand1 + (FSR[BSR]<<8)] <= -1){					//Status Affect: N
								FSR[STATUS] == FSR[STATUS] | 0b00010000;				
							}else if(FSR[code->operand1 + (FSR[BSR]<<8)] >= 0x81){			//Status Affect: OV
								FSR[STATUS] == FSR[STATUS] | 0b00001000;
							}else if(FSR[code->operand1 + (FSR[BSR]<<8)] == 0){				//Status Affect: Z
								FSR[STATUS] == FSR[STATUS] | 0b0000100;
							}else if(FSR[code->operand1 + (FSR[BSR]<<8)] == 0x0F){			//Status Affect: DC
								FSR[STATUS] == FSR[STATUS] | 0b00000010;
							}else if(FSR[code->operand1 + (FSR[BSR]<<8)] == 0xFF){			//Status Affect: C
								FSR[STATUS] == FSR[STATUS] | 0b00000001;
							}
						}
						else
							Throw(ERROR_BSR);
					}
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
	/*if(code->operand1 <= 0 || code->operand1 >= 255){
		Throw(ERROR_RANGE);
	}else{
		if((code->operand2 == 1 || code->operand2 == 0) && (code->operand3 == 0 || code->operand3 == 1)){
			Throw(ERROR_OPERAND2);
		}else if(code->operand2 == -1 && code->operand3 == -1){
			Throw(ERROR_OPERAND3);
		}else if((code->operand2 == 1 || code->operand2 == 0) && code->operand3 == -1){
			Throw(ERROR_OPERAND2andOPERAND3);
		}else if(FSR[BSR] > 15){
			Throw(ERROR_BSR);
		}else{
			if(code->operand3 == 0){
				FSR[code->operand1] = ~(FSR[code->operand1]) + 1;
			}else{
				FSR[code->operand1] = ~(FSR[code->operand1 + (FSR[BSR]<<8)]) + 1;
			}
		}
	}
}*/