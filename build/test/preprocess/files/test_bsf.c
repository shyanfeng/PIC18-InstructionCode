#include "unity.h"
#include "CException.h"
#include "Bytecode.h"
#include "Bcf.h"


void setUp() {}

void tearDown() {}



void test_bcf_should_clear_seventh_bit_to_0() {



  Instruction inst = {

                      .mnemonic = BCF,

                      .name = "bcf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x40,

     .operand2 = 7,

     .operand3 = 0

                  };





  FSR[code.operand1] = 0xC7;

  bcf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x47)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)26, UNITY_DISPLAY_STYLE_HEX8);

}



void test_bcf_should_clear_sixth_bit_to_0() {



  Instruction inst = {

                      .mnemonic = BCF,

                      .name = "bcf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x40,

     .operand2 = 6,

     .operand3 = 0

                  };





  FSR[code.operand1] = 0xD7;

  bcf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x97)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)46, UNITY_DISPLAY_STYLE_HEX8);

}



void test_bcf_should_clear_fifth_bit_to_0() {



  Instruction inst = {

                      .mnemonic = BCF,

                      .name = "bcf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x40,

     .operand2 = 5,

     .operand3 = 0

                  };





  FSR[code.operand1] = 0xE7;

  bcf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xC7)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)66, UNITY_DISPLAY_STYLE_HEX8);

}



void test_bcf_should_clear_fourth_bit_to_0() {



  Instruction inst = {

                      .mnemonic = BCF,

                      .name = "bcf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x40,

     .operand2 = 4,

     .operand3 = 0

                  };





  FSR[code.operand1] = 0x57;

  bcf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x47)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)86, UNITY_DISPLAY_STYLE_HEX8);

}



void test_bcf_should_clear_third_bit_to_0() {



  Instruction inst = {

                      .mnemonic = BCF,

                      .name = "bcf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x40,

     .operand2 = 3,

     .operand3 = 0

                  };





  FSR[code.operand1] = 0xAC;

  bcf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xA4)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)106, UNITY_DISPLAY_STYLE_HEX8);

}



void test_bcf_should_clear_second_bit_to_0() {



  Instruction inst = {

                      .mnemonic = BCF,

                      .name = "bcf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x40,

     .operand2 = 2,

     .operand3 = 0

                  };





  FSR[code.operand1] = 0x7D;

  bcf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x79)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)126, UNITY_DISPLAY_STYLE_HEX8);

}



void test_bcf_should_clear_first_bit_to_0() {



  Instruction inst = {

                      .mnemonic = BCF,

                      .name = "bcf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x40,

     .operand2 = 1,

     .operand3 = 0

                  };





  FSR[code.operand1] = 0x6B;

  bcf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x69)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)146, UNITY_DISPLAY_STYLE_HEX8);

}



void test_bcf_should_clear_zero_bit_to_0() {



  Instruction inst = {

                      .mnemonic = BCF,

                      .name = "bcf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x40,

     .operand2 = 0,

     .operand3 = 0

                  };





  FSR[code.operand1] = 0xE7;

  bcf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xE6)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)166, UNITY_DISPLAY_STYLE_HEX8);

}



void test_bcf_should_clear_seventh_bit_to_0_BSR() {



  Instruction inst = {

                      .mnemonic = BCF,

                      .name = "bcf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x41,

     .operand2 = 7,

     .operand3 = 1

                  };





  FSR[0xFE0] = 0x0E;

  FSR[code.operand1+(FSR[0xFE0]<<8)] = 0x8F;

  bcf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x0F)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)187, UNITY_DISPLAY_STYLE_HEX8);

}



void test_bcf_should_clear_sixth_bit_to_0_BSR() {



  Instruction inst = {

                      .mnemonic = BCF,

                      .name = "bcf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x41,

     .operand2 = 6,

     .operand3 = 1

                  };





  FSR[0xFE0] = 0x0E;

  FSR[code.operand1+(FSR[0xFE0]<<8)] = 0x72;

  bcf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x32)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)208, UNITY_DISPLAY_STYLE_HEX8);

}



void test_bcf_should_clear_fifth_bit_to_0_BSR() {



  Instruction inst = {

                      .mnemonic = BCF,

                      .name = "bcf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x41,

     .operand2 = 5,

     .operand3 = 1

                  };





  FSR[0xFE0] = 0x0E;

  FSR[code.operand1+(FSR[0xFE0]<<8)] = 0x6A;

  bcf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x4A)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)229, UNITY_DISPLAY_STYLE_HEX8);

}



