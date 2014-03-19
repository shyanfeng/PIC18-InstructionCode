#ifndef	__BCF_H__
#define	__BCF_H__

#define WREG	0xf8b
#define	BSR 	0xFE0

extern unsigned char FSR[];

void bcf(Bytecode *code);

#endif	// __BCF_H__