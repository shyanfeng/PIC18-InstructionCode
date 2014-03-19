#include "unity.h"
#include "Bytecode.h"
#include "Movf.h"
#include "CException.h"

void setUp() {}
void tearDown() {}

void test_movf_should_move_fileReg_to_WREG() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = MOVF,
                      .name = "movf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x3C,
					.operand2 = 0,
					.operand3 = 0
                  };
	
  // Test MOVF of the bytecode
  FSR[code.operand1] = 0x22;
  movf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x22, FSR[WREG]);
}

void test_movf_should_move_fileReg_to_fileReg() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = MOVF,
                      .name = "movf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x3C,
					.operand2 = 1,
					.operand3 = 0
                  };
	
  // Test MOVF of the bytecode
  FSR[code.operand1] = 0x56;
  movf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x56, FSR[code.operand1]);
}

void test_movf_should_move_fileReg_to_WREG_BSR() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = MOVF,
                      .name = "movf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x3C,
					.operand2 = 0,
					.operand3 = 1
                  };
	
  // Test MOVF of the bytecode
  FSR[code.operand1] = 0x1C;
  movf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x1C, FSR[WREG]);
}

void test_movf_should_move_fileReg_to_fileReg_BSR() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = MOVF,
                      .name = "movf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x3C,
					.operand2 = 1,
					.operand3 = 1
                  };
	
  // Test MOVF of the bytecode
  FSR[code.operand1] = 0x5A;
  movf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x5A, FSR[code.operand1]);
}

void test_movf_should_throw_exception_error_BSR_more_than_15() {

  ExceptionError exception;
  
  // Create test fixture
  Instruction inst = {
                      .mnemonic = MOVF,
                      .name = "movf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x54,
					.operand2 = 0,
					.operand3 = 1
                  };
	
  // Test MOVF of the bytecode
  FSR[BSR] = 0xff;
  
  Try{
	movf(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_BSR, exception);
  }
}

void test_movf_operand1_should_throw_exception_error_more_than_255_or_less_than_0(){
  ExceptionError exception;
  
  // Create test fixture
  Instruction inst = {
                      .mnemonic = MOVF,
                      .name = "movf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0xfff,
					.operand2 = 0,
					.operand3 = 1
                  };
	
  // Test MOVF of the bytecode
  
  Try{
	movf(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_RANGE, exception);
  }
}

void test_movf_operand3_has_valid_value_while_operand2_is_negative_1_should_throw_exception_error(){
  ExceptionError exception;
  
  // Create test fixture
  Instruction inst = {
                      .mnemonic = MOVF,
                      .name = "movf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x2A,
					.operand2 = -1,
					.operand3 = 0
                  };
	
  // Test MOVF of the bytecode
  
  Try{
	movf(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_OPERAND2, exception);
  }
}

void test_movf_operand2_has_valid_value_while_operand3_is_negative_1_should_throw_exception_error(){
  ExceptionError exception;
  
  // Create test fixture
  Instruction inst = {
                      .mnemonic = MOVF,
                      .name = "movf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x2A,
					.operand2 = 0,
					.operand3 = -1
                  };
	
  // Test MOVF of the bytecode
  
  Try{
	movf(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_OPERAND3, exception);
  }
}

void test_movf_operand2_and_operand3_is_negative_1_should_throw_exception_error(){
  ExceptionError exception;
  
  // Create test fixture
  Instruction inst = {
                      .mnemonic = MOVF,
                      .name = "movf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x7D,
					.operand2 = -1,
					.operand3 = -1
                  };
	
  // Test MOVF of the bytecode
  
  Try{
	movf(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_OPERAND2andOPERAND3, exception);
  }
}

