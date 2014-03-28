#include "unity.h"
#include "Movf.h"
#include "CException.h"
#include "Bytecode.h"


void setUp() {}

void tearDown() {}



void test_movf_should_throw_error_exception__if_operand1_over_range(){



  Instruction inst = {

                      .mnemonic = MOVF,

                      .name = "movf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0xfff,

     .operand2 = 0,

     .operand3 = ACCESS

                  };

  int exception;





  FSR[code.operand1] = 0x53;





  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

 movf(&code);

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

 UnityAssertEqualNumber((_U_SINT)((ERROR_RANGE)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)30, UNITY_DISPLAY_STYLE_INT);

  }

}



void test_movf_should_throw_error_exception__if_operand2_more_than_7_and_less_than_0(){



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

 UnityAssertEqualNumber((_U_SINT)((ERROR_OPERAND2)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)55, UNITY_DISPLAY_STYLE_INT);

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

 UnityAssertEqualNumber((_U_SINT)((ERROR_OPERAND3)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)81, UNITY_DISPLAY_STYLE_INT);

  }



}



void test_movf_should_move_fileReg_to_WREG_when_operand1_less_than_0x80() {



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

  movf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x22)), (_U_SINT)(_US8 )((FSR[0xf8b])), (((void *)0)), (_U_UINT)103, UNITY_DISPLAY_STYLE_HEX8);

}



void test_movf_should_move_fileReg_to_WREG_when_operand1_more_than_0x80() {



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

  movf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xA2)), (_U_SINT)(_US8 )((FSR[0xf8b + (0x0F00)])), (((void *)0)), (_U_UINT)123, UNITY_DISPLAY_STYLE_HEX8);

}



void test_movf_should_move_fileReg_to_fileReg_when_operand1_less_than_0x80() {



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

  movf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x56)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)143, UNITY_DISPLAY_STYLE_HEX8);

}



void test_movf_should_move_fileReg_to_fileReg_when_operand1_more_than_0x80() {



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

  movf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x56)), (_U_SINT)(_US8 )((FSR[code.operand1 + (0x0F00)])), (((void *)0)), (_U_UINT)163, UNITY_DISPLAY_STYLE_HEX8);

}



void test_movf_should_move_fileReg_to_WREG_BSR_when_operand1_more_than_0x80() {



  Instruction inst = {

                      .mnemonic = MOVF,

                      .name = "movf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x3C,

     .operand2 = 0,

     .operand3 = 1

                  };





  FSR[code.operand1 + (FSR[0xFE0]<<8)] = 0x1C;

  movf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x1C)), (_U_SINT)(_US8 )((FSR[0xf8b])), (((void *)0)), (_U_UINT)183, UNITY_DISPLAY_STYLE_HEX8);

}



void test_movf_should_move_fileReg_to_fileReg_BSR() {



  Instruction inst = {

                      .mnemonic = MOVF,

                      .name = "movf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x9E,

     .operand2 = F,

     .operand3 = BANKED

                  };





  FSR[code.operand1 + (FSR[0xFE0]<<8)] = 0x5A;

  movf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x5A)), (_U_SINT)(_US8 )((FSR[code.operand1 + (FSR[0xFE0]<<8)])), (((void *)0)), (_U_UINT)203, UNITY_DISPLAY_STYLE_HEX8);

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

 UnityAssertEqualNumber((_U_SINT)((ERROR_BSR)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)228, UNITY_DISPLAY_STYLE_INT);

  }

}
