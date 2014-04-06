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
#include "Clrf.h"
#include "CException.h"


char unsigned FSR[0x1000];

/**
  *
  *	Name		: CLRF
  *	Input		: f{,a}
  *	Operation	: 000h->f, 1->Z
  *	Destroy		: Z
  *
 */ 

int clrf(Bytecode *code){
	if(code->operand1 >= 0x00 && code->operand1 <= 0xfff){
		if(code->operand2 >= -5 && code->operand2 <= 1 && code->operand2 != -2 && code->operand2 != -3){
			if(code->operand3 == -1){
				if(code->operand2 == ACCESS || code->operand2 == -1 || code->operand2 == 0){
					if(code->operand1 < 0x80){
						FSR[code->operand1] = 0;
						if(FSR[code->operand1] == 0){							//Status Affect: Z
							FSR[STATUS] = FSR[STATUS] | 0b00000100;
						}
						return code->absoluteAddress += 1;
					}
					else{
						FSR[code->operand1 + (0x0F00)] = 0;
						if(FSR[code->operand1 + (0x0F00)] == 0){				//Status Affect: Z
							FSR[STATUS] = FSR[STATUS] | 0b00000100;
						}
						return code->absoluteAddress += 1;
					}
				}else{
					if(FSR[BSR] >= 0 && FSR[BSR] <= 15){
						FSR[code->operand1 + (FSR[BSR]<<8)] = 0;
						if(FSR[code->operand1 + (FSR[BSR]<<8)] == 0){			//Status Affect: Z
							FSR[STATUS] = FSR[STATUS] | 0b00000100;
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
