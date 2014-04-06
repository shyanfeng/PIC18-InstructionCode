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
#include "Bra.h"
#include "CException.h"

/**
  *
  *	Name		: BRA
  *	Input		: n
  *	Operation	: (PC) +2 + 2n ->PC
  *	Destroy		: None
  *
 */ 

char unsigned FSR[0x1000];

int bra(Bytecode *code){
	if(code->operand1 >= -1024 && code->operand1 <= 1023){
		return code->operand1;
	}
	else
		Throw(ERROR_RANGE);
}