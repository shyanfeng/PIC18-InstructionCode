/**
 * Author: Lee Shyan Feng
 * Email: shyanfeng@gmail.com
 * Date: 2/3/2014
 * Project name: PIC18 simulator
 * Programme: Microeletronic with Embedded Technology
 * Institution: Tunku Abdul Rahman University College
 * Copyright: GPLv3
 */

#ifndef	__BYTECODE_H__
#define	__BYTECODE_H__

int pc;
extern int pc;

typedef enum	{
					ERROR_RANGE,
					ERROR_BSR,
					ERROR_OPERAND2,
					ERROR_OPERAND3,
				}ExceptionError;

typedef enum	{
					ACCESS = -5,
					BANKED = -4,
					F = -3,
					W = -2
				}SyntaxError;
				
typedef enum 	{
					CLRF,
					CPFSLT,
					INCF,
					MOVF,
					NEGF,
					RRNCF,
					SUBWFB,
					BCF,
					BNN,
					BRA
				} Mnemonic;
				
typedef struct {
	Mnemonic	mnemonic;
	char *name;
} Instruction;

typedef struct {
	Instruction *instruction;
	int operand1;
	int operand2;
	int operand3;
	int absoluteAddress;
} Bytecode;


#endif	// __BYTECODE_H__
