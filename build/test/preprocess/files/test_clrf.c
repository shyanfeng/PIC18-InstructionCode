#include "unity.h"
#include "Clrf.h"
#include "CException.h"
#include "Bytecode.h"


void setUp() {}

void tearDown() {}



void test_clrf_should_clear_fileReg() {



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





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)26, UNITY_DISPLAY_STYLE_HEX8);

}



void test_clrf_should_clear_BSR() {



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





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[code.operand1+(FSR[0xFE0]<<8)])), (((void *)0)), (_U_UINT)47, UNITY_DISPLAY_STYLE_HEX8);

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



 UnityAssertEqualNumber((_U_SINT)((ERROR_BSR)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)73, UNITY_DISPLAY_STYLE_INT);

  }



}



void test_clrf_operand1_should_throw_exception_more_than_255_or_less_than_0(){

  ExceptionError exception;





  Instruction inst = {

                      .mnemonic = CLRF,

                      .name = "clrf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0xfff,

     .operand2 = -1,

     .operand3 = 1

                  };







  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

 clrf(&code);

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){



 UnityAssertEqualNumber((_U_SINT)((ERROR_RANGE)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)99, UNITY_DISPLAY_STYLE_INT);

  }

}
