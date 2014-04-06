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
#include "Bnn.h"
#include "CException.h"

char unsigned FSR[0x1000];

/**
  *
  *	Name		: BNN
  *	Input		: n
  *	Operation	: If Negative bit is 0
  *	Destroy		: None
  *
 */ 

int bnn(Bytecode *code){

	if(code->operand1 >= -128 && code->operand1 <= 127){
		if(FSR[STATUS] == 0b00010000){
			return code->absoluteAddress++;
		}
		else{
			return code->operand1;
		}
	}
	else
		Throw(ERROR_RANGE);

}