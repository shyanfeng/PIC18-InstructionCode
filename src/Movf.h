#ifndef	__MOVF_H__
#define	__MOVF_H__

#define WREG	0xf8b
#define	BSR 	0xFE0

extern unsigned char FSR[];

void movf(Bytecode *code);

#endif	// __MOVF_H__