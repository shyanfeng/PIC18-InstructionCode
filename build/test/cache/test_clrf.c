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

                    .operand1 = 0xfff,

     .operand2 = 0,

     .operand3 = ACCESS

                  };

  int exception;





  FSR[code.operand1] = 0x53;





  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

 clrf(&code);

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

 UnityAssertEqualNumber((_U_SINT)((ERROR_RANGE)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)30, UNITY_DISPLAY_STYLE_INT);

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

 UnityAssertEqualNumber((_U_SINT)((ERROR_OPERAND2)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)56, UNITY_DISPLAY_STYLE_INT);

  }



}



void test_clrf_should_throw_error_exception__if_operand3_more_than_negative_5_and_1_and_is_negative_2_and_negative_3(){



  Instruction inst = {

                      .mnemonic = CLRF,

                      .name = "clrf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x40,

     .operand2 = 0,

     .operand3 = -3

                  };

  int exception;





  FSR[code.operand1] = 0x23;





  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

 clrf(&code);

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

 UnityAssertEqualNumber((_U_SINT)((ERROR_OPERAND3)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)82, UNITY_DISPLAY_STYLE_INT);

  }



}



void test_clrf_should_clear_fileReg_when_operand2_is_empty() {



  Instruction inst = {

                      .mnemonic = CLRF,

                      .name = "clrf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x40,

     .operand2 = -1,

     .operand3 = 0

                  };





  FSR[code.operand1] = 0x45;

  clrf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)104, UNITY_DISPLAY_STYLE_HEX8);

}



void test_clrf_should_clear_BSR_when_operand2_is_empty() {



  Instruction inst = {

                      .mnemonic = CLRF,

                      .name = "clrf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x41,

     .operand2 = -1,

     .operand3 = 1

                  };





  FSR[code.operand1] = 0x8F;

  FSR[0xFE0] = 0x0F;

  clrf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[code.operand1+(FSR[0xFE0]<<8)])), (((void *)0)), (_U_UINT)125, UNITY_DISPLAY_STYLE_HEX8);

}



void test_clrf_should_clear_fileReg_when_operand3_is_empty() {



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

  clrf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)145, UNITY_DISPLAY_STYLE_HEX8);

}



void test_clrf_should_clear_BSR_when_operand3_is_empty() {



  Instruction inst = {

                      .mnemonic = CLRF,

                      .name = "clrf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x41,

     .operand2 = BANKED,

     .operand3 = -1

                  };





  FSR[code.operand1] = 0x8F;

  FSR[0xFE0] = 0x0F;

  clrf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[code.operand1+(FSR[0xFE0]<<8)])), (((void *)0)), (_U_UINT)166, UNITY_DISPLAY_STYLE_HEX8);

}



void test_clrf_should_throw_exception_error_BSR_more_than_15() {



  ExceptionError exception;





  Instruction inst = {

                      .mnemonic = CLRF,

                      .name = "clrf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x54,

     .operand2 = -1,

     .operand3 = 1

                  };





  FSR[0xFE0] = 0xff;



  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

 clrf(&code);

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

 UnityAssertEqualNumber((_U_SINT)((ERROR_BSR)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)191, UNITY_DISPLAY_STYLE_INT);

  }



}
