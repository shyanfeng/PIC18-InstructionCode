#include "unity.h"
#include "Bytecode.h"
#include "Movf.h"
#include "CException.h"

void setUp() {}
void tearDown() {}

void test_movf_should_throw_error_exception__if_operand1_over_range(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = MOVF,
                      .name = "movf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0xfff,
					.operand2 = 0,
					.operand3 = ACCESS
                  };
  int exception;
  
  // Test MOVF of the bytecode			  
  FSR[code.operand1] = 0x53;
  
  // Unit test
  Try{
	movf(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_RANGE, exception);
  }
}

void test_movf_should_throw_error_exception_if_operand2_more_than_1_and_less_than_negative_5(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = MOVF,
                      .name = "movf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x40,
					.operand2 = -1,
					.operand3 = ACCESS
                  };
  int exception;
  
  // Test MOVF of the bytecode			  
  FSR[code.operand1] = 0x53;
  
  // Unit test
  Try{
	movf(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_OPERAND2, exception);
  }
  
}

void test_movf_should_throw_error_exception__if_operand3_more_than_negative_5_and_1_and_is_negative_2_and_negative_3(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = MOVF,
                      .name = "movf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x40,
					.operand2 = 0,
					.operand3 = -3
                  };
  int exception;
  
  // Test MOVF of the bytecode			  
  FSR[code.operand1] = 0x23;
  
  // Unit test
  Try{
	movf(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_OPERAND3, exception);
  }
  
}

void test_movf_should_move_fileReg_to_WREG_when_operand1_less_than_0x80_and_operand2_is_0_and_operand3_is_0() {
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

void test_movf_should_move_fileReg_to_WREG_when_operand1_more_than_0x80_and_operand2_is_0_and_operand3_is_0() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = MOVF,
                      .name = "movf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x8C,
					.operand2 = 0,
					.operand3 = 0
                  };
	
  // Test MOVF of the bytecode
  FSR[code.operand1 + (0x0F00)] = 0xA2;
  movf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0xA2, FSR[WREG + (0x0F00)]);
}

void test_movf_should_move_fileReg_to_fileReg_when_operand1_less_than_0x80_and_operand2_is_F_and_operand3_is_ACCESS() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = MOVF,
                      .name = "movf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x3C,
					.operand2 = F,
					.operand3 = ACCESS
                  };
	
  // Test MOVF of the bytecode
  FSR[code.operand1] = 0x56;
  movf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x56, FSR[code.operand1]);
}

void test_movf_should_move_fileReg_to_fileReg_when_operand1_more_than_0x80_and_operand2_is_F_and_operand3_is_ACCESS() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = MOVF,
                      .name = "movf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0xD1,
					.operand2 = F,
					.operand3 = BANKED
                  };
	
  // Test MOVF of the bytecode
  FSR[code.operand1 + (0x0F00)] = 0x56;
  movf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x56, FSR[code.operand1 + (0x0F00)]);
}

void test_movf_should_move_fileReg_to_WREG_BSR_when_operand2_is_0_and_operand3_is_1() {
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
  FSR[code.operand1 + (FSR[BSR]<<8)] = 0x1C;
  movf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x1C, FSR[WREG]);
}

void test_movf_should_move_fileReg_to_fileReg_BSR_when_operand2_is_F_and_operand3_is_BANKED() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = MOVF,
                      .name = "movf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x9E,
					.operand2 = F,
					.operand3 = BANKED
                  };
	
  // Test MOVF of the bytecode
  FSR[code.operand1 + (FSR[BSR]<<8)] = 0x5A;
  movf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x5A, FSR[code.operand1 + (FSR[BSR]<<8)]);
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
					.operand2 = F,
					.operand3 = BANKED
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


