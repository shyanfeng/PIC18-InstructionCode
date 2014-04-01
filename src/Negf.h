#ifndef	__NEGF_H__
#define	__NEGF_H__

#define WREG	0xf8b
#define	BSR 	0xFE0
#define STATUS	0xFD8

extern unsigned char FSR[];

void negf(Bytecode *code);

#endif	// __NEGF_H__