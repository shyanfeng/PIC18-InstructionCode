#ifndef	__INCF_H__
#define	__INCF_H__

#define WREG	0xf8b
#define	BSR 	0xFE0
#define STATUS	0xFD8

extern unsigned char FSR[];

void incf(Bytecode *code);

#endif	// __INCF_H__