#include "unity.h"
#include "Incf.h"
#include "Bytecode.h"


void setUp() {}

void tearDown() {}



void test_incf_should_increment_fileReg_and_store_in_fileReg() {



  Instruction inst = {

                      .mnemonic = INCF,

                      .name = "incf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0xB4,

     .operand2 = 1,

     .operand3 = 0

                  };





  FSR[code.operand1] = 0x40;

  incf(&code);







  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x41)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)26, UNITY_DISPLAY_STYLE_HEX8);

}



void test_incf_should_increment_fileReg_and_store_in_WREG() {



  Instruction inst = {

                      .mnemonic = INCF,

                      .name = "incf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0xB5,

     .operand2 = 0,

     .operand3 = 0

                  };





  FSR[code.operand1] = 0xF2;

  incf(&code);







  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xF2)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)47, UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xF3)), (_U_SINT)(_US8 )((FSR[0xf8b])), (((void *)0)), (_U_UINT)48, UNITY_DISPLAY_STYLE_HEX8);

}



void test_incf_should_increment_fileReg_and_select_BSR_and_store_in_fileReg() {



  Instruction inst = {

                      .mnemonic = INCF,

                      .name = "incf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0xB2,

     .operand2 = 1,

     .operand3 = 1

                  };





  FSR[code.operand1] = 0x53;

  FSR[0xFE0] = 0x0C;

  FSR[code.operand1+(FSR[0xFE0]<<8)] = 22;

  incf(&code);







  UnityAssertEqualNumber((_U_SINT)(_US8 )((23)), (_U_SINT)(_US8 )((FSR[code.operand1+(FSR[0xFE0]<<8)])), (((void *)0)), (_U_UINT)71, UNITY_DISPLAY_STYLE_HEX8);

}



void test_incf_should_increment_fileReg_and_select_BSR_and_store_in_WREG() {



  Instruction inst = {

                      .mnemonic = INCF,

                      .name = "incf"

                     };

  Bytecode code = { .instruction = &inst,

                    .operand1 = 0xB2,

     .operand2 = 0,

     .operand3 = 1

                  };





  FSR[code.operand1] = 0x34;

  FSR[0xFE0] = 0x08;

  FSR[code.operand1+(FSR[0xFE0]<<8)] = 56;

  incf(&code);







  UnityAssertEqualNumber((_U_SINT)(_US8 )((56)), (_U_SINT)(_US8 )((FSR[code.operand1+(FSR[0xFE0]<<8)])), (((void *)0)), (_U_UINT)94, UNITY_DISPLAY_STYLE_HEX8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((57)), (_U_SINT)(_US8 )((FSR[0xf8b])), (((void *)0)), (_U_UINT)95, UNITY_DISPLAY_STYLE_HEX8);

}
