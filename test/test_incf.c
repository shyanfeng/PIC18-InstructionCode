#include "unity.h"
#include "Bytecode.h"
#include "Incf.h"
#include "CException.h"

void setUp() {}
void tearDown() {}

void test_incf_should_throw_error_exception__if_operand1_over_range(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = INCF,
                      .name = "incf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0xffff,
					.operand2 = 0,
					.operand3 = ACCESS
                  };
  int exception;	  
  
  // Unit test
  Try{
	incf(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_RANGE, exception);
  }
  
}

void test_incf_should_throw_error_exception__if_operand2_more_than_1_and_less_than_negative_5(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = INCF,
                      .name = "incf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x40,
					.operand2 = 5,
					.operand3 = 0
                  };
  int exception;
  
  // Test INCF of the bytecode			  
  FSR[code.operand1] = 0x53;
  
  // Unit test
  Try{
	incf(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_OPERAND2, exception);
  }
  
}

void test_incf_should_throw_error_exception__if_operand3_more_than_negative_5_and_1_and_is_negative_2_and_negative_3(){
  // Create test fixture
  Instruction inst = {
                      .mnemonic = INCF,
                      .name = "incf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x40,
					.operand2 = 0,
					.operand3 = -3
                  };
  int exception;
  
  // Test INCF of the bytecode			  
  FSR[code.operand1] = 0x23;
  
  // Unit test
  Try{
	incf(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_OPERAND3, exception);
  }
  
}

void test_incf_should_increment_fileReg_and_store_in_fileReg_when_operand1_less_than_0x80_and_operand2_is_1_and_operand3_is_ACCESS() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = INCF,
                      .name = "incf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x36,
					.operand2 = 1,
					.operand3 = ACCESS
                  };
	
  // Test INCF of the bytecode
  FSR[code.operand1] = 0x12;
  code.absoluteAddress = 0x10;
  incf(&code);
	
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x13, FSR[code.operand1]);
  TEST_ASSERT_EQUAL_HEX8(0x11, code.absoluteAddress);
  TEST_ASSERT_EQUAL(0b00000000, FSR[STATUS]);
}

void test_incf_should_increment_fileReg_and_store_in_fileReg_when_operand1_more_than_0x80_and_operand2_is_1_and_operand3_is_ACCESS() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = INCF,
                      .name = "incf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0xB2,
					.operand2 = 1,
					.operand3 = ACCESS
                  };
	
  // Test INCF of the bytecode
  FSR[code.operand1 + (0x0F00)] = 0x40;
  code.absoluteAddress = 0x10;
  incf(&code);
	
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x41, FSR[code.operand1 + (0x0F00)]);
  TEST_ASSERT_EQUAL_HEX8(0x11, code.absoluteAddress);
  TEST_ASSERT_EQUAL(0b00000010, FSR[STATUS]);
}

void test_incf_should_increment_fileReg_and_store_in_WREG_when_operand1_less_than_0x80_and_operand2_is_W_and_operand3_is_ACCESS() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = INCF,
                      .name = "incf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x13,
					.operand2 = W,
					.operand3 = ACCESS
                  };
	
  // Test INCF of the bytecode
  FSR[code.operand1] = 0xF2;
  code.absoluteAddress = 0x10;
  incf(&code);
	
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0xF2, FSR[code.operand1]);
  TEST_ASSERT_EQUAL_HEX8(0xF3, FSR[WREG]);
  TEST_ASSERT_EQUAL_HEX8(0x11, code.absoluteAddress);
}

void test_incf_should_increment_fileReg_and_store_in_WREG_when_operand1_more_than_0x80_and_operand2_is_W_and_operand3_is_ACCESS() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = INCF,
                      .name = "incf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x13,
					.operand2 = W,
					.operand3 = ACCESS
                  };
	
  // Test INCF of the bytecode
  FSR[code.operand1] = 0x34;
  code.absoluteAddress = 0x10;
  incf(&code);
	
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x34, FSR[code.operand1]);
  TEST_ASSERT_EQUAL_HEX8(0x35, FSR[WREG]);
  TEST_ASSERT_EQUAL_HEX8(0x11, code.absoluteAddress);
}

void test_incf_should_increment_fileReg_and_store_in_fileReg_when_BSR_more_than_0_and_less_than_15_and_operand2_is_F_and_operand3_is_BANKED() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = INCF,
                      .name = "incf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0xB2,
					.operand2 = F,
					.operand3 = BANKED
                  };
	
  // Test INCF of the bytecode
  FSR[BSR] = 0x0C;
  FSR[code.operand1+(FSR[BSR]<<8)] = 0x23;
  code.absoluteAddress = 0x10;
  incf(&code);

  
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x24, FSR[code.operand1+(FSR[BSR]<<8)]);
  TEST_ASSERT_EQUAL_HEX8(0x11, code.absoluteAddress);
}

void test_incf_should_increment_fileReg_and_store_in_WREG_when_BSR_more_than_0_and_less_than_15_and_operand2_is_W_and_operand3_is_BANKED() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = INCF,
                      .name = "incf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0xB2,
					.operand2 = W,
					.operand3 = BANKED
                  };
	
  // Test INCF of the bytecode
  FSR[BSR] = 0x08;
  FSR[code.operand1 + (FSR[BSR]<<8)] = 0x56;
  code.absoluteAddress = 0x10;
  incf(&code);

  
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x56, FSR[code.operand1 + (FSR[BSR]<<8)]);
  TEST_ASSERT_EQUAL_HEX8(0x57, FSR[WREG]);
  TEST_ASSERT_EQUAL_HEX8(0x11, code.absoluteAddress);
}

void test_incf_should_increment_fileReg_with_status_affected_and_store_in_fileReg_and_operand2_is_W_and_operand3_is_ACCESS() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = INCF,
                      .name = "incf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0x98,
					.operand2 = F,
					.operand3 = ACCESS
                  };
	
  // Test INCF of the bytecode
  FSR[code.operand1 + (0x0F00)] = 0xFF;
  code.absoluteAddress = 0x10;
  incf(&code);

  
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x00, FSR[code.operand1 + (0x0F00)]);
  TEST_ASSERT_EQUAL_HEX8(0x11, code.absoluteAddress);
}

void test_incf_should_throw_exception_error_BSR_more_than_15() {

  ExceptionError exception;

  // Create test fixture
  Instruction inst = {
                      .mnemonic = INCF,
                      .name = "incf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0xB2,
					.operand2 = 0,
					.operand3 = 1
                  };
	
  // Test INCF of the bytecode
  FSR[BSR] = 0xff;
  
  Try{
	incf(&code);
  }
  Catch(exception){
	TEST_ASSERT_EQUAL(ERROR_BSR, exception);
  }

}

