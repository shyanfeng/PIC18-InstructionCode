#ifndef	__BYTECODE_H__
#define	__BYTECODE_H__

typedef enum	{
					ERROR_RANGE,
					ERROR_BSR,
				}ExceptionError;

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
} Bytecode;


#endif	// __BYTECODE_H__
