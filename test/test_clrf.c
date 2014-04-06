#include "unity.h"
#include "Bytecode.h"
#include "Clrf.h"
#include "CException.h"

void setUp() {}
void tearDown() {}

void test_clrf_should_throw_error_exception__if_operand1_over_range(){
  // Create test fixture
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

  // Unit test
  Try{
	clrf(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_RANGE, exception);
  }
  
}

void test_clrf_should_throw_error_exception__if_operand2_more_than_1_and_less_than_negative_5(){
  // Create test fixture
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
  
  // Test CLRF of the bytecode			  
  FSR[code.operand1] = 0x53;
  
  // Unit test
  Try{
	clrf(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_OPERAND2, exception);
  }
  
}

void test_clrf_should_clear_fileReg_when_operand2_is_empty_and_operand3_is_empty() {
  ExceptionError exception;
  // Create test fixture
  Instruction inst = {
                      .mnemonic = CLRF,
                      .name = "clrf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x41,
					.operand2 = -1,
					.operand3 = -1
                  };
	
  // Test CLRF of the bytecode
  FSR[code.operand1] = 0x34;
  code.absoluteAddress = 0x10;
  clrf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x00, FSR[code.operand1]);
  TEST_ASSERT_EQUAL(0b00000100, FSR[STATUS]);
  TEST_ASSERT_EQUAL_HEX8(0x11, code.absoluteAddress);
}

void test_clrf_should_clear_fileReg_when_operand1_is_less_than_0x80_and_operand2_is_0_and_operand3_is_empty() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = CLRF,
                      .name = "clrf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x40,
					.operand2 = 0,
					.operand3 = -1
                  };
	
  // Test CLRF of the bytecode
  FSR[code.operand1] = 0x45;
  code.absoluteAddress = 0x10;
  clrf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x00, FSR[code.operand1]);
  TEST_ASSERT_EQUAL(0b00000100, FSR[STATUS]);
  TEST_ASSERT_EQUAL_HEX8(0x11, code.absoluteAddress);
}

void test_clrf_should_clear_fileReg_when_operand1_is_more_than_0x80_and_operand2_is_ACCESS_and_operand3_is_empty() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = CLRF,
                      .name = "clrf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0xEF,
					.operand2 = ACCESS,
					.operand3 = -1
                  };
	
  // Test CLRF of the bytecode
  FSR[code.operand1 + (0x0F00)] = 0x45;
  code.absoluteAddress = 0x10;
  clrf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x00, FSR[code.operand1 + (0x0F00)]);
  TEST_ASSERT_EQUAL(0b00000100, FSR[STATUS]);
  TEST_ASSERT_EQUAL_HEX8(0x11, code.absoluteAddress);
}

void test_clrf_should_clear_BSR_is_more_than_0_and_less_than_15_when_operand2_is_BANKED_and_operand3_is_empty() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = CLRF,
                      .name = "clrf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0xA2,
					.operand2 = BANKED,
					.operand3 = -1
                  };
	
  // Test CLRF of the bytecode
  FSR[code.operand1 +(FSR[BSR]<<8)] = 0x8F;
  code.absoluteAddress = 0x10;
  FSR[BSR] = 0x0F;
  clrf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x00, FSR[code.operand1 + (FSR[BSR]<<8)]);
  TEST_ASSERT_EQUAL(0b00000100, FSR[STATUS]);
  TEST_ASSERT_EQUAL_HEX8(0x11, code.absoluteAddress);
}

void test_clrf_should_throw_exception_when_operand3_is_not_empty() {

  ExceptionError exception;
  
  // Create test fixture
  Instruction inst = {
                      .mnemonic = CLRF,
                      .name = "clrf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x54,
					.operand2 = 1,
					.operand3 = 1
                  };
	
  // Test CLRF of the bytecode
  Try{
	clrf(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_OPERAND3, exception);
  }

}

void test_clrf_should_throw_exception_error_BSR_more_than_15() {

  ExceptionError exception;
  
  // Create test fixture
  Instruction inst = {
                      .mnemonic = CLRF,
                      .name = "clrf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x54,
					.operand2 = 1,
					.operand3 = -1
                  };
	
  // Test CLRF of the bytecode
  FSR[BSR] = 0xff;
  
  Try{
	clrf(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_BSR, exception);
  }

}