void test_bcf_should_clear_fourth_bit_to_0_BSR() {



  Instruction inst = {

                      .mnemonic = BCF,

                      .name = "bcf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x41,

     .operand2 = 4,

     .operand3 = 1

                  };





  FSR[0xFE0] = 0x0E;

  FSR[code.operand1+(FSR[0xFE0]<<8)] = 0xD3;

  bcf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xC3)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)250, UNITY_DISPLAY_STYLE_HEX8);

}



void test_bcf_should_clear_third_bit_to_0_BSR() {



  Instruction inst = {

                      .mnemonic = BCF,

                      .name = "bcf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x41,

     .operand2 = 3,

     .operand3 = 1

                  };





  FSR[0xFE0] = 0x0E;

  FSR[code.operand1+(FSR[0xFE0]<<8)] = 0xFB;

  bcf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xF3)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)271, UNITY_DISPLAY_STYLE_HEX8);

}



void test_bcf_should_clear_second_bit_to_0_BSR() {



  Instruction inst = {

                      .mnemonic = BCF,

                      .name = "bcf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x41,

     .operand2 = 2,

     .operand3 = 1

                  };





  FSR[0xFE0] = 0x0E;

  FSR[code.operand1+(FSR[0xFE0]<<8)] = 0xAF;

  bcf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xAB)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)292, UNITY_DISPLAY_STYLE_HEX8);

}



void test_bcf_should_clear_first_bit_to_0_BSR() {



  Instruction inst = {

                      .mnemonic = BCF,

                      .name = "bcf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x41,

     .operand2 = 1,

     .operand3 = 1

                  };





  FSR[0xFE0] = 0x0E;

  FSR[code.operand1+(FSR[0xFE0]<<8)] = 0xC3;

  bcf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xC1)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)313, UNITY_DISPLAY_STYLE_HEX8);

}



void test_bcf_should_clear_zero_bit_to_0_BSR() {



  Instruction inst = {

                      .mnemonic = BCF,

                      .name = "bcf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x41,

     .operand2 = 0,

     .operand3 = 1

                  };





  FSR[0xFE0] = 0x0E;

  FSR[code.operand1+(FSR[0xFE0]<<8)] = 0x73;

  bcf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x72)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)334, UNITY_DISPLAY_STYLE_HEX8);

}



void test_bcf_should_throw_exception_error_BSR_more_than_15() {



  ExceptionError exception;





  Instruction inst = {

                      .mnemonic = BCF,

                      .name = "bcf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x54,

     .operand2 = 0,

     .operand3 = 1

                  };





  FSR[0xFE0] = 0xff;



  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

 bcf(&code);

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

 UnityAssertEqualNumber((_U_SINT)((ERROR_BSR)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)359, UNITY_DISPLAY_STYLE_INT);

  }



}



void test_bcf_operand1_should_throw_exception_error_more_than_255_or_less_than_0(){

  ExceptionError exception;





  Instruction inst = {

                      .mnemonic = BCF,

                      .name = "bcf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0xfff,

     .operand2 = 0,

     .operand3 = 1

                  };







  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

 bcf(&code);

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

 UnityAssertEqualNumber((_U_SINT)((ERROR_RANGE)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)384, UNITY_DISPLAY_STYLE_INT);

  }

}



void test_bcf_operand3_has_valid_value_while_operand2_is_negative_1_should_throw_exception_error(){

  ExceptionError exception;





  Instruction inst = {

                      .mnemonic = BCF,

                      .name = "bcf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x2A,

     .operand2 = -1,

     .operand3 = 0

                  };







  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

 bcf(&code);

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

 UnityAssertEqualNumber((_U_SINT)((ERROR_OPERAND2)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)408, UNITY_DISPLAY_STYLE_INT);

  }

}



void test_bcf_operand2_has_valid_value_while_operand3_is_negative_1_should_throw_exception_error(){

  ExceptionError exception;





  Instruction inst = {

                      .mnemonic = BCF,

                      .name = "bcf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x2A,

     .operand2 = 0,

     .operand3 = -1

                  };







  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

 bcf(&code);

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

 UnityAssertEqualNumber((_U_SINT)((ERROR_OPERAND3)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)432, UNITY_DISPLAY_STYLE_INT);

  }

}



void test_bcf_operand2_and_operand3_is_negative_1_should_throw_exception_error(){

  ExceptionError exception;





  Instruction inst = {

                      .mnemonic = BCF,

                      .name = "bcf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x7D,

     .operand2 = -1,

     .operand3 = -1

                  };







  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

 bcf(&code);

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

 UnityAssertEqualNumber((_U_SINT)((ERROR_OPERAND2andOPERAND3)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)456, UNITY_DISPLAY_STYLE_INT);

  }

}
