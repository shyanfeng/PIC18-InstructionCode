/**
 * Author: Lee Shyan Feng
 * Email: shyanfeng@gmail.com
 * Date: 2/3/2014
 * Project name: PIC18 simulator
 * Programme: Microeletronic with Embedded Technology
 * Institution: Tunku Abdul Rahman University College
 * Copyright: GPLv3
 */

#ifndef	__SUBWFB_H__
#define	__SUBWFB_H__

#define WREG	0xf8b
#define	BSR 	0xFE0
#define STATUS	0xFD8

extern unsigned char FSR[];

int subwfb(Bytecode *code);

#endif	// __SUBWFB_H__