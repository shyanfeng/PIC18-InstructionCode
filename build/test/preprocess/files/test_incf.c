#include "unity.h"
#include "Incf.h"
#include "CException.h"
#include "Bytecode.h"


void setUp() {}

void tearDown() {}



void test_incf_should_throw_error_exception__if_operand1_over_range(){



  Instruction inst = {

                      .mnemonic = INCF,

                      .name = "incf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0xfff,

     .operand2 = 0,

     .operand3 = ACCESS

                  };

  int exception;





  FSR[code.operand1] = 0x53;





  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

 incf(&code);

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

 UnityAssertEqualNumber((_U_SINT)((ERROR_RANGE)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)30, UNITY_DISPLAY_STYLE_INT);

  }



}



void test_incf_should_throw_error_exception__if_operand2_more_than_1_and_less_than_negative_5(){



  Instruction inst = {

                      .mnemonic = INCF,

                      .name = "incf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x40,

     .operand2 = 5,

     .operand3 = 0

                  };

  int exception;





  FSR[code.operand1] = 0x53;





  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

 incf(&code);

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

 UnityAssertEqualNumber((_U_SINT)((ERROR_OPERAND2)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)56, UNITY_DISPLAY_STYLE_INT);

  }



}



void test_incf_should_throw_error_exception__if_operand3_more_than_negative_5_and_1_and_is_negative_2_and_negative_3(){



  Instruction inst = {

                      .mnemonic = INCF,

                      .name = "incf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x40,

     .operand2 = 0,

     .operand3 = -3

                  };

  int exception;





  FSR[code.operand1] = 0x23;





  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

 incf(&code);

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

 UnityAssertEqualNumber((_U_SINT)((ERROR_OPERAND3)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)82, UNITY_DISPLAY_STYLE_INT);

  }



}



void test_incf_should_increment_fileReg_and_store_in_fileReg() {



  Instruction inst = {

                      .mnemonic = INCF,

                      .name = "incf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x36,

     .operand2 = 1,

     .operand3 = ACCESS

                  };





  FSR[code.operand1] = 0x40;

  incf(&code);







  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x41)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)105, UNITY_DISPLAY_STYLE_HEX8);

}



void test_incf_should_increment_fileReg_and_store_in_WREG() {



  Instruction inst = {

                      .mnemonic = INCF,

                      .name = "incf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x13,

     .operand2 = W,

     .operand3 = ACCESS

                  };





  FSR[code.operand1] = 0xF2;

  incf(&code);







  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xF2)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)126, UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xF3)), (_U_SINT)(_US8 )((FSR[0xf8b])), (((void *)0)), (_U_UINT)127, UNITY_DISPLAY_STYLE_HEX8);

}



void test_incf_should_increment_fileReg_and_select_BSR_and_store_in_fileReg() {



  Instruction inst = {

                      .mnemonic = INCF,

                      .name = "incf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0xB2,

     .operand2 = F,

     .operand3 = BANKED

                  };





  FSR[code.operand1] = 0x53;

  FSR[0xFE0] = 0x0C;

  FSR[code.operand1+(FSR[0xFE0]<<8)] = 0x23;

  incf(&code);







  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x24)), (_U_SINT)(_US8 )((FSR[code.operand1+(FSR[0xFE0]<<8)])), (((void *)0)), (_U_UINT)150, UNITY_DISPLAY_STYLE_HEX8);

}



void test_incf_should_increment_fileReg_and_select_BSR_and_store_in_WREG() {



  Instruction inst = {

                      .mnemonic = INCF,

                      .name = "incf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0xB2,

     .operand2 = 0,

     .operand3 = BANKED

                  };





  FSR[code.operand1] = 0x34;

  FSR[0xFE0] = 0x08;

  FSR[code.operand1 + (FSR[0xFE0]<<8)] = 0x56;

  incf(&code);







  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x56)), (_U_SINT)(_US8 )((FSR[code.operand1 + (FSR[0xFE0]<<8)])), (((void *)0)), (_U_UINT)173, UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x57)), (_U_SINT)(_US8 )((FSR[0xf8b])), (((void *)0)), (_U_UINT)174, UNITY_DISPLAY_STYLE_HEX8);

}



void test_incf_should_throw_exception_error_BSR_more_than_15() {



  ExceptionError exception;





  Instruction inst = {

                      .mnemonic = INCF,

                      .name = "incf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0xB2,

     .operand2 = 0,

     .operand3 = 1

                  };





  FSR[0xFE0] = 0xff;



  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

 incf(&code);

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

 UnityAssertEqualNumber((_U_SINT)((ERROR_BSR)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)199, UNITY_DISPLAY_STYLE_INT);

  }



}
