/**
 * Author: Lee Shyan Feng
 * Email: shyanfeng@gmail.com
 * Date: 2/3/2014
 * Project name: PIC18 simulator
 * Programme: Microeletronic with Embedded Technology
 * Institution: Tunku Abdul Rahman University College
 * Copyright: GPLv3
 */

#include <stdio.h>
#include "Bytecode.h"
#include "Negf.h"
#include "CException.h"

char unsigned FSR[0x1000];

/**
  *
  *	Name		: NEGF
  *	Input		: f{,a}
  *	Operation	: ~(F) + 1 -> f
  *	Destroy		: N, OV, C, DC, Z
  *
 */ 

int negf(Bytecode *code){
	int temp1;
	
	if(code->operand1 >= 0x00 && code->operand1 <= 0xfff){
		if(code->operand2 >= -5 && code->operand2 <= 1){
			if(code->operand3 == -1){
				if(code->operand2 == ACCESS || code->operand2 == -1 || code->operand2 == 0){
					if(code->operand1 < 0x80){
						temp1 = ~(FSR[code->operand1]) + 1;
						FSR[code->operand1] = temp1;
						if(FSR[code->operand1] <= -1){							//Status Affect: N
							FSR[STATUS] = FSR[STATUS] | 0b00010000;
						}
						if((temp1 >> 7) != (temp1 >>8)){						//Status Affect: OV
							FSR[STATUS] = FSR[STATUS] | 0b00001000;
						}
						if(FSR[code->operand1] == 0){							//Status Affect: Z
							FSR[STATUS] = FSR[STATUS] | 0b00000100;
						}
						if(FSR[code->operand1] & 0x0f){							//Status Affect: DC
							FSR[STATUS] = FSR[STATUS] | 0b00000010;
						}
						if((temp1 >> 9) == 1){									//Status Affect: C
							FSR[STATUS] = FSR[STATUS] | 0b00000001;
						}
						return code->absoluteAddress += 1;
					}
					else{
						temp1 = ~(FSR[code->operand1 + (0x0F00)]) + 1;
						FSR[code->operand1 + (0x0F00)] = temp1;
						if(FSR[code->operand1 + (0x0F00)] <= -1){				//Status Affect: N
							FSR[STATUS] = FSR[STATUS] | 0b00010000;	
						}
						if((temp1 >> 7) != (temp1 >> 8)){						//Status Affect: OV
							FSR[STATUS] = FSR[STATUS] | 0b00001000;
						}
						if(FSR[code->operand1 + (0x0F00)] == 0){				//Status Affect: Z
							FSR[STATUS] = FSR[STATUS] | 0b0000100;
						}
						if(FSR[code->operand1 + (0x0F00)] & 0x0f){				//Status Affect: DC
							FSR[STATUS] = FSR[STATUS] | 0b00000010;
						}
						if((temp1 >> 9) == 1){									//Status Affect: C
							FSR[STATUS] = FSR[STATUS] | 0b00000001;
						}
						return code->absoluteAddress += 1;
					}
				}else{
					if(FSR[BSR] >= 0 && FSR[BSR] <= 15){
						temp1 = ~(FSR[code->operand1 + (FSR[BSR]<<8)]) + 1;
						FSR[code->operand1 + (FSR[BSR]<<8)] = temp1;
						if(FSR[code->operand1 + (FSR[BSR]<<8)] <= -1){			//Status Affect: N
							FSR[STATUS] = FSR[STATUS] | 0b00010000;				
						}
						if((temp1 >> 7) != (temp1 >> 8)){						//Status Affect: OV
							FSR[STATUS] = FSR[STATUS] | 0b00001000;
						}
						if(FSR[code->operand1 + (FSR[BSR]<<8)] == 0){			//Status Affect: Z
							FSR[STATUS] = FSR[STATUS] | 0b0000100;
						}
						if(FSR[code->operand1 + (FSR[BSR]<<8)] & 0x0f){			//Status Affect: DC
							FSR[STATUS] = FSR[STATUS] | 0b00000010;
						}
						if((temp1 >> 9) == 1){									//Status Affect: C
							FSR[STATUS] = FSR[STATUS] | 0b00000001;
						}
						return code->absoluteAddress += 1;
					}
					else
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
