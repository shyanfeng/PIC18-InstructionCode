#include "unity.h"
#include "Movf.h"
#include "CException.h"
#include "Bytecode.h"


void setUp() {}

void tearDown() {}



void test_movf_should_throw_error_exception_if_operand1_over_range(){



  Instruction inst = {

                      .mnemonic = MOVF,

                      .name = "movf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0xffff,

     .operand2 = 0,

     .operand3 = ACCESS

                  };

  int exception;





  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

 movf(&code);

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

 UnityAssertEqualNumber((_U_SINT)((ERROR_RANGE)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)27, UNITY_DISPLAY_STYLE_INT);

  }

}



void test_movf_should_throw_error_exception_if_operand2_more_than_1_and_less_than_negative_5(){



  Instruction inst = {

                      .mnemonic = MOVF,

                      .name = "movf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x40,

     .operand2 = -1,

     .operand3 = ACCESS

                  };

  int exception;





  FSR[code.operand1] = 0x53;





  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

 movf(&code);

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

 UnityAssertEqualNumber((_U_SINT)((ERROR_OPERAND2)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)52, UNITY_DISPLAY_STYLE_INT);

  }



}



void test_movf_should_throw_error_exception__if_operand3_more_than_negative_5_and_1_and_is_negative_2_and_negative_3(){



  Instruction inst = {

                      .mnemonic = MOVF,

                      .name = "movf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x40,

     .operand2 = 0,

     .operand3 = -3

                  };

  int exception;





  FSR[code.operand1] = 0x23;





  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

 movf(&code);

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

 UnityAssertEqualNumber((_U_SINT)((ERROR_OPERAND3)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)78, UNITY_DISPLAY_STYLE_INT);

  }



}



void test_movf_should_move_fileReg_to_WREG_when_operand1_less_than_0x80_and_operand2_is_0_and_operand3_is_0() {



  Instruction inst = {

                      .mnemonic = MOVF,

                      .name = "movf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x3C,

     .operand2 = 0,

     .operand3 = 0

                  };





  FSR[code.operand1] = 0x22;

  code.absoluteAddress = 0x10;

  movf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x22)), (_U_SINT)(_US8 )((FSR[0xf8b])), (((void *)0)), (_U_UINT)101, UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((_U_SINT)((0b00000000)), (_U_SINT)((FSR[0xFD8])), (((void *)0)), (_U_UINT)102, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x11)), (_U_SINT)(_US8 )((code.absoluteAddress)), (((void *)0)), (_U_UINT)103, UNITY_DISPLAY_STYLE_HEX8);

}



void test_movf_should_move_fileReg_to_WREG_when_operand1_more_than_0x80_and_operand2_is_0_and_operand3_is_0() {



  Instruction inst = {

                      .mnemonic = MOVF,

                      .name = "movf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x8C,

     .operand2 = 0,

     .operand3 = 0

                  };





  FSR[code.operand1 + (0x0F00)] = 0xA2;

  code.absoluteAddress = 0x10;

  movf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xA2)), (_U_SINT)(_US8 )((FSR[0xf8b + (0x0F00)])), (((void *)0)), (_U_UINT)124, UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((_U_SINT)((0b00000000)), (_U_SINT)((FSR[0xFD8])), (((void *)0)), (_U_UINT)125, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x11)), (_U_SINT)(_US8 )((code.absoluteAddress)), (((void *)0)), (_U_UINT)126, UNITY_DISPLAY_STYLE_HEX8);

}



void test_movf_should_move_fileReg_to_fileReg_when_operand1_less_than_0x80_and_operand2_is_F_and_operand3_is_ACCESS() {



  Instruction inst = {

                      .mnemonic = MOVF,

                      .name = "movf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x3C,

     .operand2 = F,

     .operand3 = ACCESS

                  };





  FSR[code.operand1] = 0x56;

  code.absoluteAddress = 0x10;

  movf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x56)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)147, UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((_U_SINT)((0b00000000)), (_U_SINT)((FSR[0xFD8])), (((void *)0)), (_U_UINT)148, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x11)), (_U_SINT)(_US8 )((code.absoluteAddress)), (((void *)0)), (_U_UINT)149, UNITY_DISPLAY_STYLE_HEX8);

}



void test_movf_should_move_fileReg_to_fileReg_when_operand1_more_than_0x80_and_operand2_is_F_and_operand3_is_ACCESS() {



  Instruction inst = {

                      .mnemonic = MOVF,

                      .name = "movf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0xD1,

     .operand2 = F,

     .operand3 = BANKED

                  };





  FSR[code.operand1 + (0x0F00)] = 0x56;

  code.absoluteAddress = 0x10;

  movf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x56)), (_U_SINT)(_US8 )((FSR[code.operand1 + (0x0F00)])), (((void *)0)), (_U_UINT)170, UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((_U_SINT)((0b00000000)), (_U_SINT)((FSR[0xFD8])), (((void *)0)), (_U_UINT)171, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x11)), (_U_SINT)(_US8 )((code.absoluteAddress)), (((void *)0)), (_U_UINT)172, UNITY_DISPLAY_STYLE_HEX8);

}



void test_movf_should_move_fileReg_to_WREG_BSR_when_operand2_is_0_and_operand3_is_1() {



  Instruction inst = {

                      .mnemonic = MOVF,

                      .name = "movf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x3C,

     .operand2 = 0,

     .operand3 = 1

                  };





  FSR[0xFE0] = 0x0A;

  FSR[code.operand1 + (FSR[0xFE0]<<8)] = 0x1C;

  code.absoluteAddress = 0x10;

  movf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x1C)), (_U_SINT)(_US8 )((FSR[0xf8b])), (((void *)0)), (_U_UINT)194, UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((_U_SINT)((0b00000000)), (_U_SINT)((FSR[0xFD8])), (((void *)0)), (_U_UINT)195, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x11)), (_U_SINT)(_US8 )((code.absoluteAddress)), (((void *)0)), (_U_UINT)196, UNITY_DISPLAY_STYLE_HEX8);

}



void test_movf_should_move_fileReg_to_fileReg_BSR_when_operand2_is_F_and_operand3_is_BANKED() {



  Instruction inst = {

                      .mnemonic = MOVF,

                      .name = "movf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x9E,

     .operand2 = F,

     .operand3 = BANKED

                  };





  FSR[0xFE0] = 0x0A;

  FSR[code.operand1 + (FSR[0xFE0]<<8)] = 0x5A;

  code.absoluteAddress = 0x10;

  movf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x5A)), (_U_SINT)(_US8 )((FSR[code.operand1 + (FSR[0xFE0]<<8)])), (((void *)0)), (_U_UINT)218, UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((_U_SINT)((0b00000000)), (_U_SINT)((FSR[0xFD8])), (((void *)0)), (_U_UINT)219, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x11)), (_U_SINT)(_US8 )((code.absoluteAddress)), (((void *)0)), (_U_UINT)220, UNITY_DISPLAY_STYLE_HEX8);

}



void test_movf_should_throw_exception_error_BSR_more_than_15() {



  ExceptionError exception;





  Instruction inst = {

                      .mnemonic = MOVF,

                      .name = "movf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x54,

     .operand2 = F,

     .operand3 = BANKED

                  };





  FSR[0xFE0] = 0xff;



  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

 movf(&code);

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

 UnityAssertEqualNumber((_U_SINT)((ERROR_BSR)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)245, UNITY_DISPLAY_STYLE_INT);

  }

}
