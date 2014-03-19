#include "unity.h"
#include "Bytecode.h"
#include "Negf.h"
#include "CException.h"

void setUp() {}
void tearDown() {}

void test_negf_should_negate_fileReg_and_placed_to_fileReg() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = NEGF,
                      .name = "negf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x40,
					.operand2 = -1,
					.operand3 = 0
                  };
	
  // Test NEGF of the bytecode
  FSR[code.operand1] = 0x3A;
  negf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0xC6, FSR[code.operand1]);
}

void test_negf_should_negate_fileReg_and_placed_to_fileReg_BSR() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = NEGF,
                      .name = "negf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x40,
					.operand2 = -1,
					.operand3 = 1
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

void test_negf_operand1_should_throw_exception_error_more_than_255_or_less_than_0(){
  ExceptionError exception;
  
  // Create test fixture
  Instruction inst = {
                      .mnemonic = NEGF,
                      .name = "negf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0xfff,
					.operand2 = 0,
					.operand3 = 1
                  };
	
  // Test NEGF of the bytecode
  
  Try{
	negf(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_RANGE, exception);
  }
}

void test_negf_operand2_has_valid_value_while_operand3_is_negative_1_should_throw_exception_error(){
  ExceptionError exception;
  
  // Create test fixture
  Instruction inst = {
                      .mnemonic = NEGF,
                      .name = "negf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x2A,
					.operand2 = 1,
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
	TEST_ASSERT_EQUAL(ERROR_OPERAND3, exception);
  }
}

