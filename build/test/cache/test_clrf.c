#include "unity.h"
#include "Clrf.h"
#include "CException.h"
#include "Bytecode.h"


void setUp() {}

void tearDown() {}



void test_clrf_should_throw_error_exception__if_operand1_over_range(){



  Instruction inst = {

                      .mnemonic = CLRF,

                      .name = "clrf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0xffff,

     .operand2 = 0,

     .operand3 = ACCESS

                  };

  int exception;





  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

 clrf(&code);

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

 UnityAssertEqualNumber((_U_SINT)((ERROR_RANGE)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)27, UNITY_DISPLAY_STYLE_INT);

  }



}



void test_clrf_should_throw_error_exception__if_operand2_more_than_1_and_less_than_negative_5(){



  Instruction inst = {

                      .mnemonic = CLRF,

                      .name = "clrf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x40,

     .operand2 = 5,

     .operand3 = 0

                  };

  int exception;





  FSR[code.operand1] = 0x53;





  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

 clrf(&code);

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

 UnityAssertEqualNumber((_U_SINT)((ERROR_OPERAND2)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)53, UNITY_DISPLAY_STYLE_INT);

  }



}



void test_clrf_should_clear_fileReg_when_operand2_is_empty_and_operand3_is_empty() {

  ExceptionError exception;



  Instruction inst = {

                      .mnemonic = CLRF,

                      .name = "clrf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x41,

     .operand2 = -1,

     .operand3 = -1

                  };





  FSR[code.operand1] = 0x34;

  code.absoluteAddress = 0x10;

  clrf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)77, UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((_U_SINT)((0b00000100)), (_U_SINT)((FSR[0xFD8])), (((void *)0)), (_U_UINT)78, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x11)), (_U_SINT)(_US8 )((code.absoluteAddress)), (((void *)0)), (_U_UINT)79, UNITY_DISPLAY_STYLE_HEX8);

}



void test_clrf_should_clear_fileReg_when_operand1_is_less_than_0x80_and_operand2_is_0_and_operand3_is_empty() {



  Instruction inst = {

                      .mnemonic = CLRF,

                      .name = "clrf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x40,

     .operand2 = 0,

     .operand3 = -1

                  };





  FSR[code.operand1] = 0x45;

  code.absoluteAddress = 0x10;

  clrf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)100, UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((_U_SINT)((0b00000100)), (_U_SINT)((FSR[0xFD8])), (((void *)0)), (_U_UINT)101, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x11)), (_U_SINT)(_US8 )((code.absoluteAddress)), (((void *)0)), (_U_UINT)102, UNITY_DISPLAY_STYLE_HEX8);

}



void test_clrf_should_clear_fileReg_when_operand1_is_more_than_0x80_and_operand2_is_ACCESS_and_operand3_is_empty() {



  Instruction inst = {

                      .mnemonic = CLRF,

                      .name = "clrf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0xEF,

     .operand2 = ACCESS,

     .operand3 = -1

                  };





  FSR[code.operand1 + (0x0F00)] = 0x45;

  code.absoluteAddress = 0x10;

  clrf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[code.operand1 + (0x0F00)])), (((void *)0)), (_U_UINT)123, UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((_U_SINT)((0b00000100)), (_U_SINT)((FSR[0xFD8])), (((void *)0)), (_U_UINT)124, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x11)), (_U_SINT)(_US8 )((code.absoluteAddress)), (((void *)0)), (_U_UINT)125, UNITY_DISPLAY_STYLE_HEX8);

}



void test_clrf_should_clear_BSR_is_more_than_0_and_less_than_15_when_operand2_is_BANKED_and_operand3_is_empty() {



  Instruction inst = {

                      .mnemonic = CLRF,

                      .name = "clrf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0xA2,

     .operand2 = BANKED,

     .operand3 = -1

                  };





  FSR[code.operand1 +(FSR[0xFE0]<<8)] = 0x8F;

  code.absoluteAddress = 0x10;

  FSR[0xFE0] = 0x0F;

  clrf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[code.operand1 + (FSR[0xFE0]<<8)])), (((void *)0)), (_U_UINT)147, UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((_U_SINT)((0b00000100)), (_U_SINT)((FSR[0xFD8])), (((void *)0)), (_U_UINT)148, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x11)), (_U_SINT)(_US8 )((code.absoluteAddress)), (((void *)0)), (_U_UINT)149, UNITY_DISPLAY_STYLE_HEX8);

}



void test_clrf_should_throw_exception_when_operand3_is_not_empty() {



  ExceptionError exception;





  Instruction inst = {

                      .mnemonic = CLRF,

                      .name = "clrf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x54,

     .operand2 = 1,

     .operand3 = 1

                  };





  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

 clrf(&code);

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

 UnityAssertEqualNumber((_U_SINT)((ERROR_OPERAND3)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)172, UNITY_DISPLAY_STYLE_INT);

  }



}



void test_clrf_should_throw_exception_error_BSR_more_than_15() {



  ExceptionError exception;





  Instruction inst = {

                      .mnemonic = CLRF,

                      .name = "clrf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x54,

     .operand2 = 1,

     .operand3 = -1

                  };





  FSR[0xFE0] = 0xff;



  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

 clrf(&code);

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

 UnityAssertEqualNumber((_U_SINT)((ERROR_BSR)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)199, UNITY_DISPLAY_STYLE_INT);

  }



}
