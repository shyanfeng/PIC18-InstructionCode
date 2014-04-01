#include "unity.h"
#include "Bytecode.h"
#include "Negf.h"
#include "CException.h"

void setUp() {}
void tearDown() {}

void test_negf_should_throw_error_exception__if_operand1_over_range(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = NEGF,
                      .name = "negf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0xfff,
					.operand2 = 0,
					.operand3 = ACCESS
                  };
  int exception;
  
  // Test NEGF of the bytecode			  
  FSR[code.operand1] = 0x53;
  
  // Unit test
  Try{
	negf(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_RANGE, exception);
  }
}

void test_negf_should_throw_error_exception_if_operand2_more_than_1_and_less_than_negative_5(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = NEGF,
                      .name = "negf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x40,
					.operand2 = -1,
					.operand3 = ACCESS
                  };
  int exception;
  
  // Test NEGF of the bytecode			  
  FSR[code.operand1] = 0x53;
  
  // Unit test
  Try{
	negf(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_OPERAND2, exception);
  }
}

void test_negf_should_throw_error_exception__if_operand3_more_than_negative_5_and_1_and_is_negative_2_and_negative_3(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = NEGF,
                      .name = "negf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x40,
					.operand2 = 0,
					.operand3 = -3
                  };
  int exception;
  
  // Test NEGF of the bytecode			  
  FSR[code.operand1] = 0x23;
  
  // Unit test
  Try{
	negf(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_OPERAND3, exception);
  }
}

void test_negf_should_negate_fileReg_when_operand1_less_than_0x80_and_operand2_is_ACCESS_and_operand3_is_negative_1() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = NEGF,
                      .name = "negf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x5D,
					.operand2 = ACCESS,
					.operand3 = -1
                  };
	
  // Test NEGF of the bytecode
  FSR[code.operand1] = 0x3A;
  negf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0xC6, FSR[code.operand1]);
}

void test_negf_should_negate_fileReg_when_operand1_more_than_0x80_and_operand2_is_ACCESS_and_operand3_is_negative_1() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = NEGF,
                      .name = "negf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0xA1,
					.operand2 = ACCESS,
					.operand3 = -1
                  };
	
  // Test NEGF of the bytecode
  FSR[code.operand1 + (0x0F00)] = 0xD2;
  negf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x2E, FSR[code.operand1 + (0x0F00)]);
}

void test_negf_should_negate_fileReg_when_operand1_less_than_0x80_operand2_is_negative_1_and_operand3_is_ACCESS() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = NEGF,
                      .name = "negf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x40,
					.operand2 = -1,
					.operand3 = ACCESS
                  };
	
  // Test NEGF of the bytecode
  FSR[code.operand1] = 0xDB;
  negf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x25, FSR[code.operand1]);
}

void test_negf_should_throw_exception_error_BSR_more_than_15() {

  ExceptionError exception;
  
  // Create test fixture
  Instruction inst = {
                      .mnemonic = NEGF,
                      .name = "negf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x54,
					.operand2 = -1,
					.operand3 = 1
                  };
	
  // Test NEGF of the bytecode
  FSR[BSR] = 0xff;
  
  Try{
	negf(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_BSR, exception);
  }
}

void test_negf_operand2_and_operand3_is_negative_1_should_throw_exception_error(){
  ExceptionError exception;
  
  // Create test fixture
  Instruction inst = {
                      .mnemonic = NEGF,
                      .name = "negf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x7D,
					.operand2 = -1,
					.operand3 = -1
                  };
	
  // Test MOVF of the bytecode
  
  Try{
	negf(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_OPERAND2andOPERAND3, exception);
  }
}

