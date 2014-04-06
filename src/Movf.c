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
#include "Movf.h"
#include "CException.h"

char unsigned FSR[0x1000];

/**
  *
  *	Name		: MOVF
  *	Input		: f{,d {,a}}
  *	Operation	: f -> dest
  *	Destroy		: N, Z
  *
 */ 

int movf(Bytecode *code){
	if(code->operand1 >= 0x00 && code->operand1 <= 0xfff){
		if(code->operand2 >= -5 && code->operand2 <= 1){
			if(code->operand3 >= -5 && code->operand3 <= 1){
				if(code->operand3 == ACCESS || code->operand3 == -1 || code->operand3 == 0){
					if(code->operand2 == 1 || code->operand2 == F ||code->operand2 == -1){
						if(code->operand1 < 0x80){
							FSR[code->operand1] = FSR[code->operand1];
							if(FSR[code->operand1] <= -1){											//Status Affect: N
								FSR[STATUS] == FSR[STATUS] | 0b00010000;
							}
							if(FSR[code->operand1] == 0){										//Status Affect: Z
								FSR[STATUS] == FSR[STATUS] | 0b00000100;
							}
							return code->absoluteAddress += 1;
						}else{
							FSR[code->operand1 + (0x0F00)] = FSR[code->operand1 + (0x0F00)];
							if(FSR[code->operand1 + (0x0F00)] <= -1){								//Status Affect: N
								FSR[STATUS] == FSR[STATUS] | 0b00010000;
							}
							if(FSR[code->operand1 + (0x0F00)] == 0){							//Status Affect: Z
								FSR[STATUS] == FSR[STATUS] | 0b00000100;
							}
							return code->absoluteAddress += 1;
						}
					}else{
						if(code->operand1 < 0x80){
							FSR[WREG] = FSR[code->operand1];
							if(FSR[WREG] <= -1){													//Status Affect: N
								FSR[STATUS] == FSR[STATUS] | 0b00010000;
							}
							if(FSR[WREG] == 0){												//Status Affect: Z
								FSR[STATUS] == FSR[STATUS] | 0b00000100;
							}
							return code->absoluteAddress += 1;
						}else{
							FSR[WREG + (0x0F00)] = FSR[code->operand1 + (0x0F00)];
							if(FSR[WREG] + (0x0F00) <= -1){											//Status Affect: N
								FSR[STATUS] == FSR[STATUS] | 0b00010000;
							}
							if(FSR[WREG] + (0x0F00) == 0){									//Status Affect: Z
								FSR[STATUS] == FSR[STATUS] | 0b00000100;
							}
							return code->absoluteAddress += 1;
						}
					}
				}else if(code->operand3 == BANKED || code->operand3 == -4 || code->operand3 == 1){
					if(FSR[BSR] <= 15){
						if(code->operand2 == 1 || code->operand2 == F ||code->operand2 == -1){
							FSR[code->operand1 + (FSR[BSR]<<8)] = FSR[code->operand1 + (FSR[BSR]<<8)];
							if(FSR[code->operand1 + (FSR[BSR]<<8)] <= -1){							//Status Affect: N
								FSR[STATUS] == FSR[STATUS] | 0b00010000;
							}
							if(FSR[code->operand1 + (FSR[BSR]<<8)] == 0){						//Status Affect: Z
								FSR[STATUS] == FSR[STATUS] | 0b00000100;
							}
							return code->absoluteAddress += 1;
						}else{
							FSR[WREG] = FSR[code->operand1 + (FSR[BSR]<<8)];
							if(FSR[WREG] <= -1){													//Status Affect: N
								FSR[STATUS] == FSR[STATUS] | 0b00010000;
							}
							if(FSR[WREG] == 0){												//Status Affect: Z
								FSR[STATUS] == FSR[STATUS] | 0b00000100;
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
