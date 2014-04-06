#include "unity.h"
#include "Bytecode.h"
#include "Negf.h"
#include "CException.h"

void setUp() {}
void tearDown() {}

void test_negf_should_throw_error_exception_if_operand1_over_range(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = NEGF,
                      .name = "negf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0xffff,
					.operand2 = 0,
					.operand3 = ACCESS
                  };
  int exception;
  
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
					.operand3 = -1
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

void test_negf_should_throw_error_exception__if_operand3_not_empty(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = NEGF,
                      .name = "negf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x40,
					.operand2 = 0,
					.operand3 = 1
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
  code.absoluteAddress = 0x10;
  negf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0xC6, FSR[code.operand1]);
  TEST_ASSERT_EQUAL_HEX8(0x11, code.absoluteAddress);
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
  code.absoluteAddress = 0x10;
  negf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x2E, FSR[code.operand1 + (0x0F00)]);
  TEST_ASSERT_EQUAL_HEX8(0x11, code.absoluteAddress);
}

void test_negf_should_negate_fileReg_BSR_when_operand1_more_than_0x80_and_operand2_is_BANKED_and_operand3_is_negative_1() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = NEGF,
                      .name = "negf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0xA1,
					.operand2 = BANKED,
					.operand3 = -1
                  };
	
  // Test NEGF of the bytecode
  FSR[BSR] = 0x0A;
  FSR[code.operand1 + (FSR[BSR]<<8)] = 0xD2;
  code.absoluteAddress = 0x10;
  negf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x2E, FSR[code.operand1 + (FSR[BSR]<<8)]);
  TEST_ASSERT_EQUAL_HEX8(0x11, code.absoluteAddress);
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
					.operand3 = -1
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


