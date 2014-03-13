#ifndef	__CLRF_H__
#define	__CLRF_H__

#define WREG	0xf8b
#define	BSR 	0xFE0

extern unsigned char FSR[];

void clrf(Bytecode *code);

#endif	// __CLRF_H__