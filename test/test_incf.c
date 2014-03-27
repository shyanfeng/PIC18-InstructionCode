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
                    .operand1 = 0xfff,
					.operand2 = 0,
					.operand3 = ACCESS
                  };
  int exception;
  
  // Test INCF of the bytecode			  
  FSR[code.operand1] = 0x53;
  
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

void test_incf_should_increment_fileReg_and_store_in_fileReg() {
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
  FSR[code.operand1] = 0x40;
  incf(&code);
	
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x41, FSR[code.operand1]);
}

void test_incf_should_increment_fileReg_and_store_in_WREG() {
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
  incf(&code);
	
	
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0xF2, FSR[code.operand1]);
  TEST_ASSERT_EQUAL_HEX8(0xF3, FSR[WREG]);
}

void test_incf_should_increment_fileReg_and_select_BSR_and_store_in_fileReg() {
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
  FSR[code.operand1] = 0x53;
  FSR[BSR] = 0x0C;
  FSR[code.operand1+(FSR[BSR]<<8)] = 0x23;
  incf(&code);

  
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x24, FSR[code.operand1+(FSR[BSR]<<8)]);
}

void test_incf_should_increment_fileReg_and_select_BSR_and_store_in_WREG() {
  // Create test fixture
  Instruction inst = {
                      .mnemonic = INCF,
                      .name = "incf"
                     };	
  Bytecode code = { .instruction = &inst,
                    .operand1 = 0xB2,
					.operand2 = 0,
					.operand3 = BANKED
                  };
	
  // Test INCF of the bytecode
  FSR[code.operand1] = 0x34;
  FSR[BSR] = 0x08;
  FSR[code.operand1 + (FSR[BSR]<<8)] = 0x56;
  incf(&code);

  
  // Unit test
  TEST_ASSERT_EQUAL_HEX8(0x56, FSR[code.operand1 + (FSR[BSR]<<8)]);
  TEST_ASSERT_EQUAL_HEX8(0x57, FSR[WREG]);
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

