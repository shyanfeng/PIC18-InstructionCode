#include "unity.h"
#include "Movf.h"
#include "CException.h"
#include "Bytecode.h"


void setUp() {}

void tearDown() {}



void test_movf_should_move_fileReg_to_WREG() {



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





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x22)), (_U_SINT)(_US8 )((FSR[0xf8b])), (((void *)0)), (_U_UINT)26, UNITY_DISPLAY_STYLE_HEX8);

}



void test_movf_should_move_fileReg_to_fileReg() {



  Instruction inst = {

                      .mnemonic = MOVF,

                      .name = "movf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x3C,

     .operand2 = 1,

     .operand3 = 0

                  };





  FSR[code.operand1] = 0x56;

  movf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x56)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)46, UNITY_DISPLAY_STYLE_HEX8);

}



void test_movf_should_move_fileReg_to_WREG_BSR() {



  Instruction inst = {

                      .mnemonic = MOVF,

                      .name = "movf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x3C,

     .operand2 = 0,

     .operand3 = 1

                  };





  FSR[code.operand1] = 0x1C;

  movf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x1C)), (_U_SINT)(_US8 )((FSR[0xf8b])), (((void *)0)), (_U_UINT)66, UNITY_DISPLAY_STYLE_HEX8);

}



void test_movf_should_move_fileReg_to_fileReg_BSR() {



  Instruction inst = {

                      .mnemonic = MOVF,

                      .name = "movf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x3C,

     .operand2 = 1,

     .operand3 = 1

                  };





  FSR[code.operand1] = 0x5A;

  movf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x5A)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)86, UNITY_DISPLAY_STYLE_HEX8);

}



void test_movf_should_throw_exception_error_BSR_more_than_15() {



  ExceptionError exception;





  Instruction inst = {

                      .mnemonic = MOVF,

                      .name = "movf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x54,

     .operand2 = 0,

     .operand3 = 1

                  };





  FSR[0xFE0] = 0xff;



  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

 movf(&code);

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

 UnityAssertEqualNumber((_U_SINT)((ERROR_BSR)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)111, UNITY_DISPLAY_STYLE_INT);

  }

}



void test_movf_operand1_should_throw_exception_error_more_than_255_or_less_than_0(){

  ExceptionError exception;





  Instruction inst = {

                      .mnemonic = MOVF,

                      .name = "movf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0xfff,

     .operand2 = 0,

     .operand3 = 1

                  };







  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

 movf(&code);

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

 UnityAssertEqualNumber((_U_SINT)((ERROR_RANGE)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)135, UNITY_DISPLAY_STYLE_INT);

  }

}



void test_movf_operand3_has_valid_value_while_operand2_is_negative_1_should_throw_exception_error(){

  ExceptionError exception;





  Instruction inst = {

                      .mnemonic = MOVF,

                      .name = "movf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x2A,

     .operand2 = -1,

     .operand3 = 0

                  };







  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

 movf(&code);

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

 UnityAssertEqualNumber((_U_SINT)((ERROR_OPERAND2)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)159, UNITY_DISPLAY_STYLE_INT);

  }

}



void test_movf_operand2_has_valid_value_while_operand3_is_negative_1_should_throw_exception_error(){

  ExceptionError exception;





  Instruction inst = {

                      .mnemonic = MOVF,

                      .name = "movf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x2A,

     .operand2 = 0,

     .operand3 = -1

                  };







  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

 movf(&code);

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

 UnityAssertEqualNumber((_U_SINT)((ERROR_OPERAND3)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)183, UNITY_DISPLAY_STYLE_INT);

  }

}



void test_movf_operand2_and_operand3_is_negative_1_should_throw_exception_error(){

  ExceptionError exception;





  Instruction inst = {

                      .mnemonic = MOVF,

                      .name = "movf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x7D,

     .operand2 = -1,

     .operand3 = -1

                  };







  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

 movf(&code);

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

 UnityAssertEqualNumber((_U_SINT)((ERROR_OPERAND2andOPERAND3)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)207, UNITY_DISPLAY_STYLE_INT);

  }

}