#include "unity.h"
#include "Bytecode.h"
#include "Rrncf.h"
#include "CException.h"

void setUp() {}
void tearDown() {}

void test_rrncf_should_throw_error_exception_if_operand1_over_range(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = RRNCF,
                      .name = "rrncf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0xffff,
					.operand2 = 0,
					.operand3 = ACCESS
                  };
  int exception;
  
  // Unit test
  Try{
	rrncf(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_RANGE, exception);
  }
}

void test_rrncf_should_throw_error_exception_if_operand2_more_than_1_and_less_than_negative_5(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = RRNCF,
                      .name = "rrncf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x40,
					.operand2 = -1,
					.operand3 = ACCESS
                  };
  int exception;
  
  // Test RRNCF of the bytecode			  
  FSR[code.operand1] = 0x53;
  
  // Unit test
  Try{
	rrncf(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_OPERAND2, exception);
  }
}

void test_rrncf_should_throw_error_exception__if_operand3_more_than_negative_5_and_1_and_is_negative_2_and_negative_3(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = RRNCF,
                      .name = "rrncf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x40,
					.operand2 = 0,
					.operand3 = -3
                  };
  int exception;
  
  // Test RRNCF of the bytecode			  
  FSR[code.operand1] = 0x23;
  
  // Unit test
  Try{
	rrncf(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_OPERAND3, exception);
  }
}

void test_rrncf_should_rotate_right_with_11010111_to_11101011_and_store_in_fileReg_when_operand1_less_than_0x80_operand2_is_1_and_operand3_is_0() {
  Instruction inst = {
                      .mnemonic = RRNCF,
                      .name = "rrncf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x64,
					.operand2 = 1,
					.operand3 = 0
                  };
				  
  // Test RRNCF of the bytecode
  FSR[code.operand1] = 0b11010111;
  code.absoluteAddress = 0x10;
  rrncf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL(0b11101011, FSR[code.operand1]);
  TEST_ASSERT_EQUAL_HEX8(0x11, code.absoluteAddress);
  TEST_ASSERT_EQUAL(0b00000000, FSR[STATUS]);
}

void test_rrncf_should_rotate_right_with_00110101_to_10011010_and_store_in_fileReg_when_operand1_more_than_0x80_operand2_is_1_and_operand3_is_0() {
  Instruction inst = {
                      .mnemonic = RRNCF,
                      .name = "rrncf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0xAC,
					.operand2 = 1,
					.operand3 = 0
                  };
				  
  // Test RRNCF of the bytecode
  FSR[code.operand1 + (0x0F00)] = 0b00110101;
  code.absoluteAddress = 0x10;
  rrncf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL(0b10011010, FSR[code.operand1 + (0x0F00)]);
  TEST_ASSERT_EQUAL_HEX8(0x11, code.absoluteAddress);
  TEST_ASSERT_EQUAL(0b00000000, FSR[STATUS]);

}

void test_rrncf_should_rotate_right_with_10011010_to_01001101_and_store_in_WREG_when_operand1_less_than_0x80_operand2_is_W_and_operand3_is_ACCESS() {
  Instruction inst = {
                      .mnemonic = RRNCF,
                      .name = "rrncf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x76,
					.operand2 = W,
					.operand3 = ACCESS
                  };
				  
  // Test RRNCF of the bytecode
  FSR[code.operand1] = 0b10011010;
  code.absoluteAddress = 0x10;
  rrncf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL(0b01001101, FSR[WREG]);
  TEST_ASSERT_EQUAL_HEX8(0x11, code.absoluteAddress);
  TEST_ASSERT_EQUAL(0b00000000, FSR[STATUS]);
}

void test_rrncf_should_rotate_right_with_00001001_to_10000100_and_store_in_WREG_when_operand1_more_than_0x80_operand2_is_W_and_operand3_is_ACCESS() {
  Instruction inst = {
                      .mnemonic = RRNCF,
                      .name = "rrncf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0xCA,
					.operand2 = W,
					.operand3 = ACCESS
                  };
				  
  // Test RRNCF of the bytecode
  FSR[code.operand1 + (0x0F00)] = 0b00001001;
  code.absoluteAddress = 0x10;
  rrncf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL(0b10000100, FSR[WREG + (0x0F00)]);
  TEST_ASSERT_EQUAL_HEX8(0x11, code.absoluteAddress);
  TEST_ASSERT_EQUAL(0b00000000, FSR[STATUS]);
}

void test_rrncf_should_rotate_right_BSR_with_01011010_to_00101101_and_store_in_fileReg_when_operand2_is_F_and_operand3_is_BANKED() {
  Instruction inst = {
                      .mnemonic = RRNCF,
                      .name = "rrncf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0xCA,
					.operand2 = F,
					.operand3 = BANKED
                  };
				  
  // Test RRNCF of the bytecode
  FSR[BSR] = 0x08;
  FSR[code.operand1 + (FSR[BSR]<<8)] = 0b01011010;
  code.absoluteAddress = 0x10;
  rrncf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL(0b00101101, FSR[code.operand1 + (FSR[BSR]<<8)]);
  TEST_ASSERT_EQUAL_HEX8(0x11, code.absoluteAddress);
  TEST_ASSERT_EQUAL(0b00000000, FSR[STATUS]);
}

void test_rrncf_should_rotate_right_BSR_with_11100111_to_11110011_and_store_in_fileReg_when_operand2_is_W_and_operand3_is_BANKED() {
  Instruction inst = {
                      .mnemonic = RRNCF,
                      .name = "rrncf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0xCA,
					.operand2 = W,
					.operand3 = BANKED
                  };
				  
  // Test RRNCF of the bytecode
  FSR[BSR] = 0x08;
  FSR[code.operand1 + (FSR[BSR]<<8)] = 0b11100111;
  code.absoluteAddress = 0x10;
  rrncf(&code);
	
  // Unit test
  TEST_ASSERT_EQUAL(0b11110011, FSR[WREG]);
  TEST_ASSERT_EQUAL_HEX8(0x11, code.absoluteAddress);
  TEST_ASSERT_EQUAL(0b00000000, FSR[STATUS]);
}

void test_rrncf_should_throw_exception_error_BSR_more_than_15() {

  ExceptionError exception;
  
  // Create test fixture
  Instruction inst = {
                      .mnemonic = RRNCF,
                      .name = "rrncf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x54,
					.operand2 = -1,
					.operand3 = 1
                  };
	
  // Test RRNCF of the bytecode
  FSR[BSR] = 0xff;
  
  Try{
	rrncf(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_BSR, exception);
  }
}