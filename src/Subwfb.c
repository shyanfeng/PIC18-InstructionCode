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
#include "Subwfb.h"
#include "CException.h"

char unsigned FSR[0x1000];

/**
  *
  *	Name		: SUBWFB
  *	Input		: f{,d {,a}}
  *	Operation	: (F)-(W)-~(C) -> dest
  *	Destroy		: N, OV, C, DC, Z
  *
 */
 
 int subwfb(Bytecode *code){
	int temp1;
	if(code->operand1 >= 0x00 && code->operand1 <= 0xfff){
		if(code->operand2 >= -5 && code->operand2 <= 1){
			if(code->operand3 >= -5 && code->operand3 <= 1){
				if(code->operand3 == ACCESS || code->operand3 == -1 || code->operand3 == 0){
					if(code->operand2 == 1 || code->operand2 == F ||code->operand3 == -1){
						if(code->operand1 < 0x80){
							temp1 = FSR[code->operand1] - FSR[WREG] - ~(FSR[STATUS] & 0b00000001);
							FSR[code->operand1] = temp1;
							if(FSR[code->operand1] <= -1){							//Status Affect: N
								FSR[STATUS] = FSR[STATUS] | 0b00010000;
							}
							if((temp1 >> 7) != (temp1 >> 8)){						//Status Affect: OV
								FSR[STATUS] = FSR[STATUS] | 0b00001000;
							}
							if(FSR[code->operand1] == 0){							//Status Affect: Z
								FSR[STATUS] = FSR[STATUS] | 0b00000100;
							}
							if((FSR[code->operand1] & 0x0f) == 0){					//Status Affect: DC
								FSR[STATUS] = FSR[STATUS] | 0b00000010;
							}
							if((temp1 >> 9) == 1){									//Status Affect: C
								FSR[STATUS] = FSR[STATUS] | 0b00000001;
							}
							return code->absoluteAddress += 1;
						}else{
							temp1 = FSR[code->operand1 + (0x0F00)] - FSR[WREG] - ~(FSR[STATUS] & 0b00000001);
							FSR[code->operand1 + (0x0F00)] = temp1;
							if(FSR[code->operand1 + (0x0F00)] <= -1){							//Status Affect: N
								FSR[STATUS] = FSR[STATUS] | 0b00010000;
							}
							if((temp1 >> 7) != (temp1 >> 8)){						//Status Affect: OV
								FSR[STATUS] = FSR[STATUS] | 0b00001000;
							}
							if(FSR[code->operand1 + (0x0F00)] == 0){							//Status Affect: Z
								FSR[STATUS] = FSR[STATUS] | 0b00000100;
							}
							if((FSR[code->operand1 + (0x0F00)] & 0x0f) == 0){					//Status Affect: DC
								FSR[STATUS] = FSR[STATUS] | 0b00000010;
							}
							if((temp1 >> 9) == 1){									//Status Affect: C
								FSR[STATUS] = FSR[STATUS] | 0b00000001;
							}
							return code->absoluteAddress += 1;
						}
					}else{
						if(code->operand1 < 0x80){
							temp1 = FSR[code->operand1] - FSR[WREG] - ~(FSR[STATUS] & 0b00000001);
							FSR[WREG] = temp1;
							if(FSR[WREG] <= -1){							//Status Affect: N
								FSR[STATUS] = FSR[STATUS] | 0b00010000;
							}
							if((temp1 >> 7) != (temp1 >> 8)){						//Status Affect: OV
								FSR[STATUS] = FSR[STATUS] | 0b00001000;
							}
							if(FSR[WREG] == 0){							//Status Affect: Z
								FSR[STATUS] = FSR[STATUS] | 0b00000100;
							}
							if((FSR[WREG] & 0x0f) == 0){					//Status Affect: DC
								FSR[STATUS] = FSR[STATUS] | 0b00000010;
							}
							if((temp1 >> 9) == 1){									//Status Affect: C
								FSR[STATUS] = FSR[STATUS] | 0b00000001;
							}
							return code->absoluteAddress += 1;
						}else{
							temp1 = FSR[WREG + (0x0F00)] - FSR[WREG] - ~(FSR[STATUS] & 0b00000001);
							FSR[WREG + (0x0F00)] = temp1;
							if(FSR[WREG + (0x0F00)] <= -1){							//Status Affect: N
								FSR[STATUS] = FSR[STATUS] | 0b00010000;
							}
							if((temp1 >> 7) != (temp1 >> 8)){						//Status Affect: OV
								FSR[STATUS] = FSR[STATUS] | 0b00001000;
							}
							if(FSR[WREG + (0x0F00)] == 0){							//Status Affect: Z
								FSR[STATUS] = FSR[STATUS] | 0b00000100;
							}
							if((FSR[WREG + (0x0F00)] & 0x0f) == 0){					//Status Affect: DC
								FSR[STATUS] = FSR[STATUS] | 0b00000010;
							}
							if((temp1 >> 9) == 1){									//Status Affect: C
								FSR[STATUS] = FSR[STATUS] | 0b00000001;
							}
							return code->absoluteAddress += 1;
						}
					}
				}else{
					if(FSR[BSR] <= 15){
						if(code->operand2 == 1 || code->operand2 == F ||code->operand3 == -1){
							temp1 = FSR[code->operand1 + (FSR[BSR]<<8)] - FSR[WREG] - ~(FSR[STATUS] & 0b00000001);
							FSR[code->operand1 + (FSR[BSR]<<8)] = temp1;
							if(FSR[code->operand1 + (FSR[BSR]<<8)] <= -1){							//Status Affect: N
								FSR[STATUS] = FSR[STATUS] | 0b00010000;
							}
							if((temp1 >> 7) != (temp1 >> 8)){						//Status Affect: OV
								FSR[STATUS] = FSR[STATUS] | 0b00001000;
							}
							if(FSR[code->operand1 + (FSR[BSR]<<8)] == 0){							//Status Affect: Z
								FSR[STATUS] = FSR[STATUS] | 0b00000100;
							}
							if((FSR[code->operand1 + (FSR[BSR]<<8)] & 0x0f) == 0){					//Status Affect: DC
								FSR[STATUS] = FSR[STATUS] | 0b00000010;
							}
							if((temp1 >> 9) == 1){									//Status Affect: C
								FSR[STATUS] = FSR[STATUS] | 0b00000001;
							}
							return code->absoluteAddress += 1;
						}else{
							temp1 = FSR[code->operand1 + (FSR[BSR]<<8)] - FSR[WREG] - ~(FSR[STATUS] & 0b00000001);
							FSR[WREG] = temp1;
							if(FSR[code->operand1 + (FSR[BSR]<<8)] <= -1){							//Status Affect: N
								FSR[STATUS] = FSR[STATUS] | 0b00010000;
							}
							if((temp1 >> 7) != (temp1 >> 8)){						//Status Affect: OV
								FSR[STATUS] = FSR[STATUS] | 0b00001000;
							}
							if(FSR[code->operand1 + (FSR[BSR]<<8)] == 0){							//Status Affect: Z
								FSR[STATUS] = FSR[STATUS] | 0b00000100;
							}
							if((FSR[code->operand1 + (FSR[BSR]<<8)] & 0x0f) == 0){					//Status Affect: DC
								FSR[STATUS] = FSR[STATUS] | 0b00000010;
							}
							if((temp1 >> 9) == 1){									//Status Affect: C
								FSR[STATUS] = FSR[STATUS] | 0b00000001;
							}
							return code->absoluteAddress += 1;
						}
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