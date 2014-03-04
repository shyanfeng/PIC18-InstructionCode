#include "unity.h"
#include "Clrf.h"
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

     .operand2 = 0

                  };





  FSR[code.operand1] = 0xFF;

  clrf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)24, UNITY_DISPLAY_STYLE_HEX8);

}



void test_clrf_should_clear_BSR() {



  Instruction inst = {

                      .mnemonic = CLRF,

                      .name = "clrf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0x41,

     .operand2 = 1

                  };





  FSR[code.operand1] = 0xFF;

  FSR[0xFE0] = 0x0F;

  clrf(&code);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[code.operand1+(FSR[0xFE0]<<8)])), (((void *)0)), (_U_UINT)44, UNITY_DISPLAY_STYLE_HEX8);

}
