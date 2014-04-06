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
#include "Cpfslt.h"
#include "CException.h"

char unsigned FSR[0x1000];

/**
  *
  *	Name		: CPFSLT
  *	Input		: f{,a}
  *	Operation	: (F)-(W), Skip if (F)<(W)
  *	Destroy		: None
  *
 */ 

int cpfslt(Bytecode *code){
	if(code->operand1 >= 0x00 && code->operand1 <= 0xfff){
		if(code->operand2 >= -5 && code->operand2 <= 1){
			if(code->operand3 == -1){
				if(code->operand2 == ACCESS || code->operand2 == -1 || code->operand2 == 0){
					if(code->operand1 < 0x80){
						if(FSR[code->operand1] < FSR[WREG]){
							return code->absoluteAddress += 2;
						}
						else
							return code->absoluteAddress++;
					}else{
						if(FSR[code->operand1 + (0x0F00)] < FSR[WREG + (0x0F00)]){
							return code->absoluteAddress += 2;
						}
						else
							return code->absoluteAddress++;
					}
				}else{
					if(FSR[BSR] >= 0 && FSR[BSR] <= 15){
						if(code->operand1 > 0x80){
							if(FSR[code->operand1 + (FSR[BSR]<<8)] < FSR[WREG + (FSR[BSR]<<8)]){
								return code->absoluteAddress += 2;
							}
							else
								return code->absoluteAddress++;
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