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

                    .operand1 = 0xffff,

     .operand2 = 0,

     .operand3 = ACCESS

                  };

  int exception;





  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

 incf(&code);

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

 UnityAssertEqualNumber((_U_SINT)((ERROR_RANGE)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)27, UNITY_DISPLAY_STYLE_INT);

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

 UnityAssertEqualNumber((_U_SINT)((ERROR_OPERAND2)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)53, UNITY_DISPLAY_STYLE_INT);

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

 UnityAssertEqualNumber((_U_SINT)((ERROR_OPERAND3)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)79, UNITY_DISPLAY_STYLE_INT);

  }



}



void test_incf_should_increment_fileReg_and_store_in_fileReg_when_operand1_less_than_0x80_and_operand2_is_1_and_operand3_is_ACCESS() {



  Instruction inst = {

                      .mnemonic = INCF,

                      .name = "incf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x36,

     .operand2 = 1,

     .operand3 = ACCESS

                  };





  FSR[code.operand1] = 0x12;

  code.absoluteAddress = 0x10;

  incf(&code);







  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x13)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)103, UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x11)), (_U_SINT)(_US8 )((code.absoluteAddress)), (((void *)0)), (_U_UINT)104, UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((_U_SINT)((0b00000000)), (_U_SINT)((FSR[0xFD8])), (((void *)0)), (_U_UINT)105, UNITY_DISPLAY_STYLE_INT);

}



void test_incf_should_increment_fileReg_and_store_in_fileReg_when_operand1_more_than_0x80_and_operand2_is_1_and_operand3_is_ACCESS() {



  Instruction inst = {

                      .mnemonic = INCF,

                      .name = "incf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0xB2,

     .operand2 = 1,

     .operand3 = ACCESS

                  };





  FSR[code.operand1 + (0x0F00)] = 0x40;

  code.absoluteAddress = 0x10;

  incf(&code);







  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x41)), (_U_SINT)(_US8 )((FSR[code.operand1 + (0x0F00)])), (((void *)0)), (_U_UINT)127, UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x11)), (_U_SINT)(_US8 )((code.absoluteAddress)), (((void *)0)), (_U_UINT)128, UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((_U_SINT)((0b00000010)), (_U_SINT)((FSR[0xFD8])), (((void *)0)), (_U_UINT)129, UNITY_DISPLAY_STYLE_INT);

}



void test_incf_should_increment_fileReg_and_store_in_WREG_when_operand1_less_than_0x80_and_operand2_is_W_and_operand3_is_ACCESS() {



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

  code.absoluteAddress = 0x10;

  incf(&code);







  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xF2)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)151, UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xF3)), (_U_SINT)(_US8 )((FSR[0xf8b])), (((void *)0)), (_U_UINT)152, UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x11)), (_U_SINT)(_US8 )((code.absoluteAddress)), (((void *)0)), (_U_UINT)153, UNITY_DISPLAY_STYLE_HEX8);

}



void test_incf_should_increment_fileReg_and_store_in_WREG_when_operand1_more_than_0x80_and_operand2_is_W_and_operand3_is_ACCESS() {



  Instruction inst = {

                      .mnemonic = INCF,

                      .name = "incf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x13,

     .operand2 = W,

     .operand3 = ACCESS

                  };





  FSR[code.operand1] = 0x34;

  code.absoluteAddress = 0x10;

  incf(&code);







  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x34)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)175, UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x35)), (_U_SINT)(_US8 )((FSR[0xf8b])), (((void *)0)), (_U_UINT)176, UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x11)), (_U_SINT)(_US8 )((code.absoluteAddress)), (((void *)0)), (_U_UINT)177, UNITY_DISPLAY_STYLE_HEX8);

}



void test_incf_should_increment_fileReg_and_store_in_fileReg_when_BSR_more_than_0_and_less_than_15_and_operand2_is_F_and_operand3_is_BANKED() {



  Instruction inst = {

                      .mnemonic = INCF,

                      .name = "incf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0xB2,

     .operand2 = F,

     .operand3 = BANKED

                  };





  FSR[0xFE0] = 0x0C;

  FSR[code.operand1+(FSR[0xFE0]<<8)] = 0x23;

  code.absoluteAddress = 0x10;

  incf(&code);







  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x24)), (_U_SINT)(_US8 )((FSR[code.operand1+(FSR[0xFE0]<<8)])), (((void *)0)), (_U_UINT)200, UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x11)), (_U_SINT)(_US8 )((code.absoluteAddress)), (((void *)0)), (_U_UINT)201, UNITY_DISPLAY_STYLE_HEX8);

}



void test_incf_should_increment_fileReg_and_store_in_WREG_when_BSR_more_than_0_and_less_than_15_and_operand2_is_W_and_operand3_is_BANKED() {



  Instruction inst = {

                      .mnemonic = INCF,

                      .name = "incf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0xB2,

     .operand2 = W,

     .operand3 = BANKED

                  };





  FSR[0xFE0] = 0x08;

  FSR[code.operand1 + (FSR[0xFE0]<<8)] = 0x56;

  code.absoluteAddress = 0x10;

  incf(&code);







  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x56)), (_U_SINT)(_US8 )((FSR[code.operand1 + (FSR[0xFE0]<<8)])), (((void *)0)), (_U_UINT)224, UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x57)), (_U_SINT)(_US8 )((FSR[0xf8b])), (((void *)0)), (_U_UINT)225, UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x11)), (_U_SINT)(_US8 )((code.absoluteAddress)), (((void *)0)), (_U_UINT)226, UNITY_DISPLAY_STYLE_HEX8);

}



void test_incf_should_increment_fileReg_with_status_affected_and_store_in_fileReg_and_operand2_is_W_and_operand3_is_ACCESS() {



  Instruction inst = {

                      .mnemonic = INCF,

                      .name = "incf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x98,

     .operand2 = F,

     .operand3 = ACCESS

                  };





  FSR[code.operand1 + (0x0F00)] = 0xFF;

  code.absoluteAddress = 0x10;

  incf(&code);







  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[code.operand1 + (0x0F00)])), (((void *)0)), (_U_UINT)248, UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x11)), (_U_SINT)(_US8 )((code.absoluteAddress)), (((void *)0)), (_U_UINT)249, UNITY_DISPLAY_STYLE_HEX8);

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

 UnityAssertEqualNumber((_U_SINT)((ERROR_BSR)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)274, UNITY_DISPLAY_STYLE_INT);

  }



}
